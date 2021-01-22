/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: bigimageinterface.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_BIGIMAGEINTERFACE_H__
#define __BIGIMAGE_BIGIMAGEINTERFACE_H__

#include <include/stdtype.h>
#include <include/texture.h>
#include <include/material.h>
#include <include/renderer.h>
#include <include/math.h>
#include <standard/material.h>
#include <standard/renderbuffer.h>
#include <standard/texture.h>


enum _ERenderElementType {
    EREMT_PROJECTIONM,
    EREMT_VIEWM,
    EREMT_CAMERAPOS,
    EREMT_WORLDM,
    EREMT_BILLBOARDM,
    EREMT_MODELM,
    EREMT_BINDM,
    EREMT_BONEMATRIXCES,
    EREMT_BONEMATRIXCESCOUNT,
    EREMT_WORLDMODELM,
    EREMT_VIEWWORLDMODELM,
    EREMT_WORLDMODELINVERTSEM,
    EREMT_NORMALM,
    EREMT_RENDERTYPE,
    EREMT_CASTSHADOW,
    EREMT_RECEIVESHADOW,

    EREMT_SIDE,
    EREMT_BLENDING,
    EREMT_BLENDEQUATION,
    EREMT_BLENDSRC,
    EREMT_BLENDDST,
    EREMT_LINEMODE,
    EREMT_DEPTHTEST,
    EREMT_DEPTHWRITE,
    EREMT_POLYGONOFFSET,
    EREMT_POLYGONOFFSETFACTOR,
    EREMT_POLYGONOFFSETUNITS,

    EREMT_DIFFUSECOLOR,
    EREMT_EMISSIVECOLOR,
    EREMT_SPECULARCOLOR,
    EREMT_SHININESS,
    EREMT_OPACITY,

    EREMT_LIGHTENABLE,
    EREMT_FOGENABLE,

    EREMT_RENDERSTYLE,
};

enum _ERenderElementTextureType {
    ERETT_DIFFUSE,
};

typedef uint32 HRENDERELEMENTHANDLE;
HRENDERELEMENTHANDLE RenderElement_Create(void *pScriptObject);
bool32 RenderElement_Release(HRENDERELEMENTHANDLE hHandle);
bool32 RenderElement_BindParame(HRENDERELEMENTHANDLE hHandle, _ERenderElementType eValueType, void* pValue);
bool32 RenderElement_SetRenderBuffer(HRENDERELEMENTHANDLE hHandle, CVertexBuffer* hVertexHandle, CIndexBuffer* hIndexHandle);
bool32 RenderElement_SetTexture(HRENDERELEMENTHANDLE hHandle, _ERenderElementTextureType eTextureType, CTexture* pTexture);
bool32 RenderElement_SetMaterial(HRENDERELEMENTHANDLE hHandle, CMaterial* pMaterial);
bool32 RenderElement_SetShadowMaterial(HRENDERELEMENTHANDLE hHandle, CMaterial* pMaterial);
bool32 RenderElement_SetOrder(HRENDERELEMENTHANDLE hHandle, int32 nOrder);
bool32 RenderElement_GetOrder(HRENDERELEMENTHANDLE hHandle, int32* pOrder);
bool32 RenderElement_SetGroupOrder(HRENDERELEMENTHANDLE hHandle, int32 nOrder);
bool32 RenderElement_GetGroupOrder(HRENDERELEMENTHANDLE hHandle, int32* pOrder);
bool32 RenderElement_SetVisible(HRENDERELEMENTHANDLE hHandle, bool32 bVisible);
bool32 RenderElement_GetVisible(HRENDERELEMENTHANDLE hHandle, bool32* pVisible);
bool32 RenderElement_SetUserData(HRENDERELEMENTHANDLE hHandle, int32 nData);
bool32 RenderElement_GetUserData(HRENDERELEMENTHANDLE hHandle, int32* pData);
void*  RenderElement_GetParame(HRENDERELEMENTHANDLE hHandle, _ERenderElementType eValueType);
bool32 RenderElement_SetPrimitiveType(HRENDERELEMENTHANDLE hHandle, _EPRIMITIVETYPE ePrimitiveType);
_EPRIMITIVETYPE RenderElement_GetPrimitiveType(HRENDERELEMENTHANDLE hHandle);


