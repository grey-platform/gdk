/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: list.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_LIST_H__
#define __STANDARD_LIST_H__

#include <include/stdtype.h>
#include <include/stdlib.h>

template <class T> class list{
public:
    struct list_node{
        list_node *prev;
        list_node *next;
        T data;
    };

   struct iterator{
        // data member
        list_node * node; 

        iterator(){}
        iterator( list_node * x ): node( x ){}
        bool operator==( const iterator &rhs ) const{
            return node == rhs.node;
        }
        bool operator!=( const iterator &rhs ) const{
            return node != rhs.node;
        }
        T & operator*() const{
            return node->data;
        }
        //// member access
        //T * operator->() const{
        //    return (T*)(&(node->data));
        //}
        iterator &operator++(){
            node = node->next;
            return *this;
        }
        iterator operator++( int i ){
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        iterator &operator--(){
            node = node->prev;
            return *this;
        }
        iterator operator--( int i ){
            iterator temp = *this;
            --(*this);
            return temp;
        }
    };

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

    //////////////////////////////////////////////////////////////

    list_node *node;
    size_t count;
    list_node *get_node(){
        list_node* _pNode = (list_node *)CALLOC(1, sizeof( list_node ) );
        return _pNode;
    }   
    void put_node( list_node *p ){
        //list_node_allocator::deallocate( p );
        FREE( p );
    }
    list_node *create_node( const T &value ){
        list_node *p = get_node();
        p->data = value;//?????????????????
        count++;
        return p;
    }
    void destroy_node( list_node *p ){
        //destroy( &p->data );      //??????????????????????????????????????????
        put_node( p );
        count --;
    }
    void empety_initialized(){
        node = get_node();
        node->next = node;
        node->prev = node;
        count = 0;
    }
    list(){
        empety_initialized();
    }
    list( list &rhs ){
        empety_initialized();
        copy( node, rhs.node );
    }
    list &operator=( list &rhs ){
        clear();
        copy( node, rhs.node );
        return *this;
    }
    ~list(){
        clear();
        put_node( node );
    }

public: // getter
    bool empty() const{
        return node->next == node;
    }
    size_t size() const{
        return count;
    }

public: // setter
    iterator begin(){
        return iterator( node->next );
    }
    iterator end(){
        return iterator( node );
    }
    reverse_iterator rbegin(){
        return reverse_iterator( end() );
    }
    reverse_iterator rend(){
        return reverse_iterator( begin() );
    }

    T & front(){
        return *begin();
    }
    T & back(){
        return *(--end());
    }

public: // insert
    iterator insert( iterator position, const T &val ){
        list_node *temp = create_node( val );
        temp->next = position.node;
        temp->prev = position.node->prev;
        position.node->prev->next = temp;
        position.node->prev = temp;
        return iterator( temp );
    }

public: // erase
    iterator erase( iterator position ){
        list_node *next_node = position.node->next;
        list_node *prev_node = position.node->prev;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        destroy_node( position.node );
        return iterator( next_node );    
    }

    void Remove( const T &value ){
        iterator it = begin();
        iterator it_end = end();
        for( ; it != it_end; ){
            if( *it == value ){
                it = erase( it );
            } else{
                it ++;
            }
        }
    }

    void clear(){
        list_node *cur = node->next;
        while( cur != node ){
            list_node *temp = cur;
            cur = cur->next;
            destroy_node( temp );
        }
        node->next = node;
        node->prev = node;
    }

public: // push && pop
    void push_front( const T &value ){
        insert( begin(), value );
    }
    void push_back( const T &value ){
        insert( end(), value );
    }
    void pop_front(){
        erase( begin() );
    }
    void pop_back(){
        iterator temp = end();
        erase( --temp );
    }
    void copy( list_node *node, list_node *rhs_node ){
        list_node* _nodeIT = node;  //end
        list_node* _rhsNodeIT = rhs_node->next; //begin
        while( _rhsNodeIT != rhs_node ){
            list_node *temp = create_node( _rhsNodeIT->data );
            temp->next = _nodeIT;
            temp->prev = _nodeIT->prev;
            _nodeIT->prev->next = temp;
            _nodeIT->prev = temp;
            _rhsNodeIT = _rhsNodeIT->next;
        }
    }

};

#endif
