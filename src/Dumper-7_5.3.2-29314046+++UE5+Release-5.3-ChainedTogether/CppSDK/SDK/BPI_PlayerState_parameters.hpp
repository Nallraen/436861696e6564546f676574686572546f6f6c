#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPI_PlayerState

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function BPI_PlayerState.BPI_PlayerState_C.GetColor
// 0x0010 (0x0010 - 0x0000)
struct BPI_PlayerState_C_GetColor final
{
public:
	struct FLinearColor                           Color;                                             // 0x0000(0x0010)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(BPI_PlayerState_C_GetColor) == 0x000004, "Wrong alignment on BPI_PlayerState_C_GetColor");
static_assert(sizeof(BPI_PlayerState_C_GetColor) == 0x000010, "Wrong size on BPI_PlayerState_C_GetColor");
static_assert(offsetof(BPI_PlayerState_C_GetColor, Color) == 0x000000, "Member 'BPI_PlayerState_C_GetColor::Color' has a wrong offset!");

}

