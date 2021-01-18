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


#ifndef __BIGIMAGE_LIGHT_H__
#define __BIGIMAGE_LIGHT_H__

#include <standard/color.h>
#include <bigimage/renderitemmanager.h>
#include <standard/texturetarget.h>

typedef uint32 HLIGHTHANGLE;

class CLight{
public:
    CLight();
    virtual ~CLight();
    virtual void Update();
    virtual void BeginRender( int32 nViewportWidth, int32 nViewportHeight );
    virtual void EndRender();
    virtual HTEXTUREHANDLE GetShadowTextureHandle();
    virtual void AddRenderElement( HRENDERELEMENTHANDLE hHandle );
    virtual void RemoveRenderElement( HRENDERELEMENTHANDLE hHandle );
    virtual void SetPosition( float x, float y, float z );
    virtual void SetViewPort( float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar );
    virtual void SetDirectionPos( float x, float y, float z );
    virtual CVector3* GetDirectionPos();
    virtual CColor* GetColor();
    void Render();
    void UpdateRenderList();

public:
    CMatrix4 projectionMatrix;
    CMatrix4 viewMatrix;
    CMatrix4 worldMatrix;
    CMatrix4 matrixWorldInverse;
    CMatrix4 projScreenMatrix;
    CMatrix4 shadowMatrix;
    float m_fShadowBias;
    float m_fShadowRadius;
    float m_vShadowMapSize[2];
    CVector3 m_tPosition;
    CRenderItemManager* m_pRenderElementManager;
    CTextureTarget* m_pTextureDepth;
};

#endif
