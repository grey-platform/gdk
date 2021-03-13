/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: matrix4.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_MATRIX4_H__
#define __STANDARD_MATRIX4_H__

#include <include/stdtype.h>
#include <include/math.h>
#include <standard/vector3.h>
#include <standard/quaternion.h>

class CMatrix4{
public:
    static void Multiply( CMatrix4* retM, CMatrix4* leftM, CMatrix4* rightM );
    static void MultiplyVector3( CVector3* retV, CMatrix4* M, CVector3* pPos );
    CMatrix4();
    ~CMatrix4();
    void Set( CMatrix4* M );
    void Set( Matrix4 M );
    void Set( float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float _m, float n, float o, float p );
    void MakePerspective( float fFov, float fAspect, float fNear, float fFar );
    void MakeOrthographic( float width, float height, float zNearPlane, float zFarPlane );
    void MakeOrthographic( float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar );
    void MakeFrustum( float fLeft, float fRight, float fBottom, float fTop, float fNear, float fFar );
    void MakeLookAt( CVector3 *pEye, CVector3 *pTarget, CVector3 *pUp );
    void Compose( CVector3* pPos, CQuaternion* pQuaternion, CVector3* pScale );
    void GetRotationQuaternion( CQuaternion* ret );
    void GetInverse( CMatrix4* retM );
    void Identity();
    //float m[ 16 ];
   // union {
   //     struct {
            Matrix4 m;
   //     };
    //    struct {
           // float m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15;
   //     };
   // };
};


void Matrix4_Set(Matrix4 pMatrix0, Matrix4 pMatrix1);

void Matric4_IdentityScale(Matrix4 pMatrix, Vector3 pVector);

#endif
