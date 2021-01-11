/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: system.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __STANDARD_STREAM_H__
#define __STANDARD_STREAM_H__

#include <include/stdtype.h>

class CStream{
public:
    CStream();
    virtual ~CStream();
    void  SetPos( int32 n ){ m_nPos = n; }
    void  Skip( int32 n ){ m_nPos += n; }
    int32 GetSize(){ return m_nSize; }
    int32 GetPos(){ return m_nPos; }
    byte* GetCur(){ return m_pData + m_nPos; }
    byte* GetData(){ return m_pData; }
    bool32 Eof();
    bool32 Read( object32 pBuf, int32 nSize );
    int32 ReadString0( char* v );
    int32 ReadString1( char* v );
    CStream& operator >> ( int8 &v );
    CStream& operator >> ( uint8 &v );
    CStream& operator >> ( int16 &v );
    CStream& operator >> ( uint16 &v );
    CStream& operator >> ( int32 &v );
    CStream& operator >> ( uint32 &v );
    //CStream& operator >> ( bool32 &v );
    CStream& operator >> ( float &v );
   // CStream& operator >> ( bool &v );
    //CStream& operator >> ( char* &v );

    bool32 Write( object32 pBuf, int32 nSize );
    int32 WriteString0( char* v );
    int32 WriteString1( char* v );
    CStream& operator << ( int8 &v );
    CStream& operator << ( uint8 &v );
    CStream& operator << ( int16 &v );
    CStream& operator << ( uint16 &v );
    CStream& operator << ( int32 &v );
    CStream& operator << ( uint32 &v );
    //CStream& operator << ( bool32 &v );
    CStream& operator << ( float &v );
  //  CStream& operator << ( bool &v );
    //CStream& operator << ( char* &v );

protected:
    int32 m_nSize;
    int32 m_nPos;
    byte* m_pData;

};

class CDataStream: public CStream{
public:
    CDataStream();
    CDataStream( int32 nSize );
    CDataStream( void* pData, int32 nSize, bool32 bCopy );
    virtual ~CDataStream();
    void SetData( void* pData, int32 nSize, bool32 bCopy );

protected:
    bool32 m_bCopyMemory;
};

class CFileStream: public CStream{
public:
    CFileStream( const char* strFileName );
    virtual ~CFileStream();
    void Close();
protected:
    char m_strFileName[256];

};

#endif
