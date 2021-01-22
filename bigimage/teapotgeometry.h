/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: teapotgeometry.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_TEAPOTGEOMETRY_H__
#define __BIGIMAGE_TEAPOTGEOMETRY_H__

#include <bigimage/geometry.h>

class CTeapotGeometry: public CGeometry{
public:
    CTeapotGeometry( float size, int32 segments = 10, bool32 bottom = True, bool32 lid = True, bool32 body = True, bool32 fitLid = True, bool32 blinn = True );
    virtual ~CTeapotGeometry();
    virtual void Render();
    virtual CVertexBuffer* GetRenderBuffer(){ return m_pRenderBuffer; }
    virtual CIndexBuffer*  GetIndexBuffer(){ return m_pIndexBuffer; }

private:
    CVertexBuffer* m_pRenderBuffer;
    CIndexBuffer*  m_pIndexBuffer;
};

#endif
