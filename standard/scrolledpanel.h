/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: scrolledpanel.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2021
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_SCROLLEDPANEL_H__
#define __STANDARD_SCROLLEDPANEL_H__

#include <standard/gui.h>
#include <standard/delegate.h>

class CScrollBar: public CPanel, public CUIEvent{
public:
    CScrollBar( int32 x, int32 y, int32 width, int32 height );
    virtual ~CScrollBar();
    void SetScrollLength( int32 nLength );
    void SetScrollValue( int32 nValue );
    CDelegate3<CScrollBar*, int32, int32 >OnScrolled;

private:
    virtual void OnClick(CUIElement* pSelf);
    virtual void OnMouseEvent(CUIElement* pSelf, EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s);
    void UpdateSliderSize();
    int32 m_vBound[4];
    int32 m_nScorllLength;
    int32 m_nScrollValue;
    int32 m_nScrollStep;
    CButton* m_pUpBtn;
    CButton* m_pDownBtn;
    CPanel* m_pSliderBtn;

};

class CScrolledPanel: public CTranslatePanel, public CUIEvent, public IDelegateInterface{
public:
    CScrolledPanel(int32 x, int32 y, int32 width, int32 height);
    virtual ~CScrolledPanel();
    virtual void AddElement(CUIElement* pElement);
    void SetContainerSize(int32 nContainerWidth, int32 nContainerHeight);
private:
    virtual void OnMouseEvent(CUIElement* pSelf, EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s);
    void MoveComponentOffset(CUIElement* p, int32 x, int32 y);
    void OnScrollValue(CScrollBar* pSelf, int32 nValue, int32 nOffset );
    CPanel* m_pRootNode;
    CScrollBar* m_pScrollBar;

    float m_fMoveOffsetY;
};


#endif

