/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: material.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_MATERIAL_H_
#define __GRAY_SDK_MATERIAL_H_

#include <include/stdtype.h>
#include <include/texture.h>

typedef uint32 HMATERIALHANDLE;
typedef int32 HMATERIALUNIFORM;

EXTERN HMATERIALHANDLE Material_Create( const char* strVertexShaderCode, const char* strFragmentShaderCode );
EXTERN bool32 Material_Release( HMATERIALHANDLE hMaterialHandle );
EXTERN void Material_Begin( HMATERIALHANDLE hMaterialHandle );
EXTERN void Material_End( HMATERIALHANDLE hMaterialHandle );
EXTERN HMATERIALUNIFORM Material_GetUniform( HMATERIALHANDLE hMaterialHandle, const char* strName );
EXTERN void Material_SetInt( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, int32 nValue );
EXTERN void Material_SetFloat( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, float fValue );
EXTERN void Material_SetVec2( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, void* pValue );
EXTERN void Material_SetVec3( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, void* pValue );
EXTERN void Material_SetVec4( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, void* pValue );
EXTERN void Material_SetMatrix3( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, bool32 bTranspose, void* pMatrix );
EXTERN void Material_SetMatrix4( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, bool32 bTranspose, void* pMatrix );
EXTERN void Material_SetMatrix4_1(HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, int32 nCount, bool32 bTranspose, void* pMatrix);
EXTERN void Material_SetTexture( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, int32 nIndex, HTEXTUREHANDLE hTextureHandle );
EXTERN void Material_SetVec2_1( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, float x, float y );
EXTERN void Material_SetVec3_1( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, float x, float y, float z );
EXTERN void Material_SetVec4_1( HMATERIALHANDLE hMaterialHandle, HMATERIALUNIFORM hMaterialAttribute, float x, float y, float z, float w );


#endif
