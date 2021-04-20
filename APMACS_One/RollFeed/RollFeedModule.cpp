///////////////////////////////////////////////////////////////////////////////
// RollFeedModule.cpp
#include "TcPch.h"
#pragma hdrstop

#include "RollFeedModule.h"
#include "RollFeedModuleAds.h"
#include "RollFeedVersion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CRollFeedModule
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CRollFeedModule
BEGIN_INTERFACE_MAP(CRollFeedModule)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
	INTERFACE_ENTRY(IID_ITcPostCyclic, ITcPostCyclic)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_IPERSIST_LIB(CRollFeedModule, VID_RollFeed, CID_RollFeedCRollFeedModule)
IMPLEMENT_ITCOMOBJECT(CRollFeedModule)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CRollFeedModule)
IMPLEMENT_ITCADI(CRollFeedModule)
IMPLEMENT_ITCWATCHSOURCE(CRollFeedModule)

///////////////////////////////////////////////////////////////////////////////
// Set parameters of CRollFeedModule 
BEGIN_SETOBJPARA_MAP(CRollFeedModule)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_VALUE(PID_RollFeedModuleDefaultAdsPort, m_DefaultAdsPort)
	SETOBJPARA_VALUE(PID_Ctx_AdsPort, m_ContextAdsPort)
	SETOBJPARA_VALUE(PID_RollFeedModuleCounter, m_Counter)
	SETOBJPARA_VALUE(PID_RollFeedModuleMyContextId, m_MyContextId)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
	SETOBJPARA_ITFPTR(PID_RollFeedModulePostCyclicCaller, m_spPostCyclicCaller)
	SETOBJPARA_ITFPTR(PID_RollFeedModuleIOSyncIntrf1, m_spIOSyncIntrf1)
	SETOBJPARA_DATAPTR(PID_RollFeedModuleModPosBitPtr, m_spModPosBitPtr)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CRollFeedModule 
BEGIN_GETOBJPARA_MAP(CRollFeedModule)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_VALUE(PID_RollFeedModuleDefaultAdsPort, m_DefaultAdsPort)
	GETOBJPARA_VALUE(PID_Ctx_AdsPort, m_ContextAdsPort)
	GETOBJPARA_VALUE(PID_RollFeedModuleCounter, m_Counter)
	GETOBJPARA_VALUE(PID_RollFeedModuleMyContextId, m_MyContextId)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
	GETOBJPARA_ITFPTR(PID_RollFeedModulePostCyclicCaller, m_spPostCyclicCaller)
	GETOBJPARA_ITFPTR(PID_RollFeedModuleIOSyncIntrf1, m_spIOSyncIntrf1)
///</AutoGeneratedContent>
	GETOBJPARA_TYPE_CODE(PID_RollFeedModuleAdsPort, WORD, *p = AmsGetPort())
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CRollFeedModule
BEGIN_OBJPARAWATCH_MAP(CRollFeedModule)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
	OBJPARAWATCH_VALUE(PID_RollFeedModuleCounter, m_Counter)
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CRollFeedModule
BEGIN_OBJDATAAREA_MAP(CRollFeedModule)
///<AutoGeneratedContent id="ObjectDataAreaMap">
	OBJDATAAREA_VALUE(ADI_RollFeedModuleInputs, m_Inputs)
	OBJDATAAREA_VALUE(ADI_RollFeedModuleOutputs, m_Outputs)
	OBJDATAAREA_VALUE(ADI_RollFeedModuleDebug, m_Debug)
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CRollFeedModule::CRollFeedModule()
	: m_Trace(m_TraceLevelMax, m_spSrv)
	, m_log(0x12C)							//#@@# LTW
{
///<AutoGeneratedContent id="MemberInitialization">
	m_TraceLevelMax = tlAlways;
	m_DefaultAdsPort = 0;
	m_ContextAdsPort = 0;
	m_Counter = 0;
	m_MyContextId = 0;
	memset(&m_Inputs, 0, sizeof(m_Inputs));
	memset(&m_Outputs, 0, sizeof(m_Outputs));
	memset(&m_Debug, 0, sizeof(m_Debug));
///</AutoGeneratedContent>

	syncId = -1;				//#@@# LTW
	m_Debug.ExeTimeUsec = 10;
}

