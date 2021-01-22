/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: springaction.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_SPRINGACTION_H__
#define __BIGIMAGE_SPRINGACTION_H__

#include <bigimage/action.h>

class CSpringAction: public CAction{
public:
    CSpringAction( float *pValue, float fMin, float fMax, float fSpeed, bool32 bDir );
    virtual ~CSpringAction();
    virtual int32 Update( float fDelta );

private:
    float m_fMin;
    float m_fMax;
    float m_fSpeed;
    bool32 m_bDir;  //true 从小到大， false从大到小
    float *m_pValue;

};

#endif

