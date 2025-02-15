#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Torch_01_01

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_Torch_01_01.BP_Torch_01_01_C
// 0x0020 (0x02B8 - 0x0298)
class ABP_Torch_01_01_C final : public AActor
{
public:
	class UPointLightComponent*                   LightComponent0;                                   // 0x0298(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               ParticleSystemComponent0;                          // 0x02A0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMeshComponent0;                              // 0x02A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        SharedRoot;                                        // 0x02B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_Torch_01_01_C">();
	}
	static class ABP_Torch_01_01_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_Torch_01_01_C>();
	}
};
static_assert(alignof(ABP_Torch_01_01_C) == 0x000008, "Wrong alignment on ABP_Torch_01_01_C");
static_assert(sizeof(ABP_Torch_01_01_C) == 0x0002B8, "Wrong size on ABP_Torch_01_01_C");
static_assert(offsetof(ABP_Torch_01_01_C, LightComponent0) == 0x000298, "Member 'ABP_Torch_01_01_C::LightComponent0' has a wrong offset!");
static_assert(offsetof(ABP_Torch_01_01_C, ParticleSystemComponent0) == 0x0002A0, "Member 'ABP_Torch_01_01_C::ParticleSystemComponent0' has a wrong offset!");
static_assert(offsetof(ABP_Torch_01_01_C, StaticMeshComponent0) == 0x0002A8, "Member 'ABP_Torch_01_01_C::StaticMeshComponent0' has a wrong offset!");
static_assert(offsetof(ABP_Torch_01_01_C, SharedRoot) == 0x0002B0, "Member 'ABP_Torch_01_01_C::SharedRoot' has a wrong offset!");

}

