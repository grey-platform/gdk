/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: vector.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_VECTOR_H__
#define __STANDARD_VECTOR_H__

#include <include/stdtype.h>
#include <standard/allocator.h>
#include <include/string.h>

template<class T>
class vector{
public:
    typedef T* iterator;

    struct reverse_iterator{
        // data member
        iterator current;

        reverse_iterator(){}
        reverse_iterator( iterator value ): current( value ){}
        iterator base() const{
            return current;
        }
        T& operator*() const{
            iterator temp = current;
            return *--temp;
        }
        reverse_iterator &operator++(){
            --current;
            return *this;
        }
        reverse_iterator operator++( int ){
            reverse_iterator temp = *this;
            --current;
            return temp;
        }
        reverse_iterator &operator--(){
            ++current;
            return *this;
        }
        reverse_iterator operator--( int ){
            reverse_iterator temp = *this;
            ++current;
            return temp;
        }
        bool operator==( const reverse_iterator &rhs ) const{
            return current == rhs.current;
        }
        bool operator!=( const reverse_iterator &rhs ) const{
            return !((*this) == rhs);
        }

    };


private:
    T *start_;
    T *finish_;
    T *endOfStorage_;



public:
    vector():start_( 0 ), finish_( 0 ), endOfStorage_( 0 ){
    }
    vector( size_t n ):start_( 0 ), finish_( 0 ), endOfStorage_( 0 ){
        resize( n );
    }
    //vector( size_t n, const T& value ):start_( 0 ), finish_( 0 ), endOfStorage_( 0 ){
    //    resize( n, value );
    //}
    vector( const vector& v ){
        allocateAndCopy( v.start_, v.finish_ );
    }
    vector& operator = ( const vector& v ){
        if( this != &v ){
            destroyAndDeallocateAll();
            allocateAndCopy( v.start_, v.finish_ );
        }
        return *this;
    }
    ~vector(){
        destroyAndDeallocateAll();
    }

    iterator begin(){ 
        return (start_); 
    }
    iterator end(){ 
        return (finish_);
    }
    reverse_iterator rbegin(){
        return reverse_iterator( end() );
    }
    reverse_iterator rend(){
        return reverse_iterator( begin() );
    }
    
    //
    size_t size()const{
        return finish_ - start_; 
    }
    size_t capacity()const{
        return endOfStorage_ - start_; 
    }
    bool empty()const{ 
        return start_ == finish_; 
    }
    void resize( size_t n ){
        T val;
        if( n < size() ){
            //dataAllocator::destroy( start_ + n, finish_ );
            finish_ = start_ + n;
        } else if( n > size() && n <= capacity() ){
            size_t lengthOfInsert = n - size();
            finish_ = uninitialized_fill_n( finish_, lengthOfInsert, val );
        } else if( n > capacity() ){
            size_t lengthOfInsert = n - size();
            T *newStart = (T *)Allocator__allocate( sizeof(T), getNewCapacity( lengthOfInsert ) );
            T *newFinish = uninitialized_copy( begin(), end(), newStart );
            newFinish = uninitialized_fill_n( newFinish, lengthOfInsert, val );
            destroyAndDeallocateAll();
            start_ = newStart;
            finish_ = newFinish;
            endOfStorage_ = start_ + n;
        }
    }
    void reserve( size_t n ){
        //if( n <= capacity() )
        //    return;
        //T *newStart = dataAllocator::allocate( n );
        //T *newFinish = stl::uninitialized_copy( begin(), end(), newStart );
        //destroyAndDeallocateAll();

        //start_ = newStart;
        //finish_ = newFinish;
        //endOfStorage_ = start_ + n;
    }
    //void shrink_to_fit();

    //
    T& at( const size_t i ){
        if( i < size() ){
            return *(begin() + i); 
        } else{
            return *(begin());
        }
    }
    T& operator[]( const size_t i ){
        if( i < size() ){
            return *(begin() + i);
        } else{
            return *(begin());
        }
    }

