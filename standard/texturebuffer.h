/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: texturebuffer.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TEXTUREBUFFER_H__
#define __STANDARD_TEXTUREBUFFER_H__

#include <include/stdtype.h>
#include <standard/texture.h>

class CTextureBuffer: public CTexture{
public:
    CTextureBuffer( int32 nWidth, int32 nHeight, int32 nChannel, void* pPixelData, ETextureWrapModes eWrapS = RepeatWrapping, ETextureWrapModes eWrapT = RepeatWrapping, ETextureFilters eMagFilter = LinearFilter, ETextureFilters eMinFilter = LinearFilter, bool32 bGenerateMipmaps = False );
    virtual ~CTextureBuffer();
    virtual void Update( void* pPixelData );

};


#endif
