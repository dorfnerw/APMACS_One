///////////////////////////////////////////////////////////////////////////////
// PressPositionDriver.cpp
#include "TcPch.h"
#pragma hdrstop

#include "PressPositionDriver.h"
#include "PressPositionClassFactory.h"

DECLARE_GENERIC_DEVICE(PRESSPOSITIONDRV)

IOSTATUS CPressPositionDriver::OnLoad( )
{
	TRACE(_T("CObjClassFactory::OnLoad()\n") );
	m_pObjClassFactory = new CPressPositionClassFactory();

	return IOSTATUS_SUCCESS;
}

VOID CPressPositionDriver::OnUnLoad( )
{
	delete m_pObjClassFactory;
}

unsigned long _cdecl CPressPositionDriver::PRESSPOSITIONDRV_GetVersion( )
{
	return( (PRESSPOSITIONDRV_Major << 8) | PRESSPOSITIONDRV_Minor );
}

