#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_PivotStoneWall

#include "Basic.hpp"

#include "BP_PivotStoneWall_classes.hpp"
#include "BP_PivotStoneWall_parameters.hpp"


namespace SDK
{

// Function BP_PivotStoneWall.BP_PivotStoneWall_C.CheckDoorOpen
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_PivotStoneWall_C::CheckDoorOpen()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "CheckDoorOpen");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.ExecuteUbergraph_BP_PivotStoneWall
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_PivotStoneWall_C::ExecuteUbergraph_BP_PivotStoneWall(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "ExecuteUbergraph_BP_PivotStoneWall");

	Params::BP_PivotStoneWall_C_ExecuteUbergraph_BP_PivotStoneWall Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.GetPivotAlpha
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// double                                  Alpha                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_PivotStoneWall_C::GetPivotAlpha(double* Alpha)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "GetPivotAlpha");

	Params::BP_PivotStoneWall_C_GetPivotAlpha Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Alpha != nullptr)
		*Alpha = Parms.Alpha;
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.IsActivated
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Activated                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_PivotStoneWall_C::IsActivated(bool* Activated)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "IsActivated");

	Params::BP_PivotStoneWall_C_IsActivated Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Activated != nullptr)
		*Activated = Parms.Activated;
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.OnPivot
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// double                                  Axis                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_PivotStoneWall_C::OnPivot(double Axis)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "OnPivot");

	Params::BP_PivotStoneWall_C_OnPivot Parms{};

	Parms.Axis = Axis;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.OnRep_Open
// (BlueprintCallable, BlueprintEvent)

void ABP_PivotStoneWall_C::OnRep_Open()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "OnRep_Open");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.OpenDoor
// (BlueprintCallable, BlueprintEvent)

void ABP_PivotStoneWall_C::OpenDoor()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "OpenDoor");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.Pushed
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_PivotStoneWall_C::Pushed()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "Pushed");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_PivotStoneWall_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.Released
// (Public, BlueprintCallable, BlueprintEvent)

void ABP_PivotStoneWall_C::Released()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "Released");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.Timeline_0__FinishedFunc
// (BlueprintEvent)

void ABP_PivotStoneWall_C::Timeline_0__FinishedFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "Timeline_0__FinishedFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.Timeline_0__UpdateFunc
// (BlueprintEvent)

void ABP_PivotStoneWall_C::Timeline_0__UpdateFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "Timeline_0__UpdateFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_PivotStoneWall.BP_PivotStoneWall_C.UserConstructionScript
// (Event, Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void ABP_PivotStoneWall_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_PivotStoneWall_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}

