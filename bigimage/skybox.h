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


#ifndef __BIGIMAGE_SKYBOX_H__
#define __BIGIMAGE_SKYBOX_H__

#include <bigimage/gameobject.h>
#include <standard/renderbuffer.h>
#include <bigimage/renderitem.h>
#include <bigimage/renderitemmanager.h>

class CSkyBox: public CGameObject{
public:
    CSkyBox( CMaterial* pMaterial );
    virtual ~CSkyBox();
    virtual int32 GetRenderElementHandles( HRENDERELEMENTHANDLE *vRenderElementHandle, int32 nMaxCount );
    virtual void Update( Vector3 pCameraPos, int32 nDelta, float fDelta, void* pUserData );
    void SetTexture( const char* strFileDir );
    void Render();

private:
    void Init( CMaterial* pMaterial );
    char m_strFileName[64];
    CRenderItemManager* m_pRenderManager;
    CTexture* m_pTexture[6];
    CVertexBuffer* m_vRenderBuffer[6];
    CRenderItem* m_vRenderElement[6];
};

#endif

