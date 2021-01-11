/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: spherical.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_SPHERICAL_H__
#define __STANDARD_SPHERICAL_H__

#include <include/math.h>

class CVector3;
//«Ú–Œ
class CSpherical {
public:
    CSpherical();
    CSpherical(float radius, float phi, float theta);
    CSpherical& set(float radius, float phi, float theta);
    CSpherical clone();
    CSpherical& copy(CSpherical& other);
    // restrict phi to be betwee EPS and PI-EPS
    CSpherical& makeSafe();
    CSpherical& setFromVector3(CVector3 &vec3);


    float radius, phi, theta;
};

#endif
