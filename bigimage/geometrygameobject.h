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


#ifndef __BIGIMAGE_GEOMETRYGAMEOBJECT_H__
#define __BIGIMAGE_GEOMETRYGAMEOBJECT_H__

#include <bigimage/gameobject.h>
#include <bigimage/geometry.h>
#include <bigimage/renderitem.h>

class CGeometryGameObject: public CGameObject{
public:
    CGeometryGameObject();
    CGeometryGameObject( CGeometry* pGeometry, CTexture* pTexture );
    virtual ~CGeometryGameObject();
    void Init( CGeometry* pGeometry, CTexture* pTexture );
    virtual void Update( Vector3 pCameraPos, int32 nDelta, float fDelta, void* pUserData );
    virtual int32 GetRenderElementHandles( HRENDERELEMENTHANDLE *vRenderElementHandle, int32 nMaxCount );
    virtual void ApplyTransform();
    void SetOrder( int32 nOrder );
    void SetVisible( bool32 bVisible );

public:
    CGeometry* m_pGeometry;
    CTexture* m_pTexture;
    CRenderItem* m_pRenderElement;
};

#endif
