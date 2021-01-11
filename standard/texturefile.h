/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: texturefile.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TEXTUREFILE_H__
#define __STANDARD_TEXTUREFILE_H__

#include <include/stdtype.h>
#include <standard/texture.h>

class CTextureFile: public CTexture{
public:
    CTextureFile( const char* strFileName, ETextureWrapModes eWrapS = RepeatWrapping, ETextureWrapModes eWrapT = RepeatWrapping, ETextureFilters eMagFilter = LinearFilter, ETextureFilters eMinFilter = LinearFilter, bool32 bGenerateMipmaps = False );
    //CTextureFile( CStream* pStream );
    virtual ~CTextureFile();
public:
    char m_strFileName[128];
};

void SaveToTga( const char* strFileName, void* pData, int32 nWidth, int32 nHeight, int32 nChannel );

#endif

