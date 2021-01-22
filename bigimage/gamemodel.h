/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: gamemodel.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_GAMEMODEL_H__
#define __BIGIMAGE_GAMEMODEL_H__

#include <standard/renderbuffer.h>
#include <standard/texture.h>
#include <standard/vector.h>

struct TGameObjectRenderPass{
    CVertexBuffer* m_pRenderBuffer;
    CTexture* m_pTexture;
};

class CGameModel;
class CGameModelEvent {
public:
    virtual CTexture* OnGetTexture(CGameModel* pGameModel, const char* strFileName );
};

class CGameObject;
class CGameModel{
public:
    CGameModel( void* pStream );
    virtual ~CGameModel();
    virtual void Init(CGameModelEvent* pGameModelEventObject);
    uint32 m_nKey;
    CGameModelEvent* m_pGameModelEventObject;
    vector< CTexture* >m_vTextureList;
};

CGameModel* CreateGameModel(void* pStream, uint32 nFileExt );

#endif
