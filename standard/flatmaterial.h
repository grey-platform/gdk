/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: flatmaterial.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_FLATMATERIAL_H__
#define __STANDARD_FLATMATERIAL_H__

#include <standard/material.h>
#include <include/math.h>

class CFlatMaterial: public CMaterial{
public:
    CFlatMaterial();
    virtual ~CFlatMaterial();
    virtual void Init();
    virtual void Begin();
    virtual void End();
    void RenderText( float x, float y, const char* strText, color32 c, int32 nStyle, color32 bk );

private:


};


#endif
