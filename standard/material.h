/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: material.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_MATERIAL_H__
#define __STANDARD_MATERIAL_H__

#include <include/stdtype.h>
#include <include/material.h>
#include <include/math.h>
#include <standard/texture.h>


enum EMATERIALRENDERTYPE {
    EMRT_SKELETONANIMATION, //��������
    EMRT_MORPHANIMATION,    //���ζ���
    EMRT_NORMALMODEL,       //��ͨģ��
};

class CMaterial{
public:
    CMaterial();
    virtual ~CMaterial();
    virtual void Init();
    virtual void Begin();
    virtual void End();
    virtual void Final();
    virtual void SetDiffuseTexture(CTexture* pTexture);
//    virtual void SetDiffuseTexture( int32 nID, CTexture* pTexture);
    virtual void SetDiffuseTexture(int32 nID, HTEXTUREHANDLE hTextureHandle);

    virtual void SetProjectionMatrix(Matrix4 pMatrix);          //����ͶӰ����
    virtual void SetViewMatrix(Matrix4 pMatrix);                //�����ӿھ���
    virtual void SetModelMatrix(Matrix4 pMatrix);               //����ģ�;���
    virtual void SetProjectionViewMatrix(Matrix4 pMatrix);      //����ͶӰ�ӿھ���
    virtual void SetViewWorldMatrix(Matrix4 pMatrix);           //�����ӿ�ģ�;���
    virtual void SetNormalMatrix(Matrix3 pMatrix);              //���÷���������
    virtual void SetBindMatrix(Matrix4 pMatrix);                //������ģ�Ͱ󶨾���
    virtual void SetBindMatrixInverse(Matrix4 pMatrix);         //������ģ�Ͱ������
    virtual void SetBoneMatrixces(Matrix4 pMatrixces, int32 nCount);    //���ù�������(���128)
    virtual void SetRenderType(EMATERIALRENDERTYPE eRenderType);  //���û�������
    virtual void SetShadowEnable(bool32 bEnable);                 //�����Ƿ�������Ӱ

    virtual void SetDiffuseTexture(int32 nTexture, CTexture *pTexture);  //��������������
    virtual void SetDiffuse(Color color);                   //���������ɫ
    virtual void SetEmissive(Color color);                  //��������ɫ
    virtual void SetShininess(float fValue);                      //����ָ���������ȣ�
    virtual void SetSpecular(Color color);                  //���淴�����ɫ
    virtual void SetOpacity(float fValue);                        //��͸����
    virtual void SetFogEnable(bool32 bEnable);
    virtual void SetFogInfo(Color color, float fNear, float fFar);  //���������
    virtual void SetCameraPosition(Vector3 pVec3);          //���������λ��

    virtual void SetLightEnable(bool32 bEnable);
    virtual void SetAmbientLightColor(Color color);
    virtual void SetDirectionalShadowMatrix(Matrix4 pMatrix);
    virtual void SetDirectionalShadowMap(HTEXTUREHANDLE hTextureHandle);
    virtual void SetDirectionalLights_Direction(Vector3 pVec3);
    virtual void SetDirectionalLights_Color(Color color);
    virtual void SetDirectionalLights_ShadowBias(float fValue);
    virtual void SetDirectionalLights_ShadowMapSize(float fWidth, float fHeight);
    virtual void SetDirectionalLights_ShadowRadius(float fRadius);

    HMATERIALHANDLE m_hMaterialHandle;

protected:
    virtual HMATERIALUNIFORM GetUniformLocation(const char* strAttributeName);
    virtual void SetUniform1i(HMATERIALUNIFORM nAttribute, int32 nValue);
    virtual void SetUniform1f(HMATERIALUNIFORM nAttribute, float fValue);
    virtual void SetUniform2fv(HMATERIALUNIFORM nAttribute, void *pData);
    virtual void SetUniform3fv(HMATERIALUNIFORM nAttribute, void *pData);
    virtual void SetUniform4fv(HMATERIALUNIFORM nAttribute, void *pData);
    virtual void SetUniform2f(HMATERIALUNIFORM nAttribute, float x, float y);
    virtual void SetUniform3f(HMATERIALUNIFORM nAttribute, float x, float y, float z);
    virtual void SetUniform4f(HMATERIALUNIFORM nAttribute, float x, float y, float z, float w);
    virtual void SetUniformMatrix3fv(HMATERIALUNIFORM nAttribute, bool32 bTranspose, void *pData);
    virtual void SetUniformMatrix4fv(HMATERIALUNIFORM nAttribute, bool32 bTranspose, void *pData);
    virtual void SetUniformTexture(HMATERIALUNIFORM nAttribute, int32 nIndex, CTexture* pTexture);

protected:
    HMATERIALUNIFORM m_hProjectionMatrixHandle;
    HMATERIALUNIFORM m_hViewMatrixHandle;
    HMATERIALUNIFORM m_hModelMatrixHandle;
    HMATERIALUNIFORM m_hModelViewMatrixHandle;
    HMATERIALUNIFORM m_hProjectionViewMatrixHandle;
    HMATERIALUNIFORM m_hNormalMatrixHandle;
    HMATERIALUNIFORM m_hFogEnableHandle;
    HMATERIALUNIFORM m_hFogColorHandle;
    HMATERIALUNIFORM m_hFogNearHandle;
    HMATERIALUNIFORM m_hFogFarHandle;

    HMATERIALUNIFORM m_hBindMatrixHandle;
    HMATERIALUNIFORM m_hBindMatrixInverseHandle;
    HMATERIALUNIFORM m_hBoneMatricesHandle;
    HMATERIALUNIFORM m_hRenderTypeHandle;
    HMATERIALUNIFORM m_hEmissiveHandle;
    HMATERIALUNIFORM m_hShininessHandle;
    HMATERIALUNIFORM m_hSpecularHandle;
    HMATERIALUNIFORM m_hDiffuseHandle;
    HMATERIALUNIFORM m_hOpacityHandle;
    HMATERIALUNIFORM m_hAmbientLightColorHandle;
    HMATERIALUNIFORM m_hDiffuseMapHandle;
    HMATERIALUNIFORM m_hToneMappingExposureHandle;
    HMATERIALUNIFORM m_hCameraPositionHandle;

    HMATERIALUNIFORM m_hLightEnableHandle;
    HMATERIALUNIFORM m_hDirectionalShadowMatrixHandle;
    HMATERIALUNIFORM m_hDirectionalShadowMap_0Handle;
    HMATERIALUNIFORM m_hDirectionalLights_0_colorHandle;
    HMATERIALUNIFORM m_hDirectionalLights_0_directionHandle;
    HMATERIALUNIFORM m_hDirectionalLights_0_shadowHandle;
    HMATERIALUNIFORM m_hDirectionalLights_0_shadowBiasHandle;
    HMATERIALUNIFORM m_hDirectionalLights_0_shadowRadiusHandle;
    HMATERIALUNIFORM m_hDirectionalLights_0_shadowMapSizeHandle;


};




#endif

