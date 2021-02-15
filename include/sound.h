/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: sound.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_SOUND_H__
#define __GRAY_SDK_SOUND_H__

#include <include/stdtype.h>

typedef uint32 HSOUNDHANDLE;

EXTERN HSOUNDHANDLE Sound_Play( const char* strFileName, bool32 bLoop );
EXTERN HSOUNDHANDLE Sound_PlayOgg( void* pData, int32 nDataSize, bool32 bLoop );
EXTERN HSOUNDHANDLE Sound_PlayByStream( uint32 nHashCode, void* pData, int32 nDataSize, bool32 bLoop );
EXTERN HSOUNDHANDLE Sound_PlayDynamic( int32 nFrequency, int32 eFormat, int32 aChannel );
EXTERN void   Sound_Stop( HSOUNDHANDLE hSoundHandle );
EXTERN void   Sound_Pause( HSOUNDHANDLE hSoundHandle, bool32 bPause );
EXTERN int32  Sound_Length( HSOUNDHANDLE hSoundHandle );
EXTERN int32  Sound_GetPos( HSOUNDHANDLE hSoundHandle );
EXTERN int32  Sound_SetPos( HSOUNDHANDLE hSoundHandle, int32 nPos );
EXTERN int32  Sound_GetVolume( HSOUNDHANDLE hSoundHandle );
EXTERN int32  Sound_SetVolume( HSOUNDHANDLE hSoundHandle, int32 nVolume );
EXTERN int32  Sound_GetAllVolume();
EXTERN int32  Sound_SetAllVolume( int32 nVolume );
EXTERN void   Sound_StopAll();
EXTERN void   Sound_UpdateSoundBuffer(HSOUNDHANDLE hSoundHandle, void* pData, int32 nDataSize);
EXTERN int32  Sound_Mp3Decode( void* pInData, int32 nInDataSize, void* pBuff, int32 nBuffSize );
EXTERN int32  Sound_GetBuffData( HSOUNDHANDLE hSoundHandle,  int32 nPos, void* pBuff, int32 nBuffSize );
EXTERN int32  Sound_GetState( HSOUNDHANDLE hSoundHandle );

typedef uint32 HMPEGHANDLE;

EXTERN HMPEGHANDLE MPEG_CreateWithFileData( void* pFileData, int32 nDataSize, bool32 bVideo, bool32 bAudio );
EXTERN HMPEGHANDLE MPEG_CreateWithDynamicData( int32 nDataSize, int32 nBuffSize, bool32 bVideo, bool32 bAudio );
EXTERN HMPEGHANDLE MPEG_CreateWithStream( int32 nBuffSize );
EXTERN bool32 MPEG_GetInfo( HMPEGHANDLE hMpegHandle, int32 *samplerate, int32 *framerate, float *duration, int32 *width, int32 *height );
EXTERN bool32 MPEG_Destroy( HMPEGHANDLE hMpegHandle );
EXTERN bool32 MPEG_Decode( HMPEGHANDLE hMpegHandle, float fDeltaTime, void* pData, int32 nStride );
EXTERN bool32 MPEG_Ended( HMPEGHANDLE hMpegHandle );
EXTERN float MPEG_GetTime( HMPEGHANDLE hMpegHandle );

#endif
