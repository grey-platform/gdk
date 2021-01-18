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


#ifndef __BIGIMAGE_RENDERITEMMANAGER_H__
#define __BIGIMAGE_RENDERITEMMANAGER_H__

#include <bigimage/bigimageinterface.h>
#include <standard/matrix4.h>

class CRenderItemManager{
public:
    CRenderItemManager();
    virtual ~CRenderItemManager();
    void Add( HRENDERELEMENTHANDLE hRenderElementHandle );
    void Remove( HRENDERELEMENTHANDLE hRenderElementHandle );
    void Clear();
    void Update( CMatrix4& pProjectM, CMatrix4& pViewM, CMatrix4& pProjViewM );
    void UpdateShadow( CMatrix4& pProjectM, CMatrix4& pViewM, CMatrix4& pProjViewM );
    void Render();
    void RenderShadow();

private:
    HRENDERELEMENTMANAGERHANDLE m_hRenderElementManagerHandle;

};


#endif
