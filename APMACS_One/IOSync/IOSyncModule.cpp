///////////////////////////////////////////////////////////////////////////////
// IOSyncModule.cpp
#include "TcPch.h"
#pragma hdrstop

#include "IOSyncModule.h"
#include "IOSyncModuleAds.h"
#include "IOSyncVersion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
DEFINE_THIS_FILE()

///////////////////////////////////////////////////////////////////////////////
// CIOSyncModule
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Collection of interfaces implemented by module CIOSyncModule
BEGIN_INTERFACE_MAP(CIOSyncModule)
	INTERFACE_ENTRY_ITCOMOBJECT()
	INTERFACE_ENTRY(IID_ITcADI, ITcADI)
	INTERFACE_ENTRY(IID_ITcWatchSource, ITcWatchSource)
///<AutoGeneratedContent id="InterfaceMap">
	INTERFACE_ENTRY(IID_ITcCyclic, ITcCyclic)
	INTERFACE_ENTRY(IID_ITcPostCyclic, ITcPostCyclic)
///</AutoGeneratedContent>
END_INTERFACE_MAP()

IMPLEMENT_IPERSIST_LIB(CIOSyncModule, VID_IOSync, CID_IOSyncCIOSyncModule)
IMPLEMENT_ITCOMOBJECT(CIOSyncModule)
IMPLEMENT_ITCOMOBJECT_SETSTATE_LOCKOP2(CIOSyncModule)
IMPLEMENT_ITCADI(CIOSyncModule)
IMPLEMENT_ITCWATCHSOURCE(CIOSyncModule)

///////////////////////////////////////////////////////////////////////////////
// Set parameters of CIOSyncModule 
BEGIN_SETOBJPARA_MAP(CIOSyncModule)
	SETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="SetObjectParameterMap">
	SETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	SETOBJPARA_VALUE(PID_IOSyncModuleDefaultAdsPort, m_DefaultAdsPort)
	SETOBJPARA_VALUE(PID_Ctx_AdsPort, m_ContextAdsPort)
	SETOBJPARA_VALUE(PID_IOSyncModuleCounter, m_Counter)
	SETOBJPARA_VALUE(PID_IOSyncModuleMyContextId, m_MyContextId)
	SETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleRTime, m_spRTime)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf1, m_spIOSyncIntrf1)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf2, m_spIOSyncIntrf2)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf3, m_spIOSyncIntrf3)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf4, m_spIOSyncIntrf4)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf5, m_spIOSyncIntrf5)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf6, m_spIOSyncIntrf6)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf7, m_spIOSyncIntrf7)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf8, m_spIOSyncIntrf8)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf9, m_spIOSyncIntrf9)
	SETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf10, m_spIOSyncIntrf10)
	SETOBJPARA_ITFPTR(PID_IOSyncModulePostCyclicCaller, m_spPostCyclicCaller)
///</AutoGeneratedContent>
END_SETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get parameters of CIOSyncModule 
BEGIN_GETOBJPARA_MAP(CIOSyncModule)
	GETOBJPARA_DATAAREA_MAP()
///<AutoGeneratedContent id="GetObjectParameterMap">
	GETOBJPARA_VALUE(PID_TcTraceLevel, m_TraceLevelMax)
	GETOBJPARA_VALUE(PID_IOSyncModuleDefaultAdsPort, m_DefaultAdsPort)
	GETOBJPARA_VALUE(PID_Ctx_AdsPort, m_ContextAdsPort)
	GETOBJPARA_VALUE(PID_IOSyncModuleCounter, m_Counter)
	GETOBJPARA_VALUE(PID_IOSyncModuleMyContextId, m_MyContextId)
	GETOBJPARA_ITFPTR(PID_Ctx_TaskOid, m_spCyclicCaller)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleRTime, m_spRTime)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf1, m_spIOSyncIntrf1)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf2, m_spIOSyncIntrf2)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf3, m_spIOSyncIntrf3)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf4, m_spIOSyncIntrf4)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf5, m_spIOSyncIntrf5)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf6, m_spIOSyncIntrf6)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf7, m_spIOSyncIntrf7)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf8, m_spIOSyncIntrf8)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf9, m_spIOSyncIntrf9)
	GETOBJPARA_ITFPTR(PID_IOSyncModuleIOSyncIntrf10, m_spIOSyncIntrf10)
	GETOBJPARA_ITFPTR(PID_IOSyncModulePostCyclicCaller, m_spPostCyclicCaller)
