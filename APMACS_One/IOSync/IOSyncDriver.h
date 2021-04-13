///////////////////////////////////////////////////////////////////////////////
// IOSyncDriver.h

#ifndef __IOSYNCDRIVER_H__
#define __IOSYNCDRIVER_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "TcBase.h"

#define IOSYNCDRV_NAME        "IOSYNC"
#define IOSYNCDRV_Major       1
#define IOSYNCDRV_Minor       0

#define DEVICE_CLASS CIOSyncDriver

#include "ObjDriver.h"

class CIOSyncDriver : public CObjDriver
{
public:
	virtual IOSTATUS	OnLoad();
	virtual VOID		OnUnLoad();

	//////////////////////////////////////////////////////
	// VxD-Services exported by this driver
	static unsigned long	_cdecl IOSYNCDRV_GetVersion();
	//////////////////////////////////////////////////////
	
};

Begin_VxD_Service_Table(IOSYNCDRV)
	VxD_Service( IOSYNCDRV_GetVersion )
End_VxD_Service_Table


#endif // ifndef __IOSYNCDRIVER_H__