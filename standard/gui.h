/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: gui.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_GUI_H__
#define __STANDARD_GUI_H__

#include <include/stdtype.h>
#include <include/ui.h>
//#include <include/delegate.h>
//#include <standard/delegate.h>
#include <standard/texture.h>
#include <standard/list.h>

#define EVENTTABLESIZE (512)
#define EVENTTABLESTART (100)


typedef enum EUIElement{
    UI_ELEMENT,
    UI_TRANSFORMELEMENT,
    UI_TASKPANEL,
    UI_MANAGER,
    UI_WINDOW,
    UI_BUTTON,
    UI_ICONBUTTON,
    UI_LABEL,
    UI_IMAGE,
    UI_TEXTVIEW,
    UI_PANELELEMENT,
    UI_PANELTRANSFORMELEMENT,
    UI_LISTVIEW,
    UI_SCROLLBAR,
    UI_CANVAS,
    UI_TEXTBOX,
    UI_EDITBOX,
    UI_PROGRESSBAR,
    UI_SCROLLPANEL,
    UI_SUBSCROLLPANEL,
    UI_3DCANVAS,
    UI_ANIMATION,
    UI_USERELEMENT,
    UI_USERTRANSFORMELEMENT,
    UI_DATAVIEW,
    UI_RICHTEXTVIEW,
    UI_HTMLVIEW,
    UI_COUNT,
}EUIElement;

typedef enum EUIMouseMessage{
    UME_MOUSELDOWN,
    UME_MOUSELUP,
    UME_MOUSERDOWN,
    UME_MOUSERUP,
    UME_MOUSEMOVE,
    UME_MOUSEWHEEL,
    UME_MOUSEENTER,
    UME_MOUSELEVEL,
    UME_MOUSEMDOWN,
    UME_MOUSEMUP,
}EUIMouseMessage;

typedef enum EUIKeyMessage{
    UKE_KEYDOWN,
    UKE_KEYUP,
}EUIKeyMessage;


/*
*VirtualKeys,StandardSet
*/
#define VK_LBUTTON 0x01
#define VK_RBUTTON 0x02
#define VK_CANCEL 0x03
#define VK_MBUTTON 0x04/*NOTcontiguouswithL&RBUTTON*/
#define VK_BACK 0x08
#define VK_TAB 0x09
#define VK_CLEAR 0x0C
#define VK_RETURN 0x0D
#define VK_SHIFT 0x10
#define VK_CONTROL 0x11
#define VK_MENU 0x12
#define VK_PAUSE 0x13
#define VK_CAPITAL 0x14
#define VK_KANA 0x15
#define VK_HANGEUL 0x15/*oldname-shouldbehereforcompatibility*/
#define VK_HANGUL 0x15
#define VK_JUNJA 0x17
#define VK_FINAL 0x18
#define VK_HANJA 0x19
#define VK_KANJI 0x19
#define VK_ESCAPE 0x1B
#define VK_CONVERT 0x1C
#define VK_NONCONVERT 0x1D
#define VK_ACCEPT 0x1E
#define VK_MODECHANGE 0x1F
#define VK_SPACE 0x20
#define VK_PRIOR 0x21
#define VK_NEXT 0x22
#define VK_END 0x23
#define VK_HOME 0x24
#define VK_LEFT 0x25
#define VK_UP 0x26
#define VK_RIGHT 0x27
#define VK_DOWN 0x28
#define VK_SELECT 0x29
#define VK_PRINT 0x2A
#define VK_EXECUTE 0x2B
#define VK_SNAPSHOT 0x2C
#define VK_INSERT 0x2D
#define VK_DELETE 0x2E
#define VK_HELP 0x2F

//* VK_0 - VK_9 arethesameas ASCII '0' - '9'( 0x30 - 0x39 )
//* 0x40:unassigned
//*VK_A - VK_ZarethesameasASCII'A' - 'Z'( 0x41 - 0x5A )


#define VK_0 0x30
#define VK_1 0x31
#define VK_2 0x32
#define VK_3 0x33
#define VK_4 0x34
#define VK_5 0x35
#define VK_6 0x36
#define VK_7 0x37
#define VK_8 0x38
#define VK_9 0x39

