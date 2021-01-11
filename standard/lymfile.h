#ifndef __LYMFILE_H__
#define __LYMFILE_H__

#include <include/stdtype.h>
#include <standard/stream.h>

//typedef struct SRGBInfo{
//    byte R, G, B;
//}SRGBInfo;
//
//typedef union SPixelInfo{
//    uint64 m_nInfo;
//    struct{
//        uint64 m_nColorIndex: 20;
//        uint64 m_nFrameCoords : 20;
//    }SICInfo;
//}SPixelInfo;
//
//typedef struct _SPixelInfo{
//    byte m_vData[5];
//}_SPixelInfo;
//
//#define PIXELINFOSIZE (5)
//
//class CLymFile{
//public:
//
//public:
//    CLymFile();
//    ~CLymFile();
//    bool32 Open( const char* strFileName );
//    SRGBInfo* GetNextFrame( int32 nFrame );
//    SRGBInfo* GetFrame( int32 nFrame );
//
//public:
//    CDataStream m_sFS;
//    int32 m_nVersionCode;
//    int32 m_nFrameWidth;
//    int32 m_nFrameHeight;
//    int32 m_nFrameCount;
//    int32 m_nColorPalette;
//    byte* m_pData;
//
//    SRGBInfo** m_ppColorPaletteInfo;
//    int32* m_pFrameInfoPosList;
//    SRGBInfo* m_pFrameRGBInfoBuff;
//
//};




#endif
