#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BeltFallNotify

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BeltFallNotify.BeltFallNotify_C
// 0x0000 (0x0038 - 0x0038)
class UBeltFallNotify_C final : public UAnimNotify
{
public:
	bool Received_Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, const struct FAnimNotifyEventReference& EventReference) const;

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BeltFallNotify_C">();
	}
	static class UBeltFallNotify_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UBeltFallNotify_C>();
	}
};
static_assert(alignof(UBeltFallNotify_C) == 0x000008, "Wrong alignment on UBeltFallNotify_C");
static_assert(sizeof(UBeltFallNotify_C) == 0x000038, "Wrong size on UBeltFallNotify_C");

}

