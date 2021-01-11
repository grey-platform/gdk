/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: renderer.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_RENDERER_H__
#define __GRAY_SDK_RENDERER_H__

#include <include/stdtype.h>
#include <include/texture.h>
#include <include/material.h>

typedef enum _EMaterialSide{
    FrontSide,
    BackSide,
    DoubleSide,
}_EMaterialSide;

// blending modes
typedef enum _EBlendingModes{
    NoBlending,
    NormalBlending,
    AdditiveBlending,
    SubtractiveBlending,
    MultiplyBlending,
    CustomBlending,
    //InitBlending,
}_EBlendingModes;

// custom blending equations
typedef enum _ECustomBlendingEquations{
    ECBE_Unknown,
    AddEquation,
    SubtractEquation,
    ReverseSubtractEquation,
}_ECustomBlendingEquations;

// custom blending destination factors
typedef enum _ECustomBlendingFactors{
    ECBDF_Unknown,
    ZeroFactor,
    OneFactor,
    SrcColorFactor,
    OneMinusSrcColorFactor,
    SrcAlphaFactor,
    OneMinusSrcAlphaFactor,
    DstAlphaFactor,
    OneMinusDstAlphaFactor,
    DstColorFactor,
    OneMinusDstColorFactor,
    SrcAlphaSaturateFactor,
}_ECustomBlendingFactors;


/////////////////////////////////////////////////////////////////////////
//vertexbuff
typedef enum _EVERTEXTYPE{
    EVT_UNKONW,
    EVT_VECTOR,
    EVT_VECTOR_COLOR,
    EVT_VECTOR_TEXCOORDS,
    EVT_VECTOR_COLOR_TEXCOORDS,
    EVT_VECTOR_COLOR4F_TEXCOORDS,
    EVT_VECTOR_NORMAL,
    EVT_VECTOR_NORMAL_TEXCOORDS,
    EVT_VECTOR_NORMAL_COLOR_TEXCOORDS,
    EVT_VECTOR_NORMAL_TEXCOORDS_TANGENT,
    EVT_VECTOR_NORMAL_TEXCOORDS_SKININDEX_SKINWEIGHT,
    EVT_VECTOR_NORMAL_TEXCOORDS_MORPHVECTOR0_MORPHVECTOR1_WEIGHT,
    EVT_VECTOR_NORMAL_TEXCOORDS_ATEXCOORDS_TEXCOORDS0_TEXCOORDS1_TEXCOORDS2_TEXCOORDS3,
    EVT_COUNT,
}_EVERTEXTYPE;

typedef enum _EPRIMITIVETYPE{
    EPT_TRIANGLE_LIST,
    EPT_TRIANGLE_STRIP,
    EPT_LINE_LIST,
    EPT_LINE_STRIP,
    EPT_POINT_LIST,
    EPT_LINES,
}_EPRIMITIVETYPE;


typedef struct TV2{
    float X, Y;
}TV2;

typedef struct TV3{
    float X, Y, Z;
}TV3;

typedef struct TV4{
    float X, Y, Z, W;
}TV4;

typedef struct TV3C1{
    float X, Y, Z;
    color32 C;
}TV3C1;

typedef struct TV3T2{
    float X, Y, Z, U, V;
}TV3T2;

typedef struct TV3C1T2{
    float X, Y, Z;
    color32 C;
    float U, V;
}TV3C1T2;

typedef struct TV3C4FT2{
    float X, Y, Z;
    float R, G, B, A;
    float U, V;
}TV3C4FT2;


typedef struct TV3N3{
    float X, Y, Z, NX, NY, NZ;
}TV3N3;

typedef struct TV3N3T2{
    float X, Y, Z, NX, NY, NZ, U, V;
}TV3N3T2;

typedef struct TV3N3C1T2{
    float X, Y, Z, NX, NY, NZ;
    color32 C;
    float U, V;
}TV3N3C1T2;

typedef struct TV3N3T2T4{
    float X, Y, Z, NX, NY, NZ, U, V, TX, TY, TZ, TW;
}TV3N3T2T4;

typedef struct TV3N3T2T2T2T2T2T2{
    float X, Y, Z, NX, NY, NZ, U, V, AU, AV, U0, V0, U1, V1, U2, V2, U3, V3;
}TV3N3T2T2T2T2T2T2;