///</AutoGeneratedContent>
	GETOBJPARA_TYPE_CODE(PID_IOSyncModuleAdsPort, WORD, *p = AmsGetPort())
END_GETOBJPARA_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get watch entries of CIOSyncModule
BEGIN_OBJPARAWATCH_MAP(CIOSyncModule)
	OBJPARAWATCH_DATAAREA_MAP()
///<AutoGeneratedContent id="ObjectParameterWatchMap">
	OBJPARAWATCH_VALUE(PID_IOSyncModuleCounter, m_Counter)
///</AutoGeneratedContent>
END_OBJPARAWATCH_MAP()

///////////////////////////////////////////////////////////////////////////////
// Get data area members of CIOSyncModule
BEGIN_OBJDATAAREA_MAP(CIOSyncModule)
///<AutoGeneratedContent id="ObjectDataAreaMap">
	OBJDATAAREA_VALUE(ADI_IOSyncModuleInputs, m_Inputs)
	OBJDATAAREA_VALUE(ADI_IOSyncModuleOutputs, m_Outputs)
	OBJDATAAREA_VALUE(ADI_IOSyncModuleDebug, m_Debug)
///</AutoGeneratedContent>
END_OBJDATAAREA_MAP()


///////////////////////////////////////////////////////////////////////////////
CIOSyncModule::CIOSyncModule()
	: m_Trace(m_TraceLevelMax, m_spSrv)
	, m_log(0x12C)						// #@@# LTW
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

	m_Debug.DelayUsec = 75;

}

///////////////////////////////////////////////////////////////////////////////
CIOSyncModule::~CIOSyncModule() 
{
}

///////////////////////////////////////////////////////////////////////////////
// State Transitions 
///////////////////////////////////////////////////////////////////////////////
IMPLEMENT_ITCOMOBJECT_SETOBJSTATE_IP_PI(CIOSyncModule)

///////////////////////////////////////////////////////////////////////////////
// State transition from PREOP to SAFEOP
//
// Initialize input parameters 
// Allocate memory
HRESULT CIOSyncModule::SetObjStatePS(PTComInitDataHdr pInitData)
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;
	IMPLEMENT_ITCOMOBJECT_EVALUATE_INITDATA(pInitData);

	hr = SUCCEEDED(hr) ? InitAmsPort(m_spSrv, m_DefaultAdsPort) : hr;

	// #@@# LTW Initialize log mark
	m_log.SetContextId(m_MyContextId);// (1);	//-- NOTE: 0.1.0.1 each instance specifies contextId for RealTimeMonitor software.
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
HRESULT CIOSyncModule::SetObjStateSO()
{
	m_Trace.Log(tlVerbose, FENTERA);
	HRESULT hr = S_OK;

	// TODO: Add any additional initialization
	//#@@# LTW get reference to TC-RTime-Instance
	m_spRTime.SetOID(OID_TCRTIME_CTRL);														//-- set object ID
	hr = FAILED(hr) ? hr : m_spSrv->TcQuerySmartObjectInterface(m_spRTime);					//-- initialize pointer
	hr = FAILED(hr) ? hr : InitIOSyncIntrfPointers();

//	hr = FAILED(hr) ? hr : AddModuleToPostCyclicCaller();


	// If following call is successful the CycleUpdate method will be called, 
	// possibly even before this method has been left.
	hr = FAILED(hr) ? hr : AddModuleToCaller(); 

	// Cleanup if transition failed at some stage
	if ( FAILED(hr) )
	{
		RemoveModuleFromCaller(); 

		// #@@# LTW
		m_spRTime = NULL;
		ResetIOSyncIntrfPointers();
	}
	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from OP to SAFEOP
HRESULT CIOSyncModule::SetObjStateOS()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;

	RemoveModuleFromCaller(); 
	
//	RemoveModuleFromPosyCyclicCaller();

	//#@@# LTW
	m_spRTime = NULL;
	ResetIOSyncIntrfPointers();

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////
// State transition from SAFEOP to PREOP
HRESULT CIOSyncModule::SetObjStateSP()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	ShutdownAmsPort();

	//#@@# LTW De-initialize log mark 
	m_log.ReleaseLogMark();

	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
	return hr;
}

