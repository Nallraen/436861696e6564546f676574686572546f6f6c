#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_paddle_wheel

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_paddle_wheel.BP_paddle_wheel_C
// 0x0028 (0x02C0 - 0x0298)
class ABP_paddle_wheel_C final : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0298(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UC_TickOptimizer_C*                     C_TickOptimizer;                                   // 0x02A0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   SM_paddle_wheel;                                   // 0x02A8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x02B0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	double                                        Delta_Rotation_Y__Pitch_;                          // 0x02B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_BP_paddle_wheel(int32 EntryPoint);
	void ReceiveTick(float DeltaSeconds);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_paddle_wheel_C">();
	}
	static class ABP_paddle_wheel_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_paddle_wheel_C>();
	}
};
static_assert(alignof(ABP_paddle_wheel_C) == 0x000008, "Wrong alignment on ABP_paddle_wheel_C");
static_assert(sizeof(ABP_paddle_wheel_C) == 0x0002C0, "Wrong size on ABP_paddle_wheel_C");
static_assert(offsetof(ABP_paddle_wheel_C, UberGraphFrame) == 0x000298, "Member 'ABP_paddle_wheel_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ABP_paddle_wheel_C, C_TickOptimizer) == 0x0002A0, "Member 'ABP_paddle_wheel_C::C_TickOptimizer' has a wrong offset!");
static_assert(offsetof(ABP_paddle_wheel_C, SM_paddle_wheel) == 0x0002A8, "Member 'ABP_paddle_wheel_C::SM_paddle_wheel' has a wrong offset!");
static_assert(offsetof(ABP_paddle_wheel_C, DefaultSceneRoot) == 0x0002B0, "Member 'ABP_paddle_wheel_C::DefaultSceneRoot' has a wrong offset!");
static_assert(offsetof(ABP_paddle_wheel_C, Delta_Rotation_Y__Pitch_) == 0x0002B8, "Member 'ABP_paddle_wheel_C::Delta_Rotation_Y__Pitch_' has a wrong offset!");

}

