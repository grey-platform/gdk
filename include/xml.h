/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: xml.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_XML_H__
#define __GRAY_SDK_XML_H__

#include <include/stdtype.h>

typedef uint32 HXMLDOCUMENTHANDLE;
typedef uint32 HXMLNODEHANDLE;

EXTERN HXMLDOCUMENTHANDLE XMLDocument_Open( const char* strContent );
EXTERN HXMLNODEHANDLE XMLDocument_GetFirstNode( HXMLDOCUMENTHANDLE hDocumentHandle );
EXTERN HXMLNODEHANDLE XMLDocument_GetNode( HXMLDOCUMENTHANDLE hDocumentHandle, const char *strName );
EXTERN void XMLDocument_Destroy( HXMLDOCUMENTHANDLE hDocumentHandle );
EXTERN HXMLNODEHANDLE XMLNode_GetFirstNode( HXMLNODEHANDLE hNodeHandle );
EXTERN HXMLNODEHANDLE XMLNode_GetNextNode( HXMLNODEHANDLE hNodeHandle, const char* strName );
EXTERN HXMLNODEHANDLE XMLNode_GetNode( HXMLNODEHANDLE hNodeHandle, const char *strName );
EXTERN int32 XMLNode_GetNodeCount( HXMLNODEHANDLE hNodeHandle, const char *strName );
EXTERN int32 XMLNode_GetChildCount( HXMLNODEHANDLE hNodeHandle );
EXTERN char* XMLNode_GetName( HXMLNODEHANDLE hNodeHandle, char* strTextBuff );
EXTERN char* XMLNode_GetValue( HXMLNODEHANDLE hNodeHandle, char* strTextBuff );
EXTERN char* XMLNode_GetAttributeValue( HXMLNODEHANDLE hNodeHandle, const char *strName, char* strTextBuff );

#endif
