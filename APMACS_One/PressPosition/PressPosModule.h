///////////////////////////////////////////////////////////////////////////////
// PressPosModule.h
#pragma once

#include "PressPositionInterfaces.h"
#include "AdsR0.h"
#include <TcLogMark.h>	// #@@# LTW
#include "MotionControlFunctions.h"

// parameter ids for TwinCAT module PressPosModule with disabled code generation
// could be moved to PressPositionServices.h
const PTCID PID_PressPosModuleAdsPort        = 0x00000002;

class CPressPosModule 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
	, public ITcPostCyclic
///</AutoGeneratedContent>
	, public CAdsR0FifoPort
{
public:
	DECLARE_IUNKNOWN()
	DECLARE_IPERSIST_LIB()
	DECLARE_ITCOMOBJECT_LOCKOP()
	DECLARE_ITCADI()
	DECLARE_ITCWATCHSOURCE()
	DECLARE_OBJPARAWATCH_MAP()
	DECLARE_OBJDATAAREA_MAP()

	CPressPosModule();
	virtual	~CPressPosModule();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

	// ITcPostCyclic
	virtual HRESULT TCOMAPI PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

///</AutoGeneratedContent>

	// CAds
	virtual	void	AdsReadWriteInd
	(
		AmsAddr& rAddr, 
		ULONG invokeId, 
		ULONG indexGroup,
		ULONG indexOffset, 
		ULONG cbReadLength, 
		ULONG cbWriteLength, 
		PVOID pData 
	);

	virtual void AdsReadCon
	(
		AmsAddr& rAddr, 
		ULONG invokeId, 
		ULONG result, 
		ULONG cbLength, 
		PVOID pData
	);

protected:
	DECLARE_ITCOMOBJECT_SETSTATE();

	HRESULT AddModuleToCaller();
	VOID RemoveModuleFromCaller();

	// Tracing
	CTcTrace m_Trace;

///<AutoGeneratedContent id="Members">
	TcTraceLevel m_TraceLevelMax;
	WORD m_DefaultAdsPort;
	WORD m_ContextAdsPort;
	ULONG m_Counter;
	SHORT m_MyContextId;
	PressPosModuleInputs m_Inputs;
	PressPosModuleOutputs m_Outputs;
	PressPosModuleDebug m_Debug;
	PressPosModulePressDriveVariables m_PressDriveVariables;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	ITcPostCyclicCallerInfoPtr m_spPostCyclicCaller;
	IIOSyncInterfacePtr m_spIOSyncIntrf1;
///</AutoGeneratedContent>

	void SubmitAdsReadReq();
	enum 
	{
		invokeIdReadByOidAndPid = 1
	};
	ULONG  m_ReadByOidAndPid;

	//#@@# LTW
	HRESULT AddModuleToPostCyclicCaller();
	VOID RemoveModuleFromPosyCyclicCaller();

	CTcLogMark m_log;
	short syncId;

	HRESULT AddModuleToIOSync();
	void RemoveModuleFromIOSync();
	bool IsAddedToIOSync();
	bool WaitTillInputReady(int time_out_usec);

	void DelayUsec(int usec);
	void DelayUsec(void);

	//WPD
	MotionControlFunctions PressDriveMotionControl;
};