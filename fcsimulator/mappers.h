#ifndef MAPPERS_H_
#define MAPPERS_H_


//class JSNES;

typedef void(*FPMappers_Mappers)(/*JSNES* nes*/);
typedef void(*FPMappers_reset)();
typedef void(*FPMappers_write)(int address, int value);
typedef void(*FPMappers_writelow)(int address, int value);
typedef int (*FPMappers_load)(int address);
typedef int (*FPMappers_regLoad)(int address);
typedef void(*FPMappers_regWrite)(int address, int value);
typedef int (*FPMappers_joy1Read)();
typedef int (*FPMappers_joy2Read)();
typedef void(*FPMappers_loadROM)(int rom);
typedef void(*FPMappers_loadPRGROM)();
typedef void(*FPMappers_loadCHRROM)();
typedef void(*FPMappers_loadBatteryRam)();
typedef void(*FPMappers_loadRomBank)(int bank, int address);
typedef void(*FPMappers_loadVromBank)(int bank, int address);
typedef void(*FPMappers_load32kRomBank)(int bank, int address);
typedef void(*FPMappers_load8kVromBank)(int bank4kStart, int address);
typedef void(*FPMappers_load1kVromBank)(int bank1k, int address);
typedef void(*FPMappers_load2kVromBank)(int bank2k, int address);
typedef void(*FPMappers_load8kRomBank)(int bank8k, int address);
typedef void(*FPMappers_clockIrqCounter)();
typedef void(*FPMappers_latchAccess)(int address);

void Mappers_Init(int mapperType/*, JSNES* nes*/);
extern FPMappers_reset Mappers_reset;
extern FPMappers_loadROM Mappers_loadROM;
extern FPMappers_load Mappers_load;
extern FPMappers_write Mappers_write;
extern FPMappers_clockIrqCounter Mappers_clockIrqCounter;
extern FPMappers_latchAccess Mappers_latchAccess;

void Mappers0_Mappers0(/*JSNES* nes*/);
void Mappers0_reset();
void Mappers0_write(int address, int value);
void Mappers0_writelow(int address, int value);
int  Mappers0_load(int address);
int  Mappers0_regLoad(int address);
void Mappers0_regWrite(int address, int value);
int  Mappers0_joy1Read();
int  Mappers0_joy2Read();
void Mappers0_loadROM(int rom);
void Mappers0_loadPRGROM();
void Mappers0_loadCHRROM();
void Mappers0_loadBatteryRam();
void Mappers0_loadRomBank(int bank, int address);
void Mappers0_loadVromBank(int bank, int address);
void Mappers0_load32kRomBank(int bank, int address);
void Mappers0_load8kVromBank(int bank4kStart, int address);
void Mappers0_load1kVromBank(int bank1k, int address);
void Mappers0_load2kVromBank(int bank2k, int address);
void Mappers0_load8kRomBank(int bank8k, int address);
void Mappers0_clockIrqCounter();
void Mappers0_latchAccess(int address);

//extern JSNES* Mappers0_nes;
extern int Mappers0_joy1StrobeState;
extern int Mappers0_joy2StrobeState;
extern int Mappers0_joypadLastWrite;
extern int Mappers0_mousePressed;
extern int Mappers0_mouseX;
extern int Mappers0_mouseY;


void Mappers1_Mappers1(/*JSNES* nes*/);
void Mappers1_reset();
void Mappers1_write(int address, int value);
void Mappers1_setReg(int reg, int value);
int  Mappers1_getRegNumber(int address);
void Mappers1_loadROM(int rom);
void Mappers1_switchLowHighPrgRom(int oldSetting);
void Mappers1_switch16to32();
void Mappers1_switch32to16();

extern int Mappers1_regBuffer;
extern int Mappers1_regBufferCounter;
extern int Mappers1_mirroring;
extern int Mappers1_oneScreenMirroring;
extern int Mappers1_prgSwitchingArea;
extern int Mappers1_prgSwitchingSize;
extern int Mappers1_vromSwitchingSize;
extern int Mappers1_romSelectionReg0;
extern int Mappers1_romSelectionReg1;
extern int Mappers1_romBankSelect;



void Mappers2_Mappers2(/*JSNES* nes*/);
void Mappers2_write(int address, int value);
void Mappers2_loadROM(int rom);

#define CMD_SEL_2_1K_VROM_0000  0
#define CMD_SEL_2_1K_VROM_0800  1
#define CMD_SEL_1K_VROM_1000  2
#define CMD_SEL_1K_VROM_1400  3
#define CMD_SEL_1K_VROM_1800  4
#define CMD_SEL_1K_VROM_1C00  5
#define CMD_SEL_ROM_PAGE1  6
#define CMD_SEL_ROM_PAGE2  7


void Mappers4_Mappers4(/*JSNES* nes*/);
void Mappers4_write(int ddress, int value);
void Mappers4_executeCommand(int cmd, int arg);
void Mappers4_loadROM(int rom);
void Mappers4_clockIrqCounter();
       
    
extern int Mappers4_command;
extern int Mappers4_prgAddressSelect;
extern int Mappers4_chrAddressSelect;
extern int Mappers4_pageNumber;
extern int Mappers4_irqCounter;
extern int Mappers4_irqLatchValue;
extern int Mappers4_irqEnable;
extern int Mappers4_prgAddressChanged;




#endif
