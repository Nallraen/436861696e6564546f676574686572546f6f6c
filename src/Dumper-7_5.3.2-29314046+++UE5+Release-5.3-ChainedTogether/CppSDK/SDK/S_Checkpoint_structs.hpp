#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: S_Checkpoint

#include "Basic.hpp"


namespace SDK
{

// UserDefinedStruct S_Checkpoint.S_Checkpoint
// 0x0018 (0x0018 - 0x0000)
struct FS_Checkpoint final
{
public:
	class FString                                 CheckpointName_2_3ED09233423B63DF448DCCB839500F5E; // 0x0000(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	int32                                         Seconds_6_58FD30484D1082D8916F699A553BD81C;        // 0x0010(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(FS_Checkpoint) == 0x000008, "Wrong alignment on FS_Checkpoint");
static_assert(sizeof(FS_Checkpoint) == 0x000018, "Wrong size on FS_Checkpoint");
static_assert(offsetof(FS_Checkpoint, CheckpointName_2_3ED09233423B63DF448DCCB839500F5E) == 0x000000, "Member 'FS_Checkpoint::CheckpointName_2_3ED09233423B63DF448DCCB839500F5E' has a wrong offset!");
static_assert(offsetof(FS_Checkpoint, Seconds_6_58FD30484D1082D8916F699A553BD81C) == 0x000010, "Member 'FS_Checkpoint::Seconds_6_58FD30484D1082D8916F699A553BD81C' has a wrong offset!");

}

