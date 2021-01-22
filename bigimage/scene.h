/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: scene.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_SCENE_H__
#define __BIGIMAGE_SCENE_H__

#include <bigimage/gameobject.h>
#include <bigimage/camera.h>
#include <bigimage/light.h>
#include <bigimage/skybox.h>
#include <bigimage/water.h>
#include <bigimage/wfxgameparticlemanager.h>
#include <bigimage/wfxgameparticlematerial.h>
#include <standard/texturetarget.h>

class CScene;
class CSceneEvent {
public:
    virtual void OnUpdate(CScene* pScene, float fDelta, int32 nCode);
    virtual void OnRender(CScene* pScene, int32 nCode);
};

class CScene: public CGameObject{
public:
    static CScene* m_pCurrentActiveScene;
public:    
    CScene();
    virtual ~CScene();
    virtual void Update( float fDelta );
    virtual void Render( CTextureTarget* pTextureTarget, int32 nViewportWidth, int32 nViewportHeight );
    virtual CCamera* GetCamera();
    virtual CLight* GetLight();
    virtual CSkyBox* GetSkyBox();
    virtual CWater* GetWater();
    void SetCamera( CCamera* pCamera );
    virtual void AddRenderElement( CGameObject* pGameObject );
    virtual void RemoveRenderElement( CGameObject* pGameObject );
    CWFXGameParticleMaterial* GetParticleMaterial(){ return m_pParticlaMaterial; }

    CSceneEvent* m_pSceneEventObject;

protected:
    void UpdateParticles( float fDelta );
    void RenderParticles();
    CCamera* m_pCamera;
    CColor m_tClearColor;
    CWFXGameParticleMaterial* m_pParticlaMaterial;
    CWFXGameParticleManager* m_pWFXParticleManager;

};

#endif
