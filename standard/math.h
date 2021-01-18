/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: math.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_MATH_H__
#define __STANDARD_MATH_H__

#include <include/stdtype.h>

#define PI		        (3.14159265359f)
#define TWO_PI			(6.28318530718f)
#define RECIPROCAL_PI	(0.31830988618f)
#define HALF_PI	        (1.57079632679f)
#define HALF_HALF_PI    (0.78539816339f)
#define DEGTORAD        (0.01745329252f)
#define RADTODEG        (57.29577951308f)
#define POWER( x ) ( ( x ) *( x ) )


#ifndef MAKEWORD
#define MAKEWORD(a, b)      ((uint16)(((uint8)((uint32)(a) & 0xff)) | ((uint16)((uint8)((uint32)(b) & 0xff))) << 8))
#endif
#ifndef MAKELONG
#define MAKELONG(a, b)      ((uint32)(((uint16)((uint32)(a) & 0xffff)) | ((uint32)((uint16)((uint32)(b) & 0xffff))) << 16))
#endif
#ifndef LOWORD 
#define LOWORD(l)           ((uint16)((uint32)(l) & 0xffff))
#endif
#ifndef HIWORD
#define HIWORD(l)           ((uint16)((uint32)(l) >> 16))
#endif
#ifndef LOBYTE
#define LOBYTE(w)           ((uint8)((uint32)(w) & 0xff))
#endif
#ifndef HIBYTE
#define HIBYTE(w)           ((uint8)((uint32)(w) >> 8))
#endif

#define GETALPHA( c, a ) ( a = (byte)((c & 0xFF000000) >> 24) )
#define GETCOLOR( c, a, r, g, b ) ( a = (byte)((c & 0xFF000000) >> 24), b = (byte)((c & 0x00FF0000) >> 16), g = (byte)((c & 0x0000FF00) >> 8), r = (byte)(c & 0x000000FF) )
#define MAKECOLOR32( a, r, g, b ) (color32((((color32)(a) & 0xff) << 24) | (((color32)(b) & 0xff) << 16) | (((color32)(g) & 0xff) << 8) | ((color32)(r) & 0xff)))
#define SETALPHA( c, a ) (c = (color32(((a & 0xff) << 24) | ((color32)(c) & 0x00FFFFFF ) ) ))
#define MAKEINT32( a, b ) ( a << 16 | b )


void SRand( uint32 nValue );
int32 Rand();                               // 0~32767
int32 Rand( int32 nMax );                   //0~nMax
int32 Rand( int32 nMin, int32 nMax );       //nmin ~ nMax
float fRand();                              //0.0f ~ 1.0f
float fRand( float fMax );
float fRand( float lower, float upper );
bool32 RandPercent( float fValue );
int32* RandArray( int32 *pArray, int32 nCount );


template<class T>
inline const T& Min( const T& a, const T& b ){
    const T &r = a < b ? a : b;
    return r;
}

template<class T>
inline const T& Min( const T& a, const T& b, const T& c ){
    return a < b ? Min( a, c ) : Min( b, c );
}

template<class T>
inline const T& Max( const T& a, const T& b ){
    const T &r = a < b ? b : a;
    return r;
}

template<class T>
inline const T& Max( const T& a, const T& b, const T& c ){
    return a < b ? Max( b, c ) : Max( a, c );
}

template<class T>
inline T Abs( const T& a ){
    return a < (T)0 ? -a : a;
}

template<class T>
inline int32 Sign( const T& a ){
    return a > 0.0 ? 1 : (a < 0.0 ? -1 : 0);
}

template<class T>
inline T Lerp( T a, T b, float t ){
    return (T)(a * (1.0f - t)) + (b * t);
}

template <class T>
inline void Swap( T& a, T& b ){
    T c( a );
    a = b;
    b = c;
}

inline int32 Round( const float a ){
    return (int32)(a + 0.5f);
}

template<class T>
inline T Pow( const T& a, int32 nPower ){
    T Ret = a;
    for( int32 i = 1; i < nPower; i ++ ){
        Ret *= a;
    }
    return Ret;
}


float LinerInterpolate(const float r, const float v1, const float v2);
float HermiteInterpolate(const float r, const float &v1, const float &v2, const float&in, const float &out);

template <class T>
inline const T Clamp( const T& value, const T& low, const T& high ){
    return Min( Max( value, low ), high );
}


template <class T>
inline T Distance( const T& x0, const T& y0, const T& x1, const T& y1 ){
    T nx = x0 - x1;
    T ny = y0 - y1;
    T _fLen = nx * nx + ny * ny;
    return _fLen;
}
template <class T>
inline bool PointInRect( const T x, const T y, const T left, const T top, const T right, const T bottom ){
    return x >= left && x <= right && y >= top && y <= bottom;
}

template <class T>
inline bool RectIntersectRect( const T x01, const T y01, const T x02, const T y02, const T x11, const T y11, const T x12, const T y12 ){
    float zx = Abs( x01 + x02 - x11 - x12 );
    float x = Abs( x01 - x02 ) + Abs( x11 - x12 );
    float zy = Abs( y01 + y02 - y11 - y12 );
    float y = Abs( y01 - y02 ) + Abs( y11 - y12 );
    return (zx <= x && zy <= y);
}


//计算两个颜色之间的距离，距离越小，说明这两个颜色看起来越相近
//https://www.compuphase.com/cmetric.htm
//LAB颜色空间:
//LAB颜色空间是基于人眼对颜色的感知，可以表示人眼所能感受到的所有颜色。L表示明度，A表示红绿色差，B表示蓝黄色差。两个颜色之见的色差：
//ΔE = (ΔL ^ 2 + ΔA ^ 2 + ΔB ^ 2) ^ (1 / 2)
//ΔE 表示色差，ΔL / ΔA / Δb分别表示两个颜色之间在不同分量的差值。
//为了简化计算及保证计算效果，有人在RGB空间上通过公式计算出加权的欧式距离。
float ColourDistance( byte e1[3], byte e2[3] );


bool IsPowerOfTwo( int32 val );
int32 FindPowerOfTwo( int32 value );

#endif
