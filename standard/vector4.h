/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: vector4.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_VECTOR4_H__
#define __STANDARD_VECTOR4_H__

#include <include/math.h>

class CVector4 {
public:
    CVector4();
    CVector4(float x, float y, float z, float w);
    ~CVector4();
    float* GetData();
    void Set(float x, float y, float z, float w) {
        X = x, Y = y, Z = z, W = w;
    }
    //union {
    //    float m[4];
    //    struct {
            float X, Y, Z, W; 
    //    };
    //};
};

#endif

