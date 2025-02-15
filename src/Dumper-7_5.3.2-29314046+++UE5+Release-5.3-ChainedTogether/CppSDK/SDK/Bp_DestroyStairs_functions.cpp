#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Bp_DestroyStairs

#include "Basic.hpp"

#include "Bp_DestroyStairs_classes.hpp"
#include "Bp_DestroyStairs_parameters.hpp"


namespace SDK
{

// Function Bp_DestroyStairs.Bp_DestroyStairs_C.BndEvt__Bp_DestroyStairs_Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature
// (HasOutParams, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*              OverlappedComponent                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
// class AActor*                           OtherActor                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, NoDestructor, HasGetValueTypeHash)
// class UPrimitiveComponent*              OtherComp                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
// int32                                   OtherBodyIndex                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bFromSweep                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FHitResult                       SweepResult                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor, ContainsInstancedReference)

void ABp_DestroyStairs_C::BndEvt__Bp_DestroyStairs_Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Bp_DestroyStairs_C", "BndEvt__Bp_DestroyStairs_Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature");

	Params::Bp_DestroyStairs_C_BndEvt__Bp_DestroyStairs_Box_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature Parms{};

	Parms.OverlappedComponent = OverlappedComponent;
	Parms.OtherActor = OtherActor;
	Parms.OtherComp = OtherComp;
	Parms.OtherBodyIndex = OtherBodyIndex;
	Parms.bFromSweep = bFromSweep;
	Parms.SweepResult = std::move(SweepResult);

	UObject::ProcessEvent(Func, &Parms);
}


// Function Bp_DestroyStairs.Bp_DestroyStairs_C.ExecuteUbergraph_Bp_DestroyStairs
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABp_DestroyStairs_C::ExecuteUbergraph_Bp_DestroyStairs(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Bp_DestroyStairs_C", "ExecuteUbergraph_Bp_DestroyStairs");

	Params::Bp_DestroyStairs_C_ExecuteUbergraph_Bp_DestroyStairs Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Bp_DestroyStairs.Bp_DestroyStairs_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABp_DestroyStairs_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Bp_DestroyStairs_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Bp_DestroyStairs.Bp_DestroyStairs_C.test
// (BlueprintCallable, BlueprintEvent)

void ABp_DestroyStairs_C::Test()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Bp_DestroyStairs_C", "test");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Bp_DestroyStairs.Bp_DestroyStairs_C.Timeline__FinishedFunc
// (BlueprintEvent)

void ABp_DestroyStairs_C::Timeline__FinishedFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Bp_DestroyStairs_C", "Timeline__FinishedFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Bp_DestroyStairs.Bp_DestroyStairs_C.Timeline__UpdateFunc
// (BlueprintEvent)

void ABp_DestroyStairs_C::Timeline__UpdateFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Bp_DestroyStairs_C", "Timeline__UpdateFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Bp_DestroyStairs.Bp_DestroyStairs_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void ABp_DestroyStairs_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Bp_DestroyStairs_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}

