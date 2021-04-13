///////////////////////////////////////////////////////////////////////////////
// IOSyncCtrl.h

#ifndef __IOSYNCCTRL_H__
#define __IOSYNCCTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "IOSyncW32.h"
#include "TcBase.h"
#include "IOSyncClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CIOSyncCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CIOSyncCtrl, &CLSID_IOSyncCtrl>
	, public IIOSyncCtrl
	, public ITcOCFCtrlImpl<CIOSyncCtrl, CIOSyncClassFactory>
{
public:
	CIOSyncCtrl();
	virtual ~CIOSyncCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_IOSYNCCTRL)
DECLARE_NOT_AGGREGATABLE(CIOSyncCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIOSyncCtrl)
	COM_INTERFACE_ENTRY(IIOSyncCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __IOSYNCCTRL_H__
