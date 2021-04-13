///////////////////////////////////////////////////////////////////////////////
// RollFeedDriver.h

#ifndef __ROLLFEEDDRIVER_H__
#define __ROLLFEEDDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define ROLLFEEDDRV_NAME        "ROLLFEED"
#define ROLLFEEDDRV_Major       1
#define ROLLFEEDDRV_Minor       0

#define DEVICE_CLASS CRollFeedDriver

#include "ObjDriver.h"

class CRollFeedDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl ROLLFEEDDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(ROLLFEEDDRV)
	VxD_Service( ROLLFEEDDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __ROLLFEEDDRIVER_H__