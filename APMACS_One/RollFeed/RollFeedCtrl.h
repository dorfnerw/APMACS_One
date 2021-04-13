///////////////////////////////////////////////////////////////////////////////
// RollFeedCtrl.h

#ifndef __ROLLFEEDCTRL_H__
#define __ROLLFEEDCTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "RollFeedW32.h"
#include "TcBase.h"
#include "RollFeedClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CRollFeedCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CRollFeedCtrl, &CLSID_RollFeedCtrl>
	, public IRollFeedCtrl
	, public ITcOCFCtrlImpl<CRollFeedCtrl, CRollFeedClassFactory>
{
public:
	CRollFeedCtrl();
	virtual ~CRollFeedCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_ROLLFEEDCTRL)
DECLARE_NOT_AGGREGATABLE(CRollFeedCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRollFeedCtrl)
	COM_INTERFACE_ENTRY(IRollFeedCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __ROLLFEEDCTRL_H__
