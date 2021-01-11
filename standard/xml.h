/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: xml.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_XML_H__
#define __STANDARD_XML_H__

#include <include/stdtype.h>
#include <include/xml.h>
#include <standard/list.h>

class CXML{
public:
    CXML( const char* strText );
    virtual ~CXML();
    void Close();
    HXMLNODEHANDLE GetFirstNode();
    HXMLNODEHANDLE GetNode( const char* strName );
    HXMLNODEHANDLE GetFirstNode( HXMLNODEHANDLE hXMLNodeHandle );
    HXMLNODEHANDLE GetNode( HXMLNODEHANDLE hXMLNodeHandle, const char* strName );
    HXMLNODEHANDLE GetNextNode( HXMLNODEHANDLE hXMLNodeHandle );
    HXMLNODEHANDLE GetNextNode( HXMLNODEHANDLE hXMLNodeHandle, const char* strName );
    int32 GetNodeCount( HXMLNODEHANDLE hNodeHandle, const char* strName );
    int32 GetChildCount( HXMLNODEHANDLE hNodeHandle );
    const char* GetName( HXMLNODEHANDLE hNodeHandle, char* strBuff );

    const char* GetValue( HXMLNODEHANDLE hNodeHandle, char* strBuff );
    int32 GetValueInt32( HXMLNODEHANDLE hNodeHandle, int32 nDefaultValue = 0 );
    float GetValueFloat( HXMLNODEHANDLE hNodeHandle, float fDefaultValue = 0.0f );
    int32 GetValueInt32List( HXMLNODEHANDLE hNodeHandle, list<int32>* _pInt32List );

    const char* GetNodeValue( HXMLNODEHANDLE hNodeHandle, const char* strNodeName, char* strBuff );
    int32 GetNodeValueInt32( HXMLNODEHANDLE hNodeHandle, const char* strNodeName, int32 nDefaultValue = 0 );
    float GetNodeValueFloat( HXMLNODEHANDLE hNodeHandle, const char* strNodeName, float fDefaultValue = 0.0f );


    const char* GetAttributeValue( HXMLNODEHANDLE hNodeHandle, const char* strName, char* strBuff );
    int32 GetAttributeValueInt32( HXMLNODEHANDLE hNodeHandle, const char* strName, int32 nDefaultValue = 0 );
    float GetAttributeValueFloat( HXMLNODEHANDLE hNodeHandle, const char* strName, float fDefaultValue = 0.0f );
    uint32 GetAttributeValueReverseUint32( HXMLNODEHANDLE hNodeHandle, const char* strAttriName );
    int32 GetAttributeValueInt32List( HXMLNODEHANDLE hNodeHandle, const char* strName, list<int32>* _pInt32List );

private:
    HXMLDOCUMENTHANDLE m_hXMLDocmentHandle;
};

#endif
