/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: applite.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_GAMEMODELMANAGER_H__
#define __BIGIMAGE_GAMEMODELMANAGER_H__

#include <bigimage/gamemodel.h>
#include <standard/map.h>

class CGameModelManager{
public:
    static CGameModelManager* GetInterface();
    CGameModelManager();
    ~CGameModelManager();
    CGameModel* GetGameModelFormFile(CGameModelEvent* pGameModelEventObject, const char* strFileName, void* pFileStream = NULL );
    void Remove( CGameModel* pGameModel );
    void Clear();
    void GC();

private:
    map<uint32, CGameModel*>m_vGameModelTable;
};



#endif

