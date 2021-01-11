/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: map.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_MAP_H__
#define __STANDARD_MAP_H__

#include <include/stdtype.h>
#include <include/stdlib.h>

////
////map<int, int> _vIntMapTest;
////_vIntMapTest.insert( 10, 1000 );
////_vIntMapTest.insert( 90, 1001 );
////_vIntMapTest.insert( 80, 1002 );
////_vIntMapTest.insert( 5, 1003 );
////_vIntMapTest.insert( 2, 1004 );
////_vIntMapTest.insert( 1, 1005 );
////_vIntMapTest.insert( 87, 1006 );
////_vIntMapTest.insert( 0, 1007 );
//////_vIntMapTest.insert( 1, 1000 );
//////_vIntMapTest.insert( 2, 1001 );
////map<int, int>::iterator it_end = _vIntMapTest.end();
////for( map<int, int>::iterator it = _vIntMapTest.begin(); it != it_end;/* it ++*/ ){
////    int key = it.first();
////    int value = it.second();
////    printf( "%d,%d\n", key, value );
////    if( key > 50 ){
////        it = _vIntMapTest.erase( it );
////    } else{
////        it ++;
////    }
////}
////map<int, int>::reverse_iterator rit_end = _vIntMapTest.rend();
////for( map<int, int>::reverse_iterator it = _vIntMapTest.rbegin(); it != rit_end; it ++ ){
////    int key = it.first();
////    int value = it.second();
////    printf( "%d,%d\n", key, value );
////}
////map<int, int>::iterator it = _vIntMapTest.find( 90 );
////if( it != _vIntMapTest.end() ){
////    int key = it.first();
////    int value = it.second();
////    printf( "%d,%d\n", key, value );
////}
////_vIntMapTest.clear();


template <class KeyType, class ValueType>
class map{
    //template <class KeyTypeRB, class ValueTypeRB>
    class RBTree{
    public:
        RBTree( const KeyType& k, const ValueType& v ):
        LeftChild( 0 ), RightChild( 0 ), Parent( 0 ), Key( k ),
        Value( v ), IsRed( true ){
        }

        void setLeftChild( RBTree* p ){
            LeftChild = p;
            if( p )
                p->setParent( this );
        }

        void setRightChild( RBTree* p ){
            RightChild = p;
            if( p )
                p->setParent( this );
        }

        void setParent( RBTree* p ){ Parent = p; }

        void setValue( const ValueType& v ){ Value = v; }

        void setRed(){ IsRed = true; }
        void setBlack(){ IsRed = false; }

        RBTree* getLeftChild() const{ return LeftChild; }
        RBTree* getRightChild() const{ return RightChild; }
        RBTree* getParent() const{ return Parent; }

        const ValueType& getValue() const{
            return Value;
        }

        ValueType& getValue(){
            return Value;
        }

        const KeyType& getKey() const{
            return Key;
        }


        bool isRoot() const{
            return Parent == 0;
        }

        bool isLeftChild() const{
            return (Parent != 0) && (Parent->getLeftChild() == this);
        }

        bool isRightChild() const{
            return (Parent != 0) && (Parent->getRightChild() == this);
        }

        bool isLeaf() const{
            return (LeftChild == 0) && (RightChild == 0);
        }

        unsigned int getLevel() const{
            if( isRoot() )
                return 1;
            else
                return getParent()->getLevel() + 1;
        }


        bool isRed() const{
            return IsRed;
        }

        bool isBlack() const{
            return !IsRed;
        }

    private:
        RBTree();

        RBTree* LeftChild;
        RBTree* RightChild;

        RBTree* Parent;

        KeyType Key;
        ValueType Value;

