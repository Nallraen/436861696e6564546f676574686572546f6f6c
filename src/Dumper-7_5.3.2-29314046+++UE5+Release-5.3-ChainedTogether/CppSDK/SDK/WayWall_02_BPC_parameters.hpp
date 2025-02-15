#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WayWall_02_BPC

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function WayWall_02_BPC.WayWall_02_BPC_C.ExecuteUbergraph_WayWall_02_BPC
// 0x0128 (0x0128 - 0x0000)
struct WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_382C[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	double                                        CallFunc_UpdateSpeedByPlayersNumber_ReturnSpeed;   // 0x0008(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        CallFunc_Lerp_ReturnValue;                         // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_MakeVector_ReturnValue;                   // 0x0018(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FHitResult                             CallFunc_K2_SetRelativeLocation_SweepHitResult;    // 0x0030(0x00E8)(IsPlainOldData, NoDestructor, ContainsInstancedReference)
	float                                         CallFunc_SetPlayRate_NewRate_ImplicitCast;         // 0x0118(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_382D[0x4];                                     // 0x011C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	double                                        CallFunc_Lerp_Alpha_ImplicitCast;                  // 0x0120(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC) == 0x000008, "Wrong alignment on WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC");
static_assert(sizeof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC) == 0x000128, "Wrong size on WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC");
static_assert(offsetof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC, EntryPoint) == 0x000000, "Member 'WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC::EntryPoint' has a wrong offset!");
static_assert(offsetof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC, CallFunc_UpdateSpeedByPlayersNumber_ReturnSpeed) == 0x000008, "Member 'WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC::CallFunc_UpdateSpeedByPlayersNumber_ReturnSpeed' has a wrong offset!");
static_assert(offsetof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC, CallFunc_Lerp_ReturnValue) == 0x000010, "Member 'WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC::CallFunc_Lerp_ReturnValue' has a wrong offset!");
static_assert(offsetof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC, CallFunc_MakeVector_ReturnValue) == 0x000018, "Member 'WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC::CallFunc_MakeVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC, CallFunc_K2_SetRelativeLocation_SweepHitResult) == 0x000030, "Member 'WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC::CallFunc_K2_SetRelativeLocation_SweepHitResult' has a wrong offset!");
static_assert(offsetof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC, CallFunc_SetPlayRate_NewRate_ImplicitCast) == 0x000118, "Member 'WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC::CallFunc_SetPlayRate_NewRate_ImplicitCast' has a wrong offset!");
static_assert(offsetof(WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC, CallFunc_Lerp_Alpha_ImplicitCast) == 0x000120, "Member 'WayWall_02_BPC_C_ExecuteUbergraph_WayWall_02_BPC::CallFunc_Lerp_Alpha_ImplicitCast' has a wrong offset!");

}

