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
#include <standard/reference.h>
#include <standard/vector.h>


void Vertex_Set( TV3C1 *pVert, float x, float y, float z, color32 c );
void Vertex_Set( TV3C1T2 *pVert, float x, float y, float z, color32 c, float u, float v );
void Vertex_Set(TV3C4FT2 *pVert, float x, float y, float z, float r, float g, float b, float a, float u, float v);



class CVertexBuffer;
class CIndexBuffer: public CRefObject{
public:
    CIndexBuffer( void* pIndexData, int32 nCount, bool32 bDynamic, int32 nElementDataSize );
    ~CIndexBuffer();
    void UpdateBuffer( void* pIndexData, int32 nCount );

public:
    HINDEXBUFFERHANDLE m_hIndexBufferHandle;
};

class CVertexBuffer: public CRefObject{
public:
    CVertexBuffer( _EVERTEXTYPE eVertexType, void* pVertexData, int32 nVertexCount, bool32 bDynamic );
    ~CVertexBuffer();
    void UpdateBuffer( void* pVertexData, int32 nCount );
    void Render( _EPRIMITIVETYPE ePrimitiveType );
    void Render( _EPRIMITIVETYPE ePrimitiveType, CIndexBuffer* pIndexBuffer );

public:
    HVERTEXBUFFERHANDLE m_hVertexBufferHandle;
};


class CRenderDataBuffer: public CRefObject{
public:
    CRenderDataBuffer();
    ~CRenderDataBuffer();
    void Render( _EPRIMITIVETYPE ePrimitiveType );
    void Reset();
    bool32 Vaild();

    bool32 CanUpdateVertex(void* pData, int32 nDataSize);
    int32 GetVertexCount();
    bool32 SetVertexData( TV3C1T2* pData, int32 nCount );
    bool32 SetVertexData( TV3C4FT2* pData, int32 nCount );
    TV3C1T2* GetVertexV3C1T2();
    TV3C4FT2* GetVertexV3C4FT2();
    bool32 UpdateVertexData();
    bool32 AddVertexData( TV3C1T2* pData, int32 nCount );
    bool32 AddVertexData( TV3C4FT2* pData, int32 nCount );


    int32 GetIndexCount();
    bool32 SetIndexData( uint16* pData, int32 nCount );
    bool32 SetIndexData( int32* pData, int32 nCount );
    uint16* GetIndexUint16();
    int32* GetIndexInt32();
    bool32 UpdateIndexData();
    bool32 AddIndexData( uint16* pData, int32 nCount );
    bool32 AddIndexData( int32* pData, int32 nCount );

public:
    Ref<CVertexBuffer*> m_pVertexBuffer;
    Ref<CIndexBuffer*> m_pIndexBuffer;

    _EVERTEXTYPE m_eVertexType;
    vector<byte>m_vVertexData;
    int32 m_nVertexCount;

    bool32 m_bIndexIsInt32;
    vector<byte>m_vIndexData;
    int32 m_nIndexCount;
};


#endif
