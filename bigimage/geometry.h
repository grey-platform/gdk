/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: applite.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_GEOMETRY_H__
#define __BIGIMAGE_GEOMETRY_H__

#include <standard/renderbuffer.h>

class CGeometry{
public:
    CGeometry();
    virtual ~CGeometry();
    virtual void Update();
    virtual void Render();
    virtual CVertexBuffer* GetRenderBuffer();
    virtual CIndexBuffer*  GetIndexBuffer();
};


#endif
