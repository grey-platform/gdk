#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include <texture.h>
#include <camera.h>
#include <material.h>

extern CCamera *g_pCamera;
extern CMaterialPointer* g_pMaterial;
void InitGraphic( float w, float h );
void BeginRender();
void EndRender();
void SetTranslate( float x, float y );
void SetRotation( float r );
void SetScale( float x, float y );
void SetTexture( CTexture* pTexture );
void SetColor( float r, float g, float b, float a );
void FinalGraphic();

#endif

