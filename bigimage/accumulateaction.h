/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: applite.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __BIGIMAGE_ACCUMULATEACTION_H__
#define __BIGIMAGE_ACCUMULATEACTION_H__


#include <bigimage/action.h>

class CAccumulateaction: public CAction{
public:
    CAccumulateaction( float *pValue, float fSpeed, bool32 bDir );
    virtual ~CAccumulateaction();
    virtual int32 Update( float fDelta );

private:
    float *m_pValue;
    float m_fSpeed;
    bool32 m_bDir;//true ¼Ó£¬ false ¼õ

};

#endif

