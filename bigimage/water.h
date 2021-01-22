/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: renderitem.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_WATER_H__
#define __BIGIMAGE_WATER_H__

#include <bigimage/gameobject.h>
#include <bigimage/renderitem.h>
#include <bigimage/renderitemmanager.h>
#include <bigimage/perspectivecamera.h>
#include <standard/vector4.h>
#include <bigimage/watermaterial.h>

class CWater: public CGameObject{
public:
    CWater();
    virtual ~CWater();
    virtual int32 GetRenderElementHandles( HRENDERELEMENTHANDLE *vRenderElementHandle, int32 nMaxCount );
    virtual void Update( Vector3 pCameraPos, int32 nDelta, float fDelta, void* pUserData );
    virtual void Render( CCamera* pCamera, CVector3 &tSunDirection, CColor& tSunColor, CColor& tFogColor, float fFogNear, float fFogFar  );
    float alpha;
    float time;
    float size;
    bool32 m_bVisible;
    CColor waterColor;
    CColor mirrorColor;
    CVector3 eye;
    float distortionScale;
    int32 side;
    CVector3 normal;
    CVector3 mirrorWorldPosition;
    CVector3 cameraWorldPosition;
    CMatrix4 rotationMatrix;
    CVector3 lookAtPosition;
    CVector4 clipPlane;
    CVector3 view;
    CVector3 target;
    CVector4 q;
    CMatrix4 textureMatrix;
    CPerspectiveCamera* mirrorCamera;

private:
    void Init();
    CRenderItem* m_pRenderElement;
    CVertexBuffer* m_pRenderBuffer;
    CWaterMaterial* m_pMaterial;
    CTexture* m_pNormalTexture;
    CTexture* m_pMirrorTexture;
    CRenderItemManager* m_pWaterRenderManager;
};

#endif

