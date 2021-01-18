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


#ifndef __BIGIMAGE_GAMEOBJECT_H__
#define __BIGIMAGE_GAMEOBJECT_H__

#include <standard/vector3.h>
#include <standard/quaternion.h>
#include <standard/matrix4.h>
#include <standard/texture.h>
#include <standard/list.h>
#include <bigimage/bigimageinterface.h>

class CGameObject{
public:
    CGameObject();
    virtual ~CGameObject();
    virtual void Init( const char* strFileName );
    virtual void Update( Vector3 pCameraPos, int32 nDelta, float fDelta, void* pUserData );
    virtual void SetTexture( CTexture* pTexture );
    virtual void ApplyTransform();
    virtual void AddChild( CGameObject* pGameObject );
    virtual void RemoveChild( CGameObject* pGameObject );
    virtual void ClearAllChild();
    virtual int32 GetRenderElementHandles( HRENDERELEMENTHANDLE *vRenderElementHandle, int32 nMaxCount ){ return 0;  }
    virtual void SetPosition( float x, float y, float z );
    virtual void SetRotation( float x, float y, float z );
    //virtual void SetRotationFormQuation( float x, float y, float z,  );
    virtual void SetScale( float x, float y, float z );
    virtual void SetViewPos( float x, float y, float z );
    virtual void SetVisible( bool32 bValue );
    virtual bool32 GetVisible();
    CVector3* GetPosition(){ return &m_tPosition; }
    CVector3* GetRotation(){ return &m_tRotation; }
    CVector3* GetScale(){ return &m_tScale; }

public:
    int32 m_nID;
    CGameObject* m_pParent;
    list<CGameObject*> m_vChildens;
    CVector3 m_tPosition;
    CVector3 m_tRotation;
    CQuaternion m_tQuaternion;
    CVector3 m_tScale;

public: //render element
    CMatrix4 m_tWorldM;
    CMatrix4 m_tBillboardM; //¹«¸æ°å¾ØÕó

    int32 m_nBillBoardType;
    
};

#endif

