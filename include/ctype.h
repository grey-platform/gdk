/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: ctype.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_CTYPE_H___
#define __GRAY_SDK_CTYPE_H___

#include <include/stdtype.h>

#ifdef _NATIVE_
#include <ctype.h>
#else
#define isalnum ___isalnum___
#define isalpha ___isalpha___
#define iscntrl ___iscntrl___
#define isdigit ___isdigit___
#define isgraph ___isgraph___
#define islower ___islower___
#define isprint ___isprint___
#define ispunct ___ispunct___
#define isspace ___isspace___
#define isupper ___isupper___
#define isxdigit ___isxdigit___
#define tolower ___tolower___
#define toupper ___toupper___
#endif

EXTERN int ___isalnum___( int ch );
EXTERN int ___isalpha___( int ch );
EXTERN int ___iscntrl___( int ch );
EXTERN int ___isdigit___( int ch );
EXTERN int ___isgraph___( int ch );
EXTERN int ___islower___( int ch );
EXTERN int ___isprint___( int ch );
EXTERN int ___ispunct___( int ch );
EXTERN int ___isspace___( int ch );
EXTERN int ___isupper___( int ch );
EXTERN int ___isxdigit___( int ch );
EXTERN int ___tolower___( int ch );
EXTERN int ___toupper___( int ch );


#endif
