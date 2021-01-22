/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: texturepack.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TEXTUREPACK_H__
#define __STANDARD_TEXTUREPACK_H__

#include <include/stdtype.h>
#include <include/texture.h>
#include <standard/texture.h>
#include <standard/vector.h>

class CTexturePack: public CTexture {
public:
    CTexturePack( const char* strFileName, ETextureWrapModes eWrapS = RepeatWrapping, ETextureWrapModes eWrapT = RepeatWrapping, ETextureFilters eMagFilter = LinearFilter, ETextureFilters eMinFilter = LinearFilter, bool32 bGenerateMipmaps = False );
    virtual ~CTexturePack();
    virtual void SetParame(int32 nParame, int32 nValue);
    CTexture* GetTexture(int32 nFrame);
    void Init(void* pData);

    int32 m_nBlendType;
    bool32 m_bTranslate;
    float m_fTranslateX;
    float m_fTranslateY;
    bool32 m_bRotation;
    float m_fRotAngle;
    bool32 m_bScale;
    int32 m_fScaleFunc;
    float m_vScaleArg[4];
    bool32 m_bAlpha;
    int32 m_fAlphaFunc;
    float m_vAlphaArg[4];
    int32 m_nFrame;
    float m_fFrameSpeed;
    vector<CTexture*> m_vTextureFrame;
};

#endif

