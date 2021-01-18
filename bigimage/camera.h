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


#ifndef __BIGIMAGE_CAMERA_H__
#define __BIGIMAGE_CAMERA_H__

#include <standard/matrix4.h>
#include <bigimage/bigimageinterface.h>
#include <bigimage/renderitemmanager.h>

class CCamera {
public:
    CCamera();
    virtual ~CCamera();
    virtual void LookAt( float x, float y, float z );
    virtual void UpdateMatrix( CMatrix4 *pParentM );
    void TranslateX( float distance );
    void TranslateY( float distance );
    void TranslateZ( float distance );
    void TranslateOnAxis( CVector3 &v, float distance );
    void Init();

    virtual void UpdateProjectionMatrix();
    void AddRenderElement( HRENDERELEMENTHANDLE hHandle );
    void RemoveRenderElement( HRENDERELEMENTHANDLE hHandle );
    void Render();
    void UpdateRenderList();

public:
    void UpdateLook();
    CVector3 m_tPosition;
    CVector3 m_tView;
    CVector3 m_tUp;
    CQuaternion m_tQuaternion;
    CMatrix4 m_tMatrixWorld;
    CMatrix4 m_tMatrixWorldInverse;
    CMatrix4 m_tProjectionMatrix;
    CMatrix4 m_tProjectionMatrixInverse;

    CMatrix4 m_tProjectionWorldInverse, m_pWorldProjectionInverse;
    CMatrix4 m_tProjScreenMatrix;
    float zoom;

    CRenderItemManager* m_pRenderElementManager;
};


#endif
