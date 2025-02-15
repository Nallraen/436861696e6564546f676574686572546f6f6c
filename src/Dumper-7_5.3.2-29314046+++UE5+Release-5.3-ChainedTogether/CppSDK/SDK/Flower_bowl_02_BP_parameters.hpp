#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Flower_bowl_02_BP

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function flower_bowl_02_BP.flower_bowl_02_BP_C.UserConstructionScript
// 0x0180 (0x0180 - 0x0000)
struct Flower_bowl_02_BP_C_UserConstructionScript final
{
public:
	class UMaterialInterface*                     CallFunc_Array_Get_Item;                           // 0x0000(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_RandomRotatorFromStream_ReturnValue;      // 0x0008(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor)
	int32                                         CallFunc_RandomIntegerInRangeFromStream_ReturnValue; // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_36CC[0x4];                                     // 0x0024(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_BreakRotIntoAxes_X;                       // 0x0028(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_BreakRotIntoAxes_Y;                       // 0x0040(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_BreakRotIntoAxes_Z;                       // 0x0058(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_Conv_VectorToRotator_ReturnValue;         // 0x0070(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor)
	class UStaticMesh*                            CallFunc_Array_Get_Item_1;                         // 0x0088(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	struct FHitResult                             CallFunc_K2_AddRelativeRotation_SweepHitResult;    // 0x0090(0x00E8)(IsPlainOldData, NoDestructor, ContainsInstancedReference)
	bool                                          CallFunc_SetStaticMesh_ReturnValue;                // 0x0178(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_SetStaticMesh_ReturnValue_1;              // 0x0179(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_SetStaticMesh_ReturnValue_2;              // 0x017A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_SetStaticMesh_ReturnValue_3;              // 0x017B(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(Flower_bowl_02_BP_C_UserConstructionScript) == 0x000008, "Wrong alignment on Flower_bowl_02_BP_C_UserConstructionScript");
static_assert(sizeof(Flower_bowl_02_BP_C_UserConstructionScript) == 0x000180, "Wrong size on Flower_bowl_02_BP_C_UserConstructionScript");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_Array_Get_Item) == 0x000000, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_Array_Get_Item' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_RandomRotatorFromStream_ReturnValue) == 0x000008, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_RandomRotatorFromStream_ReturnValue' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_RandomIntegerInRangeFromStream_ReturnValue) == 0x000020, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_RandomIntegerInRangeFromStream_ReturnValue' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_BreakRotIntoAxes_X) == 0x000028, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_BreakRotIntoAxes_X' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_BreakRotIntoAxes_Y) == 0x000040, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_BreakRotIntoAxes_Y' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_BreakRotIntoAxes_Z) == 0x000058, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_BreakRotIntoAxes_Z' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_Conv_VectorToRotator_ReturnValue) == 0x000070, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_Conv_VectorToRotator_ReturnValue' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_Array_Get_Item_1) == 0x000088, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_Array_Get_Item_1' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_K2_AddRelativeRotation_SweepHitResult) == 0x000090, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_K2_AddRelativeRotation_SweepHitResult' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_SetStaticMesh_ReturnValue) == 0x000178, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_SetStaticMesh_ReturnValue' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_SetStaticMesh_ReturnValue_1) == 0x000179, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_SetStaticMesh_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_SetStaticMesh_ReturnValue_2) == 0x00017A, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_SetStaticMesh_ReturnValue_2' has a wrong offset!");
static_assert(offsetof(Flower_bowl_02_BP_C_UserConstructionScript, CallFunc_SetStaticMesh_ReturnValue_3) == 0x00017B, "Member 'Flower_bowl_02_BP_C_UserConstructionScript::CallFunc_SetStaticMesh_ReturnValue_3' has a wrong offset!");

}

