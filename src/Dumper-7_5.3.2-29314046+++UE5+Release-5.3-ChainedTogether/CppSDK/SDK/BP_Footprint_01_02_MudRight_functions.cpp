#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_Footprint_01_02_MudRight

#include "Basic.hpp"

#include "BP_Footprint_01_02_MudRight_classes.hpp"
#include "BP_Footprint_01_02_MudRight_parameters.hpp"


namespace SDK
{

// Function BP_Footprint_01_02_MudRight.BP_Footprint_01_02_MudRight_C.ExecuteUbergraph_BP_Footprint_01_02_MudRight
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_Footprint_01_02_MudRight_C::ExecuteUbergraph_BP_Footprint_01_02_MudRight(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Footprint_01_02_MudRight_C", "ExecuteUbergraph_BP_Footprint_01_02_MudRight");

	Params::BP_Footprint_01_02_MudRight_C_ExecuteUbergraph_BP_Footprint_01_02_MudRight Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_Footprint_01_02_MudRight.BP_Footprint_01_02_MudRight_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABP_Footprint_01_02_MudRight_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_Footprint_01_02_MudRight_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}

}

