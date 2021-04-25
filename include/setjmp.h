/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: setjmp.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_STJUMP_H__
#define __GRAY_SDK_STJUMP_H__

#include <include/stdtype.h>

#define _JBLEN  16
#define _JBTYPE int
typedef _JBTYPE jmp_buf[_JBLEN];


#define longjmp ___longjmp___
#define setjmp ___setjmp___


EXTERN void ___longjmp___( jmp_buf envbuf, int status );

EXTERN int ___setjmp___( jmp_buf envbuf );

#endif