/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: math.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_MATH_H__
#define __GRAY_SDK_MATH_H__

#include <include/stdtype.h>
#ifdef _NATIVE_
#include <math.h>
#else
#define acos ___acos___
#define asin ___asin___
#define atan ___atan___
#define atan2 ___atan2___
#define ceil ___ceil___
#define cos ___cos___
#define cosh ___cosh___
#define exp ___exp___
#define fabs ___fabs___
#define floor ___floor___
#define fmod ___fmod___
#define frexp ___frexp___
#define labs ___labs___
#define ldexp ___ldexp___
#define log ___log___
#define log10 ___log10___
#define modf ___modf___
#define pow ___pow___
#define sin ___sin___
#define sinh ___sinh___
#define sqrt ___sqrt___
#define tan ___tan___
#define tanh ___tanh___
#define isfinite ___isfinite___
#define isnormal ___isnormal___
#define isnan ___isnan___
#define isinf ___isinf___

#ifndef _HUGE_ENUF
//#define _HUGE_ENUF  1e+300  // _HUGE_ENUF*_HUGE_ENUF must overflow
#define _HUGE_ENUF  1e+30  // _HUGE_ENUF*_HUGE_ENUF must overflow
#endif

#define INFINITY   ((float)(_HUGE_ENUF * _HUGE_ENUF))
#define HUGE_VAL   ((float)INFINITY)
#define HUGE_VALF  ((float)INFINITY)
//#define HUGE_VALL  ((long double)INFINITY)
#define NAN        ((float)(INFINITY * 0.0F))

#endif



EXTERN float ___acos___( float arg );
EXTERN float ___asin___( float arg );
EXTERN float ___atan___( float arg );
EXTERN float ___atan2___( float y, float x );
EXTERN float ___ceil___( float num );
EXTERN float ___cos___( float arg );
EXTERN float ___cosh___( float arg );
EXTERN float ___exp___( float arg );
EXTERN float ___fabs___( float arg );
EXTERN float ___floor___( float arg );
EXTERN float ___fmod___( float x, float y );
EXTERN float ___frexp___( float num, int *exp );
EXTERN long ___labs___( long num );
EXTERN float ___ldexp___( float num, int exp );
EXTERN float ___log___( float num );
EXTERN float ___log10___( float num );
EXTERN float ___modf___( float num, float *i );
EXTERN float ___pow___( float base, float exp );
EXTERN float ___sin___( float arg );
EXTERN float ___sinh___( float arg );
EXTERN float ___sqrt___( float num );
EXTERN float ___tan___( float arg );
EXTERN float ___tanh___( float arg );
EXTERN int ___isfinite___( float x );
EXTERN int ___isnormal___( float x );
EXTERN int ___isnan___( float x );
EXTERN int ___isinf___( float x );

typedef float Vector2[2];
typedef float Vector3[3];
typedef float Vector4[4];
typedef float Quaternion[4];
typedef float Matrix3[9];
typedef float Matrix4[16];
typedef float Color[4];
typedef byte  Double_[8];
typedef byte  Int64_[8];

EXTERN void Math_Vector3_Normalize( Vector3 pVector );
EXTERN float Math_Vector3_Length( Vector3 pVector );

EXTERN void Math_Vector3_RotateX(Vector3 pRet, float fValue);
EXTERN void Math_Vector3_RotateY(Vector3 pRet, float fValue);
EXTERN void Math_Vector3_RotateZ(Vector3 pRet, float fValue);
EXTERN bool32 Math_Vector3_BoundPointSphere(Vector3 sPosDot, float fDistance, Vector3 sPosA, Vector3 sPosB);
EXTERN void Math_Vector3_ApplyProjection( Matrix4 pMatrix, Vector3 a, Vector3 v );

EXTERN void Math_Quaternion_SetEuler( Quaternion q, float x, float y, float z );
EXTERN void Math_Matrix3_Identity( Matrix3 pMatrix );
EXTERN void Math_Matrix3_GetNormalMatrix( Matrix4 pMatrix, Matrix3 pRet );

