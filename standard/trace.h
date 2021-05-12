#ifndef __STANDARD_TRACE_H__
#define __STANDARD_TRACE_H__

#include <include/stdtype.h>

class CTraceInfo{
public:
    CTraceInfo( const char* strFileName, int32 nLine, const char* strFuncName );
    ~CTraceInfo();

private:
    char m_strFileName[256];
    int32 m_nLine;
    char m_strFuncName[256];
};


#define TRACE CTraceInfo ___trace___info___( __FILE__, __LINE__, __FUNCTION__ );


#endif
