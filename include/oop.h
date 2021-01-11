/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: oop.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_OOP_H__
#define __GRAY_SDK_OOP_H__

#include <include/stdlib.h>
//#include <include/stdtype.h>

////#define THIS _this
////
////#define SUPER THIS->_super
////
////#define NEW(c) c##__Create( c##__ClassInit( ( c*)malloc(sizeof( c)) ) )
////
////#define DELETE( p ) p->Destroy( p ), free( p ), p = 0
////
////#define BindMember(c, f) THIS->f = &(c##__##f);
////
////#define ClassBegin( type, parent ) typedef struct type{ parent _SUPER; parent* _super;
////
////#define ClassEnd( type, parent )struct type*(*Create)(struct type *THIS );\
////void(*Destroy)(struct type * THIS); }type;\
////struct type* type##__ClassInit( struct type *THIS);
////
////#define ClassBeginInit( type, parent )\
////struct type* type##__ClassInit( struct type *THIS){\
////SUPER = &THIS->_SUPER;\
////parent##__ClassInit( SUPER );\
////BindMember(type, Create);\
////BindMember(type, Destroy);
////
////#define ClassEndInit() return THIS; }
////
////#define DeclareClass( type )typedef struct type _##type;\
////DeclareCreate( type ) \
////DeclareDestroy( type )
////
////#define DefineMember(type, f)_##type##__##f f;
////
////#define DeclareCreate( type )\
////typedef struct type*( *_##type##__Create )( struct type* THIS ); \
////struct type* type##__Create( struct type* THIS );
////
////#define DeclareDestroy( type )\
////typedef void( *_##type##__Destroy )( struct type* THIS ); \
////void type##__Destroy( struct type* THIS );
////
////#define DeclareFunc0( type, func, ret )\
////typedef ret( *_##type##__##func )( struct type* THIS );\
////ret type##__##func( struct type* THIS );
////
////#define DeclareFunc1( type, func, ret, a )\
////typedef ret( *_##type##__##func )( struct type* THIS, a );\
////ret type##__##func( struct type* THIS, a );
////
////#define DeclareFunc2( type, func, ret, a, b )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b );\
////ret type##__##func( struct type* THIS, a, b );
////
////#define DeclareFunc3( type, func, ret, a, b, c )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b, c );\
////ret type##__##func( struct type* THIS, a, b, c );
////
////#define DeclareFunc4( type, func, ret, a, b, c, d )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b, c, d );\
////ret type##__##func( struct type* THIS, a, b, c, d );
////
////#define DeclareFunc5( type, func, ret, a, b, c, d, e )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b, c, d, e );\
////ret type##__##func( struct type* THIS, a, b, c, d, e );
////
////#define DeclareFunc6( type, func, ret, a, b, c, d, e, f )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b, c, d, e, f );\
////ret type##__##func( struct type* THIS, a, b, c, d, e, f );
////
////#define DeclareFunc7( type, func, ret, a, b, c, d, e, f, g )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b, c, d, e, f, g );\
////ret type##__##func( struct type* THIS, a, b, c, d, e, f, g );
////
////#define DeclareFunc8( type, func, ret, a, b, c, d, e, f, g, h )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b, c, d, e, f, g, h );\
////ret type##__##func( struct type* THIS, a, b, c, d, e, f, g, h );
////
////#define DeclareFunc9( type, func, ret, a, b, c, d, e, f, g, h, i )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b, c, d, e, f, g, h, i );\
////ret type##__##func( struct type* THIS, a, b, c, d, e, f, g, h, i );
////
////#define DeclareFunc10( type, func, ret, a, b, c, d, e, f, g, h, i, j )\
////typedef ret( *_##type##__##func )( struct type* THIS, a, b, c, d, e, f, g, h, i, j );\
////ret type##__##func( struct type* THIS, a, b, c, d, e, f, g, h, i, j );
////
////
////typedef struct BaseClass{
////    int m_nID;
////}BaseClass;
////
////struct BaseClass* BaseClass__ClassInit(struct BaseClass*);

#define THIS _this

#define VT( o ) o->vt

#define INVOK( o, f ) o->vt->f (o

//#define NEW( type ) type##__Create( _##type##__ClassInit_( ( type*)malloc(sizeof( type ))) )

//#define DELETE( p ) if( p ) p->Destroy( p ), free( p->vt ), free( p ), p = 0

#define DeclareClassInit( type )\
type* _##type##__ClassInit_( type *THIS );\
void type##__ClassInit( type *THIS );

