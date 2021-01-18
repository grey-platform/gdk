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


#ifndef __BIGIMAGE_SHADOWMATERIAL_H__
#define __BIGIMAGE_SHADOWMATERIAL_H__

#include <standard/material.h>

class CShadowMaterial: public CMaterial{
public:
    CShadowMaterial();
    virtual ~CShadowMaterial();
    virtual void Init();
    virtual void SetProjectionMatrix(Matrix4 pMatrix);          //设置投影矩阵
    virtual void SetViewMatrix(Matrix4 pMatrix);                //设置视口矩阵
    virtual void SetModelMatrix(Matrix4 pMatrix);
    virtual void SetProjectionViewMatrix(Matrix4 pMatrix);
    virtual void SetViewWorldMatrix(Matrix4 pMatrix);
    virtual void SetNormalMatrix(Matrix3 pMatrix);
    virtual void SetBindMatrix(Matrix4 pMatrix);
    virtual void SetBindMatrixInverse(Matrix4 pMatrix);
    virtual void SetBoneMatrixces(Matrix4 pMatrixces, int32 nCount);
    virtual void SetRenderType(EMATERIALRENDERTYPE eRenderType);
    virtual void SetDiffuseTexture(int32 nTexture, CTexture *pTexture);

private:
};

#endif

