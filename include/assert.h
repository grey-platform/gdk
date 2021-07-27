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

#define assert( exp ) if( !(exp) ){___assert___( 0, __FILE__, __LINE__ );}

//#define assert ___assert___
EXTERN void ___assert___( bool32 exp, const char* file, int fileno );


#endif
