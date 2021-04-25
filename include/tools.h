/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: tools.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_TOOLS_H__
#define __GRAY_SDK_TOOLS_H__

#include <include/stdtype.h>

typedef uint32 HTTPHANDLE;
typedef uint32 REMOTEFILEHANDLE;

EXTERN int32 GetAssetFileSize( const char* strFileName );
EXTERN void* GetAssetFileData( const char* strFileName, int32* nDataSize, void* pDataBuff );
EXTERN void* GetFileImageData( const char* strFileName, int32* nWidth, int32* nHeight, int32 *nChannel, int32* nDataSize );
EXTERN bool32 SaveImageFile( const char* strFileName, int32 nWidth, int32 nHeight, int32 nChannel, void* pData );

EXTERN int32 APP_GetAllCount( int32* pAppIDBuffer );
EXTERN int32 APP_GetInfo( int32 nAppID, char* strAppName, char* strTaskName, uint32* pAppIconTextureHandle, char* strDeveloper, char* strDescript );
EXTERN int32 APP_Startup( byte* pData, int32 nSize );
EXTERN int32 APP_GetMemoryInfo( int32 nAppID, int32* pIdle, int32* pUsage );
EXTERN int32 APP_GetCPUInfo( int32* pInstCount, int32* pNetDataSize );
EXTERN int32 SYSTEM_GetFarData( int32 nFarDataAddress, void* pData, int32 nSize );
EXTERN char* Format( char *buffer, const char *format, ... );
EXTERN void LogInfo( int32 nType, const char* strFileName, int32 nFileNo );
EXTERN void LogOut( const char *format, ... );
EXTERN void LogMem( void* p, int32 size );
EXTERN HTTPHANDLE HttpRequest( uint32 ID, const char* strHost, int32 nPort, const char* strAddress );
EXTERN char** GetFileList( const char* strFindDirName, int32* nCount );
EXTERN void MakeMD532( void* pData, int32 nSize, char* pMD5Code_ );
EXTERN void MakeMD516( void* pData, int32 nSize, byte* pMD5Code_ );
EXTERN int32 ConvertUTF8ToGB2312( char* strDest, int32 nDestSize, char* strSrc, int32 nSrcSize );
EXTERN int32 ConvertGB2312ToUTF8( char* strDest, int32 nDestSize, char* strSrc, int32 nSrcSize );
EXTERN int32 UnCompressData( void* pSrc, int32 nSrcData, void* pDestBuff, int32 nDestBuffSize, byte* pProp );
EXTERN int32 SYSTEM_SetFarData( int32 nFarDataAddress, void* pData, int32 nSize );
EXTERN REMOTEFILEHANDLE GetRemoteFile( uint32 ID, const char* strURL, void* pBuff, int32 nBuffSize );
//EXTERN int32 WritePng( const char* strFileName, int32 nWidth, int32 nHeight, int32 nChannel, void* pData );
#endif
