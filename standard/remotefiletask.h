/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: remotefiletask.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_REMOTEFILETASK_H__
#define __STANDARD_REMOTEFILETASK_H__

#include <include/stdtype.h>
#include <include/tools.h>

class CRemoteFileTask;
class CRemoteFileTaskEvent{
public:
    virtual void OnComplate( CRemoteFileTask* pRemoteFileTask, void* pData, int32 nSize );
    virtual void OnError( CRemoteFileTask* pRemoteFileTask, void* pData, int32 nSize );
    virtual void OnProcess( CRemoteFileTask* pRemoteFileTask, int32 nCur, int32 nMax );
};

class CRemoteFileTask{
public:
    CRemoteFileTask( const char* strURL );
    CRemoteFileTask( const char* strURL, void* pBuff, int32 nBuffSize );
    virtual ~CRemoteFileTask();
    int32 m_nMaskType;
    CRemoteFileTaskEvent* OnRemoteFileTaskObject;
    REMOTEFILEHANDLE m_hRemoteFileTaskHandle;
    int32 m_nID;
    void* m_pUserData0;
    void* m_pUserData1;
    void* m_pUserData2;
    void* m_pUserData3;

};



#endif
