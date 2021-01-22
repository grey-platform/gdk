/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: orbitcontrols.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_ORBITCONTROLS_H__
#define __BIGIMAGE_ORBITCONTROLS_H__

#include <bigimage/camera.h>
#include <standard/spherical.h>
#include <standard/vector2.h>

enum STATE{
    NONE = - 1,
    ROTATE = 0,
    DOLLY = 1,
    PAN = 2,
    TOUCH_ROTATE = 3,
    TOUCH_DOLLY_PAN = 4,
};


enum keys{
    LEFT = 37,
    UP = 38,
    RIGHT = 39,
    BOTTOM = 40,
};

// Mouse buttons
enum mouseButtons{
    ORBIT = 0,
    ZOOM = 1,
    _PAN = 2,
};

class COrbitControls{
public:
    COrbitControls( CCamera* object, float clientWidth, float clientHeight );
    ~COrbitControls();
    float getPolarAngle();
    float getAzimuthalAngle();
    void saveState();
    void reset();
    bool32 update();
    float getAutoRotationAngle();
    float getZoomScale();
    void rotateLeft( float angle );
    void rotateUp( float angle );
    void panLeft( float distance, CMatrix4 &objectMatrix );
    void panUp( float distance, CMatrix4 &objectMatrix );
    void pan( float deltaX, float deltaY );
    void dollyIn( float dollyScale );
    void dollyOut( float dollyScale );
    void handleMouseDownRotate( float x, float y );
    void handleMouseDownDolly( float x, float y );
    void handleMouseDownPan( float x, float y );
    void handleMouseMoveRotate( float x, float y );
    void handleMouseMoveDolly( float x, float y );
    void handleMouseMovePan( float x, float y );
    void handleMouseUp( float x, float y );
    void handleMouseWheel( float deltaY );
    void handleKeyDown( int32 keyCode );
    void onMouseDown( int32 button, float x, float y );
    void onMouseMove( float x, float y );
    void onMouseUp( int32 button, float x, float y );
    void onMouseWheel( float Y );


    CCamera* object;
    float clientWidth;
    float clientHeight;

    bool32 enabled;
    CVector3 target;
    float minDistance;
    float maxDistance;

    float minZoom;
    float maxZoom;

    float minPolarAngle;
    float maxPolarAngle;

    float minAzimuthAngle;
    float maxAzimuthAngle;

    bool32 enableDamping;
    float dampingFactor;

    bool32 enableZoom;
    float zoomSpeed;

    bool32 enableRotate;
    float rotateSpeed;

    bool32 enablePan;
    float panSpeed;

    bool32 screenSpacePanning;
    float keyPanSpeed;

    bool32 autoRotate;
    float autoRotateSpeed;

    bool32 enableKeys;

    CVector3 target0;
    CVector3 position0;
    float zoom0;

    CSpherical spherical;
    CSpherical sphericalDelta;

    STATE state;

    float EPS;
    float scale;

    CVector3 panOffset;
    bool32 zoomChanged;

    CVector2 rotateStart;
    CVector2 rotateEnd;
    CVector2 rotateDelta;

    CVector2 panStart;
    CVector2 panEnd;
    CVector2 panDelta;

    CVector2 dollyStart;
    CVector2 dollyEnd;
    CVector2 dollyDelta;

};

#endif
