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


#ifndef __STANDARD_SYSTEM_H__
#define __STANDARD_SYSTEM_H__

#include <include/stdtype.h>
#include <include/stdio.h>

void *__vec_new( void *op, int number, int size, void *f );
void __vec_delete( void *op, int n, int sz, void *f, int del, int x );

int Base64Encode( const byte *bindata, int binlength, char *base64 );
int Base64Decode( const char *base64, byte *bindata );
uint32 HashString( const char* strText );
bool StrIsInteger( const char* sStr );
bool StrIsPositiveInteger( const char* sStr );
bool StrIsNumber( const char* sStr );
bool SafeStrToInteger( const char* sStr, int32 *pValue );
bool SafeStrToPositiveInteger( const char* sStr, int32 *pValue );
bool SafeStrToNumber( const char* sStr, float *pValue );
color32 StrToColor32( const char* s );
int32 StrToInt( const char* s );
bool  StrToInt2( const char* s, const char* s0, int32* n0, int32* n1 );
bool  StrToInt3( const char* s, const char* s0, int32* n0, int32* n1, int32* n2 );
bool  StrToInt4( const char* s, const char* s0, int32* n0, int32* n1, int32* n2, int32* n3 );
float StrToFloat( const char* s );
bool  StrToFloat2( const char* s, const char* s0, float* f0, float* f1 );
bool  StrToFloat3( const char* s, const char* s0, float* f0, float* f1, float* f2 );
bool  StrToFloat4( const char* s, const char* s0, float* f0, float* f1, float* f2, float* f3 );
uint32 ReverseUint32( char a, char b, char c, char d );
char* NewString( const char* strRes );
int32 GetToken( char* strText, char* strBuff );

//file="subdir1/subdir2/myImage.jpg"
void GetPathToFileName( const char* strFilePathName, char* strResult ); //return subdir1_subdir2_myImage.jpg
void GetFileName( const char* strFilePathName, char* strResult );     //ret myImage.jpg
void GetFileNamePath( const char* strFilePathName, char* strResult );   //ret subdir1/subdir2
void GetFileNameFile( const char* strFilePathName, char* strResult ); //ret myImage
void GetFileNameType( const char* strFilePathName, char* strResult ); //ret jpg

uint32 GetFileExt(const char* strFileName);



#endif
