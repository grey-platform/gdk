/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: httprequest.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_HTTPREQUEST_H__
#define __STANDARD_HTTPREQUEST_H__

#include <include/stdtype.h>
#include <include/tools.h>

class CHttpRequest;
class CHttpRequestEvent{
public:
    virtual void OnComplate( CHttpRequest* pHttpRequest, void* pData, int32 nSize );
    virtual void OnError( CHttpRequest* pHttpRequest, void* pData, int32 nSize );
    virtual void OnProcess( CHttpRequest* pHttpRequest, int32 nCur, int32 nMax );
};

class CHttpRequest{
public:
    CHttpRequest( const char* strHost, int32 nPort, const char* strAddress );
    virtual ~CHttpRequest();
    uint32 m_nMaskType;
    CHttpRequestEvent* OnHttpEventObject;
    HTTPHANDLE m_hHttpRequest;

};



#endif
