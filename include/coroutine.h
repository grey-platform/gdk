/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: coroutine.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __GRAY_SDK_COROUTINE_H__
#define __GRAY_SDK_COROUTINE_H__

//#ifdef _NATIVE_
//#include <time.h>
//#else
#include <include/stdtype.h>
#include <include/time.h>
#include <include/assert.h>
//#endif

#define CORO0 1
#define CORO1 2
#define CORO2 3
#define CORO3 4
#define CORO4 5
#define CORO5 6
#define CORO6 7
#define CORO7 8
#define CORO8 9
#define CORO9 10
#define CORO10 11
#define CORO11 12
#define CORO12 13
#define CORO13 14
#define CORO14 15
#define CORO15 16
#define CORO16 17
#define CORO17 18
#define CORO18 19
#define CORO19 20
#define CORO20 21
#define CORO21 22
#define CORO22 23
#define CORO23 24
#define CORO24 25
#define CORO25 26
#define CORO26 27
#define CORO27 28
#define CORO28 29
#define CORO29 30
#define CORO30 31
#define CORO31 32
#define CORO32 33
#define CORO33 34
#define CORO34 35
#define CORO35 36
#define CORO36 37
#define CORO37 38
#define CORO38 39
#define CORO39 40
#define CORO40 41
#define CORO41 42
#define CORO42 43
#define CORO43 44
#define CORO44 45
#define CORO45 46
#define CORO46 47
#define CORO47 48
#define CORO48 49
#define CORO49 50
#define CORO50 51
#define CORO51 52
#define CORO52 53
#define CORO53 54
#define CORO54 55
#define CORO55 56
#define CORO56 57
#define CORO57 58
#define CORO58 59
#define CORO59 60
#define CORO60 61
#define CORO61 62
#define CORO62 63
#define CORO63 64
#define CORO64 65
#define CORO65 66
#define CORO66 67
#define CORO67 68
#define CORO68 69
#define CORO69 70
#define CORO70 71
#define CORO71 72
#define CORO72 73
#define CORO73 74
#define CORO74 75
#define CORO75 76
#define CORO76 77
#define CORO77 78
#define CORO78 79
#define CORO79 80
#define CORO80 81
#define CORO81 82
#define CORO82 83
#define CORO83 84
#define CORO84 85
#define CORO85 86
#define CORO86 87
#define CORO87 88
#define CORO88 89
#define CORO89 90
#define CORO90 91
#define CORO91 92
#define CORO92 93
#define CORO93 94
#define CORO94 95
#define CORO95 96
#define CORO96 97
#define CORO97 98
#define CORO98 99
#define CORO99 100

#define LC_INIT(s) s = 0;

#define LC_RESUME(s) switch(s) { case 0:

#define LC_SET(s,l) s = l; case l:

#define LC_END(s) }

#define PT_WAITING 0
#define PT_YIELDED 1
#define PT_EXITED  2
#define PT_ENDED   3

#define PT_INIT(pt)   LC_INIT(pt)

#define PT_THREAD(name_args) uint32 name_args

#define PT_BEGIN(pt) { uint32 PT_YIELD_FLAG = 1; LC_RESUME(pt)

#define PT_END(pt) LC_END(pt); PT_YIELD_FLAG = 0;\
    PT_INIT(pt); return PT_ENDED; }

#define PT_WAIT_UNTIL(pt, condition, l) \
    LC_SET(pt,l); \
    if(!(condition)) { \
    return PT_WAITING; \
    }

#define PT_WAIT_WHILE(pt, cond, l)  PT_WAIT_UNTIL(pt, !(cond), l)

#define PT_WAIT_THREAD(pt, thread) PT_WAIT_WHILE(pt, PT_SCHEDULE(thread))

#define PT_SPAWN(pt, child, thread) \
    PT_INIT((child)); \
    PT_WAIT_THREAD(pt, (thread));

#define PT_RESTART(pt) \
    PT_INIT(pt); \
    return PT_WAITING;

#define PT_EXIT(pt) \
    PT_INIT(pt); \
    return PT_EXITED;

#define PT_SCHEDULE(f) ((f) < PT_EXITED)