///////////////////////////////////////////////////////////////////////////////
CRollFeedModule::~CRollFeedModule() 
{
}

///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CRollFeedModule)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CRollFeedModule::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	hr = SUCCEEDED(hr) ? InitAmsPort(m_spSrv, m_DefaultAdsPort) : hr;

	// #@@# LTW Initialize log mark
	//OTCID objId = TcGetObjectId();
	//if (objId == 0x01010020)
	//{
	//	m_ContextID = 2;
	//}
	//else
	//{
	//	m_ContextID = 3;
	//}
	//m_log.SetContextId(m_ContextID);
	//hr = m_log.InitLogMark(m_spSrv);
	m_log.SetContextId(m_MyContextId);	//-- NOTE: 0.1.0.1 Specify ContextId for RealTimeMonitor softare for each instance. 
	hr = m_log.InitLogMark(m_spSrv);

	// cleanup on failure
	if (FAILED(hr))
	{
		ShutdownAmsPort();
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to OP
//
// Register with other TwinCAT objects
HRESULT CRollFeedModule::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	// TODO: Add any additional initialization
	// #@@# LTW get reference to TC-RTime-Instance
	m_spRTime.SetOID(OID_TCRTIME_CTRL);														//-- set object ID
	hr = FAILED(hr) ? hr : m_spSrv->TcQuerySmartObjectInterface(m_spRTime);					//-- initialize pointer
	hr = FAILED(hr) ? hr : AddModuleToPostCyclicCaller();
	hr = FAILED(hr) ? hr : AddModuleToIOSync();

	// Initialize data pointer
	hr = FAILED(hr) ? hr : InitDataPointer();

	// If following call is successful the CycleUpdate method will be called, 
	// possibly even before this method has been left.
//	hr = FAILED(hr) ? hr : AddModuleToCaller();			//#@@# LTW

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
//		RemoveModuleFromCaller();	//#@@# LTW

		// #@@# LTW
		m_spRTime = NULL;
		RemoveModuleFromPosyCyclicCaller();
		RemoveModuleFromIOSync();
		
		DeinitDataPointer();


	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CRollFeedModule::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;

//	RemoveModuleFromCaller();	//#@@# LTW

	// #@@# LTW
	m_spRTime = NULL;
	RemoveModuleFromPosyCyclicCaller();
	RemoveModuleFromIOSync();

	DeinitDataPointer();

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CRollFeedModule::SetObjStateSP()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	ShutdownAmsPort();

	// #@@# LTW De-initialize log mark
	m_log.ReleaseLogMark();

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
HRESULT CRollFeedModule::InitDataPointer()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	if(m_spModPosBitPtr.HasOID()) hr = FAILED(hr) ? hr : m_spModPosBitPtr.Init(m_spSrv);	//-- If data pointer is not mapped for object instance, do not initialize pointer. otherwise, TC triggers invalid object paramters when transitioning to OP state

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
VOID CRollFeedModule::DeinitDataPointer()
{
	m_Trace.Log(tlVerbose, FENTERA);

	m_spModPosBitPtr = NULL;

	m_Trace.Log(tlVerbose, FLEAVEA);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CRollFeedModule::AddModuleToCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	if (m_spCyclicCaller.HasOID())
	{
		if (SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spCyclicCaller)))
		{
			if (FAILED(hr = m_spCyclicCaller->AddModule(m_spCyclicCaller, THIS_CAST(ITcCyclic))))
			{
				m_spCyclicCaller = NULL;
			}
		}
	}
	else
	{
		hr = ADS_E_INVALIDOBJID;
		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
VOID CRollFeedModule::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	if (m_spCyclicCaller)
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller = NULL;
	m_Trace.Log(tlVerbose, FLEAVEA);
}

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
HRESULT CRollFeedModule::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;

	// handle pending ADS indications and confirmations
	CheckOrders();

	// TODO: Additional evaluation of input from ADS indication or confirmations

	// TODO: Submit your ADS requests 
	ULONGLONG cnt = 0;
	if (SUCCEEDED(ipTask->GetCycleCounter(&cnt)))
	{
		if (cnt % 100 == 0)
		{
			SubmitAdsReadReq();
		}
	}

	// TODO: Replace the sample with your cyclic code
	m_Counter++;
	//m_Counter+= (1+m_Inputs.Value);
	//m_Outputs.Value=m_Counter;

	return hr;
}
///</AutoGeneratedContent>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HRESULT CRollFeedModule::AddModuleToPostCyclicCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	if (m_spPostCyclicCaller.HasOID())
	{
		if (SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spPostCyclicCaller)))
		{
			if (FAILED(hr = m_spPostCyclicCaller->AddPostModule(m_spPostCyclicCaller, THIS_CAST(ITcPostCyclic))))
			{
				m_spPostCyclicCaller = NULL;
			}
		}
	}
	else
	{
		hr = ADS_E_INVALIDOBJID;
		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

VOID CRollFeedModule::RemoveModuleFromPosyCyclicCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);
	if (m_spPostCyclicCaller)
	{
		m_spPostCyclicCaller->RemovePostModule(m_spPostCyclicCaller);
	}
	m_spPostCyclicCaller = NULL;
	m_Trace.Log(tlVerbose, FLEAVEA);
}


