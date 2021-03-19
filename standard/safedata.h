/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: safedata.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __SAFEDATA_H__
#define __SAFEDATA_H__

#include <include/stdtype.h>

/*  ²âÊÔÓÃÀý

CSafeInt32 _sInt32( 1234567890 );
int32 _n = _sInt32.GetValue();
_n += 10123;
_sInt32.SetValue( _n );
printf( "%d\n", _sInt32.GetValue() );

CSafeFloat _sFloat32( 10.34f );
float _n1 = _sFloat32.GetValue();
_n1 += 56.324f;
_sFloat32.SetValue( _n1 );
printf( "%f\n", _sFloat32.GetValue() );

struct STest{
    int32 m_nID;
    int32 m_nNumber;
};

STest _sTest = { 123,456 };

CSafeMem _sSafeMem( &_sTest, sizeof( STest ) );
STest* _pTest = (STest*)_sSafeMem.Lock();
_pTest->m_nID = 987;
_pTest->m_nNumber = 453;
_sSafeMem.UnLock();

_pTest->m_nID = 346;
_pTest->m_nNumber = 567;
if( _sSafeMem.Check() == False ){
    printf( "error \n" );
}
*/

#define SAFEDATAKEY (0x2f4d87a3)

class CSafeInt32{
public:
    CSafeInt32();
    CSafeInt32( int32 nValue );
    ~CSafeInt32();
    void SetValue( int32 nValue );
    int32 GetValue();

private:
    byte m_vValue[4];
};

class CSafeFloat{
public:
    CSafeFloat();
    CSafeFloat( float fValue );
    ~CSafeFloat();
    void SetValue( float fValue );
    float GetValue();

private:
    byte m_vValue[4];
};


class CSafeMem{
public:
    CSafeMem( int32 nSize );
    CSafeMem( void* pData, int32 nSize );
    ~CSafeMem();
    void* Lock();
    void UnLock();
    bool32 Check();

private:
    void* m_pData;
    int32 m_nSize;
    bool32 m_bRef;
    byte m_vMD5Code[16];
};









#endif