#define PT_YIELD(pt,l) \
    PT_YIELD_FLAG = 0; \
    LC_SET(pt,l); \
    if(PT_YIELD_FLAG == 0) { \
    return PT_YIELDED; \
    }

#define PT_YIELD_UNTIL(pt, cond,l) \
    PT_YIELD_FLAG = 0; \
    LC_SET(pt,l); \
    if((PT_YIELD_FLAG == 0) || !(cond)) { \
    return PT_YIELDED; \
    }


#define PT_WAIT_RETURN_UNTIL(pt, condition, l, r) \
    LC_SET(pt,l); \
    if(!(condition)) { \
    return r; \
    }

#define PT_WAIT_RETURN_WHILE(pt, cond, l, r)  PT_WAIT_RETURN_UNTIL(pt, !(cond), l, r)

///////////////////////////////////////////////////////////////////////////////////////////

#define TASKBEGIN() PT_BEGIN( pt1 )
#define TASKEND() PT_END(pt1)
#define SLEEP( n ) \
    m_tCoroTimer = clock() + n;\
    PT_WAIT_UNTIL(pt1, (clock() >= m_tCoroTimer), __LINE__ );
#define YIELD() PT_YIELD( pt1, __LINE__ )
#define WAIT( c) PT_WAIT_WHILE(pt1, c, __LINE__ )
#define WAITRETURN( c, r ) PT_WAIT_RETURN_WHILE(pt1, c, __LINE__, r )
#define EXIT() PT_EXIT(pt1)


#define SLEEP_NEW( n, l ) \
    m_tCoroTimer = clock() + n;\
    PT_WAIT_UNTIL(pt1, (clock() >= m_tCoroTimer), l );
#define YIELD_NEW(l) PT_YIELD( pt1, l )
#define WAIT_NEW( c,l) PT_WAIT_WHILE(pt1, c, l )
#define WAITRETURN_NEW( c, r, l ) PT_WAIT_RETURN_WHILE(pt1, c, l, r )


//////////////////////////////////////////////////////////////////////////////////
//COROFUNC

#define COROFUNCNAME() __pt_##FUNCNAME__
#define COROFUNCYIELD() PT_YIELD( COROFUNCNAME(), __LINE__ );

#define COROFUNCBEGIN( a, b, c, d )\
int32 FUNCNAME( int32 nDelta, float fDelta, a, b, c, d ){ \
static int32 COROFUNCNAME() = 0;
    

#define COROFUNCEND() PT_END(COROFUNCNAME()); }

#define COROFUNCCALL( FuncName, a, b, c, d ) PT_WAIT_WHILE( COROFUNCNAME(),  FuncName( nDelta, fDelta, a, b, c, d ) != PT_ENDED, __LINE__ );

#define COROFUNCDECLAR( FuncName, a, b, c, d ) int32 FuncName( int32 nDelta, float fDelta, a, b, c, d );

#define COROFUNCS() PT_BEGIN( COROFUNCNAME() );


#define COROFUNCRETURN() PT_EXIT(COROFUNCNAME());

#define COROFUNCTRACENAMEVALUE( s ) printf("coro name:%s value: %d\n", #s, COROFUNCNAME() );

////COROFUNCDECLAR( BBB )
////
////#define FUNCNAME AAA
////COROFUNCBEGIN()
////printf( "%d\n", 1 );
////COROFUNCYIELD()
////printf( "%d\n", 2 );
////COROFUNCYIELD()
////printf( "%d\n", 3 );
////COROFUNCYIELD()
////COROFUNCCALL( BBB );
////printf( "%d\n", 4 );
////COROFUNCYIELD()
////printf( "%d\n", 5 );
////COROFUNCEND()
////#undef FUNCNAME
////
////#define FUNCNAME BBB
////COROFUNCBEGIN()
////printf( "%d\n", 11 );
////COROFUNCYIELD()
////printf( "%d\n", 12 );
////COROFUNCYIELD()
////printf( "%d\n", 13 );
////COROFUNCYIELD()
////printf( "%d\n", 14 );
////COROFUNCYIELD()
////printf( "%d\n", 15 );
////COROFUNCEND()
////#undef FUNCNAME

#endif

