///////////////////////////////////////////////////////////////////////////////
// IOSyncDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "IOSyncDriver.h"
#include "IOSyncClassFactory.h"

DECLARE_GENERIC_DEVICE(IOSYNCDRV)

IOSTATUS CIOSyncDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CIOSyncClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CIOSyncDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CIOSyncDriver::IOSYNCDRV_GetVersion( )
{
	return( (IOSYNCDRV_Major << 8) | IOSYNCDRV_Minor );
}

