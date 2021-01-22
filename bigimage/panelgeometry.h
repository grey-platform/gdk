/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: panelgeometry.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_PANELGEOMETRY_H__
#define __BIGIMAGE_PANELGEOMETRY_H__

#include <bigimage/geometry.h>

class CPanelGeometry: public CGeometry{
public:
    CPanelGeometry( float width, float height, int32 widthSegments = 1, int32 heightSegments = 1 );
    virtual ~CPanelGeometry();
    void Render();
    virtual CVertexBuffer* GetRenderBuffer(){ return m_pRenderBuffer; }
    virtual CIndexBuffer*  GetIndexBuffer(){ return m_pIndexBuffer; }

private:
    CVertexBuffer* m_pRenderBuffer;
    CIndexBuffer*  m_pIndexBuffer;

};

#endif
