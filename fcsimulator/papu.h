#ifndef PAPU_H_
#define PAPU_H_

#define square_table_length 512
#define tnd_table_length 3264
#define samplesize 8192
//class JSNES;
//class ChannelSquare;


void PAPU_PAPU(/*JSNES* nes*/);
void PAPU_reset();
void PAPU_Release();
int  PAPU_readReg(int address);
void PAPU_writeReg(int address, int value);
void PAPU_resetCounter();
void PAPU_updateChannelEnable(int value);
void PAPU_clockFrameCounter(int nCycles);
void PAPU_accSample(int cycles);
void PAPU_frameCounterTick();
void PAPU_sample();
int  PAPU_getLengthMax(int value);
int  PAPU_getDmcFrequency(int value);
int  PAPU_getNoiseWaveLength(int value);
void PAPU_setPanning(int pos);
void PAPU_setMasterVolume(int value);
void PAPU_updateStereoPos();
void PAPU_initLengthLookup();
void PAPU_initDmcFrequencyLookup();
void PAPU_initNoiseWavelengthLookup();
void PAPU_initDACtables();
    
//extern JSNES* PAPU_nes;
extern int PAPU_frameIrqCounter;
extern int PAPU_frameIrqCounterMax;
extern int PAPU_initCounter;
extern int PAPU_channelEnableValue;
extern int PAPU_bufferSize;
extern int PAPU_bufferIndex;
extern int PAPU_sampleRate;
extern int PAPU_lengthLookup[32];
extern int PAPU_dmcFreqLookup[16];
extern int PAPU_noiseWavelengthLookup[16];
extern int PAPU_square_table[square_table_length];
extern int PAPU_tnd_table[tnd_table_length];
//extern int* PAPU_sampleBuffer;
extern unsigned short PAPU_sampleBuffer[samplesize];
extern int PAPU_frameIrqEnabled;
extern int PAPU_frameIrqActive;
extern int PAPU_frameClockNow;
extern int PAPU_startedPlaying;
extern int PAPU_recordOutput;
extern int PAPU_initingHardware;
extern int PAPU_masterFrameCounter;
extern int PAPU_derivedFrameCounter;
extern int PAPU_countSequence;
extern int PAPU_sampleTimer;
extern int PAPU_frameTime;
extern int PAPU_sampleTimerMax;
extern int PAPU_sampleCount;
extern int PAPU_triValue;
extern int PAPU_smpSquare1;
extern int PAPU_smpSquare2;
extern int PAPU_smpTriangle;
extern int PAPU_smpDmc;
extern int PAPU_accCount;
extern int PAPU_prevSampleL;
extern int PAPU_prevSampleR;
extern int PAPU_smpAccumL;
extern int PAPU_smpAccumR;
extern int PAPU_dacRange;
extern int PAPU_dcValue;
extern int PAPU_masterVolume;
extern int PAPU_stereoPosLSquare1;
extern int PAPU_stereoPosLSquare2;
extern int PAPU_stereoPosLTriangle;
extern int PAPU_stereoPosLNoise;
extern int PAPU_stereoPosLDMC;
extern int PAPU_stereoPosRSquare1;
extern int PAPU_stereoPosRSquare2;
extern int PAPU_stereoPosRTriangle;
extern int PAPU_stereoPosRNoise;
extern int PAPU_stereoPosRDMC;
extern int PAPU_extraCycles;
extern int PAPU_maxSample;
extern int PAPU_minSample;
extern int PAPU_panning[5];





void ChannelDM_ChannelDM();
void ChannelDM_clockDmc();
void ChannelDM_endOfSample();
void ChannelDM_nextSample();
void ChannelDM_writeReg(int address, int value);
void ChannelDM_setEnabled(int value);
int  ChannelDM_getLengthStatus();
int  ChannelDM_getIrqStatus();
void ChannelDM_reset();
    
extern int ChannelDM_MODE_NORMAL;
extern int ChannelDM_MODE_LOOP;
extern int ChannelDM_MODE_IRQ;
extern int ChannelDM_isEnabled;
extern int ChannelDM_hasSample;
extern int ChannelDM_irqGenerated;
extern int ChannelDM_playMode;
extern int ChannelDM_dmaFrequency;
extern int ChannelDM_dmaCounter;
extern int ChannelDM_deltaCounter;
extern int ChannelDM_playStartAddress;
extern int ChannelDM_playAddress;
extern int ChannelDM_playLength;
extern int ChannelDM_playLengthCounter;
extern int ChannelDM_shiftCounter;
extern int ChannelDM_reg4012;
extern int ChannelDM_reg4013;
extern int ChannelDM_sample;
extern int ChannelDM_dacLsb;
extern int ChannelDM_data;
    




void ChannelNoise_ChannelNoise();
void ChannelNoise_reset();
void ChannelNoise_clockLengthCounter();
void ChannelNoise_clockEnvDecay();
void ChannelNoise_updateSampleValue();
void ChannelNoise_writeReg(int address, int value);
void ChannelNoise_setEnabled(int value);
int ChannelNoise_getLengthStatus();
    
