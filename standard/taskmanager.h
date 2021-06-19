/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: taskmanager.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TASKMANAGER_H__
#define __STANDARD_TASKMANAGER_H__

#include <include/stdtype.h>
#include <standard/list.h>
#include <standard/gui.h>

class ITask;
class CTaskManager{
public:
    static CTaskManager* GetInterface();
    static void AddTask( ITask *pTask );
    CTaskManager();
    ~CTaskManager();
    void _AddTask( ITask *pTask );
    void _RemoveTask( ITask* pTask );
    void Update( float fDelta );
    void OnMouseEvent( EUIMouseMessage eMouseMessage, int32 x, int32 y );
    void OnKeyEvent( EUIKeyMessage eKeyMessage, int32 nKey );

private:
    void Clear();
    list<ITask*> m_vTaskList;
};


#endif
