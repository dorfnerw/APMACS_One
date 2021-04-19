// PressPositionCtrl.cpp : Implementation of CTcPressPositionCtrl
#include "TcPch.h"
#pragma hdrstop

#include "PressPositionW32.h"
#include "PressPositionCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CPressPositionCtrl

CPressPositionCtrl::CPressPositionCtrl() 
	: ITcOCFCtrlImpl<CPressPositionCtrl, CPressPositionClassFactory>() 
{
}

CPressPositionCtrl::~CPressPositionCtrl()
{
}

