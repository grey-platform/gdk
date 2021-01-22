/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: colorscene.h
*Module: bigimage
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __BIGIMAGE_COLORSCENE_H__
#define __BIGIMAGE_COLORSCENE_H__

#include <bigimage/scene.h>

class CColorScene: public CScene{
public:
    CColorScene( float r, float g, float b );
    virtual ~CColorScene();

public:
    CColor m_tColor;

};

#endif
