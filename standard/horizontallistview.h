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
        bool32 m_bUsed;             //是否使用
        int32 m_nDataIndex;         //数据编号
        int32 m_nListIndex;         //在list中的序号
        int32 m_nPos;               //cell当前的X坐标
        CPanel* m_pLayout;          //cell面片
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

    //cell大小
    int32 m_sItemSizewidth, m_sItemSizeheight;
    //view位置
    float m_sPosx, m_sPosy;
    //view大小
    int32 m_sSizewidth, m_sSizeheight;
    //ScrollBar* m_pScrollBar;

    //在view中可见的cell列表
    vector< SListViewSubItem > m_pLayout;
    //用于保存所有的cell
    list<SListViewSubItem*> m_vLayoutList;
    int32 m_nVisiteLayoutCount;
    //拖动距离
    float m_fMovDis;

    //cell超出view该距离会被自动清除
    static const int m_nSizeOffset = 10;
    //拖动速度参数,用于调整拖动速度
    static const int m_dragMoveScale = 20;
    //各个cell间距
    static const int m_cellSpace = 10;
    //数据条数    
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


