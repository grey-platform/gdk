/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: time.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_TIME_H__
#define __GRAY_SDK_TIME_H__

#include <include/stdtype.h>

#ifdef _NATIVE_
#include <time.h>
#else
#define asctime ___asctime___
#define clock ___clock___
#define ctime ___ctime___
#define difftime ___difftime___
#define gmtime ___gmtime___
#define localtime ___localtime___
#define mktime ___mktime___
#define strftime ___strftime___
#define time ___time___

#define CLOCKS_PER_SEC  (1000)
#endif


struct _tm{
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
};

EXTERN char *___asctime___( const struct _tm *ptr );
EXTERN unsigned int ___clock___( void );
EXTERN char *___ctime___( const unsigned int *_time );
EXTERN float ___difftime___( unsigned int time2, unsigned int time1 );
EXTERN struct _tm *___gmtime___( const unsigned int *_time, struct _tm* stm );
EXTERN struct _tm *___localtime___( const unsigned int *_time, struct _tm* stm );
EXTERN unsigned int ___mktime___( struct _tm *_time );
EXTERN int ___strftime___( char *str, int maxsize, const char *fmt, struct _tm *_time );
EXTERN unsigned int ___time___( unsigned int *_time );

#endif