#define VK_A 0x41
#define VK_B 0x42
#define VK_C 0x43
#define VK_D 0x44
#define VK_E 0x45
#define VK_F 0x46
#define VK_G 0x47
#define VK_H 0x48
#define VK_I 0x49
#define VK_J 0x4A
#define VK_K 0x4B
#define VK_L 0x4C
#define VK_M 0x4D
#define VK_N 0x4E
#define VK_O 0x4F
#define VK_P 0x50
#define VK_Q 0x51
#define VK_R 0x52
#define VK_S 0x53
#define VK_T 0x54
#define VK_U 0x55
#define VK_V 0x56
#define VK_W 0x57
#define VK_X 0x58
#define VK_Y 0x59
#define VK_Z 0x5A

#define VK_LWIN 0x5B
#define VK_RWIN 0x5C
#define VK_APPS 0x5D
#define VK_SLEEP 0x5F
#define VK_NUMPAD0 0x60
#define VK_NUMPAD1 0x61
#define VK_NUMPAD2 0x62
#define VK_NUMPAD3 0x63
#define VK_NUMPAD4 0x64
#define VK_NUMPAD5 0x65
#define VK_NUMPAD6 0x66
#define VK_NUMPAD7 0x67
#define VK_NUMPAD8 0x68
#define VK_NUMPAD9 0x69
#define VK_MULTIPLY 0x6A
#define VK_ADD 0x6B
#define VK_SEPARATOR 0x6C
#define VK_SUBTRACT 0x6D
#define VK_DECIMAL 0x6E
#define VK_DIVIDE 0x6F
#define VK_F1 0x70
#define VK_F2 0x71
#define VK_F3 0x72
#define VK_F4 0x73
#define VK_F5 0x74
#define VK_F6 0x75
#define VK_F7 0x76
#define VK_F8 0x77
#define VK_F9 0x78
#define VK_F10 0x79
#define VK_F11 0x7A
#define VK_F12 0x7B
#define VK_F13 0x7C
#define VK_F14 0x7D
#define VK_F15 0x7E
#define VK_F16 0x7F
#define VK_F17 0x80
#define VK_F18 0x81
#define VK_F19 0x82
#define VK_F20 0x83
#define VK_F21 0x84
#define VK_F22 0x85
#define VK_F23 0x86
#define VK_F24 0x87
#define VK_NUMLOCK 0x90
#define VK_SCROLL 0x91
#define VK_OEM_NEC_EQUAL 0x92//'='keyonnumpad
#define VK_OEM_FJ_JISHO 0x92//'Dictionary'key
#define VK_OEM_FJ_MASSHOU 0x93//'Unregisterword'key
#define VK_OEM_FJ_TOUROKU 0x94//'Registerword'key
#define VK_OEM_FJ_LOYA 0x95//'LeftOYAYUBI'key
#define VK_OEM_FJ_ROYA 0x96//'RightOYAYUBI'key
#define VK_LSHIFT 0xA0
#define VK_RSHIFT 0xA1
#define VK_LCONTROL 0xA2
#define VK_RCONTROL 0xA3
#define VK_LMENU 0xA4
#define VK_RMENU 0xA5
#define VK_OEM_1 0xBA//';:'forUS
#define VK_OEM_PLUS 0xBB//'+'anycountry
#define VK_OEM_COMMA 0xBC//','anycountry
#define VK_OEM_MINUS 0xBD//'-'anycountry
#define VK_OEM_PERIOD 0xBE//'.'anycountry
#define VK_OEM_2 0xBF//'/?'forUS
#define VK_OEM_3 0xC0//'`~'forUS
#define VK_OEM_4 0xDB//'[{'forUS
#define VK_OEM_5 0xDC//'\|'forUS
#define VK_OEM_6 0xDD//']}'forUS
#define VK_OEM_7 0xDE//''"'forUS
#define VK_OEM_8 0xDF
#define VK_OEM_AX 0xE1//'AX'keyonJapaneseAXkbd
#define VK_OEM_102 0xE2//"<>"or"\|"onRT102-keykbd.
#define VK_ICO_HELP 0xE3//HelpkeyonICO
#define VK_ICO_00 0xE4//00keyonICO
#define VK_ICO_CLEAR 0xE6
#define VK_OEM_RESET 0xE9
#define VK_OEM_JUMP 0xEA
#define VK_OEM_PA1 0xEB
#define VK_OEM_PA2 0xEC
#define VK_OEM_PA3 0xED
#define VK_OEM_WSCTRL 0xEE
#define VK_OEM_CUSEL 0xEF
#define VK_OEM_ATTN 0xF0
#define VK_OEM_FINISH 0xF1
#define VK_OEM_COPY 0xF2
#define VK_OEM_AUTO 0xF3
#define VK_OEM_ENLW 0xF4
#define VK_OEM_BACKTAB 0xF5
#define VK_ATTN 0xF6
#define VK_CRSEL 0xF7
#define VK_EXSEL 0xF8
#define VK_EREOF 0xF9
#define VK_PLAY 0xFA
#define VK_ZOOM 0xFB
#define VK_NONAME 0xFC
#define VK_PA1 0xFD
#define VK_OEM_CLEAR 0xFE





