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


#ifndef __BIGIMAGE_DIRECTIONALLIGHT_H__
#define __BIGIMAGE_DIRECTIONALLIGHT_H__

#include <bigimage/light.h>

class CDirectionalLight: public CLight{
public:
    CDirectionalLight();
    CDirectionalLight( int32 nWidth, int32 nHeight );
    virtual ~CDirectionalLight();
    virtual void BeginRender( int32 nViewportWidth, int32 nViewportHeight );
    virtual void EndRender();
    virtual void Update();
    virtual void SetPosition( float x, float y, float z );
    virtual void SetViewPort( float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar );
    virtual void SetDirectionPos( float x, float y, float z );
    virtual CVector3* GetDirectionPos(){ return &m_tDirection; }
    virtual CColor* GetColor();
    void Move( float x, float y, float z );

    CColor m_tColor;
    float m_fLeft, m_fRight, m_fTop, m_fBottom, m_fNear, m_fFar;
    CVector3 n_tView;
    CVector3 m_tDirection;
};






#endif




