///////////////////////////////////////////////////////////////////////////////
// RollFeedServices.h

#pragma once

#include "TcServices.h"

const ULONG DrvID_RollFeed = 0x3F000000;
#define SRVNAME_ROLLFEED "RollFeed"

///<AutoGeneratedContent id="ClassIDs">
const CTCID CID_RollFeedCRollFeedModule = {0xeef5ccea,0x3262,0x477d,{0xae,0xec,0x6f,0x91,0xa0,0x8b,0xcb,0xed}};
///</AutoGeneratedContent>

///<AutoGeneratedContent id="ParameterIDs">
const PTCID PID_RollFeedModuleDefaultAdsPort = 0x00000001;
const PTCID PID_RollFeedModuleCounter = 0x00000003;
const PTCID PID_RollFeedModulePostCyclicCaller = 0x00000004;
///</AutoGeneratedContent>

///<AutoGeneratedContent id="DataTypes">
typedef struct _RollFeedModuleInputs
{
	ULONG Value;
	ULONG Status;
	ULONG Data;
} RollFeedModuleInputs, *PRollFeedModuleInputs;

typedef struct _RollFeedModuleOutputs
{
	ULONG Value;
	ULONG Control;
	ULONG Data;
} RollFeedModuleOutputs, *PRollFeedModuleOutputs;

///</AutoGeneratedContent>



///<AutoGeneratedContent id="DataAreaIDs">
#define ADI_RollFeedModuleInputs 0
#define ADI_RollFeedModuleOutputs 1
///</AutoGeneratedContent>

///<AutoGeneratedContent id="InterfaceIDs">
#if !defined(_TC_IID_9C0AF363_67DF_4054_8D25_E35F780F42E3_INCLUDED_)
#define _TC_IID_9C0AF363_67DF_4054_8D25_E35F780F42E3_INCLUDED_
TCOM_DECL_INTERFACE("9c0af363-67df-4054-8d25-e35f780f42e3", IIOSyncInterface)
#endif // !defined(_TC_IID_9C0AF363_67DF_4054_8D25_E35F780F42E3_INCLUDED_)

///</AutoGeneratedContent>

///<AutoGeneratedContent id="EventClasses">
///</AutoGeneratedContent>
