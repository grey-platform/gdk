/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: spheregeometry.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_SPHEREGEOMETRY_H__
#define __BIGIMAGE_SPHEREGEOMETRY_H__

#include <bigimage/geometry.h>
#include <standard/math.h>

class CSphereGeometry: public CGeometry{
public:
    CSphereGeometry( float radius, int32 widthSegments, int32 heightSegments, float phiStart = 0.0f, float phiLength = TWO_PI, float thetaStart = 0.0f, float thetaLength = PI );
    virtual ~CSphereGeometry();
    virtual void Render();
    virtual CVertexBuffer* GetRenderBuffer(){ return m_pRenderBuffer; }
    virtual CIndexBuffer*  GetIndexBuffer(){ return m_pIndexBuffer; }

private:
    CVertexBuffer* m_pRenderBuffer;
    CIndexBuffer*  m_pIndexBuffer;
};

#endif
