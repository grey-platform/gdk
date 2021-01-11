/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: planematerial.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_PLANEMATERIAL_H__
#define __STANDARD_PLANEMATERIAL_H__

#include <include/stdtype.h>
#include <standard/material.h>
#include <standard/texture.h>
#include <standard/vector3.h>

class CPlaneMaterial: public CMaterial{
public:
    CPlaneMaterial( float fWidth, float fHeight );
    virtual ~CPlaneMaterial();
    virtual void Init();
    virtual void Begin();
    virtual void End();
    void RenderText( float x, float y, const char* strText, color32 c, int32 nStyle, color32 bk );
    void SetDiffuseTexture( CTexture* pTexture );
    void SetTexture( CTexture* pTexture );
    void SetPosition( float x, float y, float z );
    void SetColor( float r, float g, float b, float a );
    void SetBright( float v );
    void SetViewSize( float fWidth, float fHeight );

private:
    HMATERIALUNIFORM m_hMapAttributeHandle;
    HMATERIALUNIFORM m_hViewSizeAttributeHandle;
    HMATERIALUNIFORM m_hTranslateAttributeHandle;
    HMATERIALUNIFORM m_hColorAttributeHandle;
    HMATERIALUNIFORM m_hBrightAttributeHandle;
    CVector3 m_tViewSize;

};


#endif
