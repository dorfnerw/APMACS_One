///////////////////////////////////////////////////////////////////////////////
// PressPositionCtrl.h

#ifndef __PRESSPOSITIONCTRL_H__
#define __PRESSPOSITIONCTRL_H__

#include <atlbase.h>
#include <atlcom.h>


#include "resource.h"       // main symbols
#include "PressPositionW32.h"
#include "TcBase.h"
#include "PressPositionClassFactory.h"
#include "TcOCFCtrlImpl.h"

class CPressPositionCtrl 
	: public CComObjectRootEx<CComMultiThreadModel>
	, public CComCoClass<CPressPositionCtrl, &CLSID_PressPositionCtrl>
	, public IPressPositionCtrl
	, public ITcOCFCtrlImpl<CPressPositionCtrl, CPressPositionClassFactory>
{
public:
	CPressPositionCtrl();
	virtual ~CPressPositionCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_PRESSPOSITIONCTRL)
DECLARE_NOT_AGGREGATABLE(CPressPositionCtrl)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CPressPositionCtrl)
	COM_INTERFACE_ENTRY(IPressPositionCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl)
	COM_INTERFACE_ENTRY(ITcCtrl2)
END_COM_MAP()

};

#endif // #ifndef __PRESSPOSITIONCTRL_H__
