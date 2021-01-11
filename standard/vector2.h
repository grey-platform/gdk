/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: vector2.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_VECTOR2_H__
#define __STANDARD_VECTOR2_H__

#include <include/math.h>

class CVector2 {
public:
    CVector2();
    CVector2(float x, float y);
    ~CVector2();
    float* GetData();
    void Set(float x, float y) {
        m[0] = x, m[1] = y;
    }
    void Set(CVector2 &v) {
        m[0] = v.m[0], m[1] = v.m[1];
    }
    CVector2& SubVectors(CVector2 &a, CVector2 &b);
    CVector2& MultiplyScalar(float s);

    float m[2];
};


#endif
