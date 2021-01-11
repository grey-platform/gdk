#ifndef CPU_H_
#define CPU_H_

#define MEMLENGTH 0x10000
#define IRQ_NORMAL 0
#define IRQ_NMI 1
#define IRQ_RESET 2
#define INS_ADC 0
#define INS_AND 1
#define INS_ASL 2
#define INS_BCC 3
#define INS_BCS 4
#define INS_BEQ 5
#define INS_BIT 6
#define INS_BMI 7
#define INS_BNE 8
#define INS_BPL 9
#define INS_BRK 10
#define INS_BVC 11
#define INS_BVS 12
#define INS_CLC 13
#define INS_CLD 14
#define INS_CLI 15
#define INS_CLV 16
#define INS_CMP 17
#define INS_CPX 18
#define INS_CPY 19
#define INS_DEC 20
#define INS_DEX 21
#define INS_DEY 22
#define INS_EOR 23
#define INS_INC 24
#define INS_INX 25
#define INS_INY 26
#define INS_JMP 27
#define INS_JSR 28
#define INS_LDA 29
#define INS_LDX 30
#define INS_LDY 31
#define INS_LSR 32
#define INS_NOP 33
#define INS_ORA 34
#define INS_PHA 35
#define INS_PHP 36
#define INS_PLA 37
#define INS_PLP 38
#define INS_ROL 39
#define INS_ROR 40
#define INS_RTI 41
#define INS_RTS 42
#define INS_SBC 43
#define INS_SEC 44
#define INS_SED 45
#define INS_SEI 46
#define INS_STA 47
#define INS_STX 48
#define INS_STY 49
#define INS_TAX 50
#define INS_TAY 51
#define INS_TSX 52
#define INS_TXA 53
#define INS_TXS 54
#define INS_TYA 55
#define INS_DUMMY 56
#define ADDR_ZP         0
#define ADDR_REL        1
#define ADDR_IMP        2
#define ADDR_ABS        3
#define ADDR_ACC        4
#define ADDR_IMM        5
#define ADDR_ZPX        6
#define ADDR_ZPY        7
#define ADDR_ABSX       8
#define ADDR_ABSY       9
#define ADDR_PREIDXIND  10
#define ADDR_POSTIDXIND 11
#define ADDR_INDABS     12
    
//class JSNES;

void CPU_CPU(/*JSNES* nes*/);
void CPU_reset();
int  CPU_emulate();
int  CPU_load(int addr);
int  CPU_load16bit(int addr);
void CPU_write(int addr, int val);
void CPU_requestIrq(int type);
void CPU_push(int value);
void CPU_stackWrap();
int  CPU_pull();
int  CPU_pageCrossed(int addr1, int addr2);
void CPU_haltCycles(int cycles);
void CPU_doNonMaskableInterrupt(int status);
void CPU_doResetInterrupt();
void CPU_doIrq(int status);
int  CPU_getStatus();
void CPU_setStatus(int st);
void CPU_initOpData();
void CPU_setOp(int inst, int op, int addr, int size, int cycles);


//extern JSNES* CPU_nes;
extern int CPU_mem[MEMLENGTH];
extern int CPU_REG_ACC;
extern int CPU_REG_X;
extern int CPU_REG_Y;
extern int CPU_REG_SP;
extern int CPU_REG_PC;
extern int CPU_REG_PC_NEW;
extern int CPU_REG_STATUS;
extern int CPU_F_CARRY;
extern int CPU_F_DECIMAL;
extern int CPU_F_INTERRUPT;
extern int CPU_F_INTERRUPT_NEW;
extern int CPU_F_OVERFLOW;
extern int CPU_F_SIGN;
extern int CPU_F_ZERO;
extern int CPU_F_NOTUSED;
extern int CPU_F_NOTUSED_NEW;
extern int CPU_F_BRK;
extern int CPU_F_BRK_NEW;
extern int CPU_opdata[256];
extern int CPU_cyclesToHalt;
extern int CPU_crash;
extern int CPU_irqRequested;
extern int CPU_irqType;


    


#endif
