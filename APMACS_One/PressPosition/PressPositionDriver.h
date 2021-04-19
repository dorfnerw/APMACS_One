///////////////////////////////////////////////////////////////////////////////
// PressPositionDriver.h

#ifndef __PRESSPOSITIONDRIVER_H__
#define __PRESSPOSITIONDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define PRESSPOSITIONDRV_NAME        "PRESSPOSITION"
#define PRESSPOSITIONDRV_Major       1
#define PRESSPOSITIONDRV_Minor       0

#define DEVICE_CLASS CPressPositionDriver

#include "ObjDriver.h"

class CPressPositionDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl PRESSPOSITIONDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(PRESSPOSITIONDRV)
	VxD_Service( PRESSPOSITIONDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __PRESSPOSITIONDRIVER_H__