
/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: notification.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2021
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/

#ifndef __STANDARD_NOTIFICATION_H__
#define __STANDARD_NOTIFICATION_H__

#include <standard/reference.h>
#include <standard/delegate.h>
#include <standard/list.h>

struct SNotificationNode{
    CDelegate3<int32, int32, void* > m_Delegate;
    SNotificationNode* m_pNext;
};

struct SNotificationItem{
    char m_strName[64];
    SNotificationNode* m_pHead;
};

class CNotification{
public:
    static CNotification* GetInterface();
    static void Destroy();
    CNotification();
    ~CNotification();
    void Add( const char* strMessage, CDelegate3<int32, int32, void* > sDelegateObj );
    void Remove( const char* strMessage, CDelegate3<int32, int32, void* > sDelegateObj);
    void Clear( const char* strMessage );
    void SendMessage(const char* strMessage, int32 nWParame, int32 nLParame, void* pData );

private:
    SNotificationItem* GetNotificationItem(const char* strMessage);
    void PushBack(SNotificationItem* pItem, SNotificationNode* pNode );
    list<SNotificationItem* >m_vNotificationItemList;
};



#endif