EXTERN void Math_Matrix4_Identity( Matrix4 pMatrix );
EXTERN void Math_Matrix4_MakePerspective( Matrix4 pMatrix, float fFov, float fAspect, float fNear, float fFar );
EXTERN void Math_Matrix4_MakeOrthographic( Matrix4 pMatrix, float fLeft, float fRight, float fTop, float fBottom, float fNear, float fFar );
EXTERN void Math_Matrix4_MakeFrustum( Matrix4 pMatrix, float fLeft, float fRight, float fBottom, float fTop, float fNear, float fFar );
EXTERN void Math_Matrix4_MakeLookAt( Matrix4 pMatrix, Vector3 pEye, Vector3 pTarget, Vector3 pUp );
EXTERN void Math_Matrix4_Multiply( Matrix4 pRet, Matrix4 pLeftM, Matrix4 pRightM );
EXTERN void Math_Matrix4_Compose( Matrix4 pRet, Vector3 pPos, Quaternion pQuaternion, Vector3 pScale );
EXTERN void Math_Matrix4_GetRotationQuaternion( Quaternion pRet, Matrix4 pMatrix );
EXTERN void Math_Matrix4_GetInverse( Matrix4 pRet, Matrix4 pMatrix );
EXTERN void Math_Matrix4_MultiplyVector3( Vector3 pRet, Matrix4 pMatrix, Vector3 pPos );

EXTERN void Math_Matrix4_MultiplyVector4(Vector4 pRet, Matrix4 pMatrix, Vector4 pPos);
EXTERN void Math_Matrix4_Translate(Matrix4 pMatrix, Vector3 vVector);
EXTERN void Math_Matrix4_DirToMatrix( Matrix4 pMatrix, Vector3 pVector );
EXTERN void Math_Matrix4_RotateX(Matrix4 pMatrix, float fValue );
EXTERN void Math_Matrix4_RotateY(Matrix4 pMatrix, float fValue);
EXTERN void Math_Matrix4_RotateZ(Matrix4 pMatrix, float fValue);

EXTERN float Math_RayCaster_Intersect( Vector3 origin, Vector3 direction, float fNear, float fFar, Matrix4 pProjectViewWorldM, void* pVertex, int32 nStride, int32 nVertexCount, Vector3 pRetPT );
EXTERN float Math_RayCaster_IntersectForIndex( Vector3 origin, Vector3 direction, float fNear, float fFar, Matrix4 pProjectViewWorldM, void* pVertex, int32 nStride, void* pIndex, int32 nIndexElementSize, int32 nIndex, Vector3 pRetPT );

/////////////////////////////////////////////////////////////////
//EXTERN void Math_Double_Init( Double_ d, float v );
// double data type
EXTERN void Math_Double_ToString( char* strTextBuff, Double_ d );
EXTERN void Math_Double_ToFloat( float* r, Double_ d );
EXTERN void Math_Double_ToInt32( int32* r, Double_ d );
EXTERN void Math_Double_ToUint32( uint32* r, Double_ d );
EXTERN void Math_Double_ToInt64( Int64_ r, Double_ d );

EXTERN void Math_Double_Neg( Double_ r );
EXTERN void Math_Double_Floor( Double_ r, const Double_ a );
EXTERN void Math_Double_Ceil( Double_ r, const Double_ a );
EXTERN void Math_Double_Round( Double_ r, const Double_ a );
EXTERN void Math_Double_Abs( Double_ r, const Double_ a );

EXTERN void Math_Double_Assign_0( Double_ r, const Double_ l );
EXTERN void Math_Double_Assign_1( Double_ r, float l );
EXTERN void Math_Double_Assign_2( Double_ r, int32 l );
EXTERN void Math_Double_Assign_3( Double_ r, uint32 l );
EXTERN void Math_Double_Assign_4( Double_ r, const char* l );
EXTERN void Math_Double_Assign_5( Double_ r, const Int64_ l );

// (0:==)(1:!=)(2:<)(3:>)(4:<=)(5:>=)
EXTERN bool Math_Double_Compare_0( const Double_ r, const Double_ l, int32 nCompareType );
EXTERN bool Math_Double_Compare_1( const Double_ r, float l, int32 nCompareType );
EXTERN bool Math_Double_Compare_2( const Double_ r, int32 l, int32 nCompareType );
EXTERN bool Math_Double_Compare_3( const Double_ r, uint32 l, int32 nCompareType );

EXTERN void Math_Double_Add_0( Double_ r, const Double_ a, const Double_ b );
EXTERN void Math_Double_Add_1( Double_ r, const Double_ a, float fValue );
EXTERN void Math_Double_Add_2( Double_ r, const Double_ a, int32 nValue );
EXTERN void Math_Double_Add_3( Double_ r, const Double_ a, uint32 nValue );

EXTERN void Math_Double_Sub_0( Double_ r, const Double_ a, const Double_ b );
EXTERN void Math_Double_Sub_1( Double_ r, const Double_ a, float fValue );
EXTERN void Math_Double_Sub_2( Double_ r, const Double_ a, int32 nValue );
EXTERN void Math_Double_Sub_3( Double_ r, const Double_ a, uint32 nValue );

