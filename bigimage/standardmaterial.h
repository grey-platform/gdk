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


#ifndef __BIGIMAGE_STANDARDMATERIAL_H__
#define __BIGIMAGE_STANDARDMATERIAL_H__

#include <standard/material.h>

class CStandardMaterial: public CMaterial{
public:
    CStandardMaterial();
    virtual ~CStandardMaterial();
    virtual void Init();
    virtual void Final();
    virtual void Begin();
    virtual void End();
    virtual void RenderText( float x, float y, const char* strText, color32 c, int32 nStyle, color32 bk );
    virtual void SetProjectViewM( Matrix4 m );
    virtual void SetProjectM( Matrix4 m );
    virtual void SetViewM( Matrix4 m );
    virtual void SetWorldM( Matrix4 m );
    virtual void SetNormalM( Matrix3 m );
    virtual void SetDiffuseTexture( CTexture* pTexture );
    virtual void SetMaterialInfo( Vector3 diffuse, Vector3 ambient, Vector3 emissive, Vector3 specular, float opacity, float shininess );
    virtual void SetEnvironmentInfo( Vector3 ambientLightColor, Vector3 directionalLightDirection, Vector3 directionalLightColor );

private:
    HMATERIALATTRIBUTE m_hModelMatrixHandle;
    HMATERIALATTRIBUTE m_hViewMatrixHandle;
    HMATERIALATTRIBUTE m_hProjectionMatrixHandle;
    HMATERIALATTRIBUTE m_hNormalMatrixHandle;
    HMATERIALATTRIBUTE m_hDiffuseHandle;
    HMATERIALATTRIBUTE m_hOpacityHandle;
    HMATERIALATTRIBUTE m_hAmbientHandle;
    HMATERIALATTRIBUTE m_hEmissiveHandle;
    HMATERIALATTRIBUTE m_hSpecularHandle;
    HMATERIALATTRIBUTE m_hShininessHandle;
    HMATERIALATTRIBUTE m_hAmbientLightColorHandle;
    HMATERIALATTRIBUTE m_hDirectionalLightColorHandle;
    HMATERIALATTRIBUTE m_hDirectionalLightDirectionHandle;
    HMATERIALATTRIBUTE m_hDiffuseMapHandle;

};

#endif