///<AutoGeneratedContent id="ImplementationOf_ITcPostCyclic">
//-- NOTE: 0.0.0.1 backup
//HRESULT CRollFeedModule::PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
//{
//	HRESULT hr = E_NOTIMPL;
//	bool result = false;
//
//	//-- Wait till IO sync module indicates that input read is completed. ---
//	result = WaitTillInputReady(125);		//-- 100usec
//	if (result)
//	{
//		//-- Reset input ready flag for next cycle  ---
//		ResetInputReadyFlag();			
//
//
//
//
//		//-- This is Logic execution -----
//		m_log.LogStart(2, 2);
//		DelayUsec(30);							//-- 30 usec 
//		m_log.LogStop(2, 2);
//		//-------------------------------
//
//
//
//		//-- Indicate IO sync module that TCOM module has completed logic code execution and outputs are ready ---
//		SetOutputReadyFlag();
//
//
//		//ResetInputReadyFlag();			//-- reset input flag at the end of cycle
//	}
//	else
//	{
//		//-- Count number of time out ---
//		CountInputReadyTimeout();
//	}
//
//	return hr;
//}
HRESULT CRollFeedModule::PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = E_NOTIMPL;
	bool result = false;

	//scheduleFlag = true;
	//ResetInputReadyFlag();				//-- NOTE: 0-0-0-1 reaset input ready flag from prev cycle. input ready timeout frequently incremented when task is running twice slower than IO sync.

	//-- Wait till IO sync module indicates that input read is completed. ---
	result = WaitTillInputReady(60);		//-- usec
	if (result)
	{
		//-- Reset input ready flag for this cycle  ---
		//ResetInputReadyFlag();			

		//-- This test is for Feed A only
		//if (m_MyContextId == 2)
		//{
		//	if (m_Inputs.TestInputBit0) m_log.LogMark(4, 4);
		//}


		//-- This is Logic execution --------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------------------------
		m_log.LogStart(2, 2);

		if (m_spModPosBitPtr != NULL)
		{
			m_Inputs.ModPosBitStart = *m_spModPosBitPtr;
		}

		DelayUsec(m_Debug.ExeTimeUsec);							//-- 30 usec 


		if (m_spModPosBitPtr != NULL)
		{
			m_Inputs.ModPosBitEnd = *m_spModPosBitPtr;
		}

		////-- This test is for Feed A only
		//if (m_MyContextId == 2)
		//{
		//	if ((modcount % 100) == 0)
		//	{
		//		m_Outputs.TestOutputBit0 = !m_Outputs.TestOutputBit0;		//-- Test bit 0
		//		
		//	}

		//	if (m_Outputs.TestOutputBit0) m_log.LogMark(3, 3);

		//	modcount++;
		//}
		m_log.LogStop(2, 2);
		//-----------------------------------------------------------------------------------------------------------



		//-- Indicate IO sync module that TCOM module has completed logic code execution and outputs are ready ---
		if (IsAddedToIOSync()) m_spIOSyncIntrf1->SetOutputReadyFlag(syncId);
		if (IsAddedToIOSync()) m_spIOSyncIntrf1->ResetInputReadyFlag(syncId);			//-- reset input flag for this cycle
	}
	else
	{
		//-- Count number of time out ---
		if (IsAddedToIOSync()) m_spIOSyncIntrf1->CountInputReadyTimeout(syncId);
	}

	if (IsAddedToIOSync()) m_Debug.InputReadyTimeoutCount = m_spIOSyncIntrf1->GetInputReadyTimeout(syncId);		//-- NOTE: 0.1.0.1 Added for debugging
	if (IsAddedToIOSync()) m_Debug.OutputReadyTimeoutCount = m_spIOSyncIntrf1->GetOutputReadyTimeout(syncId);		//-- NOTE: 0.1.0.1 Added for debugging

	//scheduleFlag = false;

	return hr;
}
///</AutoGeneratedContent>

