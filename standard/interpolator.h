/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: interpolator.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_INTERPOLATOR_H__
#define __STANDARD_INTERPOLATOR_H__

#include <standard/vector.h>
#include <include/math.h>
#include <include/renderer.h>

enum EINTERPOLATIONTYPE {
    INTERPOLATION_TYPE_NONE,
    INTERPOLATION_TYPE_LINEAR,
    INTERPOLATION_TYPE_HERMITE,
    INTERPOLATION_TYPE_BEZIER,
};


//²¼¶û²åÖµÆ÷
//////////////////////////////////////////////////////////////////////////
struct TBoolInterpolatorNode {
    int32 m_nTime;
    bool m_bValue;
};

class CBoolInterpolator {
public:
    CBoolInterpolator();
    ~CBoolInterpolator();
    void Clear();
    // void GetMinMaxTime( int32 &nMin, int32 &nMax );
    bool GetCurrentValue(int32 nTime);
    void AddNode(TBoolInterpolatorNode tNode);
    void GetNode(int32 nTime, TBoolInterpolatorNode& pNode0, TBoolInterpolatorNode& pNode1);
    EINTERPOLATIONTYPE m_eInterpolationType;
    vector< TBoolInterpolatorNode > m_vNodeList;
    bool m_bCurrentValue;
    float m_fMinTime;
    float m_fMaxTime;
};


//¸¡µã²åÖµÆ÷
//////////////////////////////////////////////////////////////////////////
struct TFloatInterpolatorNode {
    float m_fTime;
    float m_fValue;
    float m_fLeftDerivative;
    float m_fLefttangent;
    float m_fRightDerivative;
    float m_fRighttangent;
};


class CFloatInterpolator {
public:
    CFloatInterpolator();
    ~CFloatInterpolator();
    void Clear();
    float GetCurrentValue(float fTime);
    float GetCurrentValue(bool32 bGlobal, float fTime);
    void AddNode(TFloatInterpolatorNode tNode);
    void GetNode(float fTime, TFloatInterpolatorNode& pNode0, TFloatInterpolatorNode& pNode1);
    bool32 HasNode() { return m_vNodeList.size() > 0; }
    // void GetMinMaxTime( float &fMinTime, float &fMaxTime );
    EINTERPOLATIONTYPE m_eInterpolationType;
    vector< TFloatInterpolatorNode > m_vNodeList;
    float m_fMinTime;
    float m_fMaxTime;

};

struct TQuationInterpolatorNode {
    float m_fTime;
    float X;
    float Y;
    float Z;
    float W;
};
class CQuationInterpolator {
public:
    CQuationInterpolator();
    ~CQuationInterpolator();
    void Clear();
    void GetCurrentValue( float fTime, Quaternion &q );
    void GetCurrentValue( bool32 bGlobal, float fTime, Quaternion &q );
    void AddNode(TQuationInterpolatorNode tNode);
    void GetNode(float fTime, TQuationInterpolatorNode& pNode0, TQuationInterpolatorNode& pNode1);
    // void GetMinMaxTime( float &fMinTime, float &fMaxTime );
    EINTERPOLATIONTYPE m_eInterpolationType;
    vector< TQuationInterpolatorNode > m_vNodeList;
    float m_fMinTime;
    float m_fMaxTime;
};




//vector3²åÖµÆ÷
//////////////////////////////////////////////////////////////////////////

struct TVector3InterpolatorNode {
    float m_fTime;
    Vector3 m_tValue;
    Vector3 m_tInTanValue;
    Vector3 m_tOutTanValue;
};

class CVector3Interpolator {
public:
    CVector3Interpolator();
    ~CVector3Interpolator();
    void Clear();
    void GetCurrentValue(float fTime, Vector3 ret);
    void AddNode(TVector3InterpolatorNode tNode);
    void GetNode(float fTime, TVector3InterpolatorNode& pNode0, TVector3InterpolatorNode& pNode1);
    EINTERPOLATIONTYPE m_eInterpolationType;
    vector< TVector3InterpolatorNode > m_vNodeList;
    Vector3 m_tCurrentValue;
    float m_fMinTime;
    float m_fMaxTime;
};


//vector4²åÖµÆ÷
//////////////////////////////////////////////////////////////////////////

struct TVector4InterpolatorNode {
    float m_fTime;
    Vector4 m_tValue;
    Vector4 m_tInTanValue;
    Vector4 m_tOutTanValue;
};

class CVector4Interpolator {
public:
    CVector4Interpolator();
    ~CVector4Interpolator();
    void Clear();
    void GetCurrentValue(float fTime, Vector4 ret);
    void InterpolatRotation(float fTime, Vector4 ret);
    void AddNode(TVector4InterpolatorNode tNode);
    void GetNode(float fTime, TVector4InterpolatorNode& pNode0, TVector4InterpolatorNode& pNode1);
    EINTERPOLATIONTYPE m_eInterpolationType;
    vector< TVector4InterpolatorNode > m_vNodeList;
    Vector4 m_tCurrentValue;
    float m_fMinTime;
    float m_fMaxTime;
};


struct TVector3ArrayInterpolatorNode {
    float m_fTime;
    //vector<TV3> m_vData;
    TV3* m_vData;
    int32 m_nData;
};

class CVector3ArrayInterpolator {
public:
    CVector3ArrayInterpolator();
    ~CVector3ArrayInterpolator();
    void Clear();
    void GetCurrentValue(float fTime, float* ret, int32 nVertexSize);
    float GetNodeRateData(float fTime, TVector3ArrayInterpolatorNode* &pNode0, TVector3ArrayInterpolatorNode* &pNode1);
    void AddNode(TVector3ArrayInterpolatorNode &tNode);
    void GetNode(float fTime, TVector3ArrayInterpolatorNode* &pNode0, TVector3ArrayInterpolatorNode* &pNode1);
    EINTERPOLATIONTYPE m_eInterpolationType;
    vector< TVector3ArrayInterpolatorNode > m_vNodeList;
    float m_fMinTime;
    float m_fMaxTime;
};


#endif
