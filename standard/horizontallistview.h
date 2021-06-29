/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: horizontallistview.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2021
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __STANDARD_HORIZONTALLISTIVEW_H__
#define __STANDARD_HORIZONTALLISTIVEW_H__

#include <standard/gui.h>
#include <standard/vector.h>
#include <standard/task.h>
#include <standard/delegate.h>

class CHorizontalListView: public CPanel, public CUIEvent, public ITask{
protected:
    struct SListViewSubItem{
        bool32 m_bUsed;             //�Ƿ�ʹ��
        int32 m_nDataIndex;         //���ݱ��
        int32 m_nListIndex;         //��list�е����
        int32 m_nPos;               //cell��ǰ��X����
        CPanel* m_pLayout;          //cell��Ƭ
    };
public:
    CHorizontalListView(int x, int y, int w, int h );
    virtual ~CHorizontalListView();
    virtual bool Init();
    virtual void InitSubItem(SListViewSubItem* pLVSI) = 0;
    virtual void UpdateSubItem(SListViewSubItem* pLVSI) = 0;
    void SetCellSize(int32 w, int32 h, int32 nPoolCount);
    void InitData(int32 nDataCount);
    virtual int32 UpdateTask(float fDelta);

private:
    virtual void OnMouseEvent(CUIElement* pSelf, EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s);

    //virtual bool onTouchBegan(Touch* pTouch, Event* pEvent) override;
    //virtual void onTouchMoved(Touch* pTouch, Event* pEvent) override;
    //virtual void onTouchEnded(Touch* pTouch, Event* pEvent) override;
    virtual void update(float fDelta);
    void UpdatePos(float fDelta);
    SListViewSubItem* GetLayoutPool();

    //cell��С
    int32 m_sItemSizewidth, m_sItemSizeheight;
    //viewλ��
    float m_sPosx, m_sPosy;
    //view��С
    int32 m_sSizewidth, m_sSizeheight;
    //ScrollBar* m_pScrollBar;

    //��view�пɼ���cell�б�
    vector< SListViewSubItem > m_pLayout;
    //���ڱ������е�cell
    list<SListViewSubItem*> m_vLayoutList;
    int32 m_nVisiteLayoutCount;
    //�϶�����
    float m_fMovDis;

    //cell����view�þ���ᱻ�Զ����
    static const int m_nSizeOffset = 10;
    //�϶��ٶȲ���,���ڵ����϶��ٶ�
    static const int m_dragMoveScale = 20;
    //����cell���
    static const int m_cellSpace = 10;
    //��������    
    int32 m_nDataCount = 0;
    int32 m_nDataBeginIndex;

};




template<class T>
class CHorizontalListViewInst:public CHorizontalListView{
public:
    ////static CHorizontalListViewInst<T>* create(int x, int y, int w, int h){
    ////    auto pLayer = new CHorizontalListViewInst<T>(x, y, w, h, mouseProtocol);
    ////    if( pLayer && pLayer->init() ){
    ////        pLayer->autorelease();
    ////        return pLayer;
    ////    }         else{
    ////        CC_SAFE_DELETE(pLayer);
    ////        return NULL;
    ////    }
    ////}

    CHorizontalListViewInst(int x, int y, int w, int h):CHorizontalListView(x, y, w, h){ Init(); }

    virtual ~CHorizontalListViewInst(){}

    virtual void InitSubItem(SListViewSubItem* pLVSI){
        m_funcInitSubItem(pLVSI->m_pLayout);
    }
    virtual void UpdateSubItem(SListViewSubItem* pLVSI){
        m_funcUpdateSubItem(pLVSI->m_pLayout, m_vData[pLVSI->m_nDataIndex]);
    }

    void SetData(vector<T>& vData){
        int32 _nDataCount = vData.size();
        m_vData = vData;
        InitData(_nDataCount);
    }


    std::function<void(Layout*)> m_funcInitSubItem;
    std::function<void(Layout*, T)> m_funcUpdateSubItem;

private:
    vector<T> m_vData;
};



#endif