HRESULT CRollFeedModule::AddModuleToIOSync()
{

	//m_Trace.Log(tlVerbose, FENTERA);

	//-- In Interface Pointer tab under TMI dialog, if the pointer is initialized to TCOM object but the object is no longer valid (because you added IOSync Interface and it changes interface GUID), 
	//-- IO Sync object shall not be able to enter OP mode and TC program could not run. You need to make sure to remove existing IO SYNC interface in TCOM and then add IO SYNC Interface again. 
	//-- To be able to see IO SYNC interface defined in IOSync C++ project from Feed C++ project, add IO SYNC interface under IOSYNC implemented interface first so that it appears in TYPE SYSTEM under SYSTEM.
	HRESULT hr = S_OK;
	if (!IsAddedToIOSync())
	{
		if (m_spIOSyncIntrf1.HasOID())
		{
			hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf1);
			if (hr == S_FALSE) m_spIOSyncIntrf1 = NULL;
		}

		if (m_spIOSyncIntrf1 != NULL)
		{
			syncId = m_spIOSyncIntrf1->AddModuleToIOSync();
		}
	}
	//-- if object ID is not set for the pointer in TMC file, pointer has no object ID and it will not transition to OP state and TC program wont run
	//if (m_spIOSyncIntrf1.HasOID())
	//{
	//	hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf1);
	//}
	//else
	//{
	//	hr = ADS_E_INVALIDOBJID;
	//	SUCCEEDED_DBGT(hr, "Invalid OID specified for intrf pointer");	
	//}

	//m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

void CRollFeedModule::RemoveModuleFromIOSync()
{
	//m_Trace.Log(tlVerbose, FENTERA);

	if (IsAddedToIOSync())
	{
		syncId = -1;
		m_spIOSyncIntrf1->RemoveModuleFromIOSync(syncId);
		m_spIOSyncIntrf1 = NULL;
	}

	//m_Trace.Log(tlVerbose, FLEAVEA);
}

bool CRollFeedModule::IsAddedToIOSync()
{	//#@@# check NULL pointer.  if object ID is not set for the pointer in TMC file, pointer is NULL and TwinCAT program shall crash
	if (syncId >= 0 && m_spIOSyncIntrf1 != NULL) return(true);

	return(false);
}

