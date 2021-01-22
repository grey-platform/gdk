/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: flycameracontrol.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_FLYCAMERACONTROL_H__
#define __BIGIMAGE_FLYCAMERACONTROL_H__

#include <bigimage/camera.h>
class CFlyCameraControl {
public:
    CFlyCameraControl( CCamera *pCamera );
    virtual ~CFlyCameraControl();
    void SetPosition( float x, float y, float z );
    void SetView( float x, float y, float z );
    void OnMouseMove( float x, float y );
    void MoveForward( float fSpeed );
    void MoveLateral( float fSpeed );
    void update( float delta );
    void updateMovementVector();
    void updateRotationVector();
    void RotateView( float angle, float x, float y, float z );

protected:
private:
    CCamera *object;
    float movementSpeed;
    float lookSpeed;
    bool32 lookVertical;
    bool32 autoForward;
    bool32 activeLook;
    bool32 heightSpeed;
    float heightCoef;
    float heightMin;
    float heightMax;
    bool32 constrainVertical;
    float verticalMin;
    float verticalMax;
    float autoSpeedFactor;
    float mouseX, mouseY;
    float lat, lon, phi, theta;
    bool32 moveForward, moveBackward, moveLeft, moveRight, moveUp, moveDown, freeze;
    bool32 m_bRotate;
    int32 viewHalfX, viewHalfY;
};

#endif