typedef uint32 HRENDERELEMENTMANAGERHANDLE;
HRENDERELEMENTMANAGERHANDLE RenderElementManager_Create();
bool32 RenderElementManager_Release(HRENDERELEMENTMANAGERHANDLE hHandle);
bool32 RenderElementManager_AddRenderElement(HRENDERELEMENTMANAGERHANDLE hHandle, HRENDERELEMENTHANDLE hRenderElement);
bool32 RenderElementManager_RemoveRenderElement(HRENDERELEMENTMANAGERHANDLE hHandle, HRENDERELEMENTHANDLE hRenderElement);
bool32 RenderElementManager_Update(HRENDERELEMENTMANAGERHANDLE hHandle, float* pProjectM, float* pViewM, float* pProjViewM);
bool32 RenderElementManager_UpdateShadow(HRENDERELEMENTMANAGERHANDLE hHandle, float* pProjectM, float* pViewM, float* pProjViewM);
bool32 RenderElementManager_Render(HRENDERELEMENTMANAGERHANDLE hHandle);
bool32 RenderElementManager_RenderShadow(HRENDERELEMENTMANAGERHANDLE hHandle);



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef uint32 HMODELHANDLE;
typedef uint32 HWFXOBJECTHANDLE;
typedef uint32 HWFXPARTICLEMANAGERHANDLE;
typedef uint32 HOBJECTHANDLE;

//////////////////////////////////////////////////////////////////////////////////
HMODELHANDLE Model_WFX_Create(void* hStreamHandle);     //wfx
void Model_WFX_Release(HMODELHANDLE hModelHandle);
void Model_WFX_GetInfo(HMODELHANDLE hModelHandle, int32 vInfos[10]);
void Model_WFX_GetSeqenceInfo(HMODELHANDLE hModelHandle, int32 nIndex, char* strText, float *pStartTime, float *pEndTime, float *pPlaySpeed);
void Model_WFX_GetTextureInfo(HMODELHANDLE hModelHandle, int32 nIndex, char* strFileName);
void Model_WFX_SetTexture(HMODELHANDLE hModelHandle, int32 nIndex, CTexture* pTexture);
/////////////////////////////////////////////////////////////////////////////////
HWFXOBJECTHANDLE Model_WFXObject_Create(void* pScriptObject);
void Model_WFXObject_Release(HWFXOBJECTHANDLE hWFXObjectHandle);
void Model_WFXObject_AddWFXModel(HWFXOBJECTHANDLE hWFXObjectHandle, HMODELHANDLE hModelHandle, Matrix4 pMatrix);
void Model_WFXObject_SetAnimationIndex(HWFXOBJECTHANDLE hWFXObjectHandle, int32 nIndex, int32 nNextIndex);
int32 Model_WFXObject_GetCurrentAnimationIndex(HWFXOBJECTHANDLE hWFXObjectHandle);
void Model_WFXObject_UpdateDefault(HWFXOBJECTHANDLE hWFXObjectHandle, void* pWorldMatrix, float fDelta, HWFXPARTICLEMANAGERHANDLE hWFXParticleManagerHandle);
int32 Model_WFXObject_MergeWFXFile(const char** pMergeFileName, int32 nCount, const char* strOutFileName);
int32 Model_WFXObject_GetRenderElementHandles(HWFXOBJECTHANDLE hWFXObjectHandle, HRENDERELEMENTHANDLE *pRenderElementHandleList, int32 nMaxCount);
bool32 Model_WFXObject_Intersect(HWFXOBJECTHANDLE hWFXObjectHandle, HOBJECTHANDLE hRayCasterHandle, void* pMatrix, void* pRet);
bool32 Model_WFXObject_ResetEffect(HWFXOBJECTHANDLE hWFXObjectHandle, Matrix4 pMatrix);
void Model_WFXObject_AddWFXModel2(HWFXOBJECTHANDLE hWFXObjectHandle, HMODELHANDLE hModelHandle, Vector3 pStartPos, Vector3 pEndPos);
//////////////////////////////////////////////////////////////////////////////////
HWFXPARTICLEMANAGERHANDLE Model_WFXParticleManager_Create();
void Model_WFXParticleManager_Release(HWFXPARTICLEMANAGERHANDLE hWFXPartieleManagerHandle);
void Model_WFXParticleManager_Update(HWFXPARTICLEMANAGERHANDLE hWFXPartieleManagerHandle, float fDelta, float* pCameraPos);
void Model_WFXParticleManager_Render(HWFXPARTICLEMANAGERHANDLE hWFXPartieleManagerHandle, CMaterial* pMaterial);
void Model_WFXParticleManager_Clear(HWFXPARTICLEMANAGERHANDLE hWFXPartieleManagerHandle);
void Model_WFXParticleManager_GetInfo(HWFXPARTICLEMANAGERHANDLE hWFXPartieleManagerHandle, int32 vInfos[10]);
void Model_WFXParticleManager_SetCameraAngle(HWFXPARTICLEMANAGERHANDLE hWFXPartieleManagerHandle, float x, float y);



#endif
