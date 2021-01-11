/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: stdarg.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_STDARG_H__
#define __GRAY_SDK_STDARG_H__

#include <include/stdtype.h>

#ifdef _NATIVE_
#include <stdarg.h>
#else
typedef char* va_list;
#define __INTSIZEOF(n) ((sizeof(n)+sizeof(int)-1)&~(sizeof(int) - 1))    //类型n的大小  
#define va_start(ap,v) ( ap = (va_list)&v + __INTSIZEOF(v) )             //ap指向第一个不定参数地址  
#define va_arg(ap,t) ( *(t *)((ap += __INTSIZEOF(t)) - __INTSIZEOF(t)) )  //下一个参数地址  返回当前ap指向的值,并且增加ap  
#define va_end(ap) ( ap = (va_list)0 )                                  // 将指针置为无效  
#endif

#endif