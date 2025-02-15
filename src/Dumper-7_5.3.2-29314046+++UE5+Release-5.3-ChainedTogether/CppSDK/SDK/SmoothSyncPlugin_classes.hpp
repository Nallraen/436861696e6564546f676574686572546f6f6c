#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SmoothSyncPlugin

#include "Basic.hpp"

#include "SmoothSyncPlugin_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// Class SmoothSyncPlugin.SmoothSync
// 0x02C0 (0x0360 - 0x00A0)
class alignas(0x10) USmoothSync final : public UActorComponent
{
public:
	uint8                                         Pad_19C2[0x58];                                    // 0x00A0(0x0058)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         InterpolationBackTime;                             // 0x00F8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ExtrapolationMode                             ExtrapolationMode;                                 // 0x00FC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          UseExtrapolationTimeLimit;                         // 0x00FD(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19C3[0x2];                                     // 0x00FE(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         ExtrapolationTimeLimit;                            // 0x0100(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          UseExtrapolationDistanceLimit;                     // 0x0104(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19C4[0x3];                                     // 0x0105(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         ExtrapolationDistanceLimit;                        // 0x0108(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SendPositionThreshold;                             // 0x010C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SendRotationThreshold;                             // 0x0110(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SendScaleThreshold;                                // 0x0114(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SendVelocityThreshold;                             // 0x0118(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         SendAngularVelocityThreshold;                      // 0x011C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ReceivedPositionThreshold;                         // 0x0120(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ReceivedRotationThreshold;                         // 0x0124(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PositionSnapThreshold;                             // 0x0128(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         RotationSnapThreshold;                             // 0x012C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ScaleSnapThreshold;                                // 0x0130(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         TimeSmoothing;                                     // 0x0134(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         PositionLerpSpeed;                                 // 0x0138(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         RotationLerpSpeed;                                 // 0x013C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         ScaleLerpSpeed;                                    // 0x0140(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ESyncMode                                     SyncPosition;                                      // 0x0144(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ESyncMode                                     SyncRotation;                                      // 0x0145(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ESyncMode                                     SyncScale;                                         // 0x0146(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ESyncMode                                     SyncVelocity;                                      // 0x0147(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	ESyncMode                                     SyncAngularVelocity;                               // 0x0148(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          SyncMovementMode;                                  // 0x0149(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsPositionCompressed;                              // 0x014A(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsRotationCompressed;                              // 0x014B(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsScaleCompressed;                                 // 0x014C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsVelocityCompressed;                              // 0x014D(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsAngularVelocityCompressed;                       // 0x014E(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19C5[0x1];                                     // 0x014F(0x0001)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         SendRate;                                          // 0x0150(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          IsUsingOriginRebasing;                             // 0x0154(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          AlwaysSendOrigin;                                  // 0x0155(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	bool                                          SyncOwnershipChange;                               // 0x0156(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19C6[0x91];                                    // 0x0157(0x0091)(Fixing Size After Last Property [ Dumper-7 ])
	class USceneComponent*                        RealComponentToSync;                               // 0x01E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19C7[0x18];                                    // 0x01F0(0x0018)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         InterpolationTime;                                 // 0x0208(0x0004)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19C8[0x134];                                   // 0x020C(0x0134)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         AtRestPositionThreshold;                           // 0x0340(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	float                                         AtRestRotationThreshold;                           // 0x0344(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash, NativeAccessSpecifierPublic)
	uint8                                         Pad_19C9[0x18];                                    // 0x0348(0x0018)(Fixing Struct Size After Last Property [ Dumper-7 ])

public:
	void ClearBuffer();
	void ClientSendsTransformToServer(const TArray<uint8>& Value);
	void EnableSmoothSync(bool Enable);
	void ForceStateSendNextFrame();
	void ServerSendsTransformToEveryone(const TArray<uint8>& Value);
	void SetSceneComponentToSync(class USceneComponent* TheComponent);
	void SmoothSyncEnableClientToServer(bool Enable);
	void SmoothSyncEnableServerToClients(bool Enable);
	void SmoothSyncTeleportClientToServer(const struct FVector3f& Position, const struct FVector3f& Rotation, const struct FVector3f& Scale, float TempOwnerTime);
	void SmoothSyncTeleportServerToClients(const struct FVector3f& Position, const struct FVector3f& Rotation, const struct FVector3f& Scale, float TempOwnerTime);
	void Teleport();

public:
	static class UClass* StaticClass()
	{
		return StaticClassImpl<"SmoothSync">();
	}
	static class USmoothSync* GetDefaultObj()
	{
		return GetDefaultObjImpl<USmoothSync>();
	}
};
static_assert(alignof(USmoothSync) == 0x000010, "Wrong alignment on USmoothSync");
static_assert(sizeof(USmoothSync) == 0x000360, "Wrong size on USmoothSync");
static_assert(offsetof(USmoothSync, InterpolationBackTime) == 0x0000F8, "Member 'USmoothSync::InterpolationBackTime' has a wrong offset!");
static_assert(offsetof(USmoothSync, ExtrapolationMode) == 0x0000FC, "Member 'USmoothSync::ExtrapolationMode' has a wrong offset!");
static_assert(offsetof(USmoothSync, UseExtrapolationTimeLimit) == 0x0000FD, "Member 'USmoothSync::UseExtrapolationTimeLimit' has a wrong offset!");
static_assert(offsetof(USmoothSync, ExtrapolationTimeLimit) == 0x000100, "Member 'USmoothSync::ExtrapolationTimeLimit' has a wrong offset!");
static_assert(offsetof(USmoothSync, UseExtrapolationDistanceLimit) == 0x000104, "Member 'USmoothSync::UseExtrapolationDistanceLimit' has a wrong offset!");
static_assert(offsetof(USmoothSync, ExtrapolationDistanceLimit) == 0x000108, "Member 'USmoothSync::ExtrapolationDistanceLimit' has a wrong offset!");
static_assert(offsetof(USmoothSync, SendPositionThreshold) == 0x00010C, "Member 'USmoothSync::SendPositionThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, SendRotationThreshold) == 0x000110, "Member 'USmoothSync::SendRotationThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, SendScaleThreshold) == 0x000114, "Member 'USmoothSync::SendScaleThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, SendVelocityThreshold) == 0x000118, "Member 'USmoothSync::SendVelocityThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, SendAngularVelocityThreshold) == 0x00011C, "Member 'USmoothSync::SendAngularVelocityThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, ReceivedPositionThreshold) == 0x000120, "Member 'USmoothSync::ReceivedPositionThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, ReceivedRotationThreshold) == 0x000124, "Member 'USmoothSync::ReceivedRotationThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, PositionSnapThreshold) == 0x000128, "Member 'USmoothSync::PositionSnapThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, RotationSnapThreshold) == 0x00012C, "Member 'USmoothSync::RotationSnapThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, ScaleSnapThreshold) == 0x000130, "Member 'USmoothSync::ScaleSnapThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, TimeSmoothing) == 0x000134, "Member 'USmoothSync::TimeSmoothing' has a wrong offset!");
static_assert(offsetof(USmoothSync, PositionLerpSpeed) == 0x000138, "Member 'USmoothSync::PositionLerpSpeed' has a wrong offset!");
static_assert(offsetof(USmoothSync, RotationLerpSpeed) == 0x00013C, "Member 'USmoothSync::RotationLerpSpeed' has a wrong offset!");
static_assert(offsetof(USmoothSync, ScaleLerpSpeed) == 0x000140, "Member 'USmoothSync::ScaleLerpSpeed' has a wrong offset!");
static_assert(offsetof(USmoothSync, SyncPosition) == 0x000144, "Member 'USmoothSync::SyncPosition' has a wrong offset!");
static_assert(offsetof(USmoothSync, SyncRotation) == 0x000145, "Member 'USmoothSync::SyncRotation' has a wrong offset!");
static_assert(offsetof(USmoothSync, SyncScale) == 0x000146, "Member 'USmoothSync::SyncScale' has a wrong offset!");
static_assert(offsetof(USmoothSync, SyncVelocity) == 0x000147, "Member 'USmoothSync::SyncVelocity' has a wrong offset!");
static_assert(offsetof(USmoothSync, SyncAngularVelocity) == 0x000148, "Member 'USmoothSync::SyncAngularVelocity' has a wrong offset!");
static_assert(offsetof(USmoothSync, SyncMovementMode) == 0x000149, "Member 'USmoothSync::SyncMovementMode' has a wrong offset!");
static_assert(offsetof(USmoothSync, IsPositionCompressed) == 0x00014A, "Member 'USmoothSync::IsPositionCompressed' has a wrong offset!");
static_assert(offsetof(USmoothSync, IsRotationCompressed) == 0x00014B, "Member 'USmoothSync::IsRotationCompressed' has a wrong offset!");
static_assert(offsetof(USmoothSync, IsScaleCompressed) == 0x00014C, "Member 'USmoothSync::IsScaleCompressed' has a wrong offset!");
static_assert(offsetof(USmoothSync, IsVelocityCompressed) == 0x00014D, "Member 'USmoothSync::IsVelocityCompressed' has a wrong offset!");
static_assert(offsetof(USmoothSync, IsAngularVelocityCompressed) == 0x00014E, "Member 'USmoothSync::IsAngularVelocityCompressed' has a wrong offset!");
static_assert(offsetof(USmoothSync, SendRate) == 0x000150, "Member 'USmoothSync::SendRate' has a wrong offset!");
static_assert(offsetof(USmoothSync, IsUsingOriginRebasing) == 0x000154, "Member 'USmoothSync::IsUsingOriginRebasing' has a wrong offset!");
static_assert(offsetof(USmoothSync, AlwaysSendOrigin) == 0x000155, "Member 'USmoothSync::AlwaysSendOrigin' has a wrong offset!");
static_assert(offsetof(USmoothSync, SyncOwnershipChange) == 0x000156, "Member 'USmoothSync::SyncOwnershipChange' has a wrong offset!");
static_assert(offsetof(USmoothSync, RealComponentToSync) == 0x0001E8, "Member 'USmoothSync::RealComponentToSync' has a wrong offset!");
static_assert(offsetof(USmoothSync, InterpolationTime) == 0x000208, "Member 'USmoothSync::InterpolationTime' has a wrong offset!");
static_assert(offsetof(USmoothSync, AtRestPositionThreshold) == 0x000340, "Member 'USmoothSync::AtRestPositionThreshold' has a wrong offset!");
static_assert(offsetof(USmoothSync, AtRestRotationThreshold) == 0x000344, "Member 'USmoothSync::AtRestRotationThreshold' has a wrong offset!");

}

