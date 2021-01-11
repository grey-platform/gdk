/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: apps.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:  
    程序启动文件
*Others:
*Function List:
1. main
*History:
1.Date:
Author:
Modification:
**********************************************************************************/


#ifndef __GRAY_SDK_APPS_H__
#define __GRAY_SDK_APPS_H__

#include <include/stdtype.h>
#include <include/string.h>
#include <include/stdlib.h>

#ifdef _APP_DEBUG_
#ifdef _CONSOLE
#define MAIN \
________main________( int nType, int nParam0, int nParam1, int nParam2, int nParam3, int nParam4, int nParam5, int nParam6, int nParam7, int nParam8, int nParam9 );\
int main( int argc, char *argv[] ){ \
    int32 _nScreenWidth = 1280; \
    int32 _nScreenHeight = 720; \
    int32 _nMemorySize = 1024 * 1024 * 16;\
    int32 _nFileBuffSize = 0;\
    int32 _nConsole = 1;\
    for( int32 i = 1; i < argc; i ++ ){\
        if( strcmp( argv[i], "-w" ) == 0 ){\
            i ++;\
            _nScreenWidth = atoi( argv[i] );\
        } else if( strcmp( argv[i], "-h" ) == 0 ){\
            i ++;\
            _nScreenHeight = atoi( argv[i] );\
        } else if( strcmp( argv[i], "-memsize" ) == 0 ){\
            i ++;\
            _nMemorySize = atoi( argv[i] );\
        } else if( strcmp( argv[i], "-filebuffsize" ) == 0 ){\
            i ++;\
            _nFileBuffSize = atoi( argv[i] );\
        } else if( strcmp( argv[i], "-console" ) == 0 ){\
            i ++;\
            _nConsole = atoi( argv[i] );\
        }\
    }\
    return SubAppStart( &________main________, _nConsole, _nScreenWidth, _nScreenHeight, _nMemorySize, _nFileBuffSize );\
}\
int ________main________
#else
#define MAIN \
________main________( int nType, int nParam0, int nParam1, int nParam2, int nParam3, int nParam4, int nParam5, int nParam6, int nParam7, int nParam8, int nParam9 );\
int __stdcall WinMain( int32 hInstance, int32 hPrevInstance, char * lpCmdLine, int nCmdShow ){ \
    return SubAppStart( &_main, 0, 1280, 720, 0 );\
}\
int ________main________
#endif
#else
#define MAIN \
main
#endif



#ifdef _APP_DEBUG_
#ifdef _CONSOLE
#define WINMAIN \
________main________( int nType, int nParam0, int nParam1, int nParam2, int nParam3, int nParam4, int nParam5, int nParam6, int nParam7, int nParam8, int nParam9 );\
int main( int argc, char *argv[] ){ \
    int32 _nScreenWidth = 1280; \
    int32 _nScreenHeight = 720; \
    int32 _nMemorySize = 1024 * 1024 * 16;\
    int32 _nFileBuffSize = 0;\
    int32 _nConsole = 1;\
    for( int32 i = 1; i < argc; i ++ ){\
        if( strcmp( argv[i], "-w" ) == 0 ){\
            i ++;\
            _nScreenWidth = atoi( argv[i] );\
        } else if( strcmp( argv[i], "-h" ) == 0 ){\
            i ++;\
            _nScreenHeight = atoi( argv[i] );\
        } else if( strcmp( argv[i], "-memsize" ) == 0 ){\
            i ++;\
            _nMemorySize = atoi( argv[i] );\
        } else if( strcmp( argv[i], "-filebuffsize" ) == 0 ){\
            i ++;\
            _nFileBuffSize = atoi( argv[i] );\
        } else if( strcmp( argv[i], "-console" ) == 0 ){\
            i ++;\
            _nConsole = atoi( argv[i] );\
        }\
    }\
    return SubAppStart( &_main, _nConsole, _nScreenWidth, _nScreenHeight, _nMemorySize, _nFileBuffSize );\
}\
int ________main________
#else
#define WINMAIN \
________main________( int nType, int nParam0, int nParam1, int nParam2, int nParam3, int nParam4, int nParam5, int nParam6, int nParam7, int nParam8, int nParam9 );\
int __stdcall WinMain( int32 hInstance, int32 hPrevInstance, char * lpCmdLine, int nCmdShow ){ \
    return SubAppStart( &_main, 1, 1280, 720, 0 );\
}\
int ________main________
#endif
#else
#define WINMAIN \
main
#endif


#ifdef _APP_DEBUG_
EXTERN int SubAppStart( void* pfnMain, int nMode, int nWidth, int nHeight, int nMemorySize, int nFileBuffSize );
#endif

#define EVMCT_Init   ( 0 )
#define EVMCT_Update ( 1 )
#define EVMCT_Render ( 2 )
#define EVMCT_Final  ( 3 )
#define EVENT_HTTPREQUEST (4)
#define EVENT_SOUND (5)
#define EVENT_NEEDDATA (6)
#define EVENT_REMOTEFILETASK (7)

#endif
