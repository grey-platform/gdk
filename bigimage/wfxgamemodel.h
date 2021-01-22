/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: wfxgamemodel.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_WFXGAMEMODEL_H__
#define __BIGIMAGE_WFXGAMEMODEL_H__

#include <bigimage/gamemodel.h>

class CWFXGameModel: public CGameModel{
public:
    CWFXGameModel( void* pStream );
    virtual ~CWFXGameModel();
    virtual void Init(CGameModelEvent* pGameModelEventObject );
    uint32 GetHandle();

public:
    uint32 m_hModelHandle;
    int32 m_nSequenceCount;
    int32 m_nTextureCount;
};

#endif
