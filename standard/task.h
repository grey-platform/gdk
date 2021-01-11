/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: task.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TASK_H__
#define __STANDARD_TASK_H__

#include <include/stdtype.h>
#include <include/coroutine.h>
#include <standard/gui.h>

class ITask{
public:
    ITask();
    virtual ~ITask();
    virtual int32 Update( float fDelta );
    virtual int32 Stop();
    virtual void OnMouseEvent( EUIMouseMessage eMouseMessage, int32 x, int32 y );
    virtual void OnKeyEvent( EUIKeyMessage eKeyMessage, int32 nKey );
    void SetActive( bool32 v );
    uint32 pt1;
    uint32 m_tCoroTimer;
    bool32 m_bActive;
};

#endif