bool CRollFeedModule::WaitTillInputReady(int time_out_usec)
{
	m_log.LogStart(1, 1);
	//Wait until inputs wait flag has been set
	LONGLONG currTime, initTime;
	bool time_out_flag = false;

	m_spRTime->GetCurPentiumTime(&initTime);
	//ipTask->GetCurPentiumTime(&initTime);

	while (!time_out_flag)
	{
		if (IsAddedToIOSync())
		{
			if (m_spIOSyncIntrf1->GetInputReadyFlag(syncId)) break;
		}

		m_spRTime->GetCurPentiumTime(&currTime);
		//ipTask->GetCurPentiumTime(&currTime);
		if ((currTime - initTime) > (time_out_usec * 10))	//-- 1 time unit is 100ns. so 10 unit is 1 usec.
		{
			time_out_flag = true;
		}
	}
	if (time_out_flag)
	{
		m_Trace.Log(tlInfo, "%s timed out waiting for inputs", TcGetObjectName());
	}
	m_log.LogStop(1, 1);

	return(!time_out_flag);
}

void CRollFeedModule::DelayUsec(int usec)
{
	for (int i = 0; i < usec; i++)
	{
		DelayUsec();
	}
}

void CRollFeedModule::DelayUsec(void)
{
	//if (ipTask == NULL) return;

	LONGLONG cur_pentium_time;
	LONGLONG start_pentium_time;

	m_spRTime->GetCurPentiumTime(&start_pentium_time);	//ipTask->GetCurPentiumTime(&start_pentium_time);
	cur_pentium_time = start_pentium_time;

	//-- pentium time is in 100ns unit. 10 unit is 1000ns or 1us.
	while (cur_pentium_time < start_pentium_time + 10)
	{
		m_spRTime->GetCurPentiumTime(&cur_pentium_time);	//ipTask->GetCurPentiumTime(&cur_pentium_time);
	}

}

//void CRollFeedModule::delay_100nsec(ITcTask* ipTask)
//{
//	if (ipTask == NULL) return;
//
//	LONGLONG cur_pentium_time;
//	LONGLONG start_pentium_time;
//
//	ipTask->GetCurPentiumTime(&start_pentium_time);
//	cur_pentium_time = start_pentium_time;
//
//	//-- pentium time is in 100ns unit. 10 unit is 1000ns or 1us.
//	while (cur_pentium_time < start_pentium_time)
//	{
//		ipTask->GetCurPentiumTime(&cur_pentium_time);
//	}
//
//}


///////////////////////////////////////////////////////////////////////////////
void CRollFeedModule::AdsReadWriteInd
(
	AmsAddr& rAddr, 
	ULONG invokeId, 
	ULONG indexGroup,
	ULONG indexOffset, 
	ULONG cbReadLength, 
	ULONG cbWriteLength, 
	PVOID pData 
)
{
	m_Trace.Log(tlVerbose, FENTERA "oid=0x%08x, invokeId=%d, indexGroup=0x%08x, indexOffset=0x%08x, cbReadLength=%d, cbWriteLength=%d, pData=0x%p",
		m_objId.value, invokeId, indexGroup, indexOffset, cbReadLength, cbWriteLength, pData);

	switch(indexGroup)
	{
	case RollFeedModuleIndexGroup1:
		switch(indexOffset)
		{

		case RollFeedModuleIndexOffset1:
			m_Trace.Log(tlInfo, FNAMEA "oid=0x%08x indexGroup=0x%08x, indexOffset=0x%08x", 
				m_objId.value, indexGroup, indexOffset );

			// TODO: add custom code here

			AdsReadWriteRes(rAddr, invokeId, ADSERR_NOERR, 0, NULL); 
			break;

		case RollFeedModuleIndexOffset2:
			m_Trace.Log(tlInfo, FNAMEA "oid=0x%08x indexGroup=0x%08x, indexOffset=0x%08x", 
				m_objId.value, indexGroup, indexOffset );

			// TODO: add custom code here

			AdsReadWriteRes(rAddr, invokeId, ADSERR_NOERR, 0, NULL); 
			break;
		}
		break;
	case RollFeedModuleIndexGroup2:
		switch(indexOffset)
		{

		case RollFeedModuleIndexOffset1:
			m_Trace.Log(tlInfo, FNAMEA "oid=0x%08x indexGroup=0x%08x, indexOffset=0x%08x", 
				m_objId.value, indexGroup, indexOffset );

			// TODO: add custom code here

			AdsReadWriteRes(rAddr, invokeId, ADSERR_NOERR, 0, NULL); 
			break;

		case RollFeedModuleIndexOffset2:
			m_Trace.Log(tlInfo, FNAMEA "oid=0x%08x indexGroup=0x%08x, indexOffset=0x%08x", 
				m_objId.value, indexGroup, indexOffset );

			// TODO: add custom code here

			AdsReadWriteRes(rAddr, invokeId, ADSERR_NOERR, 0, NULL); 
			break;
		}
		break;
	default:
		__super::AdsReadWriteInd(rAddr, invokeId, indexGroup, indexOffset, cbReadLength, cbWriteLength, pData); 
		break;
	}
	m_Trace.Log(tlVerbose, FLEAVEA);
}