///</AutoGeneratedContent>

///////////////////////////////////////////////////////////////////////////////
HRESULT CIOSyncModule::AddModuleToCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	HRESULT hr = S_OK;
	if ( m_spCyclicCaller.HasOID() )
	{
		if ( SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spCyclicCaller)) )
		{
			if ( FAILED(hr = m_spCyclicCaller->AddModule(m_spCyclicCaller, THIS_CAST(ITcCyclic))) )
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
VOID CIOSyncModule::RemoveModuleFromCaller()
{
	m_Trace.Log(tlVerbose, FENTERA);

	if ( m_spCyclicCaller )
	{
		m_spCyclicCaller->RemoveModule(m_spCyclicCaller);
	}
	m_spCyclicCaller	= NULL;
	m_Trace.Log(tlVerbose, FLEAVEA);
}

///////////////////////////////////////////////////////////////////////////////
void CIOSyncModule::AdsReadWriteInd
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
	case IOSyncModuleIndexGroup1:
		switch(indexOffset)
		{

		case IOSyncModuleIndexOffset1:
			m_Trace.Log(tlInfo, FNAMEA "oid=0x%08x indexGroup=0x%08x, indexOffset=0x%08x", 
				m_objId.value, indexGroup, indexOffset );

			// TODO: add custom code here

			AdsReadWriteRes(rAddr, invokeId, ADSERR_NOERR, 0, NULL); 
			break;

		case IOSyncModuleIndexOffset2:
			m_Trace.Log(tlInfo, FNAMEA "oid=0x%08x indexGroup=0x%08x, indexOffset=0x%08x", 
				m_objId.value, indexGroup, indexOffset );

			// TODO: add custom code here

			AdsReadWriteRes(rAddr, invokeId, ADSERR_NOERR, 0, NULL); 
			break;
		}
		break;
	case IOSyncModuleIndexGroup2:
		switch(indexOffset)
		{

		case IOSyncModuleIndexOffset1:
			m_Trace.Log(tlInfo, FNAMEA "oid=0x%08x indexGroup=0x%08x, indexOffset=0x%08x", 
				m_objId.value, indexGroup, indexOffset );

			// TODO: add custom code here

			AdsReadWriteRes(rAddr, invokeId, ADSERR_NOERR, 0, NULL); 
			break;

		case IOSyncModuleIndexOffset2:
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


void CIOSyncModule::SubmitAdsReadReq()
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
			PID_IOSyncModuleCounter,
			sizeof(m_ReadByOidAndPid)
		);
	if (nRes != ADSERR_NOERR)
	{
		m_Trace.Log(tlError, FNAMEA "AdsReadReq failed with error=0x%08x(%s)", nRes, AdsGetErrorText(nRes));
	}
	else
	{
		m_Trace.Log(tlInfo, FNAMEA "AdsReadReq by oid=0x%08x and pid=0x%08x", m_objId.value, PID_IOSyncModuleAdsPort);
	}
	m_Trace.Log(tlVerbose, FLEAVEA);
}

