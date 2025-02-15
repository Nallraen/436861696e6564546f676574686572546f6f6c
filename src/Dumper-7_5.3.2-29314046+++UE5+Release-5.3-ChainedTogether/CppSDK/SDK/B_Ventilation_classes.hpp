#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Ventilation

#include "Basic.hpp"

#include "E_VentilationType_structs.hpp"
#include "E_CornerDirectionVentilation_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_Ventilation.B_Ventilation_C
// 0x0118 (0x03B0 - 0x0298)
class AB_Ventilation_C final : public AActor
{
public:
	class USplineComponent*                       Spline;                                            // 0x0298(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x02A0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	E_VentilationType                             Type;                                              // 0x02A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	E_CornerDirectionVentilation                  CornerDirection;                                   // 0x02A9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_387F[0x6];                                     // 0x02AA(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	double                                        TargetLength;                                      // 0x02B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        CurrentDistance;                                   // 0x02B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        RealLength;                                        // 0x02C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Snap_Location;                                     // 0x02C8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3880[0x3];                                     // 0x02C9(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Snap_Location_Unit_Grid;                           // 0x02CC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	int32                                         Snap_Location_Height_Grid;                         // 0x02D0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	bool                                          Snap_Rotation;                                     // 0x02D4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3881[0x3];                                     // 0x02D5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Snap_Rotation_Degrees;                             // 0x02D8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, AdvancedDisplay, HasGetValueTypeHash)
	int32                                         Material_Type;                                     // 0x02DC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class UMaterialInterface*>             Materials;                                         // 0x02E0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          Support_Post_Enable;                               // 0x02F0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3882[0x3];                                     // 0x02F1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         Support_Post_Type;                                 // 0x02F4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<bool>                                  Support_Posts;                                     // 0x02F8(0x0010)(Edit, BlueprintVisible, AdvancedDisplay)
	TArray<class UStaticMesh*>                    Support_Posts_SM;                                  // 0x0308(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          Enable_All;                                        // 0x0318(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Enable_Only_Odd;                                   // 0x0319(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Enable_Only_Even;                                  // 0x031A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3883[0x5];                                     // 0x031B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	double                                        Height_Support_Posts;                              // 0x0320(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInterface*                     Overwrite_Material;                                // 0x0328(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   TempMesh;                                          // 0x0330(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, NoDestructor, HasGetValueTypeHash)
	class USplineMeshComponent*                   SplineTempMesh;                                    // 0x0338(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, NoDestructor, HasGetValueTypeHash)
	struct FTransform                             LastTransform;                                     // 0x0340(0x0060)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          WasTransformed;                                    // 0x03A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void Initialization_Boolean_Array(const TArray<bool>& TargetArray, int32 Length);
	void SnapRotation();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_Ventilation_C">();
	}
	static class AB_Ventilation_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_Ventilation_C>();
	}
};
static_assert(alignof(AB_Ventilation_C) == 0x000010, "Wrong alignment on AB_Ventilation_C");
static_assert(sizeof(AB_Ventilation_C) == 0x0003B0, "Wrong size on AB_Ventilation_C");
static_assert(offsetof(AB_Ventilation_C, Spline) == 0x000298, "Member 'AB_Ventilation_C::Spline' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, DefaultSceneRoot) == 0x0002A0, "Member 'AB_Ventilation_C::DefaultSceneRoot' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Type) == 0x0002A8, "Member 'AB_Ventilation_C::Type' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, CornerDirection) == 0x0002A9, "Member 'AB_Ventilation_C::CornerDirection' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, TargetLength) == 0x0002B0, "Member 'AB_Ventilation_C::TargetLength' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, CurrentDistance) == 0x0002B8, "Member 'AB_Ventilation_C::CurrentDistance' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, RealLength) == 0x0002C0, "Member 'AB_Ventilation_C::RealLength' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Snap_Location) == 0x0002C8, "Member 'AB_Ventilation_C::Snap_Location' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Snap_Location_Unit_Grid) == 0x0002CC, "Member 'AB_Ventilation_C::Snap_Location_Unit_Grid' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Snap_Location_Height_Grid) == 0x0002D0, "Member 'AB_Ventilation_C::Snap_Location_Height_Grid' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Snap_Rotation) == 0x0002D4, "Member 'AB_Ventilation_C::Snap_Rotation' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Snap_Rotation_Degrees) == 0x0002D8, "Member 'AB_Ventilation_C::Snap_Rotation_Degrees' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Material_Type) == 0x0002DC, "Member 'AB_Ventilation_C::Material_Type' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Materials) == 0x0002E0, "Member 'AB_Ventilation_C::Materials' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Support_Post_Enable) == 0x0002F0, "Member 'AB_Ventilation_C::Support_Post_Enable' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Support_Post_Type) == 0x0002F4, "Member 'AB_Ventilation_C::Support_Post_Type' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Support_Posts) == 0x0002F8, "Member 'AB_Ventilation_C::Support_Posts' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Support_Posts_SM) == 0x000308, "Member 'AB_Ventilation_C::Support_Posts_SM' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Enable_All) == 0x000318, "Member 'AB_Ventilation_C::Enable_All' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Enable_Only_Odd) == 0x000319, "Member 'AB_Ventilation_C::Enable_Only_Odd' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Enable_Only_Even) == 0x00031A, "Member 'AB_Ventilation_C::Enable_Only_Even' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Height_Support_Posts) == 0x000320, "Member 'AB_Ventilation_C::Height_Support_Posts' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, Overwrite_Material) == 0x000328, "Member 'AB_Ventilation_C::Overwrite_Material' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, TempMesh) == 0x000330, "Member 'AB_Ventilation_C::TempMesh' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, SplineTempMesh) == 0x000338, "Member 'AB_Ventilation_C::SplineTempMesh' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, LastTransform) == 0x000340, "Member 'AB_Ventilation_C::LastTransform' has a wrong offset!");
static_assert(offsetof(AB_Ventilation_C, WasTransformed) == 0x0003A0, "Member 'AB_Ventilation_C::WasTransformed' has a wrong offset!");

}

