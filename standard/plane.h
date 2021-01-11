/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: plane.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_PLANE_H__
#define __STANDARD_PLANE_H__

#include <include/stdtype.h>
#include <include/math.h>

class CPlane {
public:
    CPlane();
    //CPlane( CPlane* p );
    CPlane(Vector3 v, float fConstant);
    void SetPlane(Vector3 sStartPos, Vector3 sEndPos, Vector3 sOut);
    bool32 MultiPlane(Vector3 sPos);
    float MultiPlanef(Vector3 sPos);
    CPlane* Set(Vector3 v, float fConstant);
    CPlane* Normalize();
    CPlane* SetComponents(float x, float y, float z, float w);
    CPlane* SetFromNormalAndCoplanarPoint(Vector3 normal, Vector3 point);
    CPlane* SetFromCoplanarPoints(Vector3 a, Vector3 b, Vector3 c);
    //CPlane* Copy( CPlane* p );
    float DistanceToPoint(Vector3 point);
public:
    Vector3 m_tNormal;
    float m_fConstant;
};

#endif
