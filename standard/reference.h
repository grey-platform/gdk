/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: reference.h
*Module: standard
*Author: Xiangbin
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef WINDFORCE_REFERENCE_H_
#define WINDFORCE_REFERENCE_H_

#include <include/stdtype.h>
#include <include/assert.h>

template < class TYPE >class CRefClass;

template <class TYPE> class RefEntity;

template < class TYPE >
class Ref{
public:
    Ref();
    //Ref( const Ref& ref );
    Ref( RefEntity< TYPE >& tNewReferenceObject );
    Ref( CRefClass<TYPE>* pRefClass );
    Ref( void* pRefClass );
    Ref( const Ref< TYPE >& tObject );
    ~Ref();
    const Ref< TYPE >& operator = ( const Ref< TYPE >& tObject );
    const Ref< TYPE >& operator = ( CRefClass<TYPE>* pRefClass );
    TYPE operator->() const;
    TYPE GetEntityData() const;
    //void Destroy();
    void Attach( RefEntity< TYPE >& tNewReferenceObject );
    void Detach();
    bool IsAttached() const;
protected:
    RefEntity< TYPE >* m_pReferenceObject;
    Ref< TYPE >* m_pNextReference;
    Ref< TYPE >* m_pPreviousReference;
    friend class RefEntity< TYPE >;
};

//////////////////////////////////////////////////////////////////////////
template<class TYPE>
class RefLinkList{
public:
    struct RefListNode{
        RefListNode* m_pNext;
        Ref<TYPE> m_sRefData;
    };
public:
    RefLinkList();
    ~RefLinkList();
    void PushBack( TYPE sObject );
    bool32 Remove( TYPE sObject );
    void Clear();
    RefListNode* m_pRoot;
};



template < class TYPE >
class RefEntity{
public:
    RefEntity( TYPE tNewData );
    ~RefEntity();
    const RefEntity< TYPE >& operator = ( const RefEntity< TYPE >& tObject );
    void Clear();
    void SetData( TYPE tNewData );
    TYPE GetData() const;
    Ref<TYPE>* GetFirstReference() const;
    Ref<TYPE>* GetLastReference() const;
    Ref<TYPE>* GetNextReference( Ref< TYPE >* pReference ) const;
    Ref<TYPE>* GetPreviousReference( Ref< TYPE >* pReference ) const;
    int32 GetReferenceCount() const;
protected:
    void Add( Ref< TYPE >* pReference );
    void Remove( Ref< TYPE >* pReference );
    Ref< TYPE >* m_pFirstReference;
    Ref< TYPE >* m_pLastReference;
    int32 m_nReferenceCount;
    TYPE m_pEntityData;
    friend class Ref< TYPE >;
};

template < class TYPE >
class CRefClass{
public:
    CRefClass();
    virtual ~CRefClass();

protected:
    RefEntity< TYPE > m_pReferenceObj;

private:
    uint32 m_nResGUID;
    friend class Ref< TYPE >;
    friend class RefLinkList<TYPE>;
    friend class CGarbageCollection;
    friend class CResourceManager;
};


class CRefObject;
void ___AddObjectToGC( CRefObject *pRefObj );

class CRefObject: public CRefClass<CRefObject*>{
public:
    CRefObject(){
        ___AddObjectToGC( this );
    }
    virtual ~CRefObject(){

    }
};

///////////////////////////////////////////////////////////////////////////////////
template < class TYPE >
Ref<TYPE>::Ref(){
    m_pReferenceObject = NULL;
    m_pNextReference = NULL;
    m_pPreviousReference = NULL;
}

//template < class TYPE >
//Ref<TYPE>::Ref( const Ref& ref ){
//    m_pReferenceObject = NULL;
//    m_pNextReference = NULL;
//    m_pPreviousReference = NULL;
//    if( ref.IsAttached() ) Attach( *ref.m_pReferenceObject );
//}

template < class TYPE >
Ref<TYPE>::Ref( RefEntity< TYPE >& tNewReferenceObject ){
    m_pReferenceObject = NULL;
    m_pNextReference = NULL;
    m_pPreviousReference = NULL;
    Attach( tNewReferenceObject );
}

