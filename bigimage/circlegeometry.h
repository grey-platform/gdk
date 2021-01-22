/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: circlegeometry.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_CIRCLEGEOMETRY_H__
#define __BIGIMAGE_CIRCLEGEOMETRY_H__

#include <bigimage/geometry.h>
#include <standard/vector.h>
#include <standard/math.h>

class CCircleGeometry: public CGeometry{
public:
    CCircleGeometry( float radiusTop = 1.0f, float radiusBottom = 1.0f, float height = 1.0f, int32 radialSegments = 8, int32 heightSegments = 1, bool32 openEnded = False, float thetaStart = 0.0f, float thetaLength = TWO_PI );
    virtual ~CCircleGeometry();
    virtual void Render();
    virtual CVertexBuffer* GetRenderBuffer(){ return m_pRenderBuffer; }
    virtual CIndexBuffer*  GetIndexBuffer(){ return m_pIndexBuffer; }

private:
    void generateTorso( int32 &groupStart, float radiusTop, float radiusBottom, int32 &index, int32 heightSegments, float height, float halfHeight, int32 radialSegments, float thetaStart, float thetaLength, vector<TV3N3T2>& vertices, vector<uint16>& indices );
    void generateCap( bool32 top, int32 &groupStart, float radiusTop, float radiusBottom, int32 &index, int32 heightSegments, float height, float halfHeight, int32 radialSegments, float thetaStart, float thetaLength, vector<TV3N3T2>& vertices, vector<uint16>& indices );
    CVertexBuffer* m_pRenderBuffer;
    CIndexBuffer*  m_pIndexBuffer;

};

#endif
