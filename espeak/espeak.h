#ifndef __ESPEAK_H__
#define __ESPEAK_H__

#include <include/stdtype.h>
#include <espeak/speak_lib.h>
#include <standard/vector.h>
#include <standard/list.h>
#include <standard/string.h>
#include <standard/filewriter.h>
#include <include/sound.h>



class CESpeak{
public:
    CESpeak();
    ~CESpeak();

    bool32 Init( const char* strSpeakFilePath );
    bool32 Final();
    bool32 SpeakText( const char* strText );
    bool32 AddSpeakText( const char* strText );
    bool32 Stop();
	bool32 CheckSoundEvent(int32 nParame0, int32 nParame1);

private:
    void InitWavData(CMemFile* File, int32 nRate);
	void Write4Bytes(CMemFile* File, int32 nValue);
	void FinalWavData(CMemFile* File);

    int32 m_samplerate;
	char m_strUTF8TextBuff[1024];
	HSOUNDHANDLE m_hHandle;

    list<string>m_vSpeakTextQuene;

};


#endif

