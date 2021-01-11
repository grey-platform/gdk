/*********************************************************************************
*Copyright,2018-2028,Longyou
*FileName: translatematerial.h
*Module: standard
*Author: DaXiang
*Version: 1.0
*Date: 2020
*Description:
*Others:
*Function List:
*History:
**********************************************************************************/


#ifndef __STANDARD_TRANSLATEMATERIAL_H__
#define __STANDARD_TRANSLATEMATERIAL_H__

#include <include/stdtype.h>
#include <standard/material.h>
#include <include/math.h>

//BeginClass( CTranslateMatieral )
//#define CTranslateMatieral__Data \
//CMatieral__Data \
//HMATERIALUNIFORM m_nUniformProjectionViewMatrix;\
//HMATERIALUNIFORM m_nUniformModelMatrix;\
//HMATERIALUNIFORM m_nUniformPosition;\
//HMATERIALUNIFORM m_nUniformRotation;\
//HMATERIALUNIFORM m_nUniformScale;\
//HMATERIALUNIFORM m_nUniformDiffuseColor;\
//HMATERIALUNIFORM m_nUniformDiffuseMap;
//#define CTranslateMatieral__Func \
//CMatieral__Func \
//MemberFunc( CTranslateMatieral, Init )\
//MemberFunc( CTranslateMatieral, SetProjViewMatrix )\
//MemberFunc( CTranslateMatieral, SetModelMatrix )\
//MemberFunc( CTranslateMatieral, SetTranslate )\
//MemberFunc( CTranslateMatieral, SetRotation )\
//MemberFunc( CTranslateMatieral, SetScale )\
//MemberFunc( CTranslateMatieral, SetTexture )\
//MemberFunc( CTranslateMatieral, SetColor )
//DeclareFunc0( CTranslateMatieral, Init, bool32 )
//DeclareFunc1( CTranslateMatieral, SetProjViewMatrix, bool32, Matrix4 )
//DeclareFunc1( CTranslateMatieral, SetModelMatrix, bool32, Matrix4 )
//DeclareFunc2( CTranslateMatieral, SetTranslate, bool32, float, float )
//DeclareFunc1( CTranslateMatieral, SetRotation, bool32, float )
//DeclareFunc2( CTranslateMatieral, SetScale, bool32, float, float )
//DeclareFunc1( CTranslateMatieral, SetTexture, bool32, HTEXTUREHANDLE )
//DeclareFunc4( CTranslateMatieral, SetColor, bool32, float, float, float, float )
//EndClass( CTranslateMatieral )


////
////
////DeclareClass( CTranslateMatieral )
////DeclareFunc0( CTranslateMatieral, Init, bool32 )
////DeclareFunc0( CTranslateMatieral, Begin, bool32 )
////DeclareFunc0( CTranslateMatieral, End, bool32 )
////DeclareFunc1( CTranslateMatieral, SetProjViewMatrix, bool32, Matrix4 )
////DeclareFunc1( CTranslateMatieral, SetModelMatrix, bool32, Matrix4 )
////DeclareFunc2( CTranslateMatieral, SetTranslate, bool32, float, float )
////DeclareFunc1( CTranslateMatieral, SetRotation, bool32, float )
////DeclareFunc2( CTranslateMatieral, SetScale, bool32, float, float )
////DeclareFunc1( CTranslateMatieral, SetTexture, bool32, HTEXTUREHANDLE )
////DeclareFunc4( CTranslateMatieral, SetColor, bool32, float, float, float, float )
////
////
//////---------------------------------------------------------------------
////ClassBegin( CTranslateMatieral, CMatierlaObj )
////HMATERIALUNIFORM m_nUniformProjectionViewMatrix;
////HMATERIALUNIFORM m_nUniformModelMatrix;
////HMATERIALUNIFORM m_nUniformPosition;
////HMATERIALUNIFORM m_nUniformRotation;
////HMATERIALUNIFORM m_nUniformScale;
////HMATERIALUNIFORM m_nUniformDiffuseColor;
////HMATERIALUNIFORM m_nUniformDiffuseMap;
////DefineMember( CTranslateMatieral, Init )
////DefineMember( CTranslateMatieral, Begin )
////DefineMember( CTranslateMatieral, End )
////DefineMember( CTranslateMatieral, SetProjViewMatrix )
////DefineMember( CTranslateMatieral, SetModelMatrix )
////DefineMember( CTranslateMatieral, SetTranslate )
////DefineMember( CTranslateMatieral, SetRotation )
////DefineMember( CTranslateMatieral, SetScale )
////DefineMember( CTranslateMatieral, SetTexture )
////DefineMember( CTranslateMatieral, SetColor )
////ClassEnd( CTranslateMatieral, CMatierlaObj )


#endif