extern HUIHANDLE CUIElement__vGUIEventTable[EVENTTABLESIZE]; //UI Event Table
int32 CUIElement__BuildEventID();

class CUIElement;
class CUIEvent{
public:
    virtual void OnClick( CUIElement *pSelf );
    virtual void OnMouseEvent( CUIElement *pSelf, EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s );
    virtual void OnKeyEvent( CUIElement *pSelf, EUIKeyMessage eKeyMessage, int32 nKey );
    virtual int32 OnTextEditEvent( CUIElement *pSelf, const char* strText );
    virtual void OnSelected( CUIElement* pSelf, int32 nType, int32 nIndex );
};

class CUIElement{
public:
    static int32 LoadUIFormFile( const char* strFileName, CUIElement* pParent, list<CUIElement*>*pParentElementList );
    CUIElement();
    virtual ~CUIElement();
    void CreateGUI( int32 x, int32 y, int32 width, int32 height );
    void Destroy();
    HUIHANDLE GetHandle();
    HUIHANDLE GetParentHandle();
    virtual void SetPosition( int32 x, int32 y );
    virtual void GetPosition( int32* x, int32* y );
    virtual void SetBound( int32 x, int32 y, int32 width, int32 height );
    virtual void SetTexture( const char* strFileName );
    virtual void SetTexture( CTexture* pTexture );
    virtual void SetTexture( HTEXTUREHANDLE hTextuerHandle );
    virtual void SetTextureCoordsInfo( int32 nIndex, _TUITexCoordsInfo* pTexCoordsInfo );
    virtual void SetTextureCoordsInfo( int32 nIndex, int32 nTextureWidth, int32 nTextureHeight, int32 nLeft, int32 nTop, int32 nRight, int32 nBottom );
    virtual void ApplyTextureCoordsInfo();
    virtual void AddElement( CUIElement* pElement );
    virtual void RemoveElement( CUIElement* pElement );
    virtual void SetFontInfo( int32 nFontType, int32 nFontSize, int32 nFontStyle );
    virtual void SetFontColor( color32 nColor );
    virtual void SetVisible( bool32 bActive );
    virtual void Update( float fDelta );
    void SetColor( color32 c );
    void SetText( const char* strText );
    virtual void SetTextAlign( _ELABELTEXTALIGN eAlign );
    virtual const char* GetText( char* strTextBuffer );
    void BringToFront();
    void SendToBack();
    void SetZOrder( int32 nValue );
    CUIElement* GetChildForID( int32 nID );
    CUIElement* GetParent();
    //event Process
    virtual int32 ProcessClickEvent();
    virtual int32 ProcessTextEditEvent( int32 nStrFarAddress );
    virtual int32 ProcessMouseEvent( EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s );
    virtual int32 ProcessKeyEvent( EUIKeyMessage eKeyMessage, int32 nKey );
    virtual int32 ProcessSelectEvent( int32 nType, int32 nIndex );
    virtual int32 ProcessGetTextureEvent( const char* strFileName, HTEXTUREHANDLE* hTextureHandle );

    void SetID( int32 nID );
    void AddUIEvent( _EUIEventMessage eMessageType );
    void RemoveUIEvent( _EUIEventMessage eMessageType );
    void SetUserData0( int32 nData );
    void SetUserData1( int32 nData );
    void SetUserData2( int32 nData );
    void SetUserData3( int32 nData );
    int32 GetID();
    int32 GetUserData0();
    int32 GetUserData1();
    int32 GetUserData2();
    int32 GetUserData3();
    int32 DispatchEvent( _EUIEventMessage eMessageType, int32 nParame0, int32 nParame1, int32 nParame2, int32 nParame3, int32 nParame4, int32 nParame5, int32 nParame6 );
    void GetPosition( int32 pPos[2] );
    void GetBound( int32 pBound[4] );
    EUIElement m_eUIElement;    //UI¿‡–Õ
    int32 m_nID;
    int32 m_nGUID;

protected:
    HUIHANDLE m_hHandle;
    int32 m_nUserData[4];

};

