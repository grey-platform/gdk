/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: vector3.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_VECTOR3_H__
#define __STANDARD_VECTOR3_H__

#include <include/stdtype.h>
#include <include/math.h>


class CQuaternion;
class CMatrix4;
class CSpherical;

class CVector3{
public:
    CVector3();
    CVector3( float v );
    CVector3( float x, float y, float z );
    CVector3( float* v );
    ~CVector3();
    //Vector3 GetData();
    void Set( CVector3 &pVertor );
    void Set( float x, float y, float z ){
        X = x, Y = y, Z = z;
    }
    void Set(CSpherical &s);
    void Normalize();
    float Length();
    float Dot( CVector3 &v );
    bool Equals( const CVector3 &other ) const;
    CVector3* Cross( CVector3& v, CVector3& w );
    CVector3* CrossVectors( CVector3& a, CVector3& b );
    void MultiplyScalar( float s );
    float DistanceToSquared( CVector3& v );
    CVector3& ApplyQuaternion(CQuaternion &q);
    void SetFromMatrixColumn(CMatrix4 &m, int32 n);
    void TransformDirection(CMatrix4 *m, CVector3* r);
public:
    CVector3 operator + () const;
    CVector3 operator + ( const CVector3 &right ) const;
    CVector3 operator + ( const float val ) const;
    friend CVector3 operator +( float scalar, const CVector3 &value );
    CVector3& operator += ( const CVector3 &right );
    CVector3& operator += ( const float val );
    CVector3 operator - () const;
    CVector3 operator - ( const CVector3 &right ) const;
    CVector3 operator - ( const float val ) const;
    friend CVector3 operator -( float scalar, const CVector3 &value );
    CVector3& operator -= ( const CVector3 &right );
    CVector3& operator -= ( const float val );
    operator float* ( );
    operator const float* ( ) const;
    CVector3 operator * ( const CVector3 &right ) const;
    CVector3 operator * ( const float val ) const;
    friend CVector3 operator *( float scalar, const CVector3 &value );
    CVector3& operator *= ( const CVector3 &right );
    CVector3& operator *= ( const float val );
    CVector3 operator / ( const CVector3 &right ) const;
    CVector3 operator / ( const float val ) const;
    CVector3 operator ^ ( const CVector3 &right ) const;
    friend CVector3 operator /( float scalar, const CVector3 &value );
    CVector3& operator /= ( const CVector3 &right );
    CVector3& operator /= ( const float val );
    CVector3& operator = ( const CVector3 &right );
    bool operator == ( const CVector3 &right ) const;
    bool operator != ( const CVector3 &right ) const;

public:
   // union {
   //     struct {
   //         Vector3 m;
    //    };
    //    struct {
            float X, Y, Z;
    //    };
    //};
};

void Vector3_Set(Vector3 pVector, float v );
void Vector3_Set(Vector3 pVector, float x, float y, float z );
void Vector3_Set(Vector3 pVector0, Vector3 pVector1);

void Vector3_Add(Vector3 pVector0, Vector3 pVector1, Vector3 pVector2);
void Vector3_Sub(Vector3 pVector0, Vector3 pVector1, Vector3 pVector2);
void Vector3_Multiply(Vector3 pVector0, Vector3 pVector1, Vector3 pVector2);
void Vector3_Divide(Vector3 pVector0, Vector3 pVector1, Vector3 pVector2);
void Vector3_Add( Vector3 pVector0, Vector3 pVector1 );
void Vector3_Sub(Vector3 pVector0, Vector3 pVector1);
void Vector3_Multiply(Vector3 pVector0, Vector3 pVector1);
void Vector3_Divide(Vector3 pVector0, Vector3 pVector1);
void Vector3_Add(Vector3 pVector0, float values);
void Vector3_Sub(Vector3 pVector0, float values);
void Vector3_Multiply(Vector3 pVector0, float values);
void Vector3_Divide(Vector3 pVector0, float values);
void Vector3_CalcNormal( Vector3 pVector0, Vector3 pVector1, Vector3 pVector2, Vector3 pVector3 );




#endif
