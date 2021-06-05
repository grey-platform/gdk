/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: stdtype.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_STDTYPE_H__
#define __GRAY_SDK_STDTYPE_H__

#ifndef NULL
#define NULL 0
#endif

typedef char int8;
typedef short int16;
typedef int int32;
typedef unsigned char byte;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned int bool32;
typedef unsigned char bool8;

typedef void* object32;
typedef uint32 color32;
typedef struct{
    byte r, g, b;
}color24;

typedef uint32 HOBJECTHANDLE;

#ifndef _NATIVE_
typedef uint32 size_t;
typedef int ptrdiff_t;
typedef int intptr_t;
#else
//typedef uint32 size_t;
#endif


#define False 0
#define True  1

#ifdef CPLUS
#ifndef _APP_DEBUG_
typedef unsigned char bool;
#define false 0
#define true 1
#endif
#endif

#define INTTOFLOAT( i, f ) *(int*)&f = i
#define GETHEXVALUE( v ) *(uint32*)&(v)


#define OFFSETOF(type, f) ((uint32)((char *)&((type *)0)->f - (char *)(type *)0))


#ifdef _COMPILE_SDK_
#define __COMPILE_SDK__
#else
#ifndef _NATIVE_
#define __COMPILE_SDK__
#endif
#endif

//


#ifdef CPLUS
#ifdef _APP_DEBUG_
#define EXTERN
void debug_output( const char* strText );
void debug_outputstring( const char* strText );
void debug_outputintvalue( int value );
void* debug_malloc( unsigned int size, const char* strFileName, int nFileNo );
void* debug_calloc( unsigned int count, unsigned int size, const char* strFileName, int nFileNo );
void* debug_realloc( void* p, unsigned int size, const char* strFileName, int nFileNo );
void debug_free( void* p, const char* file, int line );

void* debug_new( unsigned int size, const char* strFileName, int nFileNo );

//#ifdef OVERRIDENEW 
//inline void* operator new(unsigned int size, const char* file, int line){
//    return debug_malloc( size, file, line );
//}
inline void* operator new(unsigned int size, const char* file, int line){
    return debug_new( size, file, line );
}
void operator delete(void* p);
void operator delete[]( void* p );
void operator delete(void* p, const char* file, int line);
void operator delete[]( void* p, const char* file, int line );
//#endif

#define new new( __FILE__, __LINE__ )
#define MALLOC( s ) debug_malloc( s, __FILE__, __LINE__ )
#define REALLOC( p, s ) debug_realloc(p,s, __FILE__, __LINE__)
#define CALLOC( n, s ) debug_calloc( n, s, __FILE__, __LINE__ )
#define FREE( p ) if( p ) debug_free( p, __FILE__, __LINE__ ), p = 0;

#else
#define EXTERN extern "C"
#define MALLOC( s ) malloc( s )
#define REALLOC( p, s ) realloc(p,s)
#define CALLOC( n, s ) calloc( n, s )
#define FREE( p ) if( p ) free( p ), p = 0;

#endif



#define NEW new
#define DELETE( p )  if( p ) delete( p ), p = 0;
#define NEW2DARRAY( p, T, x, y ){\
p = (T**)MALLOC( sizeof( T* ) * y );\
p[0] = (T*)MALLOC( sizeof( T ) * (x * y) );\
{ for( int32 i = 1; i < y; i++ ) p[i] = p[i - 1] + x; }\
}
#define DELETE2DARRAY( T, p ){\
if( p ){FREE( p[0] );FREE( p );}\
p = 0;\
}
#elif _NATIVE_
//#define EXTERN extern "C"
#else
#define EXTERN extern __declspec(dllimport)
#define STDCALL __cdecl
typedef unsigned char bool;
#define false 0
#define true 1
#endif


#include <include/debug.h>

#endif
