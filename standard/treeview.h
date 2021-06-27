/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: treeview.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2021
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TREEVIEW_H__
#define __STANDARD_TREEVIEW_H__

#include <standard/gui.h>

class CTreeView: public CListView{
public:
    CTreeView(int32 x, int32 y, int32 width, int32 height);
    virtual ~CTreeView();

};

#endif
