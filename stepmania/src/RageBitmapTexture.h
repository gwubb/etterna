#ifndef RAGEBITMAPTEXTURE_H
#define RAGEBITMAPTEXTURE_H

/*
-----------------------------------------------------------------------------
 Class: RageBitmapTexture

 Desc: Holder for a static texture with metadata.  Can load just about any image format.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/

#include "RageTexture.h"
#include "RageDisplayInternal.h"

struct SDL_Surface;
class RageBitmapTexture : public RageTexture
{
public:
	RageBitmapTexture( RageTextureID name );
	virtual ~RageBitmapTexture();
	/* only called by RageTextureManager::InvalidateTextures */
	virtual void Invalidate() { m_uGLTextureID = 0; }
	virtual void Reload( RageTextureID name );

private:
	void Create();	// called by constructor and Reload
	unsigned int GetGLTextureID() { return m_uGLTextureID; }
	unsigned int	m_uGLTextureID;

	SDL_Surface *CreateImg(int &pixfmt, GLenum &fmtTexture);
};

#endif