EXTERN void Math_Double_Mul_0( Double_ r, const Double_ a, const Double_ b );
EXTERN void Math_Double_Mul_1( Double_ r, const Double_ a, float fValue );
EXTERN void Math_Double_Mul_2( Double_ r, const Double_ a, int32 nValue );
EXTERN void Math_Double_Mul_3( Double_ r, const Double_ a, uint32 nValue );

EXTERN void Math_Double_Div_0( Double_ r, const Double_ a, const Double_ b );
EXTERN void Math_Double_Div_1( Double_ r, const Double_ a, float fValue );
EXTERN void Math_Double_Div_2( Double_ r, const Double_ a, int32 nValue );
EXTERN void Math_Double_Div_3( Double_ r, const Double_ a, uint32 nValue );

EXTERN void Math_Double_Mod_0( Double_ r, const Double_ a, const Double_ b );
EXTERN void Math_Double_Mod_1( Double_ r, const Double_ a, float fValue );
EXTERN void Math_Double_Mod_2( Double_ r, const Double_ a, int32 nValue );
EXTERN void Math_Double_Mod_3( Double_ r, const Double_ a, uint32 nValue );


// int64 data type
EXTERN void Math_Int64_ToString( char* strTextBuff, Int64_ d );
EXTERN void Math_Int64_ToInt32( int32* l, Int64_ d );
EXTERN void Math_Int64_ToUint32( uint32* l, Int64_ d );
EXTERN void Math_Int64_ToDouble( Double_ l, Int64_ d );

EXTERN void Math_Int64_Neg( Int64_ r );
EXTERN void Math_Int64_Assign_0( Int64_ r, const Int64_ l );
EXTERN void Math_Int64_Assign_1( Int64_ r, float l );
EXTERN void Math_Int64_Assign_2( Int64_ r, int32 l );
EXTERN void Math_Int64_Assign_3( Int64_ r, uint32 l );
EXTERN void Math_Int64_Assign_4( Int64_ r, const char* l );
EXTERN void Math_Int64_Assign_5( Double_ r, const Double_ l );

// (0:==)(1:!=)(2:<)(3:>)(4:<=)(5:>=)
EXTERN bool Math_Int64_Compare_0( const Int64_ r, const Int64_ l, int32 nCompareType );
EXTERN bool Math_Int64_Compare_1( const Int64_ r, float l, int32 nCompareType );
EXTERN bool Math_Int64_Compare_2( const Int64_ r, int32 l, int32 nCompareType );
EXTERN bool Math_Int64_Compare_3( const Int64_ r, uint32 l, int32 nCompareType );

EXTERN void Math_Int64_Add_0( Int64_ r, const Int64_ a, const Int64_ b );
EXTERN void Math_Int64_Add_1( Int64_ r, const Int64_ a, float fValue );
EXTERN void Math_Int64_Add_2( Int64_ r, const Int64_ a, int32 nValue );
EXTERN void Math_Int64_Add_3( Int64_ r, const Int64_ a, uint32 nValue );

EXTERN void Math_Int64_Sub_0( Int64_ r, const Int64_ a, const Int64_ b );
EXTERN void Math_Int64_Sub_1( Int64_ r, const Int64_ a, float fValue );
EXTERN void Math_Int64_Sub_2( Int64_ r, const Int64_ a, int32 nValue );
EXTERN void Math_Int64_Sub_3( Int64_ r, const Int64_ a, uint32 nValue );

EXTERN void Math_Int64_Mul_0( Int64_ r, const Int64_ a, const Int64_ b );
EXTERN void Math_Int64_Mul_1( Int64_ r, const Int64_ a, float fValue );
EXTERN void Math_Int64_Mul_2( Int64_ r, const Int64_ a, int32 nValue );
EXTERN void Math_Int64_Mul_3( Int64_ r, const Int64_ a, uint32 nValue );

EXTERN void Math_Int64_Div_0( Int64_ r, const Int64_ a, const Int64_ b );
EXTERN void Math_Int64_Div_1( Int64_ r, const Int64_ a, float fValue );
EXTERN void Math_Int64_Div_2( Int64_ r, const Int64_ a, int32 nValue );
EXTERN void Math_Int64_Div_3( Int64_ r, const Int64_ a, uint32 nValue );

EXTERN void Math_Int64_Mod_0( Int64_ r, const Int64_ a, const Int64_ b );
EXTERN void Math_Int64_Mod_1( Int64_ r, const Int64_ a, float fValue );
EXTERN void Math_Int64_Mod_2( Int64_ r, const Int64_ a, int32 nValue );
EXTERN void Math_Int64_Mod_3( Int64_ r, const Int64_ a, uint32 nValue );

#endif
