/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: delegate.h
*Module: gray
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_DELEGATE_H__
#define __GRAY_SDK_DELEGATE_H__

//#define DeclareDelegate0( name )\
//struct{\
//void* mObject;\
//void( *mFunc )(void*);\
//}name;

//#define DeclareDelegate1( name, a )\
//struct{\
//void* mObject;\
//void( *mFunc )(void*, a);\
//}name;

#define DeclareDelegate0( type, name ) typedef void( *_##type##__##name##_Delegate )(void*);
#define DeclareDelegate1( type, name, a ) typedef void( *_##type##__##name##_Delegate )(void*, a);
#define DeclareDelegate2( type, name, a, b ) typedef void( *_##type##__##name##_Delegate )(void*, a, b);
#define DeclareDelegate3( type, name, a, b, c ) typedef void( *_##type##__##name##_Delegate )(void*, a, b, c);
#define DeclareDelegate4( type, name, a, b, c, d ) typedef void( *_##type##__##name##_Delegate )(void*, a, b, c, d);
#define DeclareDelegate5( type, name, a, b, c, d, e ) typedef void( *_##type##__##name##_Delegate )(void*, a, b, c, d, e);
#define DeclareDelegate6( type, name, a, b, c, d, e, f ) typedef void( *_##type##__##name##_Delegate )(void*, a, b, c, d, e, f);
#define DeclareDelegate7( type, name, a, b, c, d, e, f, g ) typedef void( *_##type##__##name##_Delegate )(void*, a, b, c, d, e, f, g);
#define DeclareDelegate8( type, name, a, b, c, d, e, f, g, h ) typedef void( *_##type##__##name##_Delegate )(void*, a, b, c, d, e, f, g, h);
#define DeclareDelegate9( type, name, a, b, c, d, e, f, g, h, i ) typedef void( *_##type##__##name##_Delegate )(void*, a, b, c, d, e, f, g, h, i);
#define DeclareDelegate10( type, name, a, b, c, d, e, f, g, h, i, j ) typedef void( *_##type##__##name##_Delegate )(void*, a, b, c, d, e, f, g, h, i, j);

#define DefineDelegate( type, name )\
struct{\
void* mObject;\
_##type##__##name##_Delegate mFunc;\
}name;


#define DelegateBind( p, type, name, dp, df ) (p)->name.mObject=dp, (p)->name.mFunc=(_##type##__##name##_Delegate)&df;

#define DelegateInvoke0( d ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject );
#define DelegateInvoke1( d, a ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a );
#define DelegateInvoke2( d, a, b ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b );
#define DelegateInvoke3( d, a, b, c ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b, c );
#define DelegateInvoke4( d, a, b, c, d0 ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b, c, d0 );
#define DelegateInvoke5( d, a, b, c, d0, e ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b, c, d0, e );
#define DelegateInvoke6( d, a, b, c, d0, e, f ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b, c, d0, e, f );
#define DelegateInvoke7( d, a, b, c, d0, e, f, g ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b, c, d0, e, f, g );
#define DelegateInvoke8( d, a, b, c, d0, e, f, g, h ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b, c, d0, e, f, g, h );
#define DelegateInvoke9( d, a, b, c, d0, e, f, g, h, i ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b, c, d0, e, f, g, h, i );
#define DelegateInvoke10( d, a, b, c, d0, e, f, g, h, i, j ) if( d.mFunc && d.mObject ) d.mFunc( d.mObject, a, b, c, d0, e, f, g, h, i, j );

#define DelegateClear( p, d ) p->d.mObject=NULL, p->d.mFunc=NULL;

#endif
