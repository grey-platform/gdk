/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: texture.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_TEXTURE_H__
#define __GRAY_SDK_TEXTURE_H__

#include <include/stdtype.h>

typedef uint32 HTEXTUREHANDLE;
typedef uint32 HSTREAMHANDLE;

EXTERN HTEXTUREHANDLE Texture_Create_Target( int32 nWidth, int32 nHeight, bool32 bColor, bool32 bDepth, int32 eWrapS, int32 eWrapT, int32 eMagFilter, int32 eMinFilter, bool32 bGenerateMipmaps );
EXTERN HTEXTUREHANDLE Texture_Create_File( const char* strFileName, int32 eWrapS, int32 eWrapT, int32 eMagFilter, int32 eMinFilter, bool32 bGenerateMipmaps, int32 *pWidth, int32 *pHeight );
EXTERN HTEXTUREHANDLE Texture_Create_Buffer( int32 nWidth, int32 nHeight, int32 nChannel, int32 eWrapS, int32 eWrapT, int32 eMagFilter, int32 eMinFilter, bool32 bGenerateMipmaps, void* pData, int32 nDataSize );
EXTERN HTEXTUREHANDLE Texture_CreateTextureFormStream( HSTREAMHANDLE hStreamHandle );
EXTERN HTEXTUREHANDLE Texture_Create_Pack( HSTREAMHANDLE hStreamHandle );
EXTERN bool32 Texture_Release( HTEXTUREHANDLE hTextureHandle );
EXTERN void Texture_Update_Buffer( HTEXTUREHANDLE hTextureHandle, void* pData );
EXTERN void Texture_SetParame( HTEXTUREHANDLE hTextureHandle, int32 nParame, int32 nValue );
#ifdef _APP_DEBUG_
EXTERN void* Texture_GetTextureData( HTEXTUREHANDLE hTextureHandle );
#endif

#endif
