///////////////////////////////////////////////////////////////////////////////
// IOSyncModule.h
#pragma once

#include "IOSyncInterfaces.h"
#include "AdsR0.h"
#include <TcLogMark.h>		//#@@# LTW

// parameter ids for TwinCAT module IOSyncModule with disabled code generation
// could be moved to IOSyncServices.h
const PTCID PID_IOSyncModuleAdsPort        = 0x00000002;

class CIOSyncModule 
	: public ITComObject
	, public ITcADI
	, public ITcWatchSource
///<AutoGeneratedContent id="InheritanceList">
	, public ITcCyclic
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
	IOSyncModuleInputs m_Inputs;
	IOSyncModuleOutputs m_Outputs;
	ITcCyclicCallerInfoPtr m_spCyclicCaller;
	ITcRTimePtr m_spRTime;
	IIOSyncInterfacePtr m_spIOSyncIntrf1;
	IIOSyncInterfacePtr m_spIOSyncIntrf2;
	IIOSyncInterfacePtr m_spIOSyncIntrf3;
	IIOSyncInterfacePtr m_spIOSyncIntrf4;
	IIOSyncInterfacePtr m_spIOSyncIntrf5;
	IIOSyncInterfacePtr m_spIOSyncIntrf6;
	IIOSyncInterfacePtr m_spIOSyncIntrf7;
	IIOSyncInterfacePtr m_spIOSyncIntrf8;
	IIOSyncInterfacePtr m_spIOSyncIntrf9;
	IIOSyncInterfacePtr m_spIOSyncIntrf10;
///</AutoGeneratedContent>

	void SubmitAdsReadReq();
	enum 
	{
		invokeIdReadByOidAndPid = 1
	};
	ULONG  m_ReadByOidAndPid;

	// #@@# LTW
	CTcLogMark m_log;

	HRESULT InitIOSyncIntrfPointers();
	void ResetIOSyncIntrfPointers();

	void SetInputReadyFlags();
	void ResetOutputReadyFlags();
	bool IsOutputReady();
	void CountOutputReadyTimeouts();

	bool WaitTillOutputReady(int time_out_usec);
	void DelayUsec(int usec);
	void DelayUsec(void);

};
