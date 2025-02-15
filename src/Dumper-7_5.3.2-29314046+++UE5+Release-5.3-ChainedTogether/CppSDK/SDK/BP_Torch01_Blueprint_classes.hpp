#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Torch01_Blueprint

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_Torch01_Blueprint.BP_Torch01_Blueprint_C
// 0x0020 (0x02C8 - 0x02A8)
class ABP_Torch01_Blueprint_C final : public AStaticMeshActor
{
public:
	class UStaticMeshComponent*                   Torch01_Holder;                                    // 0x02A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               P_TorchFire_Entrance;                              // 0x02B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight;                                        // 0x02B8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	bool                                          Fire_Enable;                                       // 0x02C0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_Torch01_Blueprint_C">();
	}
	static class ABP_Torch01_Blueprint_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_Torch01_Blueprint_C>();
	}
};
static_assert(alignof(ABP_Torch01_Blueprint_C) == 0x000008, "Wrong alignment on ABP_Torch01_Blueprint_C");
static_assert(sizeof(ABP_Torch01_Blueprint_C) == 0x0002C8, "Wrong size on ABP_Torch01_Blueprint_C");
static_assert(offsetof(ABP_Torch01_Blueprint_C, Torch01_Holder) == 0x0002A8, "Member 'ABP_Torch01_Blueprint_C::Torch01_Holder' has a wrong offset!");
static_assert(offsetof(ABP_Torch01_Blueprint_C, P_TorchFire_Entrance) == 0x0002B0, "Member 'ABP_Torch01_Blueprint_C::P_TorchFire_Entrance' has a wrong offset!");
static_assert(offsetof(ABP_Torch01_Blueprint_C, PointLight) == 0x0002B8, "Member 'ABP_Torch01_Blueprint_C::PointLight' has a wrong offset!");
static_assert(offsetof(ABP_Torch01_Blueprint_C, Fire_Enable) == 0x0002C0, "Member 'ABP_Torch01_Blueprint_C::Fire_Enable' has a wrong offset!");

}

