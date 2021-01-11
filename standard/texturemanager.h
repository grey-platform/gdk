/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: texturemanager.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TEXTUREMANAGER_H__
#define __STANDARD_TEXTUREMANAGER_H__


#include <standard/texture.h>
#include <standard/map.h>

class CTextureManager{
public:
    static CTextureManager* GetInterface();
    static void ReleaseInterface();
    CTextureManager();
    ~CTextureManager();
    CTexture* Get( const char* strFileName, ETextureWrapModes eWrapS = RepeatWrapping, ETextureWrapModes eWrapT = RepeatWrapping, ETextureFilters eMagFilter = LinearFilter, ETextureFilters eMinFilter = LinearFilter, bool32 bGenerateMipmaps = False );
    void Release( CTexture* pTexture );
    void GC();
    void Clear();

private:
    map<uint32, CTexture*>m_vTextureMap;

};



#endif
