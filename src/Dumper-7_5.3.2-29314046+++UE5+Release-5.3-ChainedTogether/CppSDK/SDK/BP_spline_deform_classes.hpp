#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_spline_deform

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_spline_deform.BP_spline_deform_C
// 0x0018 (0x02B0 - 0x0298)
class ABP_spline_deform_C final : public AActor
{
public:
	class USplineComponent*                       Spline;                                            // 0x0298(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMesh*                            StaticMesh;                                        // 0x02A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	ESplineMeshAxis                               ForwardAxis;                                       // 0x02A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ECollisionResponse                            Chain_Collision;                                   // 0x02A9(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	ECollisionEnabled                             Collision;                                         // 0x02AA(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)

public:
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_spline_deform_C">();
	}
	static class ABP_spline_deform_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_spline_deform_C>();
	}
};
static_assert(alignof(ABP_spline_deform_C) == 0x000008, "Wrong alignment on ABP_spline_deform_C");
static_assert(sizeof(ABP_spline_deform_C) == 0x0002B0, "Wrong size on ABP_spline_deform_C");
static_assert(offsetof(ABP_spline_deform_C, Spline) == 0x000298, "Member 'ABP_spline_deform_C::Spline' has a wrong offset!");
static_assert(offsetof(ABP_spline_deform_C, StaticMesh) == 0x0002A0, "Member 'ABP_spline_deform_C::StaticMesh' has a wrong offset!");
static_assert(offsetof(ABP_spline_deform_C, ForwardAxis) == 0x0002A8, "Member 'ABP_spline_deform_C::ForwardAxis' has a wrong offset!");
static_assert(offsetof(ABP_spline_deform_C, Chain_Collision) == 0x0002A9, "Member 'ABP_spline_deform_C::Chain_Collision' has a wrong offset!");
static_assert(offsetof(ABP_spline_deform_C, Collision) == 0x0002AA, "Member 'ABP_spline_deform_C::Collision' has a wrong offset!");

}

