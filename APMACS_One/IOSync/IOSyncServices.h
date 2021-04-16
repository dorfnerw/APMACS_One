///////////////////////////////////////////////////////////////////////////////
// IOSyncServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_IOSync = 0x3F000000;
#define SRVNAME_IOSYNC "IOSync"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_IOSyncCIOSyncModule = {0x9db963ca,0x876d,0x44a3,{0x83,0x41,0x41,0xd1,0xdb,0xe2,0x89,0xf2}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_IOSyncModuleDefaultAdsPort = 0x00000001;
const PTCID PID_IOSyncModuleCounter = 0x00000003;
const PTCID PID_IOSyncModuleMyContextId = 0x0000000F;
const PTCID PID_IOSyncModuleRTime = 0x00000004;
const PTCID PID_IOSyncModuleIOSyncIntrf1 = 0x00000005;
const PTCID PID_IOSyncModuleIOSyncIntrf2 = 0x00000006;
const PTCID PID_IOSyncModuleIOSyncIntrf3 = 0x00000007;
const PTCID PID_IOSyncModuleIOSyncIntrf4 = 0x00000008;
const PTCID PID_IOSyncModuleIOSyncIntrf5 = 0x00000009;
const PTCID PID_IOSyncModuleIOSyncIntrf6 = 0x0000000A;
const PTCID PID_IOSyncModuleIOSyncIntrf7 = 0x0000000B;
const PTCID PID_IOSyncModuleIOSyncIntrf8 = 0x0000000C;
const PTCID PID_IOSyncModuleIOSyncIntrf9 = 0x0000000D;
const PTCID PID_IOSyncModuleIOSyncIntrf10 = 0x0000000E;
const PTCID PID_IOSyncModulePostCyclicCaller = 0x00000010;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
typedef struct _IOSyncModuleInputs
{
	ULONG Value;
	ULONG Status;
	ULONG Data;
} IOSyncModuleInputs, *PIOSyncModuleInputs;

typedef struct _IOSyncModuleOutputs
{
	ULONG Value;
	ULONG Control;
	ULONG Data;
} IOSyncModuleOutputs, *PIOSyncModuleOutputs;

typedef struct _IOSyncModuleDebug
{
	SHORT DelayUsec;
} IOSyncModuleDebug, *PIOSyncModuleDebug;

///</AutoGeneratedContent>



///<AutoGeneratedContent id="DataAreaIDs">
#define ADI_IOSyncModuleInputs 0
#define ADI_IOSyncModuleOutputs 1
#define ADI_IOSyncModuleDebug 3
///</AutoGeneratedContent>

///<AutoGeneratedContent id="InterfaceIDs">
#if !defined(_TC_IID_9C0AF363_67DF_4054_8D25_E35F780F42E3_INCLUDED_)
#define _TC_IID_9C0AF363_67DF_4054_8D25_E35F780F42E3_INCLUDED_
TCOM_DECL_INTERFACE("9c0af363-67df-4054-8d25-e35f780f42e3", IIOSyncInterface)
#endif // !defined(_TC_IID_9C0AF363_67DF_4054_8D25_E35F780F42E3_INCLUDED_)

///</AutoGeneratedContent>

///<AutoGeneratedContent id="EventClasses">
///</AutoGeneratedContent>
