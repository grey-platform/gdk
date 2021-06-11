/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: stdlib.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_STDLIB_H__
#define __GRAY_SDK_STDLIB_H__

#include <include/stdtype.h>

//typedef struct _div_t{
//    int quot;
//    int rem;
//} div_t;
//
//typedef struct _ldiv_t{
//    long quot;
//    long rem;
//} ldiv_t;


#define calloc ___calloc___
#define free ___free___
#define malloc ___malloc___
#define realloc ___realloc___
#define abs ___abs___
//#define div ___div___
//#define ldiv ___ldiv___
#define atof ___atof___
#define atoi ___atoi___
#define atol ___atol___
//#define abort ___abort___
#define atexit ___atexit___
#define bsearch ___bsearch___
//#define exit ___exit___
#define getenv ___getenv___
#define qsort ___qsort___
#define rand ___rand___
#define srand ___srand___
#define system ___system___
#define strtof ___strtof___

#define _RAND_MAX_ 0x7fff
#define setmallocbuffer __setmallocbuffer__



//EXTERN void __setmallocbuffer__( void* p );
EXTERN void *___calloc___( int num, int size );
EXTERN void ___free___( void *ptr );
EXTERN void *___malloc___( int size );
EXTERN void *___realloc___( void *ptr, int size );
EXTERN int ___abs___( int num );
//div_t ___div___( int numerator, int denominator );
//ldiv_t ___ldiv___( long numerator, long denominator );
EXTERN float ___atof___( const char *str );
EXTERN int ___atoi___( const char *str );
EXTERN long ___atol___( const char *str );
EXTERN void ___abort___( void );
EXTERN int ___atexit___( void( *func )(void) );
EXTERN void *___bsearch___( const void *key, const void *buf, int num, int size, int( *compare )(const void *, const void *) );
EXTERN void ___exit___( int exit_code );
EXTERN char *___getenv___( const char *name );
//EXTERN void ___qsort___( void *buf, int num, int size, int( *compare )(const void *, const void *) );
//buf:要比较的数据    
//num:数据的个数    
//structsize:单个数据的大小    
//comparepos:单个数据要比较的位置在哪里   
//compareDataType:单个数据要比较的数据类型（0：float，1：int32, 2:uint32）   
//order:升序还是降序（0：升序 1：降序） 
EXTERN void ___qsort___( void* buf, int num, int structsize, int comparepos, int compareDataType, int order );

EXTERN int ___rand___( void );
EXTERN void ___srand___( unsigned seed );
EXTERN int ___system___( const char *command );
EXTERN float ___strtof___( const char *nptr, char **endptr );


#endif
