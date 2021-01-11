/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: log.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_LOG_H__
#define __STANDARD_LOG_H__

#include <include/stdtype.h>
#include <include/tools.h>
#include <include/assert.h>

enum ELogType{
    ELT_Message,
    ELT_Info,
    ELT_Error,
    ELT_Warning,
    ELT_Debug,
    ELT_Count,
};

//#define ASSERT( c, format, ... ) if( !(c) )  LogOut( ELT_Error, __FILE__, __LINE__, format, __VA_ARGS__, "?","?","?","?","?","?","?","?","?","?","?","?" ),  CLog::Assert( false, __FILE__, __LINE__, format, __VA_ARGS__, "?","?","?","?","?","?","?","?","?","?","?","?"); 

#define LOG_MESSAGE LogInfo( ELT_Message, __FILE__, __LINE__ ); LogOut
#define LOG_INFO LogInfo( ELT_Info, __FILE__, __LINE__ ); LogOut
#define LOG_ERROR LogInfo( ELT_Error, __FILE__, __LINE__ ); LogOut
#define LOG_WARNING LogInfo( ELT_Warning, __FILE__, __LINE__ ); LogOut
#define LOG_DEBUG LogInfo( ELT_Debug, __FILE__, __LINE__ ); LogOut

#define TRACE LogInfo( ELT_Debug, __FILE__, __LINE__ ); LogOut("trace");
#define TRACEINFO LogInfo( ELT_Debug, __FILE__, __LINE__ ); LogOut
#define TRACEMEM LogInfo( ELT_Debug, __FILE__, __LINE__ ); LogOut("trace mem: "); LogMem

#define ASSERT( c ) if( !c ){ LogInfo( ELT_Debug, __FILE__, __LINE__ ); LogOut("assert"); assert( 0 ); }
//#define OPENTRACE() CLog::TraceEnable(True );
//#define CLOSETRACE() CLog::TraceEnable(False );

//class CLog{
//public:
//    static void Init( bool32 bLogEnable );
//    static void Final();
//    static void Write( ELogType eType, const char* strFileName, int32 nFileNo, const char* strFormat, ... );
//    static void Assert( bool bCondition, const char* strFileName, int32 nFileNo, const char* strFormat, ... );
//    static void Trace( const char* strFileName, int32 nFileNo );
//    static void TraceInfo( const char* strFormat, ... );
//    static void TraceEnable( bool32 bEnable );
//};

#endif
