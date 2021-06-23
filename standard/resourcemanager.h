/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: resourcemanager.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2021
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __STANDARD_RESOURCEMANAGER_H__
#define __STANDARD_RESOURCEMANAGER_H__

#include <include/stdtype.h>
#include <standard/reference.h>
#include <standard/texture.h>
#include <standard/map.h>

class CMaterial;
class CIndexBuffer;
class CVertexBuffer;
class CRenderDataBuffer;

class CResourceManager{
private:
    struct SResourceItem{
        Ref<CRefObject*> m_sItemsData;
        int32 m_nRefCount;
    };
public:
    static CResourceManager* GetInterface();
    static void Destroy();
    CResourceManager();
    ~CResourceManager();
    void Clear();
    int32 RemoveObject( CRefObject* pObj );
    int32 RemoveObject( uint32 nGUID );
    CTexture* GetTexture( const char* strFileName, ETextureWrapModes eWrapS = RepeatWrapping, ETextureWrapModes eWrapT = RepeatWrapping, ETextureFilters eMagFilter = LinearFilter, ETextureFilters eMinFilter = LinearFilter, bool32 bGenerateMipmaps = False );
    uint32 AddObject( CRefObject* pObj );
    CRefObject* GetRefObject( uint32 nGUID );
    template<class T>
    T* GetObject( uint32 nGUID );

private:
    map<uint32, SResourceItem>m_vResourceList;
    uint32 m_nResourceGUID;
};

#define RESOURCE_ADD( p )CResourceManager::GetInterface()->AddObject( p );
#define RESOURCE_GETTEXTURE( file )CResourceManager::GetInterface()->GetTexture( file );
#define RESOURCE_REMOVE( p )CResourceManager::GetInterface()->RemoveObject( p ); p = NULL;


template <class T>
T* CResourceManager::GetObject( uint32 nGUID ){
    T* _pObject = (T*)GetRefObject( nGUID );
    return _pObject;
}


#endif
