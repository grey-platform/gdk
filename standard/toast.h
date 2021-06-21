/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: toast.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TOAST_H__
#define __STANDARD_TOAST_H__

#include <standard/gui.h>
#include <standard/task.h>
#include <standard/list.h>

class CToast: public CTranslateNode{
public:
    class CToastTask: public ITask{
    public:
        CToastTask( CToast* pToast );
        virtual ~CToastTask();
        virtual int32 UpdateTask( float fDelta );

    private:
        CToast* m_pToast;
    };

public:
    CToast( float x, float y );
    virtual ~CToast();
    void Close();
    virtual int32 UpdateToast( float fDelta );

protected:
    void UpdatePos( float x, float y );
    float m_fX, m_fY;

};

class CMessageToast: public CToast{
public:
    CMessageToast( int32 x, int32 y, const char* strText );
    virtual ~CMessageToast();
   // virtual int32 UpdateTask( float fDelta );
    virtual int32 UpdateToast( float fDelta );
private:
    void UpdatePos( float fDelta );
    CLable* m_pTextLB;
    float m_fSpeed;
    float m_fTime;
};



#endif