class CWindow: public CUIElement{
public:
    CWindow( int32 x, int32 y, int32 width, int32 height );
    CWindow( int32 x, int32 y, int32 width, int32 height, const char* strTitle );
    virtual ~CWindow();
};

class CButton: public CUIElement{
public:
    CButton( int32 x, int32 y, int32 width, int32 height );
    CButton( int32 x, int32 y, int32 width, int32 height, const char* strText );
    virtual ~CButton();
    virtual int32 ProcessClickEvent();
    void SetEnable( bool32 bEnable );
    void SetCheckMode( bool32 bChecked );
    void SetChecked( bool32 nChecked );
    bool32 GetChecked();
    void SetValue( int32 nValue );
    void SetValue( float fValue );
    CUIEvent* OnClickEventObject;
};

class CLable: public CUIElement{
public:
    CLable( int32 x, int32 y, int32 width, int32 height );
    CLable( int32 x, int32 y, int32 width, int32 height, const char* strText );
    virtual ~CLable();
    void SetValue( int32 nValue );
    void SetValue( float fValue );
};

class CPanel: public CUIElement{
public:
    CPanel( int32 x, int32 y, int32 width, int32 height );
    virtual ~CPanel();
    virtual int32 ProcessClickEvent();
    virtual int32 ProcessMouseEvent( EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s );
    CUIEvent* OnMouseEventObject;
};

class CImage: public CUIElement{
public:
    CImage( int32 x, int32 y, int32 width, int32 height );
    CImage( int32 x, int32 y, int32 width, int32 height, CTexture* pTexture );
    CImage( int32 x, int32 y, int32 width, int32 height, const char* strFileName );
    virtual ~CImage();
    virtual int32 ProcessMouseEvent( EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s );
    virtual int32 ProcessKeyEvent( EUIKeyMessage eKeyMessage, int32 nKey );
    void SetImage( const char* strFileName );
    CUIEvent* OnMouseEventObject;
    CUIEvent* OnKeyEventObject;
};

class CListView: public CUIElement{
public:
    CListView( int32 x, int32 y, int32 width, int32 height );
    virtual ~CListView();
    virtual int32 ProcessSelectEvent( int32 nType, int32 nIndex );
    virtual int32 ProcessKeyEvent(EUIKeyMessage eKeyMessage, int32 nKey);
    void SetItemHeight( int32 nValue );
    void SetCell( int32 nWidth, int32 nHeight );
    void SetHeaderInfo( int32 nIndex, const char* strTitle, _ELISTITEMINFOTYPE eItemDataType, int32 nWidth );
    void ClearCell();
    int32 AddNewRow();
    void SetCellInfo( int32 nCol, int32 nRow, const char* strText );
    void SetCellInfo( int32 nCol, int32 nRow, int32 nValue );
    void SetCellInfo( int32 nCol, int32 nRow, float fValue );
    void SetItemData( int32 nRow, void* pUserData );
    void* GetItemData( int32 nRow );
    char* GetCellText( int32 nCol, int32 nRow, char* strTextBuff );
    void VisibleLastRow();
    int32 GetCellCount();
    void DeleteRow( int32 nRow );
    void SetSelect( int32 nRow );
    int32 GetSelect();
    CUIEvent* OnSelectEventObject;
    CUIEvent* OnKeyEventObject;
};

class CProgressBar: public CUIElement{
public:
    CProgressBar( int32 x, int32 y, int32 width, int32 height );
    CProgressBar( int32 x, int32 y, int32 width, int32 height, int32 nRange );
    virtual ~CProgressBar();
    void SetRange( int32 nRange );
    void SetPos( int32 nPos );
};

class CAnimation: public CUIElement{
public:
    CAnimation( int32 x, int32 y, int32 width, int32 height );
    CAnimation( int32 x, int32 y, int32 width, int32 height, int32 nRange );
    virtual ~CAnimation();
    void SetAnimationInfo( const char* strFileName, int32 nCol, int32 nRow, int32 nStartIndex, int32 nEndIndex, bool32 bLoop, int32 nFps );
    void Reset();
};

