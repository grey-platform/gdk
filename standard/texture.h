/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: texture.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TEXTURE_H__
#define __STANDARD_TEXTURE_H__

#include <include/stdtype.h>
#include <include/texture.h>
#include <standard/reference.h>

//#define NEAREST  (9728)
//#define LINEAR  (9729)
//#define NEAREST_MIPMAP_NEAREST  (9984)
//#define LINEAR_MIPMAP_NEAREST  (9985)
//#define NEAREST_MIPMAP_LINEAR  (9986)
//#define LINEAR_MIPMAP_LINEAR  (9987)
//
//#define TEXTURE_MAG_FILTER  (10240)
//#define TEXTURE_MIN_FILTER  (10241)
//#define TEXTURE_WRAP_S  (10242)
//#define TEXTURE_WRAP_T  (10243)
//
//#define CLAMP  (10496)
//#define REPEAT  (10497)
//#define MIRRORED_REPEAT  (33648)

// Wrapping modes
enum ETextureWrapModes{
    RepeatWrapping,
    ClampToEdgeWrapping,
    MirroredRepeatWrapping,
};

// Filters
enum ETextureFilters{
    NearestFilter,
    NearestMipMapNearestFilter,
    NearestMipMapLinearFilter,
    LinearFilter,
    LinearMipMapNearestFilter,
    LinearMipMapLinearFilter,
};

class CTexture: public CRefClass<CTexture*>{
public:
    CTexture();
    virtual ~CTexture();
    int32 GetWidth();
    int32 GetHeight();
    void SetParame( int32 nParame, int32 nValue );
    void* GetTextureData();

    HTEXTUREHANDLE m_hTextureHandle;
    int32 m_nWidth;
    int32 m_nHeight;
    int32 m_nRefCount;
};




#endif

