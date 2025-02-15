#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_MovingWheel

#include "Basic.hpp"

#include "BP_MovingWheel_classes.hpp"
#include "BP_MovingWheel_parameters.hpp"


namespace SDK
{

// Function BP_MovingWheel.BP_MovingWheel_C.CustomEvent
// (BlueprintCallable, BlueprintEvent)

void ABP_MovingWheel_C::CustomEvent()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_MovingWheel_C", "CustomEvent");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_MovingWheel.BP_MovingWheel_C.ExecuteUbergraph_BP_MovingWheel
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_MovingWheel_C::ExecuteUbergraph_BP_MovingWheel(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_MovingWheel_C", "ExecuteUbergraph_BP_MovingWheel");

	Params::BP_MovingWheel_C_ExecuteUbergraph_BP_MovingWheel Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_MovingWheel.BP_MovingWheel_C.OnRep_NewVar
// (BlueprintCallable, BlueprintEvent)

void ABP_MovingWheel_C::OnRep_NewVar()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_MovingWheel_C", "OnRep_NewVar");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_MovingWheel.BP_MovingWheel_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_MovingWheel_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_MovingWheel_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_MovingWheel.BP_MovingWheel_C.ReceiveTick
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaSeconds                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_MovingWheel_C::ReceiveTick(float DeltaSeconds)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_MovingWheel_C", "ReceiveTick");

	Params::BP_MovingWheel_C_ReceiveTick Parms{};

	Parms.DeltaSeconds = DeltaSeconds;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_MovingWheel.BP_MovingWheel_C.Timeline_0__FinishedFunc
// (BlueprintEvent)

void ABP_MovingWheel_C::Timeline_0__FinishedFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_MovingWheel_C", "Timeline_0__FinishedFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_MovingWheel.BP_MovingWheel_C.Timeline_0__UpdateFunc
// (BlueprintEvent)

void ABP_MovingWheel_C::Timeline_0__UpdateFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_MovingWheel_C", "Timeline_0__UpdateFunc");

	UObject::ProcessEvent(Func, nullptr);
}

}