class CTranslatePanel: public CUIElement{
public:
    CTranslatePanel( int32 x, int32 y, int32 width, int32 height );
    virtual ~CTranslatePanel();
    virtual int32 ProcessMouseEvent( EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s );
    virtual int32 ProcessKeyEvent( EUIKeyMessage eKeyMessage, int32 nKey );
    CUIEvent* OnMouseEventObject;
    CUIEvent* OnKeyEventObject;
};

class CTextView: public CUIElement{
public:
    CTextView( int32 x, int32 y, int32 width, int32 height );
    virtual ~CTextView();
    void SetClearTime( float fTime );
    void SetTextColor( color32 c );
    void AddText( const char* strText );
    void Clear();
    virtual int32 ProcessMouseEvent( EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s );
    virtual int32 ProcessKeyEvent( EUIKeyMessage eKeyMessage, int32 nKey );
    CUIEvent* OnMouseEventObject;
    CUIEvent* OnKeyEventObject;
};

class CTextBox: public CUIElement{
public:
    CTextBox( int32 x, int32 y, int32 width, int32 height );
    virtual ~CTextBox();
    virtual int32 ProcessTextEditEvent( int32 nStrFarAddress );
    void VisibleLastRow();
    void Clear();
    void SetText( const char* strText );
    void SetReadOnly( bool32 bValue );
    CUIEvent* OnTextEditEventObject;
};

class CDataView: public CUIElement{
public:
    CDataView( int32 x, int32 y, int32 width, int32 height );
    virtual ~CDataView();
    void SetData( int32 nMin, int32 nMax, int32 *pData, int32 nSize );
};

class CRichTextView: public CUIElement{
public:
    CRichTextView( int32 x, int32 y, int32 width, int32 height );
    virtual ~CRichTextView();
    void SetText( const char* strText );
    void AddText( const char* strText );
    void Clear();
    virtual int32 ProcessMouseEvent( EUIMouseMessage eMouseMessage, int32 x, int32 y, int32 z, int32 s );
    virtual int32 ProcessKeyEvent( EUIKeyMessage eKeyMessage, int32 nKey );
    virtual int32 ProcessGetTextureEvent( const char* strFileName, HTEXTUREHANDLE* hTextureHandle );
    void ClearTexture();
    //TUIMOUSEEVENT OnMouseEvent;
    //TUIKEYEVENT   OnKeyEvent;
    //TGETTEXTUREFILECALLBACK OnGetTextureEvent;
    //map<uint32, CTexture*>m_vRichViewTextureList;

};

class CHtmlView: public CUIElement{
public:
    CHtmlView( int32 x, int32 y, int32 width, int32 height );
    virtual ~CHtmlView();
    void SetText( const char* strText );
    void Clear();
    void ClearTexture();
    //TGETTEXTUREFILECALLBACK OnGetTextureEvent;
    //map<uint32, CTexture*>m_vRichViewTextureList;
};

class CEditBox: public CUIElement{
public:
    //static bool32 CheckInputText( int32 nLen, char* strBuff );
    //static bool32 CheckInputNumber( float fMin, float fMax, float* pRet );
    //static bool32 CheckInputInteger( int32 nMin, int32 nMax, int32* pRet );

    CEditBox( int32 x, int32 y, int32 width, int32 height );
    virtual ~CEditBox();
    virtual int32 ProcessTextEditEvent( int32 nStrFarAddress );
    void SetText( const char* strText );
    void Clear();
    void SetReadOnly( bool32 bValue );
    CUIEvent* OnTextEditEventObject;
};

class CSubScrollPanel: public CUIElement{
public:
    CSubScrollPanel( int32 x, int32 y, int32 width, int32 height );
    virtual ~CSubScrollPanel();
    void SetDataStruct( CUIElement* pElement, int32 nAddress, _EScorllPanelItemDataType eDataType );
};

class CScrollPanel: public CUIElement{
public:
    CScrollPanel( int32 x, int32 y, int32 width, int32 height );
    virtual ~CScrollPanel();
    void SetItemData( void* pItemData, int32 nSubItemSize, int32 nItemCount );
    virtual int32 ProcessSelectEvent( int32 nType, int32 nIndex );
    void SetSelect( int32 nRow );
    int32 GetSelect();
    CUIEvent* OnSelectEventObject;
};



#endif

