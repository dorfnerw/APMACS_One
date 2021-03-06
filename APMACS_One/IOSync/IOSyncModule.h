///////////////////////////////////////////////////////////////////////////////
// IOSyncModule.h
#pragma once

#include "IOSyncInterfaces.h"
#include "AdsR0.h"
#include <TcLogMark.h>		//#@@# LTW

// parameter ids for TwinCAT module IOSyncModule with disabled code generation
// could be moved to IOSyncServices.h
const PTCID PID_IOSyncModuleAdsPort        = 0x00000002;

const int NUM_IO_SYNC = 10;

struct IOSyncData
{
	bool syncFlag;

	bool inputReadyFlag;
	bool outputReadyFlag;

	int inputReadyTimeout;
	int outputReadyTimeout;

};

class CIOSyncModule 
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

	CIOSyncModule();
	virtual	~CIOSyncModule();


///<AutoGeneratedContent id="InterfaceMembers">
	// ITcCyclic
	virtual HRESULT TCOMAPI CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

	// ITcPostCyclic
	virtual HRESULT TCOMAPI PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context);

	// IIOSyncInterface
	virtual SHORT TCOMAPI AddModuleToIOSync();
	virtual void TCOMAPI RemoveModuleFromIOSync(SHORT index);
	virtual bool TCOMAPI GetInputReadyFlag(SHORT index);
	virtual void TCOMAPI SetInputReadyFlag(SHORT index);
	virtual void TCOMAPI ResetInputReadyFlag(SHORT index);
	virtual bool TCOMAPI GetOutputReadyFlag(SHORT index);
	virtual void TCOMAPI SetOutputReadyFlag(SHORT index);
	virtual void TCOMAPI ResetOutputReadyFlag(SHORT index);
	virtual LONG TCOMAPI GetInputReadyTimeout(SHORT index);
	virtual void TCOMAPI CountInputReadyTimeout(SHORT index);
	virtual void TCOMAPI CountOutputReadyTimeout(SHORT index);
	virtual LONG TCOMAPI GetOutputReadyTimeout(SHORT index);

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
	typedef _TCOM_SMARTDATAPTR<LONGLONG> LINTDataPtr;

	TcTraceLevel m_TraceLevelMax;
	WORD m_DefaultAdsPort;
	WORD m_ContextAdsPort;
	ULONG m_Counter;
	SHORT m_MyContextId;
	IOSyncModuleInputs m_Inputs;
	IOSyncModuleOutputs m_Outputs;
	IOSyncModuleDebug m_Debug;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	ITcRTimePtr m_spRTime;
	ITcPostCyclicCallerInfoPtr m_spPostCyclicCaller;
	LINTDataPtr m_spCurPentTimePtr;
///</AutoGeneratedContent>

	void SubmitAdsReadReq();
	enum 
	{
		invokeIdReadByOidAndPid = 1
	};
	ULONG  m_ReadByOidAndPid;

	// #@@# LTW
	HRESULT InitDataPointer();
	VOID DeinitDataPointer();

	HRESULT AddModuleToPostCyclicCaller();
	VOID RemoveModuleFromPosyCyclicCaller();

	CTcLogMark m_log;
	bool WaitTillOutputReadyOpt;
	IOSyncData IOSyncList[NUM_IO_SYNC];

	bool WaitTillOutputReady(int time_out_usec);
	bool IsOutputReady();

	void DelayUsec(int usec);
	void DelayUsec(void);
};
