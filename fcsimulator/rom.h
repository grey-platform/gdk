#ifndef ROM_H_
#define ROM_H_

#include <fcsimulator/ppu.h>

#define VERTICAL_MIRRORING 0
#define HORIZONTAL_MIRRORING 1
#define FOURSCREEN_MIRRORING 2
#define SINGLESCREEN_MIRRORING 3
#define SINGLESCREEN_MIRRORING2 4
#define SINGLESCREEN_MIRRORING3 5
#define SINGLESCREEN_MIRRORING4 6
#define CHRROM_MIRRORING 7
    
//typedef struct Tile;
//class Mappers0;
//class ROM{
//public:
void ROM_ROM();
void ROM_load(unsigned char* data, int datasize);
int  ROM_getMirroringType();
int  ROM_mapperSupported();
void ROM_createMapper();

#ifdef _CONTRA_GAME_
extern int ROM_rom[8][16384];
extern int** ROM_vrom;
extern Tile** ROM_vromTile/*[8][256]*/;
#elif _SUPERMARIO_GAME_
extern int ROM_rom[2][16384];
extern int ROM_vrom[2][4096];
extern Tile ROM_vromTile[2][256];
#else
extern int** ROM_rom;
extern int** ROM_vrom;
extern Tile** ROM_vromTile;
#endif


extern int ROM_romCount;
extern int ROM_vromCount;
extern int ROM_mirroring;
extern int ROM_batteryRam;
extern int ROM_trainer;
extern int ROM_fourScreen;
extern int ROM_mapperType;
extern int ROM_valid;
//};


#endif
    
