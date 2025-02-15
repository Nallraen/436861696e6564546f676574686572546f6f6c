#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MainMenu_W

#include "Basic.hpp"


namespace SDK::Params
{

// Function MainMenu_W.MainMenu_W_C.ExecuteUbergraph_MainMenu_W
// 0x0070 (0x0070 - 0x0000)
struct MainMenu_W_C_ExecuteUbergraph_MainMenu_W final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_33E4[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UPlayMenu_W_C*                          CallFunc_Create_ReturnValue;                       // 0x0008(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class UTroubleshooting_W_C*                   CallFunc_Create_ReturnValue_1;                     // 0x0010(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class UW_LeaderboardSwitcher_C*               CallFunc_Create_ReturnValue_2;                     // 0x0018(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class APlayerController*                      CallFunc_GetPlayerController_ReturnValue;          // 0x0020(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue;                // 0x0028(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UW_SettingsMain_C*                      CallFunc_Create_ReturnValue_3;                     // 0x0030(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class APlayerController*                      CallFunc_GetPlayerController_ReturnValue_1;        // 0x0038(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_1;              // 0x0040(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_2;              // 0x0048(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UUMGSequencePlayer*                     CallFunc_PlayAnimation_ReturnValue_3;              // 0x0050(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        CallFunc_SpawnSound2D_ReturnValue;                 // 0x0058(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        CallFunc_SpawnSound2D_ReturnValue_1;               // 0x0060(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        CallFunc_SpawnSound2D_ReturnValue_2;               // 0x0068(0x0008)(ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W) == 0x000008, "Wrong alignment on MainMenu_W_C_ExecuteUbergraph_MainMenu_W");
static_assert(sizeof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W) == 0x000070, "Wrong size on MainMenu_W_C_ExecuteUbergraph_MainMenu_W");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, EntryPoint) == 0x000000, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::EntryPoint' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_Create_ReturnValue) == 0x000008, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_Create_ReturnValue' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_Create_ReturnValue_1) == 0x000010, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_Create_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_Create_ReturnValue_2) == 0x000018, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_Create_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_GetPlayerController_ReturnValue) == 0x000020, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_GetPlayerController_ReturnValue' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_PlayAnimation_ReturnValue) == 0x000028, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_PlayAnimation_ReturnValue' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_Create_ReturnValue_3) == 0x000030, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_Create_ReturnValue_3' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_GetPlayerController_ReturnValue_1) == 0x000038, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_GetPlayerController_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_PlayAnimation_ReturnValue_1) == 0x000040, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_PlayAnimation_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_PlayAnimation_ReturnValue_2) == 0x000048, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_PlayAnimation_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_PlayAnimation_ReturnValue_3) == 0x000050, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_PlayAnimation_ReturnValue_3' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_SpawnSound2D_ReturnValue) == 0x000058, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_SpawnSound2D_ReturnValue' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_SpawnSound2D_ReturnValue_1) == 0x000060, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_SpawnSound2D_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_ExecuteUbergraph_MainMenu_W, CallFunc_SpawnSound2D_ReturnValue_2) == 0x000068, "Member 'MainMenu_W_C_ExecuteUbergraph_MainMenu_W::CallFunc_SpawnSound2D_ReturnValue_2' has a wrong offset!");

// Function MainMenu_W.MainMenu_W_C.UpdateVersion
// 0x0030 (0x0030 - 0x0000)
struct MainMenu_W_C_UpdateVersion final
{
public:
	class UGameInstance*                          CallFunc_GetGameInstance_ReturnValue;              // 0x0000(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UCustomGI_C*                            K2Node_DynamicCast_AsCustom_GI;                    // 0x0008(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0010(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_33E5[0x7];                                     // 0x0011(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_Conv_StringToText_ReturnValue;            // 0x0018(0x0018)()
};
static_assert(alignof(MainMenu_W_C_UpdateVersion) == 0x000008, "Wrong alignment on MainMenu_W_C_UpdateVersion");
static_assert(sizeof(MainMenu_W_C_UpdateVersion) == 0x000030, "Wrong size on MainMenu_W_C_UpdateVersion");
static_assert(offsetof(MainMenu_W_C_UpdateVersion, CallFunc_GetGameInstance_ReturnValue) == 0x000000, "Member 'MainMenu_W_C_UpdateVersion::CallFunc_GetGameInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_UpdateVersion, K2Node_DynamicCast_AsCustom_GI) == 0x000008, "Member 'MainMenu_W_C_UpdateVersion::K2Node_DynamicCast_AsCustom_GI' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_UpdateVersion, K2Node_DynamicCast_bSuccess) == 0x000010, "Member 'MainMenu_W_C_UpdateVersion::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(MainMenu_W_C_UpdateVersion, CallFunc_Conv_StringToText_ReturnValue) == 0x000018, "Member 'MainMenu_W_C_UpdateVersion::CallFunc_Conv_StringToText_ReturnValue' has a wrong offset!");

}

