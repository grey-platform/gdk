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


#ifndef __BIGIMAGE_WFXGAMEPARTICLEMANAGER_H__
#define __BIGIMAGE_WFXGAMEPARTICLEMANAGER_H__

#include <standard/material.h>

class CWFXGameParticleManager{
public:
    CWFXGameParticleManager();
    ~CWFXGameParticleManager();
    void Update( float fDelta, float* pCameraPos );
    void Render( CMaterial* pMateral );
    void Clear();
    void SetCameraAngle( float x, float y );
    uint32 GetHandle(){ return m_hWFXParticleManagerHandle; }

private:
    uint32 m_hWFXParticleManagerHandle;
};

#endif

