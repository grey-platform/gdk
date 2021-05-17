#ifndef __STANDARD_TRACE_H__
#define __STANDARD_TRACE_H__


#ifdef _APP_DEBUG_

#include <include/stdtype.h>
#include <standard/list.h>
#include <standard/map.h>

struct STrackInfo{
    char m_strFuncName[48];
    byte m_vParameData[128];
    int32 m_nAddress;
};

struct STrackFuncInfo{
    char m_strFuncName[48];
    uint32 m_nHashCode;
    uint32 m_nCallCount;
    uint32 m_nCallRunTime;
};

class CGreyTrace{
public:
    static void OutTrackState();
    static uint32 __HashString( const char* strText );
    static list<STrackInfo>* m_vTrackInfo;
    static map<uint32, STrackFuncInfo>* m_vTrackFuncInfo;
    static bool32 m_bGreyTraceLocked;
    CGreyTrace( const char* strFuncName );
    ~CGreyTrace();
private:
    uint32 m_nHashCode;
    uint32 m_nCallTime;
};


#define TRACE CGreyTrace ___trace___info___( __FUNCTION__ )
#define TRACESTR( s ) CGreyTrace ___trace___info___( s )
#define TRACKOUT CGreyTrace::OutTrackState()

#else

#define TRACE
#define TRACESTR( s )
#define SETTRACE( v )
#define TRACKOUT

#endif

#endif
