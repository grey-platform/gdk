/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: allocator.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_ALLOCATOR_H__
#define __STANDARD_ALLOCATOR_H__

#include <include/stdtype.h>
//#include <include/stdlib.h>
//#include <standard/task.h>

void* Allocator__allocate( size_t nObjSize, size_t nCount );
void Allocator__deallocate( void* p, size_t nCount );
//
//template<class T>
//class Allocator{
//public:
//    //static T *allocate(){
//    //    return static_cast<T *>(malloc( sizeof( T ) ));
//    //}
//    ////////////static int m_nSize = 0;
//    //////////static T *allocate( size_t n ){
//    //////////    T* _ret = NULL;
//    //////////    if( n == 0 ) return _ret;
//    //////////    size_t _size = sizeof( T ) * n;
//    //////////    //m_nSize += _size;
//    //////////    _ret = (T*)(malloc( _size ));
//    //////////    //AddMem( _ret, _size );
//    //////////    return _ret;
//    //////////}
//    ////////////static void deallocate( T *ptr ){
//    ////////////    free( ptr );
//    ////////////    //alloc::deallocate( static_cast<void *>(ptr), sizeof( T ) );
//    ////////////}
//    //////////static void deallocate( T *ptr, size_t n ){
//    //////////    if( n == 0 ) return;
//    //////////    //FreeMem( ptr, sizeof( T ) * n );
//
//    //////////    free( ptr );
//
//
//    //////////    //m_nSize -= _size;
//
//    //////////    //alloc::deallocate( static_cast<void *>(ptr), sizeof( T )* n );
//    //////////}
//
//    //static void construct( T *ptr ){
//    //    new(ptr)T();
//    //}
//    //static void construct( T *ptr, const T& value ){
//    //    new(ptr)T( value );
//    //}
//    //static void destroy( T *ptr ){
//    //    ptr->~T();
//    //}
//    //static void destroy( T *first, T *last ){
//    //    for( ; first != last; ++first ){
//    //        first->~T();
//    //    }
//    //}
//};


#endif
