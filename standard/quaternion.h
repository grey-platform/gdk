/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: quaternion.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_QUATERNION_H__
#define __STANDARD_QUATERNION_H__

#include <include/stdtype.h>
#include <include/math.h>
#include <standard/vector3.h>
//#include <standard/matrix4.h>
class CMatrix4;
class CQuaternion{
public:
    CQuaternion();
    CQuaternion( float x, float y, float z, float w );
    ~CQuaternion();
    //Quaternion GetData();
    void Set( float x, float y, float z, float w ){
        X = x, Y = y, Z = z, W = w;
    }
    void Set( CQuaternion& q ){
        X = q.X, Y = q.Y, Z = q.Z, W = q.W;
    }
    void SetEuler( float x, float y, float z );
    void GetEuler( float *x, float *y, float *z );
    CQuaternion* SetFromRotationMatrix( CMatrix4* m );
    CQuaternion& SetFromUnitVectors( CVector3 &vFrom, CVector3 &vTo );
    CQuaternion& Inverse();
    float Dot( CQuaternion& q );
    CQuaternion& Normalize();
    float Length();

    float X, Y, Z, W;
};



#endif
