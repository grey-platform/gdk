/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: raycaster.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __STANDARD_RAYCASTER_H__
#define __STANDARD_RAYCASTER_H__

#include <include/stdtype.h>
#include <include/math.h>
#include <standard/list.h>
#include <standard/plane.h>


class CRaycaster {
public:
    CRaycaster();
    ~CRaycaster();
    void SetRay(Vector3 origin, Vector3 direction, float fNear, float fFar);
    float Intersect( Matrix4 pWorldMatrix, void *pVert, int32 stride, int32 nVert, Vector3 pRet );
    float Intersect( Matrix4 pWorldMatrix, void *pVert, int32 stride, void* pIndex, int32 nIndexElementSize, int32 nIndex, Vector3 pRet );

    Vector3 m_sOrigin;
    Vector3 m_sDirection;
    float m_fNear;
    float m_fFar;
};

#endif
