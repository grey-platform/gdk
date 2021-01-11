#ifndef PPU_H_
#define PPU_H_


#define vramMem_length 0x8000
#define vramMirrorTable_length 0x8000
#define spriteMem_length 0x100
#define pixrendered_length 61440
#define STATUS_VRAMWRITE 4
#define STATUS_SLSPRITECOUNT 5
#define STATUS_SPRITE0HIT 6
#define STATUS_VBLANK 7



typedef struct NameTable{   
    int tile[32*32];
    int attrib[32*32];
}NameTable;

void NameTable_NameTable(NameTable* _this );
int NameTable_getTileIndex(NameTable* _this, int x, int y);
int NameTable_getAttrib(NameTable* _this, int x, int y);
void NameTable_writeAttrib(NameTable* _this, int index, int value);



void PaletteTable_PaletteTable();
void PaletteTable_reset();
void PaletteTable_loadNTSCPalette();
void PaletteTable_loadPALPalette();
void PaletteTable_makeTables();
void PaletteTable_setEmphasis(int emph);
int  PaletteTable_getEntry(int yiq);
int  PaletteTable_getRed(int rgb);
int  PaletteTable_getGreen(int rgb);
int  PaletteTable_getBlue(int rgb);
int  PaletteTable_getRgb(int r, int g, int b);
void PaletteTable_loadDefaultPalette();

extern int PaletteTable_curTable[64];
extern int PaletteTable_emphTable[8][64];
extern int PaletteTable_currentEmph;

typedef struct{
    int pix[64];
    int fbIndex;
    int tIndex;
    int x;
    int y;
    int w;
    int h;
    int incX;
    int incY;
    int palIndex;
    int tpri;
    int c;
    int initialized;
    int opaque[8];
}Tile;

void Tile_Tile(Tile* _this);
void Tile_setBuffer(Tile* _this, int* scanline);
void Tile_setScanline(Tile* _this, int sline, int b1, int b2);
void Tile_render(Tile* _this, int* buffer, int srcx1, int srcy1, int srcx2, int srcy2, int dx, int dy, int palAdd, int* palette, int flipHorizontal, int flipVertical, int pri, int* priTable);
int Tile_isTransparent(Tile* _this, int x, int y);

//class JSNES;


void PPU_PPU(/*JSNES* nes*/);
void PPU_reset();
void PPU_setMirroring(int mirroring);
void PPU_defineMirrorRegion(int fromStart, int toStart, int size);
void PPU_startVBlank();
void PPU_endScanline();
void PPU_startFrame();
void PPU_endFrame();
void PPU_updateControlReg1(int value);
void PPU_updateControlReg2(int value);
void PPU_setStatusFlag(int flag, int value);
int  PPU_readStatusRegister();
void PPU_writeSRAMAddress(int address);
int  PPU_sramLoad();
void PPU_sramWrite(int value);
void PPU_scrollWrite(int value);
void PPU_writeVRAMAddress(int address);
int  PPU_vramLoad();
void PPU_vramWrite(int value);
void PPU_sramDMA(int value);
void PPU_regsFromAddress();
void PPU_cntsFromAddress();
void PPU_regsToAddress();
void PPU_cntsToAddress();
void PPU_incTileCounter(int count);
int  PPU_mirroredLoad(int address);
void PPU_mirroredWrite(int address, int value);
void PPU_triggerRendering();
void PPU_renderFramePartially(int startScan, int scanCount);
void PPU_renderBgScanline(int bbgbuffer, int scan);
void PPU_renderSpritesPartially(int startscan, int scancount, int bgPri);
int  PPU_checkSprite0(int scan);
void PPU_writeMem(int address, int value);
void PPU_updatePalettes();
void PPU_patternWrite(int address, int value);
void PPU_nameTableWrite(int index, int address, int value);
void PPU_attribTableWrite(int index, int address, int value);
void PPU_spriteRamWriteUpdate(int address, int value);
void PPU_doNMI();


//extern JSNES* PPU_nes;
extern int PPU_vramMem[vramMem_length];
extern int PPU_spriteMem[spriteMem_length];
extern int PPU_vramAddress;
extern int PPU_vramTmpAddress;
extern int PPU_vramBufferedReadValue;
extern int PPU_firstWrite;
extern int PPU_sramAddress;
extern int PPU_currentMirroring;
extern int PPU_requestEndFrame;
extern int PPU_nmiOk;
extern int PPU_dummyCycleToggle;
extern int PPU_validTileData;
extern int PPU_nmiCounter;
extern int PPU_scanlineAlreadyRendered;
extern int PPU_f_nmiOnVblank;
extern int PPU_f_spriteSize;
extern int PPU_f_bgPatternTable;
extern int PPU_f_spPatternTable;
extern int PPU_f_addrInc;
extern int PPU_f_nTblAddress;
extern int PPU_f_color;
extern int PPU_f_spVisibility;
extern int PPU_f_bgVisibility;
extern int PPU_f_spClipping;
extern int PPU_f_bgClipping;
extern int PPU_f_dispType;
extern int PPU_cntFV;
extern int PPU_cntV;
extern int PPU_cntH;
extern int PPU_cntVT;
extern int PPU_cntHT;
extern int PPU_regFV;
extern int PPU_regV;
extern int PPU_regH;
extern int PPU_regVT;
extern int PPU_regHT;
extern int PPU_regFH;
extern int PPU_regS;
extern int PPU_curNt;
extern int PPU_attrib[32];
extern int PPU_buffer[256 * 240];
extern int PPU_prevBuffer[256 * 240];
extern int PPU_bgbuffer[256 * 240];
extern int PPU_pixrendered[pixrendered_length];
extern Tile* PPU_scantile[32];
extern int PPU_scanline;
extern int PPU_lastRenderedScanline;
extern int PPU_curX;
extern int PPU_sprX[64]; // X coordinate
extern int PPU_sprY[64]; // Y coordinate
extern int PPU_sprTile[64]; // Tile Index (into pattern table)
extern int PPU_sprCol[64]; // Upper two bits of color
extern int PPU_vertFlip[64]; // Vertical Flip
extern int PPU_horiFlip[64]; // Horizontal Flip
extern int PPU_bgPriority[64]; // Background priority
extern int PPU_spr0HitX;
extern int PPU_spr0HitY;
extern int PPU_hitSpr0;
extern int PPU_sprPalette[16];
extern int PPU_imgPalette[16];
#ifdef _CONTRA_GAME_
extern Tile* PPU_ptTile[512];
#elif _SUPERMARIO_GAME_
extern Tile* PPU_ptTile[512];
#else
extern Tile* PPU_ptTile[512];
#endif
extern int PPU_ntable1[4];
extern NameTable PPU_nameTable[4];
extern int PPU_vramMirrorTable[vramMirrorTable_length];
extern int PPU_showSpr0Hit;
extern int PPU_clipToTvSize;
extern int PPU_srcy1;
extern int PPU_srcy2;





    


#endif
