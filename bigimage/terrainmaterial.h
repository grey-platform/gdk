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


#ifndef __BIGIMAGE_TERRAINMATERIAL_H__
#define __BIGIMAGE_TERRAINMATERIAL_H__

#include <standard/material.h>

class CTerrainMaterial: public CMaterial{
public:
    CTerrainMaterial();
    virtual ~CTerrainMaterial();
    virtual void Init();

protected:
};


#endif

