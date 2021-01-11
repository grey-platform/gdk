/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: csv.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_CSV_H__
#define __STANDARD_CSV_H__

#include <include/stdtype.h>

class CCsv{
public:
    CCsv( const char* strText, int32 nSize );
    bool32 End();
    char* GetString();
    int32 GetInteger();
    float GetFloat();
    void Skip();

private:
    char* GetNextToken();
    const char* m_strText;
    int32 m_nSize;
    char* m_strCurText;
    char m_strTokenBuff[ 1024 ];
};



#endif