template < class TYPE >
Ref<TYPE>::Ref( CRefClass<TYPE>* pRefClass ){
    m_pReferenceObject = NULL;
    m_pNextReference = NULL;
    m_pPreviousReference = NULL;
    Attach( pRefClass->m_pReferenceObj );
}
template < class TYPE >
Ref<TYPE>::Ref( void* pRefClass ){
    m_pReferenceObject = NULL;
    m_pNextReference = NULL;
    m_pPreviousReference = NULL;
    CRefClass<TYPE>* _pRefClass = (CRefClass<TYPE>*)pRefClass;
    Attach( _pRefClass->m_pReferenceObj );
}
template < class TYPE >
Ref<TYPE>::Ref( const Ref< TYPE >& tObject ){
    m_pReferenceObject = NULL;
    m_pNextReference = NULL;
    m_pPreviousReference = NULL;
    if( tObject.IsAttached() ) Attach( *tObject.m_pReferenceObject );
}
template < class TYPE >
Ref<TYPE>::~Ref(){
    Detach();
}
template < class TYPE >
const Ref< TYPE >& Ref<TYPE>::operator = ( const Ref< TYPE >& tObject ){
    Detach();
    if( tObject.IsAttached() ) Attach( *tObject.m_pReferenceObject );
    return (*this);
}
template < class TYPE >
const Ref< TYPE >& Ref<TYPE>::operator = ( CRefClass<TYPE>* pRefClass ){
    Detach();
    assert( pRefClass );
    Attach( pRefClass->m_pReferenceObj );
    return (*this);
}
template < class TYPE >
TYPE Ref<TYPE>::operator->() const{
    return GetEntityData();
}
template < class TYPE >
TYPE Ref<TYPE>::GetEntityData() const{
    assert( m_pReferenceObject );
    TYPE _p = m_pReferenceObject->GetData();
    assert( _p );
    return _p;
}
//template < class TYPE >
//void Ref<TYPE>::Destroy(){
//    TYPE _p = GetEntityData();
//    DELETE( _p );
//}
template < class TYPE >
void Ref<TYPE>::Attach( RefEntity< TYPE >& tNewReferenceObject ){
    Detach();
    m_pReferenceObject = &tNewReferenceObject;
    m_pReferenceObject->Add( this );
}
template < class TYPE >
void Ref<TYPE>::Detach(){
    if( m_pReferenceObject != NULL ){
        m_pReferenceObject->Remove( this );
        m_pReferenceObject = NULL;
    }
    m_pNextReference = NULL;
    m_pPreviousReference = NULL;
}
template < class TYPE >
bool Ref<TYPE>::IsAttached() const{
    return (m_pReferenceObject != NULL);
}


///////////////////////////////////////////////////////////////////////////////
template < class TYPE >
RefLinkList<TYPE>::RefLinkList(){
    m_pRoot = NEW RefListNode();
    m_pRoot->m_pNext = NULL;
}
template < class TYPE >
RefLinkList<TYPE>::~RefLinkList(){
    Clear();
    DELETE( m_pRoot );
}
template < class TYPE >
void RefLinkList<TYPE>::PushBack( TYPE sObject ){
    RefListNode* _pNode = m_pRoot;
    while( _pNode->m_pNext ){
        _pNode = _pNode->m_pNext;
    }
    RefListNode* __pNode = NEW RefListNode();
    __pNode->m_pNext = NULL;
    __pNode->m_sRefData = sObject;
    _pNode->m_pNext = __pNode;
}
template < class TYPE >
bool32 RefLinkList<TYPE>::Remove( TYPE sObject ){
    RefListNode* _pPrevNode = m_pRoot;
    RefListNode* _pNode = m_pRoot->m_pNext;
    while( _pNode ){
        if( _pNode->m_sRefData.GetEntityData() == sObject ){
            _pPrevNode->m_pNext = _pNode->m_pNext;
            DELETE( _pNode );
            return True;
            break;
        }
        _pPrevNode = _pNode;
        _pNode = _pNode->m_pNext;
    }
    return False;
}
template < class TYPE >
void RefLinkList<TYPE>::Clear(){
    RefListNode* _pNode = m_pRoot->m_pNext;
    while( _pNode ){
        RefListNode* __pNode = _pNode->m_pNext;
        DELETE( _pNode );
        _pNode = __pNode;
    }
    m_pRoot->m_pNext = NULL;
}


