#ifndef __STANDARD_DELEGATE_H__
#define __STANDARD_DELEGATE_H__

#include <include/stdtype.h>

class IDelegateInterface{
public:
};

template<class TP1>
class CDelegate1{
public:
    typedef void(IDelegateInterface::* DelegateFunc)(TP1);
    CDelegate1(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
	}
    ~CDelegate1(){

    }
	void operator()( TP1 v ){
        if( m_pDelegateObj ){
            (m_pDelegateObj->*m_pFunc)(v);
        } else{

        }
    }
    void Bind( IDelegateInterface* object, DelegateFunc func ){
        m_pDelegateObj = object;
        m_pFunc = func;
    }
    void Clear(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
private:
	IDelegateInterface* m_pDelegateObj;
    DelegateFunc  m_pFunc;
};
#define BINDDELEGATEFUNC1( a, b, c, t0 ) a.Bind( (IDelegateInterface*)b, (CDelegate1<t0>::DelegateFunc)(&c) )

/// /////////////////////////////////////////////////////////////////////////////

template<class TP1, class TP2>
class CDelegate2{
public:
    typedef void(IDelegateInterface::* DelegateFunc)(TP1, TP2);
    CDelegate2(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
    ~CDelegate2(){

    }
    void operator()( TP1 v1, TP2 v2 ){
        if( m_pDelegateObj ){
            (m_pDelegateObj->*m_pFunc)(v1, v2);
        } else{

        }
    }
    void Bind( IDelegateInterface* object, DelegateFunc func ){
        m_pDelegateObj = object;
        m_pFunc = func;
    }
    void Clear(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
private:
    IDelegateInterface* m_pDelegateObj;
    DelegateFunc  m_pFunc;
};
#define BINDDELEGATEFUNC2( a, b, c, t1, t2 ) a.Bind( (IDelegateInterface*)b, (CDelegate2<t1, t2>::DelegateFunc)(&c) )

/// /////////////////////////////////////////////////////////////////////////////
template<class TP1, class TP2, class TP3>
class CDelegate3{
public:
    typedef void(IDelegateInterface::* DelegateFunc)(TP1, TP2, TP3);
    CDelegate3(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
    ~CDelegate3(){

    }
    void operator()( TP1 v1, TP2 v2, TP3 v3 ){
        if( m_pDelegateObj ){
            (m_pDelegateObj->*m_pFunc)(v1, v2, v3);
        } else{

        }
    }
    void Bind( IDelegateInterface* object, DelegateFunc func ){
        m_pDelegateObj = object;
        m_pFunc = func;
    }
    void Clear(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
private:
    IDelegateInterface* m_pDelegateObj;
    DelegateFunc  m_pFunc;
};
#define BINDDELEGATEFUNC3( a, b, c, t1, t2, t3 ) a.Bind( (IDelegateInterface*)b, (CDelegate3<t1, t2, t3>::DelegateFunc)(&c) )


/// /////////////////////////////////////////////////////////////////////////////
template<class TP1, class TP2, class TP3, class TP4>
class CDelegate4{
public:
    typedef void(IDelegateInterface::* DelegateFunc)(TP1, TP2, TP3, TP4);
    CDelegate4(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
    ~CDelegate4(){

    }
    void operator()( TP1 v1, TP2 v2, TP3 v3, TP4 v4 ){
        if( m_pDelegateObj ){
            (m_pDelegateObj->*m_pFunc)(v1, v2, v3, v4);
        } else{

        }
    }
    void Bind( IDelegateInterface* object, DelegateFunc func ){
        m_pDelegateObj = object;
        m_pFunc = func;
    }
    void Clear(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
private:
    IDelegateInterface* m_pDelegateObj;
    DelegateFunc  m_pFunc;
};
#define BINDDELEGATEFUNC4( a, b, c, t1, t2, t3, t4 ) a.Bind( (IDelegateInterface*)b, (CDelegate4<t1, t2, t3, t4>::DelegateFunc)(&c) )

/// /////////////////////////////////////////////////////////////////////////////
template<class TP1, class TP2, class TP3, class TP4, class TP5>
class CDelegate5{
public:
    typedef void(IDelegateInterface::* DelegateFunc)(TP1, TP2, TP3, TP4, TP5);
    CDelegate5(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
    ~CDelegate5(){

    }
    void operator()( TP1 v1, TP2 v2, TP3 v3, TP4 v4, TP5 v5 ){
        if( m_pDelegateObj ){
            (m_pDelegateObj->*m_pFunc)(v1, v2, v3, v4, v5);
        } else{

        }
    }
    void Bind( IDelegateInterface* object, DelegateFunc func ){
        m_pDelegateObj = object;
        m_pFunc = func;
    }
    void Clear(){
        m_pDelegateObj = NULL;
        m_pFunc = NULL;
    }
private:
    IDelegateInterface* m_pDelegateObj;
    DelegateFunc  m_pFunc;
};
#define BINDDELEGATEFUNC5( a, b, c, t1, t2, t3, t4, t5 ) a.Bind( (IDelegateInterface*)b, (CDelegate5<t1, t2, t3, t4, t5>::DelegateFunc)(&c) )



//////////
//////////class CDelegateTest{
//////////public:
//////////    CDelegateTest(){
//////////        aaa = 789;
//////////    }
//////////    virtual ~CDelegateTest(){
//////////
//////////    }
//////////    virtual void OnClick( float n ){
//////////
//////////    }
//////////
//////////    int32 aaa;
//////////};
//////////
//////////class CDelegateTest1: public CDelegateTest{
//////////public:
//////////    CDelegateTest1(){
//////////        aaa1 = 78911;
//////////    }
//////////    virtual ~CDelegateTest1(){
//////////
//////////    }
//////////    virtual void OnClick( float n ){
//////////        aaa1 = n;
//////////    }
//////////    virtual void OnClick( int32 n, int32 n1 ){
//////////        aaa1 = n;
//////////    }
//////////    virtual void OnClick( int32 n, int32 n1, int32 n2 ){
//////////        aaa1 = n;
//////////    }
//////////    virtual void OnClick( int32 n, int32 n1, int32 n2, int32 n3 ){
//////////        aaa1 = n;
//////////    }
//////////    virtual void OnClick( int32 n, int32 n1, int32 n2, int32 n3, int32 n4 ){
//////////        aaa1 = n;
//////////    }
//////////    int32 aaa1;
//////////};
//////////
//////////
//////////CDelegateTest* _pDelegateTest = NEW CDelegateTest1();
//////////CDelegate1<float >aaa;
//////////BINDDELEGATEFUNC1( aaa, _pDelegateTest, CDelegateTest::OnClick, float );
//////////aaa( 456.12356f );
//////////
//////////CDelegate2<int32, int32 >aaa1;
//////////BINDDELEGATEFUNC2( aaa1, _pDelegateTest, CDelegateTest1::OnClick, int32, int32 );
//////////aaa1( 1, 2 );
//////////
//////////CDelegate3<int32, int32, int32 >aaa2;
//////////BINDDELEGATEFUNC3( aaa2, _pDelegateTest, CDelegateTest1::OnClick, int32, int32, int32 );
//////////aaa2( 1, 2, 3 );
//////////
//////////CDelegate4<int32, int32, int32, int32 >aaa3;
//////////BINDDELEGATEFUNC4( aaa3, _pDelegateTest, CDelegateTest1::OnClick, int32, int32, int32, int32 );
//////////aaa3( 1, 2, 3, 4 );
//////////
//////////CDelegate5<int32, int32, int32, int32, int32 >aaa4;
//////////BINDDELEGATEFUNC5( aaa4, _pDelegateTest, CDelegateTest1::OnClick, int32, int32, int32, int32, int32 );
//////////aaa4( 1, 2, 3, 4, 5 );
//////////




#endif
