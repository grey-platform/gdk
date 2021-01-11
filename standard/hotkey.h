
/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: hotkey.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __STANDARD_HOTKEY_H__
#define __STANDARD_HOTKEY_H__

#include <standard/gui.h>

class CHotKeyEvent{
public:
    virtual void OnHotKey( int32 nID );
};

struct SHotKeyItem{
    int32 m_nID;
    CUIElement* m_pElement;
    int32 m_nKey;
    bool32 m_bCtrl;
    bool32 m_bShirt;
    friend bool operator==( const SHotKeyItem& l, const SHotKeyItem& r );
};

class CHotKey{

public:
    CHotKey();
    ~CHotKey();
    void Register( CUIElement* pElement, int32 nID, int32 nKey, bool32 bCtrl = False, bool32 bShirt = False );
    void Unregister( int32 nID );
    void OnKeyEvent( CUIElement* pElement, EUIKeyMessage eKeyMessage, int32 nKey );
    bool32 CheckKeyState( int32 nKey );
    void Reset();
    CHotKeyEvent* m_pHotKeyObject;
private:
    list<SHotKeyItem>m_vHotKeyItemList;
    bool32 m_bKeyState[0xff];
};



#endif
