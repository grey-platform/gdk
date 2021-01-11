/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: renderbuffer.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_RENDERBUFFER_H__
#define __STANDARD_RENDERBUFFER_H__

#include <include/stdtype.h>
#include <include/renderer.h>


void Vertex_Set( TV3C1 *pVert, float x, float y, float z, color32 c );
void Vertex_Set( TV3C1T2 *pVert, float x, float y, float z, color32 c, float u, float v );
void Vertex_Set(TV3C4FT2 *pVert, float x, float y, float z, float r, float g, float b, float a, float u, float v);



class CVertexBuffer;
class CIndexBuffer{
public:
    CIndexBuffer( void* pIndexData, int32 nCount, bool32 bDynamic, int32 nElementDataSize );
    ~CIndexBuffer();
    void UpdateBuffer( void* pIndexData, int32 nCount );

public:
    HINDEXBUFFERHANDLE m_hIndexBufferHandle;
};

class CVertexBuffer{
public:
    CVertexBuffer( _EVERTEXTYPE eVertexType, void* pVertexData, int32 nVertexCount, bool32 bDynamic );
    ~CVertexBuffer();
    void UpdateBuffer( void* pVertexData, int32 nCount );
    void Render( _EPRIMITIVETYPE ePrimitiveType );
    void Render( _EPRIMITIVETYPE ePrimitiveType, CIndexBuffer* pIndexBuffer );

public:
    HVERTEXBUFFERHANDLE m_hVertexBufferHandle;
};

class CRenderDataBuffer{
public:
    CRenderDataBuffer();
    ~CRenderDataBuffer();
    void Begin( _EVERTEXTYPE  eVertexType );
    void End();
    void Render( _EPRIMITIVETYPE ePrimitiveType, void* pVertexData, int32 nVertexCount );
    void Render( _EPRIMITIVETYPE ePrimitiveType, void* pVertexData, void* pIndexs, int32 nIndexCount, int32 nElementDataSize );

public:
    HRENDERDATABUFFER m_hRenderDataHandle;
};




#endif
