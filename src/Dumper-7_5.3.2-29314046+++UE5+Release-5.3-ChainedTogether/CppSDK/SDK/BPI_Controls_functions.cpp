#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPI_Controls

#include "Basic.hpp"

#include "BPI_Controls_classes.hpp"
#include "BPI_Controls_parameters.hpp"


namespace SDK
{

// Function BPI_Controls.BPI_Controls_C.Input Leave Tyro
// (Public, BlueprintCallable, BlueprintEvent)

void IBPI_Controls_C::Input_Leave_Tyro()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "Input Leave Tyro");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BPI_Controls.BPI_Controls_C.Jump Input
// (Public, BlueprintCallable, BlueprintEvent)

void IBPI_Controls_C::Jump_Input()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "Jump Input");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BPI_Controls.BPI_Controls_C.LookRight
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// double                                  Axis                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IBPI_Controls_C::LookRight(double Axis)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "LookRight");

	Params::BPI_Controls_C_LookRight Parms{};

	Parms.Axis = Axis;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPI_Controls.BPI_Controls_C.LookUp
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// double                                  Axis                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IBPI_Controls_C::LookUp(double Axis)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "LookUp");

	Params::BPI_Controls_C_LookUp Parms{};

	Parms.Axis = Axis;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPI_Controls.BPI_Controls_C.MoveForward
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// double                                  Axis                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IBPI_Controls_C::MoveForward(double Axis)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "MoveForward");

	Params::BPI_Controls_C_MoveForward Parms{};

	Parms.Axis = Axis;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPI_Controls.BPI_Controls_C.MoveRight
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// double                                  Axis                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IBPI_Controls_C::MoveRight(double Axis)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "MoveRight");

	Params::BPI_Controls_C_MoveRight Parms{};

	Parms.Axis = Axis;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPI_Controls.BPI_Controls_C.Sprint
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_Sprint                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void IBPI_Controls_C::Sprint(bool Param_Sprint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "Sprint");

	Params::BPI_Controls_C_Sprint Parms{};

	Parms.Param_Sprint = Param_Sprint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BPI_Controls.BPI_Controls_C.Stance
// (Public, BlueprintCallable, BlueprintEvent)

void IBPI_Controls_C::Stance()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "Stance");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BPI_Controls.BPI_Controls_C.TestControlNotify
// (Public, BlueprintCallable, BlueprintEvent)

void IBPI_Controls_C::TestControlNotify()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BPI_Controls_C", "TestControlNotify");

	UObject::ProcessEvent(Func, nullptr);
}

}