///////////////////////////////////////////////////////////////////////////////
void CIOSyncModule::AdsReadCon
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///<AutoGeneratedContent id="ImplementationOf_ITcCyclic">
// NOTE: 0.0.0.1 backup
//HRESULT CIOSyncModule::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
//{
//	HRESULT hr = S_OK;
//	bool result = false;
//	// handle pending ADS indications and confirmations
//	CheckOrders();
//
//	// TODO: Additional evaluation of input from ADS indication or confirmations
//	//-- If execution is here, IO Sync Task has read all inputs. set input ready flag so each TCOM module can begin executing logic code. ---
//	SetInputReadyFlags();
//	
//
//
//
//
//
//	//-- Wait until all TCOM modules have completed executing logic code. ---
//	result = WaitTillOutputReady(125);		//-- usec
//	if (result)
//	{
//		//-- Reset output ready flag for this cycle ---
//		ResetOutputReadyFlags();
//	}
//	else
//	{
//		//-- Count number of time outs ---
//		CountOutputReadyTimeouts();
//	}
//
//
//
//
//
//
//	// TODO: Submit your ADS requests 
//	ULONGLONG cnt = 0;
//	if (SUCCEEDED(ipTask->GetCycleCounter(&cnt)))
//	{
//		if (cnt % 100 == 0)
//		{
//			SubmitAdsReadReq();
//		}
//	}
//
//	// TODO: Replace the sample with your cyclic code
//	m_Counter += (1 + m_Inputs.Value);
//	m_Outputs.Value = m_Counter;
//
//	return hr;
//}
HRESULT CIOSyncModule::CycleUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = S_OK;
	bool result = false;
	// handle pending ADS indications and confirmations
	CheckOrders();

	// TODO: Additional evaluation of input from ADS indication or confirmations
	//-- If execution is here, IO Sync Task has read all inputs. set input ready flag so each TCOM module can begin executing logic code. ---
	SetInputReadyFlags();






	//-- Wait until all TCOM modules have completed executing logic code. ---
	//result = WaitTillOutputReady(75);		//-- usec
	DelayUsec(m_Debug.DelayUsec);//
	result = true;
	if (result)
	{
		//-- Reset output ready flag for this cycle ---
		ResetOutputReadyFlags();
	}
	else
	{
		//-- Count number of time outs ---
		CountOutputReadyTimeouts();
	}

	//-- NOTE: 0.1.0.1 Added to reset those tasks running slower than IO sync task. If task does not schedule to run this cycle, input ready flag must be reset so that task does not see it ready immediately next time it is scheduled to run.
	//ResetInputReadyFlags();

	


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
	//m_Counter += (1 + m_Inputs.Value);
	//m_Outputs.Value = m_Counter;
	m_Counter++;

	return hr;
}
///</AutoGeneratedContent>

HRESULT CIOSyncModule::InitIOSyncIntrfPointers()
{
	//m_Trace.Log(tlVerbose, FENTERA);

	//-- In Interface Pointer tab under TMI dialog, if the pointer is initialized to TCOM object but the object is no longer valid (because you added IOSync Interface and it changes interface GUID), 
	//-- IO Sync object shall not be able to enter OP mode and TC program could not run. You need to make sure to remove existing IO SYNC interface in TCOM and then add IO SYNC Interface again. 
	//-- To be able to see IO SYNC interface defined in IOSync C++ project from Feed C++ project, add IO SYNC interface under IOSYNC implemented interface first so that it appears in TYPE SYSTEM under SYSTEM.
	HRESULT hr = S_OK;
	if (m_spIOSyncIntrf1.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf1); }
	if (m_spIOSyncIntrf2.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf2); }
	if (m_spIOSyncIntrf3.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf3); }
	if (m_spIOSyncIntrf4.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf4); }
	if (m_spIOSyncIntrf5.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf5); }
	if (m_spIOSyncIntrf6.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf6); }
	if (m_spIOSyncIntrf7.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf7); }
	if (m_spIOSyncIntrf8.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf8); }
	if (m_spIOSyncIntrf9.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf9); }
	if (m_spIOSyncIntrf10.HasOID()) { hr = m_spSrv->TcQuerySmartObjectInterface(m_spIOSyncIntrf10); }

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

void CIOSyncModule::ResetIOSyncIntrfPointers()
{
	//m_Trace.Log(tlVerbose, FENTERA);

	m_spIOSyncIntrf1 = NULL;
	m_spIOSyncIntrf2 = NULL;
	m_spIOSyncIntrf3 = NULL;
	m_spIOSyncIntrf4 = NULL;
	m_spIOSyncIntrf5 = NULL;
	m_spIOSyncIntrf6 = NULL;
	m_spIOSyncIntrf7 = NULL;
	m_spIOSyncIntrf8 = NULL;
	m_spIOSyncIntrf9 = NULL;
	m_spIOSyncIntrf10 = NULL;

	//m_Trace.Log(tlVerbose, FLEAVEA);
}


