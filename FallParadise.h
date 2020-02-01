// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 spacewar.h v1.0

#ifndef _FallParadise_H             // Prevent multiple definitions if this 
#define _FallParadise_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "planet.h"
#include "player.h"

//=============================================================================
// This class is the core of the game
//=============================================================================
class FallParadise : public Game
{
private:
	// game items
	TextureManager nebulaTexture;   // nebula texture
	TextureManager gameTextures;    // game texture
	Player  player;           // player
	Planet  planet;         // the planet
	Image   nebula;         // backdrop image

public:
	// Constructor
	FallParadise();

	// Destructor
	virtual ~FallParadise();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
};

#endif
