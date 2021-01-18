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

#ifndef __BIGIMAGE_RENDERITEM_H__
#define __BIGIMAGE_RENDERITEM_H__

#include <standard/math.h>
#include <standard/matrix3.h>
#include <standard/matrix4.h>
#include <standard/renderbuffer.h>
#include <standard/color.h>
#include <standard/texture.h>
#include <standard/material.h>
#include <bigimage/bigimageinterface.h>

class CRenderItem{
public:
    CRenderItem( CMatrix4* pWorldM, CMatrix4* pBillboardM );
    virtual ~CRenderItem();
    virtual int32 OnBeginRender();
    bool32 SetRenderBuffer(CVertexBuffer* pRenderBuffer );
    bool32 SetRenderBuffer(CVertexBuffer* pRenderBuffer, CIndexBuffer* pIndexBuffer );
    bool32 SetTexture( CTexture* pTexture );
    bool32 SetMaterial( CMaterial* pMaterial );
    bool32 SetShadowMaterial( CMaterial* pMaterial );
    bool32 SetOrder( int32 nOrder );
    int32 GetOrder();
    bool32 SetGroupOrder( int32 nOrder );
    int32 GetGroupOrder();
    bool32 SetVisible( bool32 bValue );
    bool32 GetVisible();
    bool32 SetUserData( int32 nValue );
    int32 GetUserData();
    bool32 SetPrimitiveType( _EPRIMITIVETYPE ePrimitiveType );
    _EPRIMITIVETYPE GetPrimitiveType();

    HRENDERELEMENTHANDLE m_hHandle;
    CMatrix4* m_pWorldM;
    CMatrix4* m_pBillboardM; //¹«¸æ°å¾ØÕó

    CMatrix4 m_tModelM;
    CMatrix4 m_tBindM;
    CMatrix4* m_vBoneMatrixces;
    int32 m_nBoneMatrixces;
    CMatrix4 m_tWorldModelM;
    CMatrix4 m_tViewWorldModelM;
    CMatrix4 m_tWorldModelInvertseM;
    CMatrix3 m_tNormalM;

    int32 m_eRenderType;
    bool32 m_bCastShadow;
    bool32 m_bReceiveShadow;
    _EMaterialSide m_eSide;
    _EBlendingModes m_eBlending;
    _ECustomBlendingEquations m_eBlendEquation;
    _ECustomBlendingFactors m_eBlendSrc;
    _ECustomBlendingFactors m_eBlendDst;
    bool32 m_bLineMode;
    bool32 m_bDepthTest;
    bool32 m_bDepthWrite;
    bool32 m_bPolygonOffset;
    float m_fPolygonOffsetFactor;
    float m_fPolygonOffsetUnits;
    bool32 m_bFogEnable;
    bool32 m_bLightEnable;
    bool32 m_nRenderStyle;

    CColor m_tDiffuseColor;
    CColor m_tEmissiveColor;
    CColor m_tSpecularColor;
    float m_fShiness;
    float m_fOpacity;

};

#endif
