/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: color.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_COLOR_H__
#define __STANDARD_COLOR_H__

#include <include/stdtype.h>

class CColor {
public:
    CColor();
    CColor(float r, float g, float b);
    CColor(float r, float g, float b, float a);
    CColor(uint32 nColor);
    void Set(float r, float g, float b);
    void Set(float r, float g, float b, float a);
    void Set(uint32 nColor);
    float* GetPointer() { return &R; }

    float R, G, B, A;
};

#endif
