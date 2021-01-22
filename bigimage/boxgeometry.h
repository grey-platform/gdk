/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: boxgeometry.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_BOXGEOMETRY_H__
#define __BIGIMAGE_BOXGEOMETRY_H__

#include <bigimage/geometry.h>

class CBoxGeometry: public CGeometry{
public:
    CBoxGeometry( float fLength, float fWidth, float fHeight );
    virtual ~CBoxGeometry();
    virtual void Render();
    virtual CVertexBuffer* GetRenderBuffer(){ return m_pRenderBuffer; }
    virtual CIndexBuffer*  GetIndexBuffer(){ return m_pIndexBuffer; }

private:
    CVertexBuffer* m_pRenderBuffer;
    CIndexBuffer*  m_pIndexBuffer;
};

#endif

