#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPT_TyrolienneSocket

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BP_Tyrolienne_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BPT_TyrolienneSocket.BPT_TyrolienneSocket_C
// 0x0010 (0x0480 - 0x0470)
class ABPT_TyrolienneSocket_C final : public ABP_Tyrolienne_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_BPT_TyrolienneSocket_C;             // 0x0470(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void BeginMove();
	void ExecuteUbergraph_BPT_TyrolienneSocket(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BPT_TyrolienneSocket_C">();
	}
	static class ABPT_TyrolienneSocket_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABPT_TyrolienneSocket_C>();
	}
};
static_assert(alignof(ABPT_TyrolienneSocket_C) == 0x000010, "Wrong alignment on ABPT_TyrolienneSocket_C");
static_assert(sizeof(ABPT_TyrolienneSocket_C) == 0x000480, "Wrong size on ABPT_TyrolienneSocket_C");
static_assert(offsetof(ABPT_TyrolienneSocket_C, UberGraphFrame_BPT_TyrolienneSocket_C) == 0x000470, "Member 'ABPT_TyrolienneSocket_C::UberGraphFrame_BPT_TyrolienneSocket_C' has a wrong offset!");

}

