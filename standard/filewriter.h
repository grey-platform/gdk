/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: filewriter.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_FILEWRITER_H__
#define __STANDARD_FILEWRITER_H__

#include <include/stdio.h>
#include <standard/vector.h>

class CMemFile{
public:
    CMemFile();
    ~CMemFile();
    void Write(void* p, int32 nSize);
    void SetPos(int32 nPos);
    int32 GetPos();
    int32 GetSize();
    byte* GetData();

private:
    vector<byte>m_vData;
    int32 m_nPos;
};



class CFileWriter{
public:
    CFileWriter();
    ~CFileWriter();
    bool32 OpenFile( const char* strFileName );
    bool32 CloseFile();
    bool32 AddText( const char* strText );
    bool32 AddText( const char* strText, int32 nTextLen );
    bool32 AddInt( int32 nValue );
    bool32 AddFloat( float fValue );
    bool32 AddData( void* pData, int32 nSize );

private:
    _FILE* m_pFP;
};



#endif
