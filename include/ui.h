/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: ui.h
*Module: grey
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __GRAY_SDK_UI_H__
#define __GRAY_SDK_UI_H__

#include <include/stdtype.h>
#include <include/texture.h>

typedef uint32 HUIHANDLE;

typedef enum _EUIEventMessage{
    UEM_CLICK,
    UEM_MOUSEEVENT,
    UEM_KEYEVENT,
    UEM_RENDER,
    UEM_SELECT,
    UEM_GETTEXTURE,
    UEM_TEXTEDIT,
    UEM_COUNT,
}_EUIEventMessage;

typedef enum _ELISTITEMINFOTYPE{
    LIIT_INT,
    LIIT_FLOAT,
    LIIT_STRING,
    LIIT_IMAGE,
}_ELISTITEMINFOTYPE;

typedef struct _TUITexCoordsInfo{
    float m_fLeft;
    float m_fTop;
    float m_fWidth;
    float m_fHeight;
    float m_fX, m_fY, m_fR, m_fB;
}_TUITexCoordsInfo;

//struct CRenderItem{
//    HTEXTUREHANDLE m_hTextureHandle;
//    //    CVertexBufferPointer*    m_pVertBuffer;
//};

typedef enum _EScorllPanelItemDataType{
    ESPIDT_TEXT,
    ESPIDT_INT32,
    ESPIDT_FLOAT,
    ESPIDT_ICONIMAGE,
    ESPIDT_ICONINDEX,
    ESPIDT_TEXTURE,

    ESPIDT_USERDATA0 = 10,
    ESPIDT_USERDATA1,
    ESPIDT_USERDATA2,
    ESPIDT_USERDATA3,

    ESPIDT_ENABLE = 20,
}_EScorllPanelItemDataType;

typedef enum _ELABELTEXTALIGN{       //对齐方式
    ELTA_LEFT,          //左对齐
    ELTA_RIGHT,         //右对齐
    ELTA_CENTER,        //中对齐
}_ELABELTEXTALIGN;

//////////////////////////////////////////////////////////////////////////////////////////////