    T& front(){ 
        return *(begin()); 
    }
    T& back(){ 
        return *(end() - 1); 
    }
    T* data(){ 
        return start_; 
    }

    //
    //
    void clear(){
        //Allocator<T>::destroy( start_, finish_ );
        //finish_ = start_;

        destroyAndDeallocateAll();
        start_ = 0;
        finish_ = 0;
        endOfStorage_ = 0;
    }
    void push_back( const T& value ){
        insert( end(), value );
    }
    void pop_back(){
        if( finish_ != start_ )
            --finish_;
        //Allocator<T>::destroy( finish_ );
    }
    iterator insert( iterator position, const T& val ){
        const auto index = position - begin();
        insert( position, 1, val );
        return begin() + index;
    }
    void insert( iterator position, const size_t& n, const T& val ){
        insert_aux( position, n, val );
    }
    iterator erase( iterator position ){
        return erase( position, position + 1 );
    }
    iterator erase( iterator first, iterator last ){
        //
        size_t lenOfTail = end() - last;
        //
        size_t lenOfRemoved = last - first;
        finish_ = finish_ - lenOfRemoved;
        for( ; lenOfTail != 0; --lenOfTail ){
            T* temp = (last - lenOfRemoved);
            *temp = *(last++);
        }
        return (first);
    }

    void reverse(){//
        T *a = start_;
        size_t n = size();
        for( size_t i = 0; i < n / 2; ++i ){
            T temp = a[n - i - 1];
            a[n - i - 1] = a[i];
            a[i] = temp;
        }
    }
private:
    void destroyAndDeallocateAll(){
        if( capacity() != 0 ){
            Allocator__deallocate( start_, capacity() );
            //free( start_  );
        }
    }
    void allocateAndCopy( iterator first, iterator last ){
        start_ =  (T*)Allocator__allocate( sizeof( T ), (last - first) );
        //start_ = (T*)( malloc( sizeof( T) * (last - first) ) );
        finish_ = uninitialized_copy( first, last, start_ );
        endOfStorage_ = finish_;
    }
    void insert_aux( iterator position, size_t n, const T& value ){
        size_t locationLeft = endOfStorage_ - finish_;
        size_t locationNeed = n;
        if( locationLeft >= locationNeed ){
            T* tempPtr = end() - 1;
            for( ; tempPtr - position >= 0; --tempPtr ){
                *(tempPtr + locationNeed) = *tempPtr;   
               // construct( tempPtr + locationNeed, *tempPtr );
            }
            uninitialized_fill_n( position, n, value );
            finish_ += locationNeed;
        } else{
            reallocateAndFillN( position, n, value );
        }
    }

    iterator uninitialized_copy( iterator first, iterator last, T* result ){
        memcpy( result, first, (last - first) * sizeof( *first ) );
        return result + (last - first);
    }

    iterator uninitialized_fill_n( iterator first, size_t n, const T& value ){
        for( ; n > 0; --n, ++first )
            *first = value;
        return first;
    }

    void reallocateAndFillN( iterator position, const size_t& n, const T& val ){
        size_t newCapacity = getNewCapacity( n );
        T *newStart = (T*)Allocator__allocate( sizeof( T ), newCapacity );
        //T *newStart = (T *)malloc( sizeof( T ) * newCapacity );// Allocator<T>::allocate( newCapacity );
        T *newEndOfStorage = newStart + newCapacity;

        T *newFinish = uninitialized_copy( begin(), position, newStart );
        newFinish = uninitialized_fill_n( newFinish, n, val );
        newFinish = uninitialized_copy( position, end(), newFinish );

        destroyAndDeallocateAll();
        start_ = newStart;
        finish_ = newFinish;
        endOfStorage_ = newEndOfStorage;
    }
    size_t getNewCapacity( size_t len )const{
        size_t oldCapacity = endOfStorage_ - start_;
        size_t res = oldCapacity;
        if( len > res ){
            res = len;
        }
        size_t newCapacity = (oldCapacity != 0 ? (oldCapacity + res) : len);
        return newCapacity;
    }

};


#endif
