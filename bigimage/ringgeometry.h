/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: ringgeometry.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_RINGGEOMETRY_H__
#define __BIGIMAGE_RINGGEOMETRY_H__

#include <bigimage/geometry.h>
#include <standard/math.h>

class CRingGeometry: public CGeometry{
public:
    CRingGeometry( float innerRadius = 0.5f, float outerRadius = 1.0f, int32 thetaSegments = 8, int32 phiSegments = 1, float thetaStart = 0.0f, float thetaLength = TWO_PI );
    virtual ~CRingGeometry();
    virtual void Render();
    virtual CVertexBuffer* GetRenderBuffer(){ return m_pRenderBuffer; }
    virtual CIndexBuffer*  GetIndexBuffer(){ return m_pIndexBuffer; }

private:
    CVertexBuffer* m_pRenderBuffer;
    CIndexBuffer*  m_pIndexBuffer;

};

#endif