EXTERN HUIHANDLE GUI_Windows_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight, bool32 bMaxHeader );
EXTERN HUIHANDLE GUI_Lable_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_Button_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_IconButton_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_Image_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_PanelElement_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_PanelTransformElement_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_Canvas_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_TextBox_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_ScrollPanel_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_SubScrollPanel_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_ScrollView_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_TextView_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_ListView_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_EditBox_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_ProgressBar_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_Animation_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN HUIHANDLE GUI_DataView_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN void GUI_Element_AddElement( HUIHANDLE nParentHandle, HUIHANDLE nChildHandle );
EXTERN void GUI_Element_RemoveElement( HUIHANDLE nParentHandle, HUIHANDLE nChildHandle );
EXTERN void GUI_Element_SetText( HUIHANDLE hHandle, const char* strText );
EXTERN const char* GUI_Element_GetText( HUIHANDLE hHandle, char *strText );
EXTERN void GUI_Element_Clear( HUIHANDLE hHandle );
EXTERN void GUI_Element_AddText( HUIHANDLE hHandle, const char *strText );
EXTERN void GUI_Element_SetFontInfo( HUIHANDLE hHandle, int32 nFont, int32 nFontSize, int32 nFontStyle );
EXTERN void GUI_Element_SetFontColor( HUIHANDLE hHandle, color32 nColor );
EXTERN void GUI_IconButton_SetIcon( HUIHANDLE hHandle, const char *strFileName, int32 nIndex, int32 nCol, int32 nRow );
EXTERN void GUI_IconButton_SetIconFile( HUIHANDLE hHandle, const char *strFileName );
EXTERN void GUI_IconButton_SetIconIndex( HUIHANDLE hHandle, int32 nIndex );
EXTERN void GUI_Element_SetImage( HUIHANDLE hHandle, const char *strFileName );
EXTERN void GUI_Image_SetImage( HUIHANDLE hHandle, HTEXTUREHANDLE hTexture );
EXTERN void GUI_Canvas_SetRenderItems( HUIHANDLE hHandle, void* pRenderItem, int32 nCount );
EXTERN void GUI_Element_SetUIEventCallBack( HUIHANDLE hHandle, int32 nAppEventID, _EUIEventMessage eMessageType );
EXTERN void GUI_Button_SetButtonChecked( HUIHANDLE hHandle, int32 nChecked );
EXTERN void GUI_TextBox_SetFile( HUIHANDLE hHandle, const char *strFileName );
EXTERN void GUI_ScrollPanel_SetItemData( HUIHANDLE hHandle, void *pData, int32 nSubDataSize, int32 nCount );
EXTERN void GUI_SubScrollPanel_SetDataStruct( HUIHANDLE hHandle, HUIHANDLE hSubPanel, int32 nAddress, int32 nType );
EXTERN void GUI_TextView_SetClearTime( HUIHANDLE hHandle, float fTime );
EXTERN void GUI_ListView_SetCell( HUIHANDLE hHandle, int32 nWidth, int32 nHeight );
EXTERN void GUI_ListView_SetHeaderInfo( HUIHANDLE hHandle, int32 nIndex, const char* strTitle, _ELISTITEMINFOTYPE nDataType, int32 fWidth );
EXTERN void GUI_ListView_SetCellInfoText( HUIHANDLE hHandle, int32 nCol, int32 nRow, const char* strText );
EXTERN void GUI_ListView_SetCellInfoInteger( HUIHANDLE hHandle, int32 nCol, int32 nRow, int32 nData );
EXTERN void GUI_ListView_SetCellInfoFloat( HUIHANDLE hHandle, int32 nCol, int32 nRow, float fData );
EXTERN void GUI_ListView_SetCellInfoImage( HUIHANDLE hHandle, int32 nCol, int32 nRow, const char* strFileName, int32 nIndex, int32 x, int32 y );
EXTERN void GUI_ListView_SetItemHeight( HUIHANDLE hHandle, int32 fItemHeight );
EXTERN int32 GUI_ListView_AddNewRow( HUIHANDLE hHandle );
EXTERN void GUI_ListView_ClearCell( HUIHANDLE hHandle );
EXTERN int32 GUI_ListView_GetCellCount( HUIHANDLE hHandle );
EXTERN void GUI_ListView_DeleteRow( HUIHANDLE hHandle, int32 nRow );
EXTERN void GUI_Element_SetVisible( HUIHANDLE hHandle, int32 nVisible );
EXTERN void GUI_Element_SetUserData0( HUIHANDLE hHandle, int32 nData );
EXTERN void GUI_Element_SetUserData1( HUIHANDLE hHandle, int32 nData );
EXTERN void GUI_Element_SetUserData2( HUIHANDLE hHandle, int32 nData );
EXTERN void GUI_Element_SetUserData3( HUIHANDLE hHandle, int32 nData );
EXTERN int32 GUI_Element_GetUserData0( HUIHANDLE hHandle );
EXTERN int32 GUI_Element_GetUserData1( HUIHANDLE hHandle );
EXTERN int32 GUI_Element_GetUserData2( HUIHANDLE hHandle );
EXTERN int32 GUI_Element_GetUserData3( HUIHANDLE hHandle );
EXTERN void GUI_Element_SetTextureCoordsInfo( HUIHANDLE hHandle, int32 nIndex, _TUITexCoordsInfo* pTexCoordsInfo );
EXTERN void GUI_Element_SetTextureCoordsInfo1( HUIHANDLE hHandle, int32 nIndex, float fLeft, float fTop, float fRight, float fBottom );
EXTERN void GUI_Element_SetTexture( HUIHANDLE hHandle, const char *strFileName );
EXTERN void GUI_Element_SetTextureHandle( HUIHANDLE hHandle, HTEXTUREHANDLE hTexture );
EXTERN void GUI_Element_UpdateTextureCoordsInfo( HUIHANDLE hHandle );
EXTERN void GUI_Element_SetPos( HUIHANDLE hHandle, int32 x, int32 y );
EXTERN void GUI_Element_SetBound( HUIHANDLE hHandle, int32 x, int32 y, int32 w, int32 h );
EXTERN void GUI_Button_SetCheckMode( HUIHANDLE hHandle, int32 bCheckMode );
EXTERN int32 GUI_Button_GetChecked( HUIHANDLE hHandle );
EXTERN void GUI_ProgressBar_SetRange( HUIHANDLE hHandle, int32 nRange );
EXTERN void GUI_ProgressBar_SetPos( HUIHANDLE hHandle, int32 nPos );
EXTERN void GUI_Button_SetEnable( HUIHANDLE hHandle, int32 bEnable );
EXTERN void GUI_ListView_VisibleLastRow( HUIHANDLE hHandle );
EXTERN void GUI_Element_SetTextAlign( HUIHANDLE hHandle, _ELABELTEXTALIGN eAlign );
EXTERN void GUI_ListView_SetSelect( HUIHANDLE hHandle, int32 nRow );
EXTERN void GUI_SetShadowHandle( HUIHANDLE hHandle, HUIHANDLE hShadowHandle );
EXTERN HUIHANDLE GUI_GetShadowHandle( HUIHANDLE hHandle );
EXTERN void GUI_Animation_SetAnimationInfo( HUIHANDLE hHandle, const char* strFileName, int32 nCol, int32 nRow, int32 nStartIndex, int32 nEndIndex, bool32 bLoop, int32 nFps );
EXTERN void GUI_Animation_Reset( HUIHANDLE hHandle );
EXTERN void GUI_Element_SetColor( HUIHANDLE hHandle, color32 c );
EXTERN int32 GUI_ListView_GetSelect( HUIHANDLE hHandle );
EXTERN void GUI_Element_BringToFront( HUIHANDLE hHandle );
EXTERN void GUI_Element_SendToBack( HUIHANDLE hHandle );
EXTERN void GUI_ListView_SetItemData( HUIHANDLE hHandle, int32 nRow, void* pUserData );
EXTERN void* GUI_ListView_GetItemData( HUIHANDLE hHandle, int32 nRow );
EXTERN void GUI_DataView_SetData( HUIHANDLE hHandle, int32 nMin, int32 nMax, int32 *pData, int32 nSize );
EXTERN void GUI_TextBox_VisibleLastRow( HUIHANDLE hHandle );
EXTERN HUIHANDLE GUI_Element_GetChildForID( HUIHANDLE hHandle, int32 nID );
EXTERN HUIHANDLE GUI_Element_GetParent( HUIHANDLE hHandle );
EXTERN void GUI_Element_GetPos( HUIHANDLE hHandle, int32 pPos[2] );
EXTERN void GUI_Element_GetBound( HUIHANDLE hHandle, int32 pBound[4] );
EXTERN void GUI_Element_SetZOrder( HUIHANDLE hHandle, int32 nValue );
EXTERN HUIHANDLE GUI_RichTextView_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN void GUI_Element_Release( HUIHANDLE hHandle );
EXTERN HUIHANDLE GUI_HtmlView_Create( int32 fLeft, int32 fTop, int32 fWidth, int32 fHeight );
EXTERN void GUI_Element_SetID( HUIHANDLE hHandle, int32 nID );
EXTERN int32 GUI_Element_GetID( HUIHANDLE hHandle );
EXTERN void GUI_Element_SetReadOnly( HUIHANDLE hHandle, bool32 nValue );
EXTERN char* GUI_ListView_GetCellInfo( HUIHANDLE hHandle, int32 nCol, int32 nRow, char* strTextBuff );

#endif
