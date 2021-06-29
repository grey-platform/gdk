/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: layout.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2021
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_LAYOUT_H__
#define __STANDARD_LAYOUT_H__

#include <standard/gui.h>
#include <standard/map.h>

class CLayout: public CPanel{
public:
    CLayout();
    virtual ~CLayout();
    virtual void Init(int32 x, int32 y, int32 w, int32 h);
    virtual void BeforeShow();
    virtual void AfterHide();
};

class CLayoutManager{
public:
    static CLayoutManager* GetInterface();
    CLayoutManager();
    virtual ~CLayoutManager();
    void SetParent(CUIElement* pElement, int32 x, int32 y, int32 w, int32 h);
    bool32 AddLayout( CLayout* pLayout, int32 nGUID);
    bool32 Show( int32 nGUID );

private:
    map< int32, CLayout*> m_vLayoutList;
    CUIElement* m_pParent;
    int32 m_vLayoutBound[4];
    CLayout* m_pCurrentLayout;
};


#endif
