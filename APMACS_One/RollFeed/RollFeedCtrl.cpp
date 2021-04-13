// RollFeedCtrl.cpp : Implementation of CTcRollFeedCtrl
#include "TcPch.h"
#pragma hdrstop

#include "RollFeedW32.h"
#include "RollFeedCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CRollFeedCtrl

CRollFeedCtrl::CRollFeedCtrl() 
	: ITcOCFCtrlImpl<CRollFeedCtrl, CRollFeedClassFactory>() 
{
}

CRollFeedCtrl::~CRollFeedCtrl()
{
}

