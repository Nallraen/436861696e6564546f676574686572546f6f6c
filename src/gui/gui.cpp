#include "gui.hpp"

#include "Dumper-7_5.3.2-29314046+++UE5+Release-5.3-ChainedTogether/CppSDK/SDK.hpp"
#include "gui/renderer.hpp"
#include "hooks/hooking.hpp"
#include "lua/bindings/imgui_window.hpp"
#include "lua_extensions/lua_manager_extension.hpp"
#include "lua_extensions/lua_module_ext.hpp"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tlhelp32.h>
#include <Psapi.h> // To get process info
#include <sstream>
#include <string>
#include <iostream>
#include <thread>
#include <atomic>

#include <codecvt>
#include <gui/widgets/imgui_hotkey.hpp>
#include <input/hotkey.hpp>
#include <input/is_key_pressed.hpp>
#include <lua/lua_manager.hpp>
#include <memory/gm_address.hpp>
#include <misc/cpp/imgui_stdlib.h>

#define M_PI 3.14159265358979323846

namespace big
{
	void freezeTimer(uintptr_t baseAddress, const std::vector<uintptr_t>& offsets, int32_t valueToFreeze, std::atomic<bool>& running);
	void writeDwordAddress(uintptr_t baseAddress, const std::vector<uintptr_t>& offsets, int32_t newValue);
	int32_t readValueAddress(uintptr_t baseAddress, std::vector<uintptr_t> offsets);

	static int pId = 0;

	HMODULE hModule = GetModuleHandle(NULL);
	uintptr_t baseAddress = reinterpret_cast<uintptr_t>(hModule);

	// Mostly used offsets (entre autre..)
	std::vector<uintptr_t> timerOffsets = {0x06F65C48, 0x158, 0x320};

	// Atomic flag to control the freezing thread for Timer
	std::atomic<bool> running(false);
	std::thread freezeThread;
	bool freezeEnabled = false;
	bool freezeAt0   = false;
	bool freezeAtNeg = false;

	static SDK::ABP_Character_C* g_pawn  = nullptr;
	static SDK::ABP_Character_C* g_pawn2 = nullptr;
	static SDK::ABP_Character_C* g_pawn3 = nullptr;
	static SDK::ABP_Character_C* g_pawn4 = nullptr;
	static SDK::UCustomGI_C* g_customgi = nullptr;
	static SDK::AHUD* g_ahud            = nullptr;


	static SDK::IBPI_Gamestate_C* bpiGameState = nullptr;
	static SDK::AGS_Game_C* gameBaseData = nullptr;
	static int32_t timer;

	static bool g_draw_g_pawn_hitbox          = false;
	static bool g_draw_hitbox_proximity_based = false;

	static float g_draw_g_pawn_sphere_radius_hitbox   = 200;
	static int32_t g_draw_g_pawn_sphere_segment_count = 32;
	static ImVec4 g_draw_pawn_sphere_hitbox_color_edit{1, 1, 1, 1};
	static ImU32 g_draw_pawn_sphere_hitbox_color_final             = IM_COL32(255, 255, 255, 255);
	static std::optional<SDK::FVector> g_draw_pawn_sphere_position = {};

	static std::optional<SDK::FVector> g_latest_saved_position{};
	static hotkey g_chained_together_save_current_position("chained_together_save_current_position", VK_F5);
	static hotkey g_chained_together_tp_to_latest_saved_position("chained_together_tp_to_latest_saved_position", VK_F6);
	static bool g_chained_together_fly_mode_state_p1 = false;
	static bool g_chained_together_fly_mode_state_p2 = false;
	static bool g_chained_together_fly_mode_state_p3 = false;
	static bool g_chained_together_fly_mode_state_p4 = false;
	static bool g_chained_together_fly_mode_state_all = false;
	static hotkey g_chained_together_fly_mode("chained_together_fly_mode", VK_F7);
	static bool g_chained_together_perfect_bunny_state = false;
	static hotkey g_chained_together_perfect_bunny_hotkey("chained_together_perfect_bunny_toggle", 0);

	struct shouldDrawActorInfo
	{
		size_t index;
		bool shouldDraw;
	};

	static std::unordered_map<size_t, shouldDrawActorInfo> g_shouldDraw;