void CIOSyncModule::SetInputReadyFlags()
{
	//#@@# check NULL pointer.  if object ID is not set for the pointer in TMC file, pointer is NULL and TwinCAT program shall crash
	if (m_spIOSyncIntrf1 != NULL) m_spIOSyncIntrf1->SetInputReadyFlag();
	if (m_spIOSyncIntrf2 != NULL) m_spIOSyncIntrf2->SetInputReadyFlag();
	if (m_spIOSyncIntrf3 != NULL) m_spIOSyncIntrf3->SetInputReadyFlag();
	if (m_spIOSyncIntrf4 != NULL) m_spIOSyncIntrf4->SetInputReadyFlag();
	if (m_spIOSyncIntrf5 != NULL) m_spIOSyncIntrf5->SetInputReadyFlag();
	if (m_spIOSyncIntrf6 != NULL) m_spIOSyncIntrf6->SetInputReadyFlag();
	if (m_spIOSyncIntrf7 != NULL) m_spIOSyncIntrf7->SetInputReadyFlag();
	if (m_spIOSyncIntrf8 != NULL) m_spIOSyncIntrf8->SetInputReadyFlag();
	if (m_spIOSyncIntrf9 != NULL) m_spIOSyncIntrf9->SetInputReadyFlag();
	if (m_spIOSyncIntrf10 != NULL) m_spIOSyncIntrf10->SetInputReadyFlag();

}

void CIOSyncModule::ResetInputReadyFlags()
{
	//#@@# check NULL pointer.  if object ID is not set for the pointer in TMC file, pointer is NULL and TwinCAT program shall crash
	if (m_spIOSyncIntrf1 != NULL) m_spIOSyncIntrf1->ResetInputReadyFlag();
	if (m_spIOSyncIntrf2 != NULL) m_spIOSyncIntrf2->ResetInputReadyFlag();
	if (m_spIOSyncIntrf3 != NULL) m_spIOSyncIntrf3->ResetInputReadyFlag();
	if (m_spIOSyncIntrf4 != NULL) m_spIOSyncIntrf4->ResetInputReadyFlag();
	if (m_spIOSyncIntrf5 != NULL) m_spIOSyncIntrf5->ResetInputReadyFlag();
	if (m_spIOSyncIntrf6 != NULL) m_spIOSyncIntrf6->ResetInputReadyFlag();
	if (m_spIOSyncIntrf7 != NULL) m_spIOSyncIntrf7->ResetInputReadyFlag();
	if (m_spIOSyncIntrf8 != NULL) m_spIOSyncIntrf8->ResetInputReadyFlag();
	if (m_spIOSyncIntrf9 != NULL) m_spIOSyncIntrf9->ResetInputReadyFlag();
	if (m_spIOSyncIntrf10 != NULL) m_spIOSyncIntrf10->ResetInputReadyFlag();

}

void CIOSyncModule::ResetOutputReadyFlags()
{
	//#@@# check NULL pointer.  if object ID is not set for the pointer in TMC file, pointer is NULL and TwinCAT program shall crash
	if (m_spIOSyncIntrf1 != NULL) m_spIOSyncIntrf1->ResetOutputReadyFlag();			//-- reset output flag at the end of cycle
	if (m_spIOSyncIntrf2 != NULL) m_spIOSyncIntrf2->ResetOutputReadyFlag();
	if (m_spIOSyncIntrf3 != NULL) m_spIOSyncIntrf3->ResetOutputReadyFlag();
	if (m_spIOSyncIntrf4 != NULL) m_spIOSyncIntrf4->ResetOutputReadyFlag();
	if (m_spIOSyncIntrf5 != NULL) m_spIOSyncIntrf5->ResetOutputReadyFlag();
	if (m_spIOSyncIntrf6 != NULL) m_spIOSyncIntrf6->ResetOutputReadyFlag();
	if (m_spIOSyncIntrf7 != NULL) m_spIOSyncIntrf7->ResetOutputReadyFlag();
	if (m_spIOSyncIntrf8 != NULL) m_spIOSyncIntrf8->ResetOutputReadyFlag();
	if (m_spIOSyncIntrf9 != NULL) m_spIOSyncIntrf9->ResetOutputReadyFlag();
	if (m_spIOSyncIntrf10 != NULL) m_spIOSyncIntrf10->ResetOutputReadyFlag();

}

