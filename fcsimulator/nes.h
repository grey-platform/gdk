#ifndef NES_H_
#define NES_H_



void JSNES_JSNES();
void JSNES_reset();
void JSNES_start();
void JSNES_frame();
void JSNES_printFps();
void JSNES_stop();
void JSNES_reloadRom();
int  JSNES_loadRom(unsigned char* data, int datasize);
void JSNES_resetFps();
void JSNES_setFramerate(int rate);
void JSNES_OnMouseDown(int x, int y);
void JSNES_OnMouseUp(int x, int y);
void JSNES_OnKeyDown(int k);
void JSNES_OnKeyUp(int k);
void JSNES_release();

extern int JSNES_preferredFrameRate;
extern int JSNES_fpsInterval;
extern int JSNES_showDisplay;
extern int JSNES_emulateSound;
extern int JSNES_sampleRate;
extern float JSNES_CPU_FREQ_NTSC;
extern float JSNES_CPU_FREQ_PAL;

extern int JSNES_frameTime;
extern int JSNES_isRunning;
extern int JSNES_fpsFrameCount;


#endif
