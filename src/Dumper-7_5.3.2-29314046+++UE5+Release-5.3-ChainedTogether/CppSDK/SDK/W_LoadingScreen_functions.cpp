#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: W_LoadingScreen

#include "Basic.hpp"

#include "W_LoadingScreen_classes.hpp"
#include "W_LoadingScreen_parameters.hpp"


namespace SDK
{

// Function W_LoadingScreen.W_LoadingScreen_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UW_LoadingScreen_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("W_LoadingScreen_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function W_LoadingScreen.W_LoadingScreen_C.ExecuteUbergraph_W_LoadingScreen
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UW_LoadingScreen_C::ExecuteUbergraph_W_LoadingScreen(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("W_LoadingScreen_C", "ExecuteUbergraph_W_LoadingScreen");

	Params::W_LoadingScreen_C_ExecuteUbergraph_W_LoadingScreen Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}

