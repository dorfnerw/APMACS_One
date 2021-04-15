///////////////////////////////////////////////////////////////////////////////
// RollFeedModule.h
#pragma once

#include "RollFeedInterfaces.h"
#include "AdsR0.h"
#include <TcLogMark.h>	// #@@# LTW

// parameter ids for TwinCAT module RollFeedModule with disabled code generation
// could be moved to RollFeedServices.h
const PTCID PID_RollFeedModuleAdsPort        = 0x00000002;

class CRollFeedModule 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
	, public ITcPostCyclic
	, public IIOSyncInterface
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

	CRollFeedModule();
	virtual	~CRollFeedModule();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

	// ITcPostCyclic
	virtual HRESULT TCOMAPI PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

	// IIOSyncInterface
	virtual bool TCOMAPI GetInputReadyFlag();
	virtual void TCOMAPI SetInputReadyFlag();
	virtual void TCOMAPI ResetInputReadyFlag();
	virtual void TCOMAPI CountInputReadyTimeout();
	virtual bool TCOMAPI GetOutputReadyFlag();
	virtual void TCOMAPI SetOutputReadyFlag();
	virtual void TCOMAPI ResetOutputReadyFlag();
	virtual void TCOMAPI CountOutputReadyTimeout();

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
	RollFeedModuleInputs m_Inputs;
	RollFeedModuleOutputs m_Outputs;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	ITcPostCyclicCallerInfoPtr m_spPostCyclicCaller;
///</AutoGeneratedContent>

	void SubmitAdsReadReq();
	enum 
	{
		invokeIdReadByOidAndPid = 1
	};
	ULONG  m_ReadByOidAndPid;

	//#@@# LTW
//	int m_ContextID;

	bool scheduleFlag;
	bool inputReadyFlag;
	bool outputReadyFlag;
	int inputReadyTimeout;
	int outputReadyTimeout;

	CTcLogMark m_log;

	HRESULT AddModuleToPostCyclicCaller();
	VOID RemoveModuleFromPosyCyclicCaller();

	bool WaitTillInputReady(int time_out_usec);
	void DelayUsec(int usec);
	void DelayUsec(void);

};
