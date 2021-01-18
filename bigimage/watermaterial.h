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


#ifndef __BIGIMAGE_WATERMATERIAL_H__
#define __BIGIMAGE_WATERMATERIAL_H__

#include <standard/material.h>
#include <standard/color.h>
#include <standard/vector3.h>

class CWaterMaterial: public CMaterial{
public:
    CWaterMaterial();
    virtual ~CWaterMaterial();
    virtual void Init();
    void SetProjectM( Matrix4 m );
    void SetModelViewMatrixM( Matrix4 m );
    void SetWorldM( Matrix4 m );
    //void SetMirrorTexture( CTexture* pTexture );
    void SetSetMirrorColor( CColor& tColor );
    void SetNormalTexture( CTexture* pTexture );
    void SetAlpha( float fValue );
    void SetTime( float fTime );
    void SetSunColor( CColor& tColor );
    void SetWaterColor( CColor& tColor );
    void SetSunDirection( CVector3& tValue );
    void SetDistortionScale( float fScale );
    void SetTextureMatrix( CMatrix4& tValue );
    void SetEye( CVector3& tValue );
    void SetSize( float fValue );

private:
 
};

#endif

