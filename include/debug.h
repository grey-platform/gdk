/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: debug.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_DEBUG_H__
#define __GRAY_SDK_DEBUG_H__

//#include <include/stdtype.h>
#if defined( _DEBUG )
//////#include "../../engine/include/mem/memmgr.h"

////void * operator new(unsigned int size, const char *file, int line);
////
////void operator delete(void * p);
////
////void operator delete[]( void * p );
////
////void operator delete(void * p, const char *file, int line);
////
////void operator delete[]( void * p, const char *file, int line );

////////
////////#define NEW new(__FILE__, __LINE__)
////////#define SAFEDELETE( p ) if( p ) delete p, p = 0;
////////#elif defined(_APP_DEBUG_)
////////
//////////void * operator new( unsigned int size, const char *file, int line );
//////////
//////////void * operator new( unsigned int size, void *p);
//////////
//////////void operator delete(void * p);
//////////
//////////void operator delete[]( void * p );
//////////
//////////void operator delete(void * p, const char *file, int line);
//////////
//////////void operator delete[]( void * p, const char *file, int line );
////////#ifdef NEW
////////#undef NEW
////////#endif
////////
////////#define NEW new(__FILE__, __LINE__)
////////
////////
////////#ifdef SAFEDELETE
////////#undef SAFEDELETE
////////#endif
////////
////////#define SAFEDELETE( p ) if( p ) delete p, p = 0;

//#define NEW new(__FILE__, __LINE__)
//#define SAFEDELETE( p ) if( p ) delete p, p = 0;

#endif


#endif