///////////////////////////////////////////////////////////////////////////////
// PressPositionInterfaces.h

#pragma once

#include "TcInterfaces.h"
#include "TcIoInterfaces.h"
#include "TcRtInterfaces.h"
#include "PressPositionServices.h"

///<AutoGeneratedContent id="Interfaces">
#if !defined(_TC_TYPE_7EBE6026_0379_47C3_97B9_EC238F447164_INCLUDED_)
#define _TC_TYPE_7EBE6026_0379_47C3_97B9_EC238F447164_INCLUDED_
struct __declspec(novtable) IIOSyncInterface : public ITcUnknown
{
	virtual SHORT TCOMAPI AddModuleToIOSync()=0;
	virtual void TCOMAPI RemoveModuleFromIOSync(SHORT index)=0;
	virtual bool TCOMAPI GetInputReadyFlag(SHORT index)=0;
	virtual void TCOMAPI SetInputReadyFlag(SHORT index)=0;
	virtual void TCOMAPI ResetInputReadyFlag(SHORT index)=0;
	virtual bool TCOMAPI GetOutputReadyFlag(SHORT index)=0;
	virtual void TCOMAPI SetOutputReadyFlag(SHORT index)=0;
	virtual void TCOMAPI ResetOutputReadyFlag(SHORT index)=0;
	virtual LONG TCOMAPI GetInputReadyTimeout(SHORT index)=0;
	virtual void TCOMAPI CountInputReadyTimeout(SHORT index)=0;
	virtual void TCOMAPI CountOutputReadyTimeout(SHORT index)=0;
	virtual LONG TCOMAPI GetOutputReadyTimeout(SHORT index)=0;
};
_TCOM_SMARTPTR_TYPEDEF(IIOSyncInterface, IID_IIOSyncInterface);
#endif // !defined(_TC_TYPE_7EBE6026_0379_47C3_97B9_EC238F447164_INCLUDED_)

///</AutoGeneratedContent>