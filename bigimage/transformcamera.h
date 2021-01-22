/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: transformcamera.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_TRANSFORMCAMERA_H__
#define __BIGIMAGE_TRANSFORMCAMERA_H__

#include <bigimage/camera.h>

class CTransformCamera: public CCamera{
public:
    CTransformCamera( float fFov, float fAspect, float fNear, float fFar );
    virtual ~CTransformCamera();
    void RotateView( float angle, float x, float y, float z );
    void MoveView( float x, float y );
    void SetViewPos( float x, float y, float z );
    void SetTargetPos( float x, float y, float z );
    void SetUpPos( float x, float y, float z );
    void MouseMove( float x, float y );
    void Zoom( float z );
    void Apply();

private:
    float mouseX, mouseY;
};

#endif

