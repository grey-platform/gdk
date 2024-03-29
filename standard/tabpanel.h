/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: tabpanel.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2021
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __STANDARD_TABLEPANEL_H__
#define __STANDARD_TABLEPANEL_H__

#include <standard/gui.h>
#include <standard/vector.h>
#include <standard/delegate.h>

struct STabPage{
    CButton* m_pButton;
    CScrollView* m_pPanel;
};

class CTabPanel: public CTranslatePanel, public CUIEvent{
public:
    CTabPanel( int32 x, int32 y, int32 width, int32 height, char** ppCaption, int32 nButtonWidth, int32 nButtonHeight );
    virtual ~CTabPanel();
    CScrollView* GetTabPage( int32 nIndex );
    int32 GetPageCount();
    bool32 SetPage(int32 nIndex);
    CDelegate2<CUIElement*, int32 > OnTabPageChange;

private:
    virtual void OnClick(CUIElement* pSelf);

    vector<STabPage>m_vTabPageList;
};


#endif

