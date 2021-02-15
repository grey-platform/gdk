/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: assert.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_ASSERT_H___
#define __GRAY_SDK_ASSERT_H___

#include <include/stdtype.h>

#ifdef _NATIVE_
#include <assert.h>
#else
#define assert ___assert___
#endif


EXTERN void ___assert___( bool8 exp );


#endif
