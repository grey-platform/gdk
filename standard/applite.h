/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: applite.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_APPLITE_H__
#define __STANDARD_APPLITE_H__

#include <include/stdtype.h>
#include <include/ui.h>
#include <standard/reference.h>

class CAppLite: public CRefClass<CAppLite*>{
public:
    static HUIHANDLE m_hRootHandle;
    static int32 m_nRootWidth;
    static int32 m_nRootHeight;
    CAppLite();
    virtual ~CAppLite();
    virtual int32 Init( HUIHANDLE hParentHandle, int32 nWidth, int32 nHeight );
    virtual int32 Update( int32 nDelta, float fDelta );
    virtual int32 Render();
    virtual int32 Final();
    virtual int32 OnSystemCommand( int32 nCmd );
    virtual int32 Event( int32 nParam0, int32 nParam1, int32 nParam2, int32 nParam3, int32 nParam4, int32 nParam5, int32 nParam6, int32 nParam7, int32 nParam8, int32 nParam9 );
    virtual int32 HttpRequestEvent( int32 nParam0, int32 nParam1, int32 nParam2, int32 nParam3 );
    virtual int32 SoundEvent( int32 nParame0, int32 nParame1 );
    virtual int32 NeedData( int32 nParame0, int32 nParame1, int32 nParame2, int32 nParame3 );
    virtual int32 RemoteFileTaskEvent( int32 nParam0, int32 nParam1, int32 nParam2, int32 nParam3 );
    virtual int32 FinalyDebug();
    
};

CAppLite* StartApplite();

#endif
