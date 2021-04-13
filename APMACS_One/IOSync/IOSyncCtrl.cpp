// IOSyncCtrl.cpp : Implementation of CTcIOSyncCtrl
#include "TcPch.h"
#pragma hdrstop

#include "IOSyncW32.h"
#include "IOSyncCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CIOSyncCtrl

CIOSyncCtrl::CIOSyncCtrl() 
	: ITcOCFCtrlImpl<CIOSyncCtrl, CIOSyncClassFactory>() 
{
}

CIOSyncCtrl::~CIOSyncCtrl()
{
}

