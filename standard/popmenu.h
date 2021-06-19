/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: popmenu.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_POPMENU_H__
#define __STANDARD_POPMENU_H__

#include <standard/gui.h>

struct SPopMenuInfo{
    char m_strCaption[64];
    bool32 m_bEnable;
    int32 m_nID;
    int32 m_nUserData;
    int32 m_nLevel;

};

class CPopMenu: public CPanel, public CUIEvent{
public:
    static void SetMenuInfo( SPopMenuInfo* pMenuInfo, const char* strCaption, bool32 bEnable, int32 nID, int32 nCmd );
    static void OpenPopMenu( int32 x, int32 y, CUIEvent* pEventObject, SPopMenuInfo* pMenuInfo, int32 nItemWidth = 100 );
    CPopMenu();
    virtual ~CPopMenu();
    void Init( int32 x, int32 y, SPopMenuInfo* pMenuInfo, int32 nItemWidth );
    
private:
    virtual void OnClick( CUIElement *pSelf );
    virtual void OnMouseEvent( CUIElement *pSelf, EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s );
    void Close();

    CUIEvent* m_pEventObject;
    CUIElement* m_pMenuPanel;

};



#endif
