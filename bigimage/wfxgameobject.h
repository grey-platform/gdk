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


#ifndef __BIGIMAGE_WFXGAMEOBJECT_H__
#define __BIGIMAGE_WFXGAMEOBJECT_H__

#include <bigimage/gameobject.h>
#include <bigimage/wfxgamemodel.h>

class CWFXParticleManager;
typedef uint32 HOBJECTHANDLE;
class CWFXGameObject: public CGameObject{
public:
    CWFXGameObject();
    virtual ~CWFXGameObject();
    virtual void Init(CGameModelEvent* pGetTextureObject, const char* strFileName );
    virtual void Init(CGameModelEvent* pGetTextureObject, const char* strFileName, void* pFileStream );
    virtual void Init(CGameModelEvent* pGetTextureObject, const char* strFileName, Vector3 sStartPos, Vector3 sTargetPos );

    virtual void Update( Vector3 pCameraPos, int32 nDelta, float fDelta, void* pUserData );
    virtual int32 GetRenderElementHandles( HRENDERELEMENTHANDLE *vRenderElementHandle, int32 nMaxCount );
    virtual int32 OnFrame( int32 nFrame );
    virtual int32 OnAnimationEnd( int32 nAnimation );

    bool32 Intersect( HOBJECTHANDLE hRayCaster, Matrix4 m, float vRet[3] );
    bool32 ResetEffect();
    

    int32 GetSequenceCount();
    void GetSeqenceInfo( int32 nIndex, char* strText, float *pStartTime, float *pEndTime, float *pPlaySpeed );
    void SetAnimaltionIndex( int32 nIndex, int32 nNextIndex );
    int32 GetAnimationIndex();
    CWFXGameModel* GetGameModel();

protected:
    uint32 m_hWFXObjectHandle;
    CGameModel* m_pGameModelReference;

};


#endif