extern int ChannelNoise_isEnabled;
extern int ChannelNoise_envDecayDisable;
extern int ChannelNoise_envDecayLoopEnable;
extern int ChannelNoise_lengthCounterEnable;
extern int ChannelNoise_envReset;
extern int ChannelNoise_shiftNow;
extern int ChannelNoise_lengthCounter;
extern int ChannelNoise_progTimerCount;
extern int ChannelNoise_progTimerMax;
extern int ChannelNoise_envDecayRate;
extern int ChannelNoise_envDecayCounter;
extern int ChannelNoise_envVolume;
extern int ChannelNoise_masterVolume;
extern int ChannelNoise_shiftReg;
extern int ChannelNoise_randomBit;
extern int ChannelNoise_randomMode;
extern int ChannelNoise_sampleValue;
extern int ChannelNoise_accValue;
extern int ChannelNoise_accCount;
extern int ChannelNoise_tmp;






void ChannelSquare2_ChannelSquare2(int square1);
void ChannelSquare2_reset();
void ChannelSquare2_clockLengthCounter();
void ChannelSquare2_clockEnvDecay();
void ChannelSquare2_clockSweep();
void ChannelSquare2_updateSampleValue();
void ChannelSquare2_writeReg(int address, int value);
void ChannelSquare2_setEnabled(int value);
int  ChannelSquare2_getLengthStatus();
    
extern int ChannelSquare2_dutyLookup[32];
extern int ChannelSquare2_impLookup[32];
extern int ChannelSquare2_sqr1;
extern int ChannelSquare2_isEnabled;
extern int ChannelSquare2_lengthCounterEnable;
extern int ChannelSquare2_sweepActive;
extern int ChannelSquare2_envDecayDisable;
extern int ChannelSquare2_envDecayLoopEnable;
extern int ChannelSquare2_envReset;
extern int ChannelSquare2_sweepCarry;
extern int ChannelSquare2_updateSweepPeriod;
extern int ChannelSquare2_progTimerCount;
extern int ChannelSquare2_progTimerMax;
extern int ChannelSquare2_lengthCounter;
extern int ChannelSquare2_squareCounter;
extern int ChannelSquare2_sweepCounter;
extern int ChannelSquare2_sweepCounterMax;
extern int ChannelSquare2_sweepMode;
extern int ChannelSquare2_sweepShiftAmount;
extern int ChannelSquare2_envDecayRate;
extern int ChannelSquare2_envDecayCounter;
extern int ChannelSquare2_envVolume;
extern int ChannelSquare2_masterVolume;
extern int ChannelSquare2_dutyMode;
extern int ChannelSquare2_sweepResult;
extern int ChannelSquare2_sampleValue;
extern int ChannelSquare2_vol;


void ChannelSquare1_ChannelSquare1( int square1);
void ChannelSquare1_reset();
void ChannelSquare1_clockLengthCounter();
void ChannelSquare1_clockEnvDecay();
void ChannelSquare1_clockSweep();
void ChannelSquare1_updateSampleValue();
void ChannelSquare1_writeReg(int address, int value);
void ChannelSquare1_setEnabled(int value);
int  ChannelSquare1_getLengthStatus();

extern int ChannelSquare1_dutyLookup[32];
extern int ChannelSquare1_impLookup[32];
extern int ChannelSquare1_sqr1;
extern int ChannelSquare1_isEnabled;
extern int ChannelSquare1_lengthCounterEnable;
extern int ChannelSquare1_sweepActive;
extern int ChannelSquare1_envDecayDisable;
extern int ChannelSquare1_envDecayLoopEnable;
extern int ChannelSquare1_envReset;
extern int ChannelSquare1_sweepCarry;
extern int ChannelSquare1_updateSweepPeriod;
extern int ChannelSquare1_progTimerCount;
extern int ChannelSquare1_progTimerMax;
extern int ChannelSquare1_lengthCounter;
extern int ChannelSquare1_squareCounter;
extern int ChannelSquare1_sweepCounter;
extern int ChannelSquare1_sweepCounterMax;
extern int ChannelSquare1_sweepMode;
extern int ChannelSquare1_sweepShiftAmount;
extern int ChannelSquare1_envDecayRate;
extern int ChannelSquare1_envDecayCounter;
extern int ChannelSquare1_envVolume;
extern int ChannelSquare1_masterVolume;
extern int ChannelSquare1_dutyMode;
extern int ChannelSquare1_sweepResult;
extern int ChannelSquare1_sampleValue;
extern int ChannelSquare1_vol;



//class ChannelTriangle{
//public:
void ChannelTriangle_ChannelTriangle();
void ChannelTriangle_reset();
void ChannelTriangle_clockLengthCounter();
void ChannelTriangle_clockLinearCounter();
int  ChannelTriangle_getLengthStatus();
int  ChannelTriangle_readReg(int address);
void ChannelTriangle_writeReg(int address, int value);
void ChannelTriangle_clockProgrammableTimer(int nCycles);
void ChannelTriangle_clockTriangleGenerator();
void ChannelTriangle_setEnabled(int value);
void ChannelTriangle_updateSampleCondition();
    
extern int ChannelTriangle_isEnabled;
extern int ChannelTriangle_sampleCondition;
extern int ChannelTriangle_lengthCounterEnable;
extern int ChannelTriangle_lcHalt;
extern int ChannelTriangle_lcControl;
extern int ChannelTriangle_progTimerCount;
extern int ChannelTriangle_progTimerMax;
extern int ChannelTriangle_triangleCounter;
extern int ChannelTriangle_lengthCounter;
extern int ChannelTriangle_linearCounter;
extern int ChannelTriangle_lcLoadValue;
extern int ChannelTriangle_sampleValue;
extern int ChannelTriangle_tmp;
    
extern unsigned int m_nSoundSource;
//};





#endif