#define DeclareCreate( type )\
typedef type*( *_##type##__Create )( type* THIS ); \
type* type##__Create( type* THIS );

#define DeclareDestroy( type )\
typedef void( *_##type##__Destroy )( type* THIS ); \
void type##__Destroy( type* THIS );

#define DeclareFunc0( type, func, ret )\
typedef ret( *_##type##__##func )( type* THIS );\
ret type##__##func( type* THIS );

#define DeclareFunc1( type, func, ret, a )\
typedef ret( *_##type##__##func )( type* THIS, a );\
ret type##__##func( type* THIS, a );

#define DeclareFunc2( type, func, ret, a, b )\
typedef ret( *_##type##__##func )( type* THIS, a, b );\
ret type##__##func( type* THIS, a, b );

#define DeclareFunc3( type, func, ret, a, b, c )\
typedef ret( *_##type##__##func )( type* THIS, a, b, c );\
ret type##__##func( type* THIS, a, b, c );

#define DeclareFunc4( type, func, ret, a, b, c, d )\
typedef ret( *_##type##__##func )( type* THIS, a, b, c, d );\
ret type##__##func( type* THIS, a, b, c, d );

#define DeclareFunc5( type, func, ret, a, b, c, d, e )\
typedef ret( *_##type##__##func )( type* THIS, a, b, c, d, e );\
ret type##__##func( type* THIS, a, b, c, d, e );

#define DeclareFunc6( type, func, ret, a, b, c, d, e, f )\
typedef ret( *_##type##__##func )( type* THIS, a, b, c, d, e, f );\
ret type##__##func( type* THIS, a, b, c, d, e, f );

#define DeclareFunc7( type, func, ret, a, b, c, d, e, f, g )\
typedef ret( *_##type##__##func )( type* THIS, a, b, c, d, e, f, g );\
ret type##__##func( type* THIS, a, b, c, d, e, f, g );

#define DeclareFunc8( type, func, ret, a, b, c, d, e, f, g, h )\
typedef ret( *_##type##__##func )( type* THIS, a, b, c, d, e, f, g, h );\
ret type##__##func( type* THIS, a, b, c, d, e, f, g, h );

#define DeclareFunc9( type, func, ret, a, b, c, d, e, f, g, h, i )\
typedef ret( *_##type##__##func )( type* THIS, a, b, c, d, e, f, g, h, i );\
ret type##__##func( type* THIS, a, b, c, d, e, f, g, h, i );

#define DeclareFunc10( type, func, ret, a, b, c, d, e, f, g, h, i, j )\
typedef ret( *_##type##__##func )( type* THIS, a, b, c, d, e, f, g, h, i, j );\
ret type##__##func( type* THIS, a, b, c, d, e, f, g, h, i, j );

#define BindMember(type, func) THIS->func = &(type##__##func);

#define ClassBeginInit( type )\
type* _##type##__ClassInit_( type *THIS ){\
THIS->vt=(type##FuncTable*)malloc(sizeof(type##FuncTable));\
BindMember(type, Create);\
BindMember(type, Destroy);\
type##__ClassInit( THIS );\
return THIS; \
}\
void type##__ClassInit( type *THIS ){

#define InheritClass( type ) type##__ClassInit( (type*)THIS );

#define BindFunction( type, func ) VT(THIS)->func = &type##__##func;

#define OverrideFunction( type, parent, func ) VT( THIS )->func = (_##parent##__##func)&type##__##func;

#define ClassEndInit() }


#define BeginClass( type ) typedef struct type type;

#define MemberFunc( type, func ) _##type##__##func func;

#define OverrideMemberFunc( type, func ) 

#define EndClass( type ) DeclareClassInit(type) \
DeclareCreate( type ) \
DeclareDestroy( type ) \
typedef struct _##type##FuncTable{ \
type##__Func \
}type##FuncTable;\
struct type{ \
type##FuncTable* vt;\
_##type##__Create Create;\
_##type##__Destroy Destroy;\
type##__Data \
};


//test
//////////////////////////////////////////////////////////////////////////////////
////BeginClass( CBaseClass )
////#define CBaseClass__Data \
////int x;\
////int y;
////
////#define CBaseClass__Func \
////MemberFunc( CBaseClass, Print )
////
////DeclareFunc0( CBaseClass, Print, void )
////EndClass( CBaseClass )
////
////
//////////////////////////////////////////////////////////////////////////////
////BeginClass( CInhertClass )
////#define CInhertClass__Data \
////CBaseClass__Data \
////int myX;\
////int myY;
////
////#define CInhertClass__Func \
////CBaseClass__Func \
////MemberFunc( CInhertClass, GetX ) \
////MemberFunc( CInhertClass, GetY )
////
////DeclareFunc0( CInhertClass, Print, void )
////DeclareFunc0( CInhertClass, GetX, int )
////DeclareFunc0( CInhertClass, GetY, int )
////EndClass( CInhertClass )
///////////////////////////////////////////////////////////////////////////////////////
////
////BeginClass( CThirdClass )
////#define CThirdClass__Data \
////CInhertClass__Data 
////
////#define CThirdClass__Func \
////CInhertClass__Func \
////
////DeclareFunc0( CThirdClass, Print, void )
////EndClass( CThirdClass )
////
/////////////////////////////////////////////////////////////////////////////////////////////
////
////ClassBeginInit( CBaseClass )
////BindFunction( CBaseClass, Print )
////ClassEndInit()
////
////struct CBaseClass* CBaseClass__Create( struct CBaseClass* THIS ){
////    THIS->x = 0;
////    THIS->y = 1;
////    return THIS;
////}
////
////void CBaseClass__Destroy( struct CBaseClass* THIS ){
////
////}
////
////void CBaseClass__Print( struct CBaseClass* THIS ){
////    printf( "%d,%d\n", THIS->x, THIS->y );
////}
////
////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////ClassBeginInit( CInhertClass )
////InheritClass( CBaseClass )
////OverrideFunction( CInhertClass, CBaseClass, Print )
////BindFunction( CInhertClass, GetX )
////BindFunction( CInhertClass, GetY )
////ClassEndInit()
////
////struct CInhertClass* CInhertClass__Create( struct CInhertClass* THIS ){
////    THIS->x = 10;
////    THIS->y = 11;
////    THIS->myX = 100;
////    THIS->myY = 101;
////    return THIS;
////}
////
////void CInhertClass__Destroy( struct CInhertClass* THIS ){
////
////}
////
////int CInhertClass__GetX( struct CInhertClass* THIS ){
////    return THIS->myX;
////}
////int CInhertClass__GetY( struct CInhertClass* THIS ){
////    return THIS->myY;
////}
////void CInhertClass__Print( struct CInhertClass* THIS ){
////    printf( "%d,%d\n", THIS->x, THIS->y );
////    printf( "%d,%d\n", THIS->myX, THIS->myY );
////    CBaseClass__Print( (CBaseClass*)THIS );
////}
////
////////////////////////////////////////////////////////////////////////
////ClassBeginInit( CThirdClass )
////InheritClass( CInhertClass )
////OverrideFunction( CThirdClass, CInhertClass, Print )
////ClassEndInit()
////
////struct CThirdClass* CThirdClass__Create( struct CThirdClass* THIS ){
////    THIS->x = 20;
////    THIS->y = 21;
////    THIS->myX = 200;
////    THIS->myY = 201;
////    return THIS;
////}
////
////void CThirdClass__Destroy( struct CThirdClass* THIS ){
////
////}
////void CThirdClass__Print( struct CThirdClass* THIS ){
////    printf( "%d,%d\n", THIS->x, THIS->y );
////    printf( "%d,%d\n", THIS->myX, THIS->myY );
////    CInhertClass__Print( (CInhertClass*)THIS );
////}
////
////int main(){
////    CBaseClass* _pTestClass = NEW( CBaseClass );
////    VT( _pTestClass )->Print( _pTestClass );
////    DELETE( _pTestClass );
////
////    CInhertClass* _pTestClass1 = NEW( CInhertClass );
////    VT( _pTestClass1 )->Print( _pTestClass1 );
////    int _nX = VT( _pTestClass1 )->GetX( _pTestClass1 );
////    int _nY = VT( _pTestClass1 )->GetY( _pTestClass1 );
////    DELETE( _pTestClass1 );
////
////    CThirdClass* _pThirdClass = NEW( CThirdClass );
////    VT( _pThirdClass )->Print( _pThirdClass );
////    INVOK( _pThirdClass, Print ) );
////    int _nX1 = VT( _pThirdClass )->GetX( _pThirdClass );
////    int _nY1 = VT( _pThirdClass )->GetY( _pThirdClass );
////    DELETE( _pThirdClass );
////    return 0;
////}

#endif


