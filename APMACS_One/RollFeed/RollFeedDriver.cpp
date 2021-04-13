///////////////////////////////////////////////////////////////////////////////
// RollFeedDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "RollFeedDriver.h"
#include "RollFeedClassFactory.h"

DECLARE_GENERIC_DEVICE(ROLLFEEDDRV)

IOSTATUS CRollFeedDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CRollFeedClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CRollFeedDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CRollFeedDriver::ROLLFEEDDRV_GetVersion( )
{
	return( (ROLLFEEDDRV_Major << 8) | ROLLFEEDDRV_Minor );
}

