/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: directionlightscene.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_DIRECTIONLIGHTSCENE_H__
#define __BIGIMAGE_DIRECTIONLIGHTSCENE_H__

#include <bigimage/scene.h>
#include <bigimage/shadowmaterial.h>
#include <bigimage/wfxstanardmaterial.h>

class CDirectionalLight;
class CDirectionLightScene: public CScene{
public:
    static float _fCameraX;
    static float _fCameraY;
    CDirectionLightScene();
    virtual ~CDirectionLightScene();
    virtual void Update( float fDelta );
    virtual void Render( CTextureTarget* pTextureTarget, int32 nViewportWidth, int32 nViewportHeight );
    virtual CLight* GetLight();
    virtual CSkyBox* GetSkyBox(){ return m_pSkyBox;  }
    virtual CWater* GetWater(){ return m_pWater; }
//    void SetAmbientLightColor( CColor tColor );
//    void SetFogInfo( CColor tFogColor, float fFogNear, float fFogFar );
    virtual void AddRenderElement( CGameObject* pGameObject );
    virtual void RemoveRenderElement( CGameObject* pGameObject );
    void SetSkyBoxInfo( int32 nSize, const char* strFileName );
    CColor m_tAmbientLightColor;
    CColor m_tFogColor;
    float m_fFogNear;
    float m_fFogFar;


public:
    CSkyBox* m_pSkyBox;
    CWater* m_pWater;
    CDirectionalLight* m_pLight;
    CShadowMaterial* m_pShadowMaterial;
    CWFXStandardMaterial* m_pWFXStandardMaterial;
};

#endif