        bool IsRed;
    };

public:
    typedef RBTree Node;
    class const_iterator;
    class iterator{
        friend class const_iterator;
    public:
        iterator(): Root( 0 ), Cur( 0 ){}
        iterator( Node* root ): Root( root ){
            reset();
        }
        iterator( Node* root, Node* cur ): Root( root ), Cur( cur ){
            if( cur == 0 ){
                reset( false );
            }
        }
        iterator( const iterator& src ): Root( src.Root ), Cur( src.Cur ){}
        void reset( bool atLowest = true ){
            if( atLowest )
                Cur = getMin( Root );
            else
                Cur = getMax( Root );
        }
        bool atEnd() const{
            return Cur == 0;
        }
        Node* getNode() const{
            return Cur;
        }
        const KeyType & first() const{
            return Cur->getKey();
        }
        ValueType & second() const{
            return Cur->getValue();
        }
        iterator& operator=( const iterator& src ){
            Root = src.Root;
            Cur = src.Cur;
            return (*this);
        }
        bool operator==( const iterator &rhs ) const{
            return Root == rhs.Root && Cur == rhs.Cur;
        }
        bool operator!=( const iterator &rhs ) const{
            return Root != rhs.Root || Cur != rhs.Cur;
        }
        iterator &operator++(){
            inc();
            return *this;
        }
        void operator++( int ){
            inc();
        }
        iterator &operator--(){
            dec();
            return *this;
        }
        void operator--( int ){
            dec();
        }
        Node* operator->(){
            return getNode();
        }
        Node& operator*(){
            return *Cur;
        }
    private:
        Node* getMin( Node* n ) const{
            while( n && n->getLeftChild() )
                n = n->getLeftChild();
            return n;
        }
        Node* getMax( Node* n ) const{
            while( n && n->getRightChild() )
                n = n->getRightChild();
            return n;
        }
        void inc(){
            if( Cur == 0 )
                return;
            if( Cur->getRightChild() ){
                Cur = getMin( Cur->getRightChild() );
            } else if( Cur->isLeftChild() ){
                Cur = Cur->getParent();
            } else{
                while( Cur->isRightChild() )
                    Cur = Cur->getParent();
                Cur = Cur->getParent();
            }
        }
        void dec(){
            if( Cur == 0 )
                return;
            if( Cur->getLeftChild() ){
                Cur = getMax( Cur->getLeftChild() );
            } else if( Cur->isRightChild() ){
                Cur = Cur->getParent();
            } else{
                while( Cur->isLeftChild() )
                    Cur = Cur->getParent();
                Cur = Cur->getParent();
            }
        }
        Node* Root;
        Node* Cur;
    };


