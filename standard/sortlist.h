/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: sortlist.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_SORTLIST_H__
#define __STANDARD_SORTLIST_H__

#include <include/stdtype.h>
#include <include/stdlib.h>

//#ifdef CPLUS

//#endif

template <class Key, class T> class sortlist{
public:
    struct sortlist_node{
        Key first;
        sortlist_node *prev;
        sortlist_node *next;
        T second;
    };

   struct iterator{
        // data member
       sortlist_node * node;

        iterator(){}
        iterator( sortlist_node * x ): node( x ){}
        bool operator==( const iterator &rhs ) const{
            return node == rhs.node;
        }
        bool operator!=( const iterator &rhs ) const{
            return node != rhs.node;
        }
        //T & operator*() const{
        //    return node->data;
        //}
        //// member access
        //T * operator->() const{
        //    return (T*)(&(node->data));
        //}
        Key & first() const{
            return node->first;
        }
        T & second() const{
            return node->second;
        }
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
       //T& operator*() const{
       //    iterator temp = current;
       //    return *--temp;
       //}
       Key& first() const{
           iterator temp = current;
           return (--temp).first();
       }
       T& second() const{
           iterator temp = current;
           return (--temp).second();
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

    sortlist_node *node;
    size_t count;
    sortlist_node *get_node(){
        return (sortlist_node *)malloc(sizeof( sortlist_node ) );
    }   
    void put_node( sortlist_node *p ){
        //list_node_allocator::deallocate( p );
        free( p );
    }
    sortlist_node *create_node( const Key &key, const T &value ){
        sortlist_node *p = get_node();
        p->first = key;
        p->second = value;//?????????????????
        count++;
        return p;
    }
    void destroy_node( sortlist_node *p ){
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
    sortlist(){
        empety_initialized();
    }

    sortlist( sortlist &rhs ){
        empety_initialized();
        //swap( node, rhs.node );
    }
    sortlist &operator=( sortlist &rhs ){
        clear();
        //swap( rhs );
        return *this;
    }

    ~sortlist(){
        clear();
        put_node( node );
    }



public: // getter
    bool empty() const{
        return node->next == node;
    }
    size_t size() const{
        //return /*MiniSTL::*/distance( cbegin(), cend() );
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

    //T & front(){
    //    return *begin();
    //}
    //T & back(){
    //    return *(--end());
    //}

public: // insert
    iterator insert( iterator position, const Key &key, const T &val ){
        sortlist_node *temp = create_node( key, val );
        temp->next = position.node;
        temp->prev = position.node->prev;
        position.node->prev->next = temp;
        position.node->prev = temp;
        return iterator( temp );
    }

    iterator insert( const Key &key, const T &val ){
        sortlist_node *cur = node->next;
        while( cur != node ){
            //if( cur->first > key ){
            //    break;
            //}
            //cur = cur->next;

            if (cur->first < key) {
                cur = cur->next;
            } else {
                break;
            }       
        }
        return insert( iterator( cur ), key, val );
    }

    iterator find( const Key &key ){
        sortlist_node *cur = node->next;
        while( cur != node ){
            const Key& _key = cur->first;
            if( _key < key ){
                cur = cur->next;
            } else if( key < _key ){
                cur = cur->next;
            } else{
                return iterator( cur );
            }

           // if( cur->first == key ){
           //     return iterator( cur );
           // }
           // cur = cur->next;
        }
        return iterator( node );
    }

public: // erase
    iterator erase( iterator position ){
        sortlist_node *next_node = position.node->next;
        sortlist_node *prev_node = position.node->prev;
        prev_node->next = next_node;
        next_node->prev = prev_node;
        destroy_node( position.node );
        return iterator( next_node );    
    }
    void clear(){
        sortlist_node *cur = node->next;
        while( cur != node ){
            sortlist_node *temp = cur;
            cur = cur->next;
            destroy_node( temp );
        }
        node->next = node;
        node->prev = node;
    }

public: // push && pop
    //void push_front( const T &value ){
    //    insert( begin(), value );
    //}
    //void push_back( const T &value ){
    //    insert( end(), value );
    //}
    //void pop_front(){
    //    erase( begin() );
    //}
    //void pop_back(){
    //    iterator temp = end();
    //    erase( --temp );
    //}
};



//////sortlist<int, int> _vIntMapTest;
//////_vIntMapTest.insert( 10, 1000 );
//////_vIntMapTest.insert( 90, 1001 );
//////_vIntMapTest.insert( 80, 1002 );
//////_vIntMapTest.insert( 5, 1003 );
//////_vIntMapTest.insert( 2, 1004 );
//////_vIntMapTest.insert( 1, 1005 );
//////_vIntMapTest.insert( 87, 1006 );
//////_vIntMapTest.insert( 0, 1007 );
//////for( sortlist<int, int>::iterator it = _vIntMapTest.begin(); it != _vIntMapTest.end(); it ++ ){
//////    int key = it.first();
//////    int value = it.second();
//////    printf( "%d,%d\n", key, value );
//////}
//////
//////for( sortlist<int, int>::reverse_iterator it = _vIntMapTest.rbegin(); it != _vIntMapTest.rend(); it ++ ){
//////    int key = it.first();
//////    int value = it.second();
//////    printf( "%d,%d\n", key, value );
//////}
//////
//////sortlist<int, int>::reverse_iterator it = _vIntMapTest.find( 90 );
//////if( it != _vIntMapTest.end() ){
//////    int key = it.first();
//////    int value = it.second();
//////    printf( "%d,%d\n", key, value );
//////}
//////_vIntMapTest.clear();

#endif
