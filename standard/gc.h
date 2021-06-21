/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: gc.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2021
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __STANDARD_GC_H__
#define __STANDARD_GC_H__

#include <include/stdtype.h>
#include <standard/reference.h>
#include <standard/list.h>
#include <standard/task.h>


class CGarbageCollection: public ITask{
public:
    static CGarbageCollection* GetInterface();
    static bool32 AddObject( CRefObject* pRefObj );
    static bool32 RemoveObject( CRefObject* pRefObj );
public:
    CGarbageCollection();
    virtual ~CGarbageCollection();
    virtual int32 UpdateTask( float fDelta );
    bool32 _AddObject( CRefObject* pRefObj );
    bool32 _RemoveObject( CRefObject* pRefObj );
    void Sweep();
    void SweepAll();
    void Debug();
    void ClearAll();
private:

    list<CRefObject*> m_vRefObjectEntityList;
};




#endif
