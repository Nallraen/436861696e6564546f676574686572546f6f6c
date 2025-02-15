#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ButtonEvent

#include "Basic.hpp"

#include "BP_ButtonEvent_classes.hpp"
#include "BP_ButtonEvent_parameters.hpp"


namespace SDK
{

// Function BP_ButtonEvent.BP_ButtonEvent_C.CheckButtons
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Pressed                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

bool ABP_ButtonEvent_C::CheckButtons(bool Pressed)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ButtonEvent_C", "CheckButtons");

	Params::BP_ButtonEvent_C_CheckButtons Parms{};

	Parms.Pressed = Pressed;

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function BP_ButtonEvent.BP_ButtonEvent_C.CheckEventPush
// (BlueprintCallable, BlueprintEvent)

void ABP_ButtonEvent_C::CheckEventPush()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ButtonEvent_C", "CheckEventPush");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ButtonEvent.BP_ButtonEvent_C.EventRelease
// (BlueprintCallable, BlueprintEvent)

void ABP_ButtonEvent_C::EventRelease()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ButtonEvent_C", "EventRelease");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ButtonEvent.BP_ButtonEvent_C.ExecuteUbergraph_BP_ButtonEvent
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_ButtonEvent_C::ExecuteUbergraph_BP_ButtonEvent(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ButtonEvent_C", "ExecuteUbergraph_BP_ButtonEvent");

	Params::BP_ButtonEvent_C_ExecuteUbergraph_BP_ButtonEvent Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_ButtonEvent.BP_ButtonEvent_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_ButtonEvent_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ButtonEvent_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ButtonEvent.BP_ButtonEvent_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void ABP_ButtonEvent_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ButtonEvent_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}

