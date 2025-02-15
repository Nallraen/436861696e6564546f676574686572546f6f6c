#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Aimant

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_Aimant.BP_Aimant_C
// 0x0080 (0x0318 - 0x0298)
class ABP_Aimant_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0298(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UC_VinceSync_C*                         C_VinceSync;                                       // 0x02A0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UC_TickOptimizer_C*                     C_TickOptimizer;                                   // 0x02A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               PS_Aimant;                                         // 0x02B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USphereComponent*                       Sphere;                                            // 0x02B8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x02C0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Cylinder1;                                         // 0x02C8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   Cylinder;                                          // 0x02D0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x02D8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         Timeline_NewTrack_0_99B94B8843F695447000B2BF45FB2AB3; // 0x02E0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Timeline__Direction_99B94B8843F695447000B2BF45FB2AB3; // 0x02E4(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3B4A[0x3];                                     // 0x02E5(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Timeline;                                          // 0x02E8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	bool                                          Activate;                                          // 0x02F0(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, RepNotify, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3B4B[0x7];                                     // 0x02F1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                InitLoc;                                           // 0x02F8(0x0018)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        Time;                                              // 0x0310(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)

public:
	void CalculateForce(class AActor* Self2, struct FVector* Force);
	void ExecuteUbergraph_BP_Aimant(int32 EntryPoint);
	void MoveCylinder(double Alpha);
	void OnRep_Activate();
	void ReceiveBeginPlay();
	void ReceiveTick(float DeltaSeconds);
	void Timeline__Activate__EventFunc();
	void Timeline__Deactivate__EventFunc();
	void Timeline__FinishedFunc();
	void Timeline__UpdateFunc();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_Aimant_C">();
	}
	static class ABP_Aimant_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_Aimant_C>();
	}
};
static_assert(alignof(ABP_Aimant_C) == 0x000008, "Wrong alignment on ABP_Aimant_C");
static_assert(sizeof(ABP_Aimant_C) == 0x000318, "Wrong size on ABP_Aimant_C");
static_assert(offsetof(ABP_Aimant_C, UberGraphFrame) == 0x000298, "Member 'ABP_Aimant_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, C_VinceSync) == 0x0002A0, "Member 'ABP_Aimant_C::C_VinceSync' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, C_TickOptimizer) == 0x0002A8, "Member 'ABP_Aimant_C::C_TickOptimizer' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, PS_Aimant) == 0x0002B0, "Member 'ABP_Aimant_C::PS_Aimant' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, Sphere) == 0x0002B8, "Member 'ABP_Aimant_C::Sphere' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, StaticMesh) == 0x0002C0, "Member 'ABP_Aimant_C::StaticMesh' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, Cylinder1) == 0x0002C8, "Member 'ABP_Aimant_C::Cylinder1' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, Cylinder) == 0x0002D0, "Member 'ABP_Aimant_C::Cylinder' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, DefaultSceneRoot) == 0x0002D8, "Member 'ABP_Aimant_C::DefaultSceneRoot' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, Timeline_NewTrack_0_99B94B8843F695447000B2BF45FB2AB3) == 0x0002E0, "Member 'ABP_Aimant_C::Timeline_NewTrack_0_99B94B8843F695447000B2BF45FB2AB3' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, Timeline__Direction_99B94B8843F695447000B2BF45FB2AB3) == 0x0002E4, "Member 'ABP_Aimant_C::Timeline__Direction_99B94B8843F695447000B2BF45FB2AB3' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, Timeline) == 0x0002E8, "Member 'ABP_Aimant_C::Timeline' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, Activate) == 0x0002F0, "Member 'ABP_Aimant_C::Activate' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, InitLoc) == 0x0002F8, "Member 'ABP_Aimant_C::InitLoc' has a wrong offset!");
static_assert(offsetof(ABP_Aimant_C, Time) == 0x000310, "Member 'ABP_Aimant_C::Time' has a wrong offset!");

}

