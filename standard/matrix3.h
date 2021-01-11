/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: matrix3.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_MATRIX3_H__
#define __STANDARD_MATRIX3_H__

class CMatrix4;
class CMatrix3 {
public:
    CMatrix3();
    ~CMatrix3();
    void GetNormalMatrix(CMatrix4* M);
    float m[9];
};

#endif
