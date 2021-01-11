/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: texturetarget.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TEXTURETARGET_H__
#define __STANDARD_TEXTURETARGET_H__

#include <include/stdtype.h>
#include <standard/texture.h>


class CTextureTarget: public CTexture{
public:
    CTextureTarget( int32 nWidth, int32 nHeight, bool32 bColor, bool32 bDepth, ETextureWrapModes eWrapS = RepeatWrapping, ETextureWrapModes eWrapT = RepeatWrapping, ETextureFilters eMagFilter = LinearFilter, ETextureFilters eMinFilter = LinearFilter, bool32 bGenerateMipmaps = False );
    virtual ~CTextureTarget();
    void BeginRender( int32 nViewportWidth, int32 nViewportHeight );
    void EndRender();
    void Clear();

};


#endif