///////////////////////////////////////////////////////////////////////////////
template < class TYPE >
RefEntity<TYPE>::RefEntity( TYPE tNewData ){
    m_pFirstReference = NULL;
    m_pLastReference = NULL;
    m_nReferenceCount = 0;
    m_pEntityData = tNewData;
}
template < class TYPE >
RefEntity<TYPE>::~RefEntity(){
    Clear();
}
template < class TYPE >
const RefEntity< TYPE >& RefEntity<TYPE>::operator = ( const RefEntity< TYPE >& tObject ){
    m_pFirstReference = NULL;
    m_pLastReference = NULL;
    m_nReferenceCount = 0;
    m_pEntityData = NULL;
    return (*this);
}
template < class TYPE >
void RefEntity<TYPE>::Clear(){
    Ref<TYPE>* _pCurrentReference;
    Ref<TYPE>* _pNextReference;
    _pCurrentReference = m_pFirstReference;
    while( _pCurrentReference != NULL ){
        _pNextReference = _pCurrentReference->m_pNextReference;
        _pCurrentReference->m_pReferenceObject = NULL;
        _pCurrentReference->m_pNextReference = NULL;
        _pCurrentReference->m_pPreviousReference = NULL;
        _pCurrentReference = _pNextReference;
    }
    m_pFirstReference = NULL;
    m_pLastReference = NULL;
    m_nReferenceCount = 0;
}
template < class TYPE >
void RefEntity<TYPE>::SetData( TYPE tNewData ){
    m_pEntityData = tNewData;
}
template < class TYPE >
TYPE RefEntity<TYPE>::GetData() const{
    return m_pEntityData;
}
template < class TYPE >
Ref<TYPE>* RefEntity<TYPE>::GetFirstReference() const{
    return m_pFirstReference;
}
template < class TYPE >
Ref<TYPE>* RefEntity<TYPE>::GetLastReference() const{
    return m_pLastReference;
}
template < class TYPE >
Ref<TYPE>* RefEntity<TYPE>::GetNextReference( Ref< TYPE >* pReference ) const{
    if( pReference == NULL ) return NULL;
    return pReference->m_pNextReference;
}
template < class TYPE >
Ref<TYPE>* RefEntity<TYPE>::GetPreviousReference( Ref< TYPE >* pReference ) const{
    if( pReference == NULL ) return NULL;
    return pReference->m_pPreviousReference;
}
template < class TYPE >
int32 RefEntity<TYPE>::GetReferenceCount() const{
    return m_nReferenceCount;
}
template < class TYPE >
void RefEntity<TYPE>::Add( Ref< TYPE >* pReference ){
    pReference->m_pNextReference = NULL;
    pReference->m_pPreviousReference = m_pLastReference;
    if( m_pFirstReference == NULL ) m_pFirstReference = pReference;
    if( m_pLastReference != NULL ) m_pLastReference->m_pNextReference = pReference;
    m_pLastReference = pReference;
    m_nReferenceCount++;
}
template < class TYPE >
void RefEntity<TYPE>::Remove( Ref< TYPE >* pReference ){
    if( pReference->m_pNextReference == NULL ){
        if( pReference->m_pPreviousReference == NULL ){
            m_pFirstReference = NULL;
            m_pLastReference = NULL;
        } else{
            m_pLastReference = pReference->m_pPreviousReference;
            m_pLastReference->m_pNextReference = NULL;
        }
    } else{
        if( pReference->m_pPreviousReference == NULL ){
            m_pFirstReference = pReference->m_pNextReference;
            m_pFirstReference->m_pPreviousReference = NULL;
        } else{
            pReference->m_pPreviousReference->m_pNextReference = pReference->m_pNextReference;
            pReference->m_pNextReference->m_pPreviousReference = pReference->m_pPreviousReference;
        }
    }
    m_nReferenceCount--;
}