void CRollFeedModule::SubmitAdsReadReq()
{
	m_Trace.Log(tlVerbose, FENTERA);
	// m_ContextAdsPort contains the ADS port number of the task associated with context 1
	// amsAddr refers to the ADS port of this task 
	AmsAddr amsAddr(this->AmsGetNetId(), m_ContextAdsPort);

	// Request the value of a parameter from a TwinCAT module instance
	// via the task ADS port.
	// The object id of the instance is passed as index group and
	// the parameter id is passed as index offset.
	// The result is delivered by a call to AdsReadCon and can 
	// be identified by the invoke id. 
	int nRes = 
		AdsReadReq
		(
			amsAddr, 
			invokeIdReadByOidAndPid, 
			m_objId.value, 
			PID_RollFeedModuleCounter,
			sizeof(m_ReadByOidAndPid)
		);
	if (nRes != ADSERR_NOERR)
	{
		m_Trace.Log(tlError, FNAMEA "AdsReadReq failed with error=0x%08x(%s)", nRes, AdsGetErrorText(nRes));
	}
	else
	{
		m_Trace.Log(tlInfo, FNAMEA "AdsReadReq by oid=0x%08x and pid=0x%08x", m_objId.value, PID_RollFeedModuleAdsPort);
	}
	m_Trace.Log(tlVerbose, FLEAVEA);
}

///////////////////////////////////////////////////////////////////////////////
void CRollFeedModule::AdsReadCon
(
	AmsAddr& rAddr,
	ULONG invokeId,
	ULONG nResult,
	ULONG cbLength,
	PVOID pData
)
{
	m_Trace.Log(tlVerbose, FENTERA "oid=0x%08x, invokeId=%d, nResult=0x%08x, cbLength=%d, pData=0x%p",
		m_objId.value, invokeId, nResult, cbLength, pData);

	if (invokeId == invokeIdReadByOidAndPid)
	{
		if (nResult != ADSERR_NOERR)
		{
			m_Trace.Log(tlWarning, FNAMEA "ReadByOidAndPid failed with error=0x%x(%s)",
				nResult, AdsGetErrorText(nResult));
		}
		else if (cbLength == sizeof(m_ReadByOidAndPid))
		{
			m_ReadByOidAndPid = *static_cast<PULONG>(pData); 
			m_Trace.Log(tlInfo, FNAMEA "m_ReadByOidAndPid=0x%x", m_ReadByOidAndPid);
		}
	}
	else
	{
		__super::AdsReadWriteCon( rAddr, invokeId, nResult, cbLength, pData );
	}
	m_Trace.Log(tlVerbose, FLEAVEA);
}