	gui::gui()
	{
		init_pref();

		g_renderer->add_dx_callback({[this]
		                             {
			                             dx_on_tick();
		                             },
		                             -5});

		g_renderer->add_wndproc_callback(
		    [this](HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
		    {
			    wndproc(hwnd, msg, wparam, lparam);
		    });

		g_renderer->add_init_callback(
		    [this]()
		    {
			    dx_init();
			    //g_renderer->rescale(g_gui->scale);
		    });

		g_gui = this;
	}

	gui::~gui()
	{
		g_gui = nullptr;
	}

	bool gui::is_open()
	{
		return m_is_open;
	}

	void gui::toggle(bool toggle)
	{
		m_is_open = toggle;

		toggle_mouse();
	}

	void gui::dx_init()
	{
		static auto bgColor     = ImVec4(0.09f, 0.094f, 0.129f, .9f);
		static auto primary     = ImVec4(0.172f, 0.380f, 0.909f, 1.f);
		static auto secondary   = ImVec4(0.443f, 0.654f, 0.819f, 1.f);
		static auto whiteBroken = ImVec4(0.792f, 0.784f, 0.827f, 1.f);

		auto& style             = ImGui::GetStyle();
		style.WindowPadding     = ImVec2(15, 15);
		style.WindowRounding    = 10.f;
		style.WindowBorderSize  = 0.f;
		style.FramePadding      = ImVec2(5, 5);
		style.FrameRounding     = 4.0f;
		style.ItemSpacing       = ImVec2(12, 8);
		style.ItemInnerSpacing  = ImVec2(8, 6);
		style.IndentSpacing     = 25.0f;
		style.ScrollbarSize     = 15.0f;
		style.ScrollbarRounding = 9.0f;
		style.GrabMinSize       = 5.0f;
		style.GrabRounding      = 3.0f;
		style.ChildRounding     = 4.0f;

		auto& colors = style.Colors;
		//colors[ImGuiCol_Text]                 = ImGui::ColorConvertU32ToFloat4(g_gui->text_color);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		//colors[ImGuiCol_WindowBg]             = ImGui::ColorConvertU32ToFloat4(g_gui->background_color);
		//colors[ImGuiCol_ChildBg]              = ImGui::ColorConvertU32ToFloat4(g_gui->background_color);
		colors[ImGuiCol_PopupBg]              = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		colors[ImGuiCol_Border]               = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
		colors[ImGuiCol_BorderShadow]         = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
		colors[ImGuiCol_FrameBg]              = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_FrameBgHovered]       = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		colors[ImGuiCol_FrameBgActive]        = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_TitleBg]              = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed]     = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
		colors[ImGuiCol_TitleBgActive]        = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
		colors[ImGuiCol_MenuBarBg]            = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_ScrollbarBg]          = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
		colors[ImGuiCol_ScrollbarGrab]        = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive]  = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_CheckMark]            = ImVec4(1.00f, 0.98f, 0.95f, 0.61f);
		colors[ImGuiCol_SliderGrab]           = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
		colors[ImGuiCol_SliderGrabActive]     = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_Button]               = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		colors[ImGuiCol_ButtonHovered]        = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
		colors[ImGuiCol_ButtonActive]         = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_Header]               = ImVec4(0.30f, 0.29f, 0.32f, 1.00f);
		colors[ImGuiCol_HeaderHovered]        = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_HeaderActive]         = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_ResizeGrip]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_ResizeGripHovered]    = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
		colors[ImGuiCol_ResizeGripActive]     = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
		colors[ImGuiCol_PlotLines]            = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		colors[ImGuiCol_PlotLinesHovered]     = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogram]        = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg]       = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);

		save_default_style();
	}

	static void SetPlayerPosition(SDK::ABP_Character_C* Pawn, SDK::FVector& new_position)
	{
		SDK::FRotator unused{};
		SDK::FHitResult unused2{};
		Pawn->SetActorLocationAndRotation_UpdateTarget_(new_position, unused, false, true, &unused2);
	}

	static void SetPlayerPosition(SDK::ABP_Character_C* Pawn, SDK::FVector3f& new_position)
	{
		SDK::FVector pos{new_position.X, new_position.Y, new_position.Z};
		SetPlayerPosition(Pawn, pos);
	}

	template<typename T>
	static void save_to_json_file(const std::filesystem::path& positions_file_path, nlohmann::json& json, T func)
	{
		std::ofstream file(positions_file_path);
		if (file.is_open())
		{
			file << json.dump(4);

			func();
		}
	}

	static SDK::FVector RotateCorner(SDK::FVector origin, SDK::FVector corner, float theta)
	{
		float x = corner.X - origin.X;
		float y = corner.Y - origin.Y;

		return {origin.X + (x * cos(theta) - y * sin(theta)), origin.Y + (x * sin(theta) + y * cos(theta)), corner.Z};
	}

	constexpr float DegreesToRadians(float degrees)
	{
		return degrees * (M_PI / 180.0f);
	}

	bool is_player_inside_sphere(const SDK::FVector& center, const SDK::FVector& player, double radius)
	{
		// Calculate the squared distance between the center and the player
		double distanceSquared =
		    std::pow(player.X - center.X, 2) + std::pow(player.Y - center.Y, 2) + std::pow(player.Z - center.Z, 2);

		// Calculate the squared radius
		double radiusSquared = std::pow(radius, 2);

		// Check if the squared distance is less than or equal to the squared radius
		return distanceSquared <= radiusSquared;
	}

	void draw_sphere(SDK::APlayerController* playerController, SDK::FVector world_coords, int32_t segment_count, float radius, ImU32 color)
	{
		auto draw_list = ImGui::GetBackgroundDrawList();

		// Calculate the step size for both theta and phi
		float theta_step = 2.0f * M_PI / segment_count;
		float phi_step   = M_PI / segment_count;

		SDK::FVector camera_location;
		SDK::FRotator camera_rotation;
		playerController->GetPlayerViewPoint(&camera_location, &camera_rotation);
		auto world = SDK::UWorld::GetWorld();

		if (is_player_inside_sphere(world_coords, g_pawn->GetTransform().Translation, radius))
		{
			draw_list->AddText(ImVec2(ImGui::GetIO().DisplaySize.x / 2.0f, ImGui::GetIO().DisplaySize.y * 0.075f), IM_COL32(0, 255, 0, 255), "Is Inside Sphere");
		}
		else
		{
			draw_list->AddText(ImVec2(ImGui::GetIO().DisplaySize.x / 2.0f, ImGui::GetIO().DisplaySize.y * 0.075f), IM_COL32(255, 0, 0, 255), "Is Outside Sphere");
		}

		for (int i = 0; i < segment_count; ++i)
		{
			for (int j = 0; j < segment_count; ++j)
			{
				// Calculate theta and phi values
				float theta = i * theta_step;
				float phi   = j * phi_step;

				// Compute the world coordinates for the current point
				SDK::FVector world_point(world_coords.X + radius * sinf(phi) * cosf(theta),
				                         world_coords.Y + radius * sinf(phi) * sinf(theta),
				                         world_coords.Z + radius * cosf(phi));

				SDK::FHitResult raycast_result;
				// clang-format off
				if (SDK::UKismetSystemLibrary::LineTraceSingle(world,
					camera_location, world_point,
					SDK::ETraceTypeQuery::TraceTypeQuery_MAX, true, {}, SDK::EDrawDebugTrace::None, &raycast_result, false, {}, {}, 0))
				{
					continue;
				}
				// clang-format on

				// Project the world coordinates to screen space
				SDK::FVector2D screen_point;
				if (playerController->ProjectWorldLocationToScreen(world_point, &screen_point, true))
				{
					// Draw a point at the projected screen coordinates
					draw_list->AddCircleFilled(ImVec2((float)screen_point.X, (float)screen_point.Y), 3.5f, color);
				}
			}
		}
	}

	void DrawBoundingRect(SDK::APlayerController* playerController, SDK::AActor* actor)
	{
		SDK::FVector origin, extent;
		actor->GetActorBounds(true, &origin, &extent, true);
		const auto rotation = actor->K2_GetActorRotation();
		float yaw           = DegreesToRadians(rotation.Yaw);

		// Define corners of the bounding box
		SDK::FVector t1 = {origin.X - extent.X, origin.Y - extent.Y, origin.Z + extent.Z};
		SDK::FVector t2 = {origin.X + extent.X, origin.Y - extent.Y, origin.Z + extent.Z};
		SDK::FVector t3 = {origin.X + extent.X, origin.Y + extent.Y, origin.Z + extent.Z};
		SDK::FVector t4 = {origin.X - extent.X, origin.Y + extent.Y, origin.Z + extent.Z};

		SDK::FVector b1 = {origin.X - extent.X, origin.Y - extent.Y, origin.Z - extent.Z};
		SDK::FVector b2 = {origin.X + extent.X, origin.Y - extent.Y, origin.Z - extent.Z};
		SDK::FVector b3 = {origin.X + extent.X, origin.Y + extent.Y, origin.Z - extent.Z};
		SDK::FVector b4 = {origin.X - extent.X, origin.Y + extent.Y, origin.Z - extent.Z};

		// Rotate corners around the origin
		t1 = RotateCorner(origin, t1, yaw);
		t2 = RotateCorner(origin, t2, yaw);
		t3 = RotateCorner(origin, t3, yaw);
		t4 = RotateCorner(origin, t4, yaw);

		b1 = RotateCorner(origin, b1, yaw);
		b2 = RotateCorner(origin, b2, yaw);
		b3 = RotateCorner(origin, b3, yaw);
		b4 = RotateCorner(origin, b4, yaw);

		// Project corners to screen space
		SDK::FVector2D ts1, ts2, ts3, ts4;
		SDK::FVector2D bs1, bs2, bs3, bs4;

		if (!playerController->ProjectWorldLocationToScreen(t1, &ts1, true) || !playerController->ProjectWorldLocationToScreen(t2, &ts2, true)
		    || !playerController->ProjectWorldLocationToScreen(t3, &ts3, true) || !playerController->ProjectWorldLocationToScreen(t4, &ts4, true)
		    || !playerController->ProjectWorldLocationToScreen(b1, &bs1, true) || !playerController->ProjectWorldLocationToScreen(b2, &bs2, true)
		    || !playerController->ProjectWorldLocationToScreen(b3, &bs3, true) || !playerController->ProjectWorldLocationToScreen(b4, &bs4, true))
		{
			return;
		}

		auto drawList = ImGui::GetBackgroundDrawList();

		const auto color = IM_COL32(255, 255, 255, 255);

		auto draw_line = [](ImDrawList* drawList, const SDK::FVector2D& a, const SDK::FVector2D& b, const ImU32 color)
		{
			drawList->AddLine({(float)a.X, (float)a.Y}, {(float)b.X, (float)b.Y}, color, 2);
		};

		draw_line(drawList, ts1, ts2, color);
		draw_line(drawList, ts2, ts3, color);
		draw_line(drawList, ts3, ts4, color);
		draw_line(drawList, ts4, ts1, color);

		draw_line(drawList, bs1, bs2, color);
		draw_line(drawList, bs2, bs3, color);
		draw_line(drawList, bs3, bs4, color);
		draw_line(drawList, bs4, bs1, color);

		draw_line(drawList, ts1, bs1, color);
		draw_line(drawList, ts2, bs2, color);
		draw_line(drawList, ts3, bs3, color);
		draw_line(drawList, ts4, bs4, color);
	}

	void gui::dx_on_tick()
	{
		if (!g_lua_manager)
		{
			return;
		}

		g_lua_manager->process_file_watcher_queue();

		push_theme_colors();

		g_lua_manager->always_draw_independent_gui();

		pId = GetCurrentProcessId();


		if (!m_onboarded->ref<bool>())
		{
			static bool onboarding_open = false;
			if (!onboarding_open)
			{
				toggle(true);
				ImGui::OpenPopup("Unchained Mod - By Nallraen (Base by XiaoXiao)");
				onboarding_open = true;
			}

			const auto window_size = ImVec2{600, 400};
			ImGui::SetNextWindowSize(window_size, ImGuiCond_Always);

			RECT rect;
			ImVec2 window_position = ImVec2(640, 360);
			if (GetWindowRect(g_renderer->m_window_handle, &rect))
			{
				float width     = rect.right - rect.left;
				float height    = rect.bottom - rect.top;
				window_position = ImVec2{(width - window_size.x) / 2, (height - window_size.y) / 2};
			}
			ImGui::SetNextWindowPos(window_position, ImGuiCond_Always);

			if (ImGui::BeginPopupModal("Unchained Mod - By Nallraen (Base by XiaoXiao)"))
			{
				if (ImGui::Hotkey("Open GUI Keybind", g_gui_toggle))
				{
					g_editing_gui_keybind = true;
				}

				ImGui::TextWrapped("This window is here so that you can change the keyboard shortcut to open the mod's "
				                   "graphical interface.");
				ImGui::TextWrapped("Once you are done please press the Close button so that you can move or interact "
				                   "with the game window again.");

				if (ImGui::Button("Close"))
				{
					m_onboarded->ref<bool>() = true;
					save_pref();
					ImGui::CloseCurrentPopup();
				}

				ImGui::EndPopup();
			}
		}

		g_pawn     = nullptr;
		g_pawn2    = nullptr;
		g_pawn3    = nullptr;
		g_pawn4    = nullptr;
		g_customgi = nullptr;

		SDK::UWorld* World = SDK::UWorld::GetWorld();
		if (World)
		{
			SDK::ULevel* Level = World->PersistentLevel;
			if (Level)
			{
				SDK::TArray<SDK::AActor*>& volatile Actors = Level->Actors;

				auto gameState = World->GameState; // 0x158
				if (!gameState)
				{
					return;
				}
				auto playerList = gameState->PlayerArray; // 0x300
				if (!playerList || playerList.Num() <= 0)
				{
					return;
				}

				auto player = playerList[0];
				if (!player)
				{
					return;
				}

				/*auto pPawn = player->PawnPrivate;
				if (pPawn)
				{
					return;
				}*/

				g_pawn = (decltype(g_pawn))player->PawnPrivate;
				if (!g_pawn)
				{
					// LOG(DEBUG) << "Error on getting player pawn!";
					return;
				}

				if (!playerList || playerList.Num() > 1) // Check if there is more than 1 player in game
				{
					if (playerList.Num() >= 2)
					{
						auto player2 = playerList[1];
						g_pawn2      = (decltype(g_pawn2))player2->PawnPrivate;
						if (playerList.Num() >= 3)
						{
							auto player3 = playerList[2];
							g_pawn3      = (decltype(g_pawn3))player3->PawnPrivate;
							if (playerList.Num() == 4)
							{
								auto player4 = playerList[3];
								g_pawn4      = (decltype(g_pawn4))player3->PawnPrivate;
							}
						}
					}
					else
					{
						return;
					}
				}

				auto gameInstance = World->OwningGameInstance; // 0x1B8
				if (!gameInstance)
				{
					return;
				}
				auto localPlayers = gameInstance->LocalPlayers; // 0x38
				if (!localPlayers || localPlayers.Num() <= 0)
				{
					return;
				}
				auto localPlayer = localPlayers[0]; // deref pointer
				if (!localPlayer)
				{
					return;
				}
				auto playerController = localPlayer->PlayerController; // 0x30
				if (!playerController)
				{
					return;
				}

				if (g_chained_together_perfect_bunny_state)
				{
					g_pawn->Jump_Input();

					ImDrawList* draw_list              = ImGui::GetForegroundDrawList();
					static int32_t perfect_bunny_color = 0;
					perfect_bunny_color++;
					perfect_bunny_color = perfect_bunny_color % 255;
					draw_list->AddText(ImVec2(ImGui::GetIO().DisplaySize.x / 2.0f, ImGui::GetIO().DisplaySize.y * 0.075f), IM_COL32(perfect_bunny_color, 255, 255, 255), "Perfect Bunny");
				}


				try
				{
					for (int i = 0; i < SDK::UObject::GObjects->Num(); i++)
					{
						SDK::UObject* Obj = SDK::UObject::GObjects->GetByIndex(i);

						if (!Obj)
						{
							continue;
						}

						if (Obj->IsA(SDK::IBPI_Gamestate_C::StaticClass()))
						{
							bpiGameState = (decltype(bpiGameState))Obj;
							break;
						}
					}
				}
				catch (const std::exception&)
				{
				}

				try
				{
					for (int i = 0; i < SDK::UObject::GObjects->Num(); i++)
					{
						SDK::UObject* Obj = SDK::UObject::GObjects->GetByIndex(i);

						if (!Obj)
						{
							continue;
						}

						if (Obj->IsA(SDK::AGS_Game_C::StaticClass()))
						{
							gameBaseData = (decltype(gameBaseData))Obj;
							break;
						}
					}
				}
				catch (const std::exception&)
				{
				}

				

				try
				{
					for (int i = 0; i < SDK::UObject::GObjects->Num(); i++)
					{
						SDK::UObject* Obj = SDK::UObject::GObjects->GetByIndex(i);

						if (!Obj)
						{
							continue;
						}

						if (Obj->IsA(SDK::UCustomGI_C::StaticClass()))
						{
							g_customgi = (decltype(g_customgi))Obj;
							break;
						}
					}
				}
				catch (const std::exception&)
				{
				}

				try
				{
					for (SDK::AActor* Actor : Actors)
					{
						if (!Actor)
						{
							continue;
						}

						if (Actor->IsA(SDK::AHUD::StaticClass()))
						{
							g_ahud = (decltype(g_ahud))Actor;
							break;
						}
					}
				}
				catch (const std::exception&)
				{
				}

				try
				{
					if (g_draw_hitbox_proximity_based)
					{
						auto my_pawn_location = g_pawn->K2_GetActorLocation();

						size_t i = 0;
						for (SDK::AActor* Actor : Actors)
						{
							i++;
							if (!Actor)
							{
								continue;
							}

							auto pos = Actor->K2_GetActorLocation();

							if ((my_pawn_location.GetDistanceTo(pos)) > 500)
							{
								//yep.shouldDraw = false;
								continue;
							}

							//auto& yep = g_shouldDraw[i];
							//if (yep.shouldDraw)
							{
								DrawBoundingRect(playerController, Actor);
							}
						}
					}
				}
				catch (const std::exception&)
				{
				}

				if (g_pawn && g_draw_g_pawn_hitbox)
				{
					//DrawBoundingRect(playerController, g_pawn);
					draw_sphere(playerController,
					            g_draw_pawn_sphere_position ? *g_draw_pawn_sphere_position : g_pawn->GetTransform().Translation,
					            g_draw_g_pawn_sphere_segment_count,
					            g_draw_g_pawn_sphere_radius_hitbox,
					            g_draw_pawn_sphere_hitbox_color_final);
				}
			}
		}

		if (m_is_open)
		{
			if (ImGui::BeginMainMenuBar())
			{
				ImGui::SetNextWindowSize({400.0f, 0});
				if (ImGui::BeginMenu("GUI"))
				{
					if (ImGui::Checkbox("Open GUI At Startup", &m_is_open_at_startup->ref<bool>()))
					{
						save_pref();
					}

					if (ImGui::Hotkey("Open GUI Keybind", g_gui_toggle))
					{
						g_editing_gui_keybind = true;
					}

					ImGui::EndMenu();
				}

				if (ImGui::BeginMenu("Mods"))
				{
					g_lua_manager->draw_menu_bar_callbacks();

					ImGui::EndMenu();
				}

				if (ImGui::BeginMenu("Windows"))
				{
					for (auto& [mod_guid, windows] : lua::window::is_open)
					{
						if (!g_lua_manager->module_exists(mod_guid))
						{
							continue;
						}

						if (ImGui::BeginMenu(mod_guid.c_str()))
						{
							if (ImGui::Button("Open All"))
							{
								for (auto& [window_name, is_window_open] : windows)
								{
									is_window_open = true;
								}
								lua::window::serialize();
							}
							ImGui::SameLine();
							if (ImGui::Button("Close All"))
							{
								for (auto& [window_name, is_window_open] : windows)
								{
									is_window_open = false;
								}
								lua::window::serialize();
							}

							for (auto& [window_name, is_window_open] : windows)
							{
								if (ImGui::Checkbox(window_name.c_str(), &is_window_open))
								{
									lua::window::serialize();
								}
							}

							ImGui::EndMenu();
						}
					}

					ImGui::EndMenu();
				}

				ImGui::EndMainMenuBar();
			}

			ImGui::SetMouseCursor(g_gui->m_mouse_cursor);

			g_lua_manager->draw_independent_gui();

			/*if (ImGui::Button("Crash it"))
			{
				*(int*)0xDE'AD = 1;
			}*/

			if (1)
			{
				ImGui::SetNextWindowSize({483, 544}, ImGuiCond_FirstUseEver);
				if (ImGui::Begin("Unchained Mod - By Nallraen (Base by XiaoXiao)"))
				{
					if (World)
					{
						/* You might need to loop all levels in UWorld::Levels */
						SDK::ULevel* Level = World->PersistentLevel;
						if (Level)
						{
							SDK::TArray<SDK::AActor*>& volatile Actors = Level->Actors;

							try
							{
								// Fly Modes Header
								try
								{
									if (ImGui::CollapsingHeader("Fly Modes"))
									{
										if (ImGui::Checkbox("Toggle: All Players", &g_chained_together_fly_mode_state_all))
										{
											// Manually switch g_chained_together_fly_mode_state for all players
											g_chained_together_fly_mode_state_p1 = !g_chained_together_fly_mode_state_p1;
											g_chained_together_fly_mode_state_p2 = !g_chained_together_fly_mode_state_p2;
											g_chained_together_fly_mode_state_p3 = !g_chained_together_fly_mode_state_p3;
											g_chained_together_fly_mode_state_p4 = !g_chained_together_fly_mode_state_p4;


											if (g_pawn2)
											{
												g_pawn2->SetFlyMode(g_chained_together_fly_mode_state_p2);
											}
											if (g_pawn3)
											{
												g_pawn3->SetFlyMode(g_chained_together_fly_mode_state_p3);
											}
											if (g_pawn4)
											{
												g_pawn4->SetFlyMode(g_chained_together_fly_mode_state_p4);
											}
											g_pawn->SetFlyMode(g_chained_together_fly_mode_state_p1);
											//Pawn->SetFlyMode(g_chained_together_fly_mode_state);
										}

										if (ImGui::Checkbox("Toggle: Player 1", &g_chained_together_fly_mode_state_p1))
										{
											g_pawn->SetFlyMode(g_chained_together_fly_mode_state_p1);
										}

										// Check if there is a Player2
										bool disableCheckbox_p2 = (g_pawn2 == nullptr);
										ImGui::BeginDisabled(disableCheckbox_p2);
										if (ImGui::Checkbox("Toggle: Player 2", &g_chained_together_fly_mode_state_p2))
										{
											if (g_pawn2)
											{
												g_pawn2->SetFlyMode(g_chained_together_fly_mode_state_p2);
											}
										}
										ImGui::EndDisabled();
										// End Check Player2

										// Check if there is a Player3
										bool disableCheckbox_p3 = (g_pawn3 == nullptr);
										ImGui::BeginDisabled(disableCheckbox_p3);
										if (ImGui::Checkbox("Toggle: Player 3", &g_chained_together_fly_mode_state_p3))
										{
											if (g_pawn3)
											{
												g_pawn3->SetFlyMode(g_chained_together_fly_mode_state_p3);
											}
										}
										ImGui::EndDisabled();
										// End Check Player3

										// Check if there is a Player4
										bool disableCheckbox_p4 = (g_pawn4 == nullptr);
										ImGui::BeginDisabled(disableCheckbox_p4);
										if (ImGui::Checkbox("Toggle: Player 4", &g_chained_together_fly_mode_state_p4))
										{
											if (g_pawn4)
											{
												g_pawn4->SetFlyMode(g_chained_together_fly_mode_state_p4);
											}
										}
										ImGui::EndDisabled();
										// End Check Player4
									}
								}
								catch (const std::exception&)
								{}


								for (SDK::AActor* Actor : Actors)
								{
									if (!Actor || !Actor->IsA(SDK::ABP_Character_C::StaticClass()))
									{
										continue;
									}

									ImGui::PushID(Actor);

									SDK::ABP_Character_C* Pawn = static_cast<SDK::ABP_Character_C*>(Actor);

									auto current_transform = Pawn->GetTransform();
									auto& current_pos      = current_transform.Translation;

									static auto positions_file_path =
									    g_file_manager.get_project_file("./positions.json").get_path();

									if (g_customgi)
									{
										/*ImGui::Checkbox("TrueChainVisible", &g_customgi->MakeTrueChainVisible);
										ImGui::Checkbox("DevMode", &g_customgi->DevMode);
										ImGui::Checkbox("WingsSelected", &g_customgi->WingsSelected);
										ImGui::Text("SelectedGameMode %d", g_customgi->SelectedGameMode);*/

										if (ImGui::Button("Unlock Wings"))
										{
											try
											{
												for (int i = 0; i < SDK::UObject::GObjects->Num(); i++)
												{
													SDK::UObject* Obj = SDK::UObject::GObjects->GetByIndex(i);

													if (!Obj)
													{
														continue;
													}

													if (Obj->IsA(SDK::UCustomGI_C::StaticClass()))
													{
														SDK::UCustomGI_C* customgi = (decltype(customgi))Obj;

														for (size_t j = 0; j < 10; j++)
														{
															customgi->SetCollectedWing(j);
														}
													}
												}
											}
											catch (const std::exception&)
											{
											}
										}
									}

									// Not really useful, seems like none of the commands do anything
									/* static bool enable_console_once = true;
									static bool is_console_enabled  = false;
									if (ImGui::Checkbox("Enable Unreal Engine Debug Console", &is_console_enabled))
									{
										if (enable_console_once)
										{
											enable_console_once = false;

											SDK::UEngine* Engine = SDK::UEngine::GetEngine();
											SDK::UObject* ConsoleObject =
											    SDK::UGameplayStatics::SpawnObject(Engine->ConsoleClass, Engine->GameViewport);
											Engine->GameViewport->ViewportConsole = static_cast<SDK::UConsole*>(ConsoleObject);
										}

										is_console_enabled = true;
									}*/



									// Timer related part
									ImGui::SeparatorText("Timer Options");

									uint32_t newTimer = 0;

									/*			
									Ne fonctionne pas pour l'instant. Raison -> Inconnue... Probl�le de InputScalar.

									ImGui::Text("Enter a value between 0 and 4 294 967 295");
									ImGui::Text("Over 2 147 483 648 your timer will be negative!");
									ImGui::InputScalar("Timer Value", ImGuiDataType_U32, &newTimer, NULL, NULL, "%u", ImGuiInputTextFlags_CharsDecimal);

									// Clamp the value within the 4 Bytes range
									if (newTimer < 0)
									{
										newTimer = 0;
									}
									if (newTimer > UINT32_MAX)
									{
										newTimer = UINT32_MAX;
									}

									if (ImGui::Button("Set Timer!"))
									{
										try
										{
											writeDwordAddress(baseAddress, timerOffsets, newTimer);
										}
										catch (const std::exception& e)
										{
											LOG(ERROR) << e.what();
										}
									}
									*/

									ImGui::BeginDisabled(freezeAtNeg);
									if (ImGui::Checkbox("Freeze Timer at 0s", &freezeAt0))
									{
										if (freezeAt0)
										{
											running = true;
											freezeThread = std::thread(freezeTimer, baseAddress, timerOffsets, 0, std::ref(running));
										}
										else
										{
											running = false;
											if (freezeThread.joinable())
											{
												freezeThread.join();
											}
										}
									}
									ImGui::EndDisabled();

									ImGui::BeginDisabled(freezeAt0);
									if (ImGui::Checkbox("Freeze Timer at a Negative Time", &freezeAtNeg))
									{
										if (freezeAtNeg)
										{
											running = true;
											freezeThread = std::thread(freezeTimer, baseAddress, timerOffsets, -4814017, std::ref(running));
										}
										else
										{
											running = false;
											if (freezeThread.joinable())
											{
												freezeThread.join();
											}
										}
									}
									ImGui::EndDisabled();
									
									if (ImGui::Button("1s Timer"))
									{
										try
										{
											newTimer = 1;

											writeDwordAddress(baseAddress, timerOffsets, newTimer);
										}
										catch (const std::exception& e)
										{
											LOG(ERROR) << e.what();
										}
									}
									
									if (ImGui::Button("Min Timer"))
									{
										try
										{
											newTimer = 2'147'483'648;

											writeDwordAddress(baseAddress, timerOffsets, newTimer);
										}
										catch (const std::exception& e)
										{
											LOG(ERROR) << e.what();
										}
									}

									if (ImGui::Button("Reset Timer"))
									{
										try
										{
											newTimer = 0;

											writeDwordAddress(baseAddress, timerOffsets, newTimer);
										}
										catch (const std::exception& e)
										{
											LOG(ERROR) << e.what();
										}
									}


									ImGui::Separator();

									// Show the player's current position
									ImGui::Text("Player Position: X: %.2f | Y: %.2f | Z: %.2f",
									            current_pos.X,
									            current_pos.Y,
									            current_pos.Z);

									ImGui::SeparatorText("Custom Position");
									static SDK::FVector3f new_set_position{current_pos.X, current_pos.Y, current_pos.Z};
									ImGui::InputFloat("X", &new_set_position.X);
									ImGui::InputFloat("Y", &new_set_position.Y);
									ImGui::InputFloat("Z", &new_set_position.Z);

									static nlohmann::json json;
									static std::vector<std::string> positionNames;

									if (ImGui::Button("Teleport To Custom Position"))
									{
										SetPlayerPosition(Pawn, new_set_position);
										if (g_pawn2)
										{
											SetPlayerPosition(g_pawn2, new_set_position);
										}
										if (g_pawn3)
										{
											SetPlayerPosition(g_pawn3, new_set_position);
										}
										if (g_pawn4)
										{
											SetPlayerPosition(g_pawn4, new_set_position);
										}
									}

									ImGui::SeparatorText("JSON File");

									// Load JSON file and display named positions
									static std::string selectedPosition;

									static bool load_once = true;
									if (ImGui::Button("Refresh Positions From JSON File") || load_once)
									{
										load_once = false;
										std::ifstream file(positions_file_path);
										if (file.is_open())
										{
											try
											{
												file >> json;
												positionNames.clear();
												for (auto& el : json["positions"].items())
												{
													positionNames.push_back(el.key());
												}
												std::sort(positionNames.begin(), positionNames.end());
											}
											catch (const std::exception& e)
											{
												LOG(ERROR) << e.what();
											}
										}
									}

									static int currentIndex = 0;
									static bool once        = true;
									if (once && positionNames.size())
									{
										once             = false;
										selectedPosition = positionNames[0];
									}

									if (ImGui::Combo(
									        "Selected Position",
									        &currentIndex,
									        [](void* vec, int idx, const char** out_text)
									        {
										        std::vector<std::string>* vector = reinterpret_cast<std::vector<std::string>*>(vec);
										        if (idx < 0 || idx >= vector->size())
										        {
											        return false;
										        }
										        *out_text = vector->at(idx).c_str();
										        return true;
									        },
									        reinterpret_cast<void*>(&positionNames),
									        positionNames.size()))
									{
										selectedPosition = positionNames[currentIndex];
									}

									if (selectedPosition.size() && ImGui::Button("Teleport To Selected Position"))
									{
										try
										{
											current_pos.X = json["positions"][selectedPosition]["X"];
											current_pos.Y = json["positions"][selectedPosition]["Y"];
											current_pos.Z = json["positions"][selectedPosition]["Z"];
										}
										catch (const std::exception& e)
										{
											LOG(ERROR) << e.what();
										}

										SetPlayerPosition(Pawn, current_pos);
										if (g_pawn2)
										{
											SetPlayerPosition(g_pawn2, current_pos);
										}
										if (g_pawn3)
										{
											SetPlayerPosition(g_pawn3, current_pos);
										}
										if (g_pawn4)
										{
											SetPlayerPosition(g_pawn4, current_pos);
										}
									}

									if (selectedPosition.size() && ImGui::Button("Delete Selected Position From File"))
									{
										try
										{
											json["positions"].erase(selectedPosition);

											save_to_json_file(positions_file_path,
											                  json,
											                  [&]()
											                  {
												                  std::erase_if(positionNames,
												                                [&](auto& a)
												                                {
													                                return a == selectedPosition;
												                                });
												                  std::sort(positionNames.begin(), positionNames.end());
											                  });
										}
										catch (const std::exception& e)
										{
											LOG(ERROR) << e.what();
										}

										SetPlayerPosition(Pawn, current_pos);
									}

									ImGui::Separator();

									static char positionName[128] = "";
									ImGui::InputText("Position Name", positionName, IM_ARRAYSIZE(positionName));
									if (strlen(positionName) > 0)
									{
										if (ImGui::Button("Save Current Position To JSON File"))
										{
											try
											{
												json["positions"][positionName] = {{"X", current_pos.X},
												                                   {"Y", current_pos.Y},
												                                   {"Z", current_pos.Z}};

												save_to_json_file(positions_file_path,
												                  json,
												                  [&]()
												                  {
													                  positionNames.push_back(positionName);
													                  std::sort(positionNames.begin(), positionNames.end());
												                  });
											}
											catch (const std::exception& e)
											{
												LOG(ERROR) << e.what();
											}
										}
									}
									else
									{
										ImGui::Text("Please enter a valid position name for saving to JSON File");
									}

									// ImGui::SeparatorText("Keybinds");

									/*
									ImGui::Hotkey("Save Current Position", g_chained_together_save_current_position);

									ImGui::Hotkey("Teleport To Latest Saved Position", g_chained_together_tp_to_latest_saved_position, {600, 0});

									ImGui::Hotkey("Fly Mode##2", g_chained_together_fly_mode);

									ImGui::Hotkey("Perfect Bunny Hop##2", g_chained_together_perfect_bunny_hotkey);
									*/

									ImGui::PopID();
								}
							}
							catch (const std::exception& e)
							{
							}

							/*
							try
							{
								if (g_pawn)
								{
									if (ImGui::CollapsingHeader("Hitbox Debug"))
									{
										ImGui::Checkbox("Proximity Based", &g_draw_hitbox_proximity_based);
										ImGui::Checkbox("Draw Self Hitbox", &g_draw_g_pawn_hitbox);
										ImGui::SliderFloat("Draw Self - Sphere Radius", &g_draw_g_pawn_sphere_radius_hitbox, 1, 5000);
										ImGui::InputFloat("Draw Self - Sphere Radius##2", &g_draw_g_pawn_sphere_radius_hitbox);
										ImGui::SliderInt("Draw Self - Sphere Segment Count", &g_draw_g_pawn_sphere_segment_count, 1, 100);
										ImGui::InputInt("Draw Self - Sphere Segment Count##2", &g_draw_g_pawn_sphere_segment_count);
										if (ImGui::ColorEdit4("Draw Self - Sphere Color",
										                      &g_draw_pawn_sphere_hitbox_color_edit.x))
										{
											g_draw_pawn_sphere_hitbox_color_final = ImGui::ColorConvertFloat4ToU32(g_draw_pawn_sphere_hitbox_color_edit);
										}
										if (ImGui::Button("Draw Self - Sphere Place at current position"))
										{
											g_draw_pawn_sphere_position = g_pawn->GetTransform().Translation;
										}
										if (ImGui::Button("Draw Self - Sphere Place at current position DELETE"))
										{
											g_draw_pawn_sphere_position = {};
										}

										auto my_pawn_location = g_pawn->K2_GetActorLocation();
										size_t i              = 0;
										for (SDK::AActor* actor : Actors)
										{
											i++;
											if (!actor)
											{
												continue;
											}

											auto pos = actor->K2_GetActorLocation();

											auto& yep = g_shouldDraw[i];

											if ((my_pawn_location.GetDistanceTo(pos)) > 500)
											{
												//yep.shouldDraw = false;
												continue;
											}
											//yep.shouldDraw = true;

											ImGui::PushID(actor);

											ImGui::Text("[%d] %s (%.2f | Y: %.2f | Z: %.2f)", i, actor->Name.ToString().c_str(), pos.X, pos.Y, pos.Z);
											//if (ImGui::Checkbox("Draw Box ", &yep.shouldDraw))
											//{
											//}
											if (ImGui::Button("Teleport To"))
											{
												SetPlayerPosition(g_pawn, pos);
												if (g_pawn2)
												{
													SetPlayerPosition(g_pawn2, pos);
												}
												if (g_pawn3)
												{
													SetPlayerPosition(g_pawn3, pos);
												}
												if (g_pawn4)
												{
													SetPlayerPosition(g_pawn4, pos);
												}
											}
											ImGui::PopID();
										}
									}

									ImGui::Checkbox("[VERY UNSTABLE / CRASH ON EXIT] Perfect Bunny Hop", &g_chained_together_perfect_bunny_state);
								}
							}
							catch (const std::exception&)
							{
							}
							*/
						}
					}
				}
				ImGui::End();
			}
		}

		pop_theme_colors();
	}

	void gui::save_default_style()
	{
		memcpy(&m_default_config, &ImGui::GetStyle(), sizeof(ImGuiStyle));
	}

	void gui::restore_default_style()
	{
		memcpy(&ImGui::GetStyle(), &m_default_config, sizeof(ImGuiStyle));
	}

	void gui::push_theme_colors()
	{
		//auto button_color = ImGui::ColorConvertU32ToFloat4(g_gui->button_color);
		auto button_color = ImGui::ColorConvertU32ToFloat4(2'947'901'213);
		auto button_active_color =
		    ImVec4(button_color.x + 0.33f, button_color.y + 0.33f, button_color.z + 0.33f, button_color.w);
		auto button_hovered_color =
		    ImVec4(button_color.x + 0.15f, button_color.y + 0.15f, button_color.z + 0.15f, button_color.w);
		auto frame_color = ImGui::ColorConvertU32ToFloat4(2'942'518'340);
		auto frame_hovered_color =
		    ImVec4(frame_color.x + 0.14f, frame_color.y + 0.14f, frame_color.z + 0.14f, button_color.w);
		auto frame_active_color =
		    ImVec4(frame_color.x + 0.30f, frame_color.y + 0.30f, frame_color.z + 0.30f, button_color.w);

		//ImGui::PushStyleColor(ImGuiCol_WindowBg, ImGui::ColorConvertU32ToFloat4(g_gui->background_color));
		//ImGui::PushStyleColor(ImGuiCol_Text, ImGui::ColorConvertU32ToFloat4(g_gui->text_color));
		ImGui::PushStyleColor(ImGuiCol_Button, button_color);
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, button_hovered_color);
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, button_active_color);
		ImGui::PushStyleColor(ImGuiCol_FrameBg, frame_color);
		ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, frame_hovered_color);
		ImGui::PushStyleColor(ImGuiCol_FrameBgActive, frame_active_color);
	}

	void gui::pop_theme_colors()
	{
		//ImGui::PopStyleColor(8);
		ImGui::PopStyleColor(6);
	}

	static void hook_JumpDetection(SDK::ABP_Character_C* Context, void* TheStack, void* Result)
	{
		big::g_hooking->get_original<hook_JumpDetection>()(Context, TheStack, Result);

		if (Context->Grounded)
		{
			Context->Jump();
		}
	}

	void gui::wndproc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		if (msg == WM_KEYUP && wparam == g_gui_toggle.get_vk_value())
		{
			// Persist and restore the cursor position between menu instances.
			static POINT cursor_coords{};
			if (g_gui->m_is_open)
			{
				GetCursorPos(&cursor_coords);
			}
			else if (cursor_coords.x + cursor_coords.y != 0)
			{
				SetCursorPos(cursor_coords.x, cursor_coords.y);
			}

			toggle(g_editing_gui_keybind || !m_is_open);
			if (g_editing_gui_keybind)
			{
				g_editing_gui_keybind = false;
			}


			////////////////////////////////
			// DEBUG ZONE

			std::vector<uintptr_t> offsets = {0x06F65C48, 0x158, 0x320};

			int32_t value = readValueAddress(baseAddress, offsets);

			LOG(DEBUG) << "Timer is at: " << value;

			// END DEBUG ZONE
			///////////////////////////////////////



			LOG(DEBUG) << "Toggled Modding GUI to: " << (m_is_open ? "visible" : "hidden");
			//if (hModule == NULL)
			//{
			//	LOG(ERROR) << "Error getting module handle.";
			//}
			//else
			//{
			//	// The handle is actually the base address of the module
			//	LOG(DEBUG) << "Base address of the program: " << hModule;
			//}
			//LOG(DEBUG) << pId;
		}

		if (msg == WM_KEYUP && wparam == g_chained_together_save_current_position.get_vk_value() && g_pawn)
		{
			g_latest_saved_position = g_pawn->GetTransform().Translation;
		}

		if (msg == WM_KEYUP && wparam == g_chained_together_tp_to_latest_saved_position.get_vk_value() && g_pawn && g_latest_saved_position)
		{
			SetPlayerPosition(g_pawn, *g_latest_saved_position);
		}

		if (msg == WM_KEYUP && wparam == g_chained_together_fly_mode.get_vk_value() && g_pawn)
		{
			g_chained_together_fly_mode_state_p1 = !g_chained_together_fly_mode_state_p1;
			g_pawn->SetFlyMode(g_chained_together_fly_mode_state_p1);
		}

		if (msg == WM_KEYUP && wparam == g_chained_together_perfect_bunny_hotkey.get_vk_value() && g_pawn)
		{
			g_chained_together_perfect_bunny_state = !g_chained_together_perfect_bunny_state;
		}
	}

	// TODO: Cleanup all this
	using ClipCursor_t           = BOOL (*)(const RECT* lpRect);
	ClipCursor_t orig_ClipCursor = nullptr;

	static BOOL hook_ClipCursor(const RECT* lpRect)
	{
		if (!g_gui || !g_gui->is_open())
		{
			return orig_ClipCursor(lpRect);
		}

		return 1;
	}

	// TODO: Cleanup all this
	template<class F>
	bool EachImportFunction(HMODULE module, const char* dllname, const F& f)
	{
		if (module == 0)
		{
			return false;
		}

		size_t ImageBase             = (size_t)module;
		PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)ImageBase;
		if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
		{
			return false;
		}
		PIMAGE_NT_HEADERS pNTHeader = (PIMAGE_NT_HEADERS)(ImageBase + pDosHeader->e_lfanew);

		size_t RVAImports = pNTHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
		if (RVAImports == 0)
		{
			return false;
		}

		IMAGE_IMPORT_DESCRIPTOR* pImportDesc = (IMAGE_IMPORT_DESCRIPTOR*)(ImageBase + RVAImports);
		while (pImportDesc->Name != 0)
		{
			if (!dllname || stricmp((const char*)(ImageBase + pImportDesc->Name), dllname) == 0)
			{
				IMAGE_IMPORT_BY_NAME** func_names = (IMAGE_IMPORT_BY_NAME**)(ImageBase + pImportDesc->Characteristics);
				void** import_table               = (void**)(ImageBase + pImportDesc->FirstThunk);
				for (size_t i = 0;; ++i)
				{
					if ((size_t)func_names[i] == 0)
					{
						break;
					}
					const char* funcname = (const char*)(ImageBase + (size_t)func_names[i]->Name);
					f(funcname, import_table[i]);
				}
			}
			++pImportDesc;
		}
		return true;
	}

	// TODO: Cleanup all this
	template<class T>
	static void ForceWrite(T& dst, const T& src)
	{
		DWORD old_flag;
		::VirtualProtect(&dst, sizeof(T), PAGE_EXECUTE_READWRITE, &old_flag);
		dst = src;
		::VirtualProtect(&dst, sizeof(T), old_flag, &old_flag);
	}

	void gui::toggle_mouse()
	{
		auto& io = ImGui::GetIO();

		if (m_is_open)
		{
			io.MouseDrawCursor  = true;
			io.ConfigFlags     &= ~ImGuiConfigFlags_NoMouse;
			io.ConfigFlags     &= ~ImGuiConfigFlags_NoMouseCursorChange;

			// TODO: Cleanup all this
			static bool first_time = true;
			if (first_time)
			{
				first_time = false;

				if (GetModuleHandleA("user32.dll"))
				{
					orig_ClipCursor = &ClipCursor;

					EachImportFunction(::GetModuleHandleA(0),
					                   "user32.dll",
					                   [](const char* funcname, void*& func)
					                   {
						                   //if (strcmp(funcname, "SetCursorPos") == 0)
						                   if (strcmp(funcname, "ClipCursor") == 0)
						                   {
							                   ForceWrite<void*>(func, hook_ClipCursor);
						                   }
					                   });
				}
				else
				{
					LOG(ERROR) << "no user32 hook setcus";
				}
			}
		}
		else
		{
			io.MouseDrawCursor  = false;
			io.ConfigFlags     |= ImGuiConfigFlags_NoMouse;
			io.ConfigFlags     |= ImGuiConfigFlags_NoMouseCursorChange;
		}
	}

	void gui::init_pref()
	{
		try
		{
			const auto file_name = rom::g_project_name + '-' + rom::g_project_name + '-' + "GUI.cfg";
			m_file_path          = g_file_manager.get_project_folder("config").get_path() / file_name;
			if (std::filesystem::exists(m_file_path))
			{
				m_table = toml::parse_file(m_file_path.c_str());
			}

			auto init_node = [](toml::table& table, toml::node*& node, const char* node_name, bool default_value)
			{
				const auto entry_doesnt_exist = !table.contains(node_name);
				if (entry_doesnt_exist)
				{
					table.insert_or_assign(node_name, default_value);
				}

				node = table.get(node_name);
				if (node == nullptr)
				{
					LOG(ERROR) << "what";
				}

				if (node == nullptr || node->type() != toml::node_type::boolean)
				{
					LOG(WARNING) << "Invalid serialized data. Clearing " << node_name;

					table.insert_or_assign(node_name, default_value);
					node = table.get(node_name);
					if (node == nullptr)
					{
						LOG(ERROR) << "what2";
					}
				}
			};

			constexpr auto is_open_at_startup_name = "is_open_at_startup";
			init_node(m_table, m_is_open_at_startup, is_open_at_startup_name, false);
			constexpr auto onboarded_name = "onboarded";
			init_node(m_table, m_onboarded, onboarded_name, false);

			save_pref();

			toggle(m_is_open_at_startup->ref<bool>());
		}
		catch (const std::exception& e)
		{
			LOG(INFO) << "Failed init hotkeys: " << e.what();

			toggle(false);
		}
	}

	void gui::save_pref()
	{
		std::ofstream file_stream(m_file_path, std::ios::out | std::ios::trunc);
		if (file_stream.is_open())
		{
			file_stream << m_table;
		}
		else
		{
			LOG(WARNING) << "Failed to save pref.";
		}
	}


	void writeDwordAddress(uintptr_t baseAddress, const std::vector<uintptr_t>& offsets, int32_t newValue)
	{
		uintptr_t currentAddress = baseAddress;

		for (size_t i = 0; i < offsets.size() - 1; i++) {
			currentAddress = *reinterpret_cast<uintptr_t*>(currentAddress + offsets[i]);
		}

		currentAddress += offsets.back();
		*reinterpret_cast<int32_t*>(currentAddress)  = newValue;
	}


	/********************
	This function can read a value at a certain offset of the mem.
	Example : 
		- I want to read the GWorld Offset :
			- readValueAddress(baseAddresse => Fetch from proc itself, std::vector<uintptr_t> offsets = {0x06F65C48})
	**********************/
	int32_t readValueAddress(uintptr_t baseAddress, std::vector<uintptr_t> offsets)
	{
		uintptr_t currentAdd = baseAddress;

		for (size_t i = 0; i < offsets.size() - 1; i++)
		{
			currentAdd = *reinterpret_cast<uintptr_t*>(currentAdd + offsets[i]);
		}

		// Read the last offset to get the value
		currentAdd += offsets.back();
		return *reinterpret_cast<int32_t*>(currentAdd); // We return the value as a DWORD (4 Bytes value)
	}

	
	void freezeTimer(uintptr_t baseAddress, const std::vector<uintptr_t>& offsets, int32_t valueToFreeze, std::atomic<bool>& running)
	{
		while (running)
		{
			writeDwordAddress(baseAddress, offsets, valueToFreeze);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}

	/*
	Get process BaseAddress from pId and processName
	//*/
	//DWORD GetBaseAddress(const HANDLE hProcess)
	//{
	//	if (hProcess == NULL)
	//	{
	//		return NULL; // No access to the process
	//	}

	//	HMODULE lphModule[1024]; // Array that receives the list of module handles
	//	DWORD lpcbNeeded(NULL); // Output of EnumProcessModules, giving the number of bytes requires to store all modules handles in the lphModule array

	//	if (!EnumProcessModules(hProcess, lphModule, sizeof(lphModule), &lpcbNeeded))
	//	{
	//		return NULL; // Impossible to read modules
	//	}

	//	TCHAR szModName[MAX_PATH];
	//	if (!GetModuleFileNameEx(hProcess, lphModule[0], szModName, sizeof(szModName) / sizeof(TCHAR)))
	//	{
	//		return NULL; // Impossible to get module info
	//	}

	//	return (DWORD)lphModule[0]; // Module 0 is apparently always the EXE itself, returning its address
	//}


} // namespace big
