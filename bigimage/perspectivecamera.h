/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: perspectivecamera.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_PERSPECTIVECAMERA_H__
#define __BIGIMAGE_PERSPECTIVECAMERA_H__

#include <bigimage/camera.h>

class CPerspectiveCamera: public CCamera{
public:
    CPerspectiveCamera( float fFov, float fAspect, float fNear, float fFar );
    virtual ~CPerspectiveCamera();
    virtual void SetViewOffset( float fFullWidth, float fFullHeight, float fX, float fY, float fWidth, float fHeight );
    virtual void UpdateProjectionMatrix();
public:
    float m_fFov;
    float m_fAspect;
    float m_fNear;
    float m_fFar;
    float m_fFullWidth;
    float m_fFullHeight;
    float m_fX;
    float m_fY;
    float m_fWidth;
    float m_fHeight;
    
};

#endif
