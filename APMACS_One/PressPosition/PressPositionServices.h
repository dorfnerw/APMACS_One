///////////////////////////////////////////////////////////////////////////////
// PressPositionServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_PressPosition = 0x3F000000;
#define SRVNAME_PRESSPOSITION "PressPosition"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_PressPositionCPressPosModule = {0x94bc1091,0x676b,0x4998,{0xa5,0xb7,0x96,0x97,0x66,0x54,0xcc,0x00}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_PressPosModuleDefaultAdsPort = 0x00000001;
const PTCID PID_PressPosModuleCounter = 0x00000003;
const PTCID PID_PressPosModuleMyContextId = 0x00000006;
const PTCID PID_PressPosModulePostCyclicCaller = 0x00000004;
const PTCID PID_PressPosModuleIOSyncIntrf1 = 0x00000005;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
#if !defined(_TC_TYPE_C08809EA_7BAB_42E0_81CF_5748C4E9663B_INCLUDED_)
#define _TC_TYPE_C08809EA_7BAB_42E0_81CF_5748C4E9663B_INCLUDED_
enum DriveStatusEnum : SHORT {
	UnknownState = 0,
	SwitchOnDisabled = 1,
	ReadyToSwitchOn = 2,
	SwitchedOn = 3,
	Operational = 4,
	FaultReactionActive = 13,
	Fault = 14,
	Disabled = 7,
	Reset = 8
};
#endif // !defined(_TC_TYPE_C08809EA_7BAB_42E0_81CF_5748C4E9663B_INCLUDED_)

#if !defined(_TC_TYPE_DE9E8508_0D64_4C28_90CB_FED16972CF38_INCLUDED_)
#define _TC_TYPE_DE9E8508_0D64_4C28_90CB_FED16972CF38_INCLUDED_
typedef struct _DriveCommandsStruct
{
	bool Enable;
	bool Disable;
	bool Reset;
	unsigned char reserved1[13];
} DriveCommandsStruct, *PDriveCommandsStruct;
#endif // !defined(_TC_TYPE_DE9E8508_0D64_4C28_90CB_FED16972CF38_INCLUDED_)

#if !defined(_TC_TYPE_484B554E_A552_4431_AC68_AD583306F58F_INCLUDED_)
#define _TC_TYPE_484B554E_A552_4431_AC68_AD583306F58F_INCLUDED_
#pragma pack(push,1)
typedef struct _DriveInputsStruct
{
	USHORT StatusWord;
	LONG PositionActualValue;
	char ModesOfOperationDisplay;
} DriveInputsStruct, *PDriveInputsStruct;
#pragma pack(pop)
#endif // !defined(_TC_TYPE_484B554E_A552_4431_AC68_AD583306F58F_INCLUDED_)

#if !defined(_TC_TYPE_AF45A628_633B_4BB9_B395_1EA508E2E9F4_INCLUDED_)
#define _TC_TYPE_AF45A628_633B_4BB9_B395_1EA508E2E9F4_INCLUDED_
#pragma pack(push,1)
typedef struct _DriveOutputsStruct
{
	USHORT ControlWord;
	LONG TargetPosition;
	char ModesOfOperation;
	LONG TargetVelocity;
	ULONG ProfileAcceleration;
} DriveOutputsStruct, *PDriveOutputsStruct;
#pragma pack(pop)
#endif // !defined(_TC_TYPE_AF45A628_633B_4BB9_B395_1EA508E2E9F4_INCLUDED_)

#pragma pack(push,1)
typedef struct _PressPosModuleInputs
{
	ULONG Value;
	ULONG Status;
	ULONG Data;
	DriveInputsStruct PressDriveInputs;
} PressPosModuleInputs, *PPressPosModuleInputs;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _PressPosModuleOutputs
{
	ULONG Value;
	ULONG Control;
	ULONG Data;
	DriveOutputsStruct PressDriveOutputs;
} PressPosModuleOutputs, *PPressPosModuleOutputs;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _PressPosModuleDebug
{
	SHORT ExeTimeUsec;
	ULONG InputReadyTimeoutCount;
	ULONG OutputReadyTimeoutCount;
} PressPosModuleDebug, *PPressPosModuleDebug;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct _PressPosModulePressDriveVariables
{
	DriveCommandsStruct DriveCommands;
	DriveStatusEnum DriveStatus;
	SHORT VelocityInRPM;
	bool IsRunning;
} PressPosModulePressDriveVariables, *PPressPosModulePressDriveVariables;
#pragma pack(pop)

///</AutoGeneratedContent>



///<AutoGeneratedContent id="DataAreaIDs">
#define ADI_PressPosModuleInputs 0
#define ADI_PressPosModuleOutputs 1
#define ADI_PressPosModuleDebug 3
#define ADI_PressPosModulePressDriveVariables 4
///</AutoGeneratedContent>

///<AutoGeneratedContent id="InterfaceIDs">
#if !defined(_TC_IID_7EBE6026_0379_47C3_97B9_EC238F447164_INCLUDED_)
#define _TC_IID_7EBE6026_0379_47C3_97B9_EC238F447164_INCLUDED_
TCOM_DECL_INTERFACE("7ebe6026-0379-47c3-97b9-ec238f447164", IIOSyncInterface)
#endif // !defined(_TC_IID_7EBE6026_0379_47C3_97B9_EC238F447164_INCLUDED_)

///</AutoGeneratedContent>

///<AutoGeneratedContent id="EventClasses">
///</AutoGeneratedContent>
