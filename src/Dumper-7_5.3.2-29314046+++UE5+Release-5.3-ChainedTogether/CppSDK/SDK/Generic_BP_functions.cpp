#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Generic_BP

#include "Basic.hpp"

#include "Generic_BP_classes.hpp"
#include "Generic_BP_parameters.hpp"


namespace SDK
{

// Function Generic_BP.Generic_BP_C.UserConstructionScript
// (Event, Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void AGeneric_BP_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Generic_BP_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}

}