    struct reverse_iterator{
        iterator current;
        reverse_iterator(){}
        reverse_iterator( iterator value ): current( value ){}
        iterator base() const{
            return current;
        }
        const KeyType& first() const{
            iterator temp = current;
            return (temp).first();
        }
        ValueType& second() const{
            iterator temp = current;
            return (temp).second();
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

    class ParentFirstIterator{
    public:
        ParentFirstIterator(): Root( 0 ), Cur( 0 ){}
        ParentFirstIterator( Node* root ): Root( root ), Cur( 0 ){
            reset();
        }
        void reset(){
            Cur = Root;
        }
        bool atEnd() const{
            return Cur == 0;
        }
        Node* getNode(){
            return Cur;
        }
        ParentFirstIterator& operator=( const ParentFirstIterator& src ){
            Root = src.Root;
            Cur = src.Cur;
            return (*this);
        }
        void operator++( int ){
            inc();
        }
        Node* operator -> (){
            return getNode();
        }
        Node& operator* (){
            return *getNode();
        }
    private:
        void inc(){
            if( Cur == 0 )
                return;
            if( Cur->getLeftChild() ){
                Cur = Cur->getLeftChild();
            } else if( Cur->getRightChild() ){
                Cur = Cur->getRightChild();
            } else{
                while( Cur != 0 ){
                    if( Cur->isLeftChild() && Cur->getParent()->getRightChild() ){
                        Cur = Cur->getParent()->getRightChild();
                        return;
                    }
                    Cur = Cur->getParent();
                }
            }
        }

        Node* Root;
        Node* Cur;

    };
    class ParentLastIterator{
    public:
        ParentLastIterator(): Root( 0 ), Cur( 0 ){}
        ParentLastIterator( Node* root ): Root( root ), Cur( 0 ){
            reset();
        }
        void reset(){
            Cur = getMin( Root );
        }
        bool atEnd() const{
            return Cur == 0;
        }
        Node* getNode(){
            return Cur;
        }
        ParentLastIterator& operator=( const ParentLastIterator& src ){
            Root = src.Root;
            Cur = src.Cur;
            return (*this);
        }
        void operator++( int ){
            inc();
        }
        Node* operator -> (){
            return getNode();
        }
        Node& operator* (){
            return *getNode();
        }
    private:
        Node* getMin( Node* n ){
            while( n != 0 && (n->getLeftChild() != 0 || n->getRightChild() != 0) ){
                if( n->getLeftChild() )
                    n = n->getLeftChild();
                else
                    n = n->getRightChild();
            }
            return n;
        }
        void inc(){
            if( Cur == 0 )
                return;
            if( Cur->isLeftChild() && Cur->getParent()->getRightChild() ){
                Cur = getMin( Cur->getParent()->getRightChild() );
            } else
                Cur = Cur->getParent();
        }

        Node* Root;
        Node* Cur;
    };
    //class AccessClass{
    //    friend class map<KeyType, ValueType>;
    //public:
    //    void operator=( const ValueType& value ){
    //        Tree.set( Key, value );
    //    }
    //    operator ValueType(){
    //        Node* node = Tree.find( Key );
    //        return node->getValue();
    //    }
    //private:
    //    AccessClass( map& tree, const KeyType& key ): Tree( tree ), Key( key ){}
    //    AccessClass();
    //    map& Tree;
    //    const KeyType& Key;
    //};
    map(): Root( 0 ), Size( 0 ){}
    ~map(){
        clear();
    }
    bool insert( const KeyType& keyNew, const ValueType& v ){
        iterator it = find( keyNew );
        if( it != end() ){
            it.getNode()->setValue( v );
        }else{
            Node* newNode = NEW Node( keyNew, v );
            if( !insert( newNode ) ){
                DELETE( newNode );
                return false;
            }
            while( !newNode->isRoot() && (newNode->getParent()->isRed()) ){
                if( newNode->getParent()->isLeftChild() ){
                    Node* newNodesUncle = newNode->getParent()->getParent()->getRightChild();
                    if( newNodesUncle != 0 && newNodesUncle->isRed() ){
                        newNode->getParent()->setBlack();
                        newNodesUncle->setBlack();
                        newNode->getParent()->getParent()->setRed();
                        newNode = newNode->getParent()->getParent();
                    } else{
                        if( newNode->isRightChild() ){
                            newNode = newNode->getParent();
                            rotateLeft( newNode );
                        }
                        newNode->getParent()->setBlack();
                        newNode->getParent()->getParent()->setRed();
                        rotateRight( newNode->getParent()->getParent() );
                    }
                } else{
                    Node* newNodesUncle = newNode->getParent()->getParent()->getLeftChild();
                    if( newNodesUncle != 0 && newNodesUncle->isRed() ){
                        newNode->getParent()->setBlack();
                        newNodesUncle->setBlack();
                        newNode->getParent()->getParent()->setRed();
                        newNode = newNode->getParent()->getParent();
                    } else{
                        if( newNode->isLeftChild() ){
                            newNode = newNode->getParent();
                            rotateRight( newNode );
                        }
                        newNode->getParent()->setBlack();
                        newNode->getParent()->getParent()->setRed();
                        rotateLeft( newNode->getParent()->getParent() );
                    }

                }
            }
            Root->setBlack();
        } 
        return true;
    }
    //void set( const KeyType& k, const ValueType& v ){
    //    Node* p = find( k );
    //    if( p )
    //        p->setValue( v );
    //    else
    //        insert( k, v );
    //}
    //Node* delink( const KeyType& k ){
    //    Node* p = find( k );
    //    if( p == 0 )
    //        return 0;
    //    while( p->getRightChild() ){
    //        rotateLeft( p );
    //    }
    //    Node* left = p->getLeftChild();
    //    if( p->isLeftChild() )
    //        p->getParent()->setLeftChild( left );
    //    else if( p->isRightChild() )
    //        p->getParent()->setRightChild( left );
    //    else{
    //        setRoot( left );
    //    }
    //    --Size;
    //    return p;
    //}
    //bool remove( const KeyType& k ){
    //    Node* p = find( k );
    //    return remove( p );
    //}
    bool remove( Node* p ){
        if( p == 0 ){
            return false;
        }
        while( p->getRightChild() ){
            rotateLeft( p );
        }
        Node* left = p->getLeftChild();
        if( p->isLeftChild() )
            p->getParent()->setLeftChild( left );
        else if( p->isRightChild() )
            p->getParent()->setRightChild( left );
        else{
           setRoot( left );
        }
        DELETE( p );
        --Size;
        return true;
    }
    iterator erase( iterator& it ){
        iterator _rit = it;
        it ++;
        remove( _rit.getNode() );
        return it;
    }
    void clear(){
        ParentLastIterator i( getParentLastIterator() );
        while( !i.atEnd() ){
            Node* p = i.getNode();
            i++;
            DELETE( p );
        }
        Root = 0;
        Size = 0;
    }
    bool empty() const{
        return Root == 0;
    }
    bool isEmpty() const{
        return empty();
    }
    iterator find( const KeyType& keyToFind ) const{
        Node* pNode = Root;
        while( pNode != 0 ){
            const KeyType& key = pNode->getKey();
            if( keyToFind < key )
                pNode = pNode->getLeftChild();
            else if( key < keyToFind )
                pNode = pNode->getRightChild();
            else
                return iterator( Root, pNode );

            //if( keyToFind == key )
            //    return iterator( Root, pNode );
            //else if( keyToFind < key )
            //    pNode = pNode->getLeftChild();
            //else
            //    pNode = pNode->getRightChild();
        }
        return end();
    }
    Node* getRoot() const{
        return Root;
    }
    uint32 size() const{
        return Size;
    }
    iterator begin() const{
        iterator it( Root );
        return it;
    }
    iterator end() const{
        iterator it( Root, 0 );
        it ++;
        return it;
    }
    reverse_iterator rbegin(){
        iterator _end( Root, 0 );;
        return reverse_iterator( _end );
    }
    reverse_iterator rend(){
        iterator _begin( Root );
        _begin --;
        return reverse_iterator( _begin );
    }
    ParentFirstIterator getParentFirstIterator() const{
        ParentFirstIterator it( getRoot() );
        return it;
    }
    ParentLastIterator getParentLastIterator() const{
        ParentLastIterator it( getRoot() );
        return it;
    }
    ////ValueType operator[]( const KeyType& k ){
    ////    iterator it = find( k );
    ////    if( it != end() ){
    ////        return it.second();
    ////    }
    ////    return ValueType();
    ////}
    ////ValueType& operator[]( const KeyType& k ) const {
    ////    iterator it = find( k );
    ////    if( it != end() ){
    ////        return it.second();
    ////    }
    ////    return ValueType();
    ////}

    ////map( const map& src ){
    ////    //map<KeyType, ValueType>::iterator it = src.begin();
    ////    //map<KeyType, ValueType>::iterator it_end = src.end();
    ////    //for( ; it != it_end; it ++ ){
    ////    //    insert( it.first(), it.second() );
    ////    //}
    ////    ParentLastIterator i( src.getParentLastIterator() );
    ////    while( !i.atEnd() ){
    ////        Node* p = i.getNode();
    ////        i++;
    ////        insert( p );
    ////    }
    ////}
private:
   // map( const map& src );
   // map& operator = ( const map& src );
    void setRoot( Node* newRoot ){
        Root = newRoot;
        if( Root != 0 ){
            Root->setParent( 0 );
            Root->setBlack();
        }
    }
    bool insert( Node* newNode ){
        bool result = true;
        if( Root == 0 ){
            setRoot( newNode );
            Size = 1;
        } else{
            Node* pNode = Root;
            const KeyType& keyNew = newNode->getKey();
            while( pNode ){
                const KeyType& key = pNode->getKey();

                if( keyNew < key ){
                    if( pNode->getLeftChild() == 0 ){
                        pNode->setLeftChild( newNode );
                        pNode = 0;
                    } else{
                        pNode = pNode->getLeftChild();
                    }
                } else if( key < keyNew ){
                    if( pNode->getRightChild() == 0 ){
                        pNode->setRightChild( newNode );
                        pNode = 0;
                    } else{
                        pNode = pNode->getRightChild();
                    }
                } else{
                    result = false;
                    pNode = 0;
                }


                //if( keyNew == key ){
                //    result = false;
                //    pNode = 0;
                //} else if( keyNew < key ){
                //    if( pNode->getLeftChild() == 0 ){
                //        pNode->setLeftChild( newNode );
                //        pNode = 0;
                //    } else
                //        pNode = pNode->getLeftChild();
                //} else{
                //    if( pNode->getRightChild() == 0 ){
                //        pNode->setRightChild( newNode );
                //        pNode = 0;
                //    } else{
                //        pNode = pNode->getRightChild();
                //    }
                //}
            }
            if( result )
                ++Size;
        }
        return result;
    }
    void rotateLeft( Node* p ){
        Node* right = p->getRightChild();
        p->setRightChild( right->getLeftChild() );
        if( p->isLeftChild() )
            p->getParent()->setLeftChild( right );
        else if( p->isRightChild() )
            p->getParent()->setRightChild( right );
        else
            setRoot( right );
        right->setLeftChild( p );
    }
    void rotateRight( Node* p ){
        Node* left = p->getLeftChild();
        p->setLeftChild( left->getRightChild() );
        if( p->isLeftChild() )
            p->getParent()->setLeftChild( left );
        else if( p->isRightChild() )
            p->getParent()->setRightChild( left );
        else
            setRoot( left );
        left->setRightChild( p );
    }
    Node* Root;
    uint32 Size;
};

#endif
