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


#ifndef __STANDARD_CSVLIB_H__
#define __STANDARD_CSVLIB_H__

#include <include/stdtype.h>
#include <include/stdio.h>

class CCSV{
public:
    CCSV();
    ~CCSV();
    char* Init(const char* strText);
    void Close();
    int32 GetCol();
    int32 GetRow();
    char* GetNextRow(char* strCode);
    const char* GetRowItem(int32 i);
    int32 GetRowItemInteger(int32 i);
    float GetRowItemFloat(int32 i);

private:
    int _GetRowLine(char* strCode);
    int _Split(char* sLine);
    char* _Advquoted(char* p);
    bool32 _GetColRowCount(char* strCode);
    int32 m_nCol;
    int32 m_nRow;
    char** m_vTextField;
};


//≤‚ ‘”√¿˝
////int32 _nSize = 0;
////char* _strTextContent = (char*)GetAssetFileData("city.csv", &_nSize, NULL);
////CCsvLib _sCsvLib;
////char* _strCode = _strTextContent;
////char* __str = _sCsvLib.Init(_strCode);
////if( __str ){
////	__str = _sCsvLib.GetNextRow(__str);
////	while( __str ){
////		for( int32 i = 0, n = _sCsvLib.GetCol(); i < n; i++ ){
////			const char* _strText = _sCsvLib.GetRowItem(i);
////			printf("%s ", _strText);
////		}
////		printf("\n");
////		__str = _sCsvLib.GetNextRow(__str);
////	}
////}
////_sCsvLib.Close();
////FREE(_strTextContent);


#endif

