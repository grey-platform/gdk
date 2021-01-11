#ifndef UI_H_
#define UI_H_


void DummyUI_DummyUI();
void DummyUI_enable();
void DummyUI_updateStatus(const char* ss);
void DummyUI_writeAudio();
void DummyUI_writeFrame(int* buffer, int *prevBuffer);


#endif
