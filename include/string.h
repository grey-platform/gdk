/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: string.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_STRING_H__
#define __GRAY_SDK_STRING_H__

#include <include/stdtype.h>
#ifdef _NATIVE_
#include <string.h>
#else
#define memchr ___memchr___
#define memcmp ___memcmp___
#define memcpy ___memcpy___
#define memmove ___memmove___
#define memset ___memset___
#define strcat ___strcat___
#define strchr ___strchr___
#define strcmp ___strcmp___
#define strcoll ___strcoll___
#define strcpy ___strcpy___
#define strcspn ___strcspn___
#define strerror ___strerror___
#define strlen ___strlen___
#define strncat ___strncat___
#define strncmp ___strncmp___
#define strncpy ___strncpy___
#define strpbrk ___strpbrk___
#define strrchr ___strrchr___
#define strspn ___strspn___
#define strstr ___strstr___
#define strtod ___strtod___
#define strtok ___strtok___
#define strtol ___strtol___
#define strtoul ___strtoul___
#define strxfrm ___strxfrm___
#endif


EXTERN void *___memchr___( const void *buffer, int ch, int count );
EXTERN int ___memcmp___( const void *buffer1, const void *buffer2, int count );
EXTERN void *___memcpy___( void *to, const void *from, int count );
EXTERN void *___memmove___( void *to, const void *from, int count );
EXTERN void *___memset___( void *buffer, int ch, int count );
EXTERN char *___strcat___( char *str1, const char *str2 );
EXTERN char *___strchr___( const char *str, int ch );
EXTERN int ___strcmp___( const char *str1, const char *str2 );
EXTERN int ___strcoll___( const char *str1, const char *str2 );
EXTERN char *___strcpy___( char *to, const char *from );
EXTERN int ___strcspn___( const char *str1, const char *str2 );
EXTERN char *___strerror___( int num );
EXTERN int ___strlen___( const char *str );
EXTERN char *___strncat___( char *str1, const char *str2, int count );
EXTERN int ___strncmp___( const char *str1, const char *str2, int count );
EXTERN char *___strncpy___( char *to, const char *from, int count );
EXTERN char *___strpbrk___( const char *str1, const char *str2 );
EXTERN char *___strrchr___( const char *str, int ch );
EXTERN int ___strspn___( const char *str1, const char *str2 );
EXTERN char *___strstr___( const char *str1, const char *str2 );
EXTERN double ___strtod___( const char *start, char **end );
EXTERN char *___strtok___( char *str1, const char *str2 );
EXTERN long ___strtol___( const char *start, char **end, int base );
EXTERN unsigned long ___strtoul___( const char *start, char **end, int base );
EXTERN int ___strxfrm___( char *str1, const char *str2, int num );


#endif