////////////////////////////////////////////////////////////////////////////////////////////////
template < class TYPE >
CRefClass<TYPE>::CRefClass():m_pReferenceObj( (TYPE)this ), m_nResGUID(0){
}

template < class TYPE >
CRefClass<TYPE>::~CRefClass(){

}

//template < class TYPE >
//void CRefClass<TYPE>::SetData( TYPE _this ){
//    m_pReferenceObj.SetData( this );
//}

#endif


/*
// reference 用例
    //用例說明，常用的角色和紋理的關係，一個角色对象(CRoleTest)可能會使用多个纹理对象(CTextureTest)
    //这时在角色对象上添加一个引用(CReference)把引用的类型设置为纹理对象(CTextureTest)
    //在纹理对象上添加一个引用对象(CReferenceObject)并且把引用的类型设置成自己的类型,并且要在构造函数里添加实例数据
    //在对象实例化了过后就可以添加引用了( Attach  ) 
    //CReferenceObject引用对象，可以自动添加计数，自动识别同类引用，在主类删除时自动清空引用等


    class CTextureTest;         
    class CRoleTest{
    public:
        CRoleTest(){
        }
        CReference<  void*, CTextureTest* > m_pTextureReference;        //引用
    };

    class CTextureTest{
    public:
        CTextureTest(){
            m_pReferenceObj.SetData( this );
        }
        CReferenceObject< void*, CTextureTest* > m_pReferenceObj;       //引用对象，可能是多个
        int32 m_nID;
    };


    void test( ){
        CRoleTest* _testRef = NEW CRoleTest();
        CRoleTest* _testRef1 = NEW CRoleTest();

        CTextureTest* _tex0 = NEW CTextureTest();
        _tex0->m_nID = 0;
        _testRef->m_pTextureReference.Attach( _tex0->m_pReferenceObj );         //添加引用
        _testRef1->m_pTextureReference.Attach( _tex0->m_pReferenceObj );        //再添加引用 (_tex0　m_pReferenceObj)的引用计数应该为２
        CTextureTest* _tex1 = NEW CTextureTest();
        _tex1->m_nID = 1;
        _testRef->m_pTextureReference.Attach( _tex1->m_pReferenceObj );         //添加其它的引用 (_tex0　m_pReferenceObj)的引用计数应该为1了
        _testRef1->m_pTextureReference.Attach( _tex1->m_pReferenceObj );
        CTextureTest* _tex2 = NEW CTextureTest();
        _tex2->m_nID = 2;
        _testRef->m_pTextureReference.Attach( _tex2->m_pReferenceObj );
        _testRef1->m_pTextureReference.Attach( _tex2->m_pReferenceObj );
        CTextureTest* _tex3 = NEW CTextureTest();
        _tex3->m_nID = 3;
        _testRef->m_pTextureReference.Attach( _tex3->m_pReferenceObj );
        _testRef1->m_pTextureReference.Attach( _tex3->m_pReferenceObj );

        CTextureTest* _TestTex = _testRef->m_pTextureReference.GetObjectData();
        if ( _TestTex ){
        printf( "%d", _TestTex->m_nID );
        }
        _TestTex = _testRef1->m_pTextureReference.GetObjectData();
        if ( _TestTex ){
        printf( "%d", _TestTex->m_nID );
        }
        DELETE( _testRef );                                                     //可以自动删除引用的

        DELETE( _tex3 );                                                        //可以自动清空引用的

        _TestTex = _testRef->m_pTextureReference.GetObjectData();
        if ( _TestTex ){
        printf( "%d", _TestTex->m_nID );
        }
        _TestTex = _testRef1->m_pTextureReference.GetObjectData();
        if ( _TestTex ){
        printf( "%d", _TestTex->m_nID );
        }
    }

*/