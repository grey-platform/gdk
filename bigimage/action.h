/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: action.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __BIGIMAGE_ACTION_H__
#define __BIGIMAGE_ACTION_H__

#include <include/stdtype.h>

class CAction{
public:
    CAction();
    virtual ~CAction();
    virtual int32 Update( float fDelta );
};

#endif