typedef uint32 HVERTEXBUFFERHANDLE;
typedef uint32 HINDEXBUFFERHANDLE;
typedef uint32 HRENDERDATABUFFER;
EXTERN HVERTEXBUFFERHANDLE Renderer_VertexBuffer_Create( _EVERTEXTYPE eVertexType, void* pVertexData, int32 nVertexCount, bool32 bDynamic );
EXTERN bool32 Renderer_VertexBuffer_Rlease( HVERTEXBUFFERHANDLE hVertexBufferHandle );
EXTERN void Renderer_VertexBuffer_Update( HVERTEXBUFFERHANDLE hVertexBufferHandle, void* pVertexData, int32 nVertexCount );
EXTERN void Renderer_VertexBuffer_Render0( HVERTEXBUFFERHANDLE hVertexBufferHandle, _EPRIMITIVETYPE ePrimitiveType );
EXTERN void Renderer_VertexBuffer_Render1( HVERTEXBUFFERHANDLE hVertexBufferHandle, _EPRIMITIVETYPE ePrimitiveType, HINDEXBUFFERHANDLE hIndexBufferHandle );


EXTERN HINDEXBUFFERHANDLE Renderer_IndexBuffer_Create( void* pIndexData, int32 nCount, bool32 bDynamic, int32 nElementDataSize );
EXTERN bool32 Renderer_IndexBuffer_Rlease( HINDEXBUFFERHANDLE hIndexBufferHandle );
EXTERN void Renderer_IndexBuffer_Update( HINDEXBUFFERHANDLE hIndexBufferHandle, void* pIndexData, int32 nCount );


EXTERN HRENDERDATABUFFER Renderer_VertexDataBuffer_Create();
EXTERN bool32 Renderer_VertexDataBuffer_Release( HRENDERDATABUFFER hRenderDataBufferHandle );
EXTERN void Renderer_VertexDataBuffer_Begin( HRENDERDATABUFFER hRenderDataBufferHandle, _EVERTEXTYPE eVertexType );
EXTERN void Renderer_VertexDataBuffer_End( HRENDERDATABUFFER hRenderDataBufferHandle );
EXTERN void Renderer_VertexDataBuffer_Render( HRENDERDATABUFFER hRenderDataBufferHandle, _EPRIMITIVETYPE ePrimitiveType, void* pVertexData, int32 nVertexCount );
EXTERN void Renderer_VertexDataBuffer_Render_Index( HRENDERDATABUFFER hRenderDataBufferHandle, _EPRIMITIVETYPE ePrimitiveType, void* pVertexData, void* pIndexs, int32 nIndexCount, int32 nElementDataSize );

EXTERN void Renderer_BeginRenderTarget( HTEXTUREHANDLE hTextureTarget, int32 nViewportWidth, int32 nViewportHeight );
EXTERN void Renderer_EndRenderTarget();
EXTERN void Renderer_SetClearColor( float r, float g, float b, float a );
EXTERN void Renderer_SetDepthTest( bool32 bValue );
EXTERN void Renderer_SetDepthWrite( bool32 bValue );
EXTERN void Renderer_Clear( bool32 bColor, bool32 bDepth );
EXTERN void Renderer_SetLineMode( bool32 bValue );
EXTERN void Renderer_SetMaterialFaces( _EMaterialSide eMaterialSide );
EXTERN void Renderer_SetBlending( _EBlendingModes eBlending, _ECustomBlendingEquations eBlendEquation, _ECustomBlendingFactors eBlendSrc, _ECustomBlendingFactors eBlendDst );

EXTERN void Renderer_Font_Render( int32 nFontType, float x, float y, const char* strText, HMATERIALHANDLE hMaterialHandle, color32 c, uint32 nStyle, color32 bk, bool32 bHFlip );
EXTERN HTEXTUREHANDLE Renderer_Font_GetTextureInfo( int32 nFontType, int32 nCode, float* pU0, float* pV0, float* pU1, float* pV1 );
EXTERN void* Renderer_Font_GetCharData( int32 nFontType, int32 nCode, int32* nWidth, int32* nHeight );
EXTERN void Renerer_Font_BufferPrint( void* pDesc, int32 nDescWidth, int32 nDescHeight, int32 nDescChannel, int32 nFontType, int32 x, int32 y, const char* strText, color32 nColor );
EXTERN int32 Render_Font_GetTextInfo( int32 nFontType, const char* strText, int32 *pWidth, int32 *pHeight );
EXTERN int32 Render_Font_CreateFont( void* pData, int32 nSize );
EXTERN bool32 Render_Font_ReleaseFont( int32 hFont );
EXTERN int32 Render_Font_CalcAlignOffset( int32 hFont, const char* strText, int32 nAlign, float fRectWidth, float fRectHeight, float *pOffsetX, float *pOffsetY, bool32 bHFlip );

#endif