bool CIOSyncModule::IsOutputReady()
{	//#@@# check NULL pointer.  if object ID is not set for the pointer in TMC file, pointer is NULL and TwinCAT program shall crash
	if (m_spIOSyncIntrf1 != NULL) { if (!m_spIOSyncIntrf1->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf2 != NULL) { if (!m_spIOSyncIntrf2->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf3 != NULL) { if (!m_spIOSyncIntrf3->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf4 != NULL) { if (!m_spIOSyncIntrf4->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf5 != NULL) { if (!m_spIOSyncIntrf5->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf6 != NULL) { if (!m_spIOSyncIntrf6->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf7 != NULL) { if (!m_spIOSyncIntrf7->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf8 != NULL) { if (!m_spIOSyncIntrf8->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf9 != NULL) { if (!m_spIOSyncIntrf9->GetOutputReadyFlag()) return(false); }
	if (m_spIOSyncIntrf10 != NULL) { if (!m_spIOSyncIntrf10->GetOutputReadyFlag()) return(false); }
	return(true);
}

//NOTE: 0.0.0.1 backup
//void CIOSyncModule::CountOutputReadyTimeouts()
//{
//	//#@@# check NULL pointer.  if object ID is not set for the pointer in TMC file, pointer is NULL and TwinCAT program shall crash
//	if (m_spIOSyncIntrf1 != NULL) { if (!m_spIOSyncIntrf1->GetOutputReadyFlag()) m_spIOSyncIntrf1->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf2 != NULL) { if (!m_spIOSyncIntrf2->GetOutputReadyFlag()) m_spIOSyncIntrf2->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf3 != NULL) { if (!m_spIOSyncIntrf3->GetOutputReadyFlag()) m_spIOSyncIntrf3->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf4 != NULL) { if (!m_spIOSyncIntrf4->GetOutputReadyFlag()) m_spIOSyncIntrf4->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf5 != NULL) { if (!m_spIOSyncIntrf5->GetOutputReadyFlag()) m_spIOSyncIntrf5->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf6 != NULL) { if (!m_spIOSyncIntrf6->GetOutputReadyFlag()) m_spIOSyncIntrf6->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf7 != NULL) { if (!m_spIOSyncIntrf7->GetOutputReadyFlag()) m_spIOSyncIntrf7->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf8 != NULL) { if (!m_spIOSyncIntrf8->GetOutputReadyFlag()) m_spIOSyncIntrf8->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf9 != NULL) { if (!m_spIOSyncIntrf9->GetOutputReadyFlag()) m_spIOSyncIntrf9->CountOutputReadyTimeout(); }
//	if (m_spIOSyncIntrf10 != NULL) { if (!m_spIOSyncIntrf10->GetOutputReadyFlag()) m_spIOSyncIntrf10->CountOutputReadyTimeout(); }
//}

void CIOSyncModule::CountOutputReadyTimeouts()
{
	//#@@# check NULL pointer.  if object ID is not set for the pointer in TMC file, pointer is NULL and TwinCAT program shall crash
	//-- count only if task is scheduled to run
	if (m_spIOSyncIntrf1 != NULL) { if (!m_spIOSyncIntrf1->GetInputReadyFlag() && !m_spIOSyncIntrf1->GetOutputReadyFlag()) { m_spIOSyncIntrf1->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf2 != NULL) { if (!m_spIOSyncIntrf2->GetInputReadyFlag() && !m_spIOSyncIntrf2->GetOutputReadyFlag()) { m_spIOSyncIntrf2->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf3 != NULL) { if (!m_spIOSyncIntrf3->GetInputReadyFlag() && !m_spIOSyncIntrf3->GetOutputReadyFlag()) { m_spIOSyncIntrf3->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf4 != NULL) { if (!m_spIOSyncIntrf4->GetInputReadyFlag() && !m_spIOSyncIntrf4->GetOutputReadyFlag()) { m_spIOSyncIntrf4->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf5 != NULL) { if (!m_spIOSyncIntrf5->GetInputReadyFlag() && !m_spIOSyncIntrf5->GetOutputReadyFlag()) { m_spIOSyncIntrf5->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf6 != NULL) { if (!m_spIOSyncIntrf6->GetInputReadyFlag() && !m_spIOSyncIntrf6->GetOutputReadyFlag()) { m_spIOSyncIntrf6->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf7 != NULL) { if (!m_spIOSyncIntrf7->GetInputReadyFlag() && !m_spIOSyncIntrf7->GetOutputReadyFlag()) { m_spIOSyncIntrf7->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf8 != NULL) { if (!m_spIOSyncIntrf8->GetInputReadyFlag() && !m_spIOSyncIntrf8->GetOutputReadyFlag()) { m_spIOSyncIntrf8->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf9 != NULL) { if (!m_spIOSyncIntrf9->GetInputReadyFlag() && !m_spIOSyncIntrf9->GetOutputReadyFlag()) { m_spIOSyncIntrf9->CountOutputReadyTimeout(); } }
	if (m_spIOSyncIntrf10 != NULL) { if (!m_spIOSyncIntrf10->GetInputReadyFlag() && !m_spIOSyncIntrf10->GetOutputReadyFlag()) { m_spIOSyncIntrf10->CountOutputReadyTimeout(); } }
}

bool CIOSyncModule::WaitTillOutputReady(int time_out_usec)
{
	m_log.LogStart(1, 1);
	//Wait until inputs wait flag has been set
	LONGLONG currTime, initTime;
	bool time_out_flag = false;

	m_spRTime->GetCurPentiumTime(&initTime);
	//ipTask->GetCurPentiumTime(&initTime);

	// this works too.
	//do
	//{
	//	if (m_spIOSyncIntrf1->GetOutputReadyFlag() && m_spIOSyncIntrf2->GetOutputReadyFlag()) break;

	//	m_spRTime->GetCurPentiumTime(&currTime);
	//	//ipTask->GetCurPentiumTime(&currTime);
	//	if ((currTime - initTime) > (time_out_usec * 10))	//-- 1 time unit is 100ns. so 10 unit is 1 usec.
	//	{
	//		time_out_flag = true;
	//	}
	//} while (!time_out_flag);

	//while ((!m_spIOSyncIntrf1->GetOutputReadyFlag() || !m_spIOSyncIntrf2->GetOutputReadyFlag()) && !time_out_flag)
	while (!IsOutputReady() && !time_out_flag)
	{

		m_spRTime->GetCurPentiumTime(&currTime);
		//ipTask->GetCurPentiumTime(&currTime);
		if ((currTime - initTime) > (time_out_usec * 10))	//-- 1 time unit is 100ns. so 10 unit is 1 usec.
		{
			time_out_flag = true;
		}
	}

	if (time_out_flag)
	{
		m_Trace.Log(tlInfo, "%s timed out waiting for outputs", TcGetObjectName());
	}
	m_log.LogStop(1, 1);

	return(!time_out_flag);
}

void CIOSyncModule::DelayUsec(int usec)
{
	for (int i = 0; i < usec; i++)
	{
		DelayUsec();
	}
}

void CIOSyncModule::DelayUsec(void)
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

///<AutoGeneratedContent id="ImplementationOf_ITcPostCyclic">
HRESULT CIOSyncModule::PostCyclicUpdate(ITcTask* ipTask, ITcUnknown* ipCaller, ULONG_PTR context)
{
	HRESULT hr = E_NOTIMPL;




	return hr;
}
///</AutoGeneratedContent>

///<AutoGeneratedContent id="Obsolete_ImplementationOf_ITcPostCyclic">
//
//HRESULT CIOSyncModule::AddModuleToPostCyclicCaller()
//{
//	m_Trace.Log(tlVerbose, FENTERA);
//	HRESULT hr = S_OK;
//	if (m_spPostCyclicCaller.HasOID())
//	{
//		if (SUCCEEDED_DBG(hr = m_spSrv->TcQuerySmartObjectInterface(m_spPostCyclicCaller)))
//		{
//			if (FAILED(hr = m_spPostCyclicCaller->AddPostModule(m_spPostCyclicCaller, THIS_CAST(ITcPostCyclic))))
//			{
//				m_spPostCyclicCaller = NULL;
//			}
//		}
//	}
//	else
//	{
//		hr = ADS_E_INVALIDOBJID;
//		SUCCEEDED_DBGT(hr, "Invalid OID specified for caller task");
//	}
//	m_Trace.Log(tlVerbose, FLEAVEA "hr=0x%08x", hr);
//	return hr;
//}
//
//
//VOID CIOSyncModule::RemoveModuleFromPosyCyclicCaller()
//{
//	m_Trace.Log(tlVerbose, FENTERA);
//	if (m_spPostCyclicCaller)
//	{
//		m_spPostCyclicCaller->RemovePostModule(m_spPostCyclicCaller);
//	}
//	m_spPostCyclicCaller = NULL;
//	m_Trace.Log(tlVerbose, FLEAVEA);
//}
//
///</AutoGeneratedContent>
