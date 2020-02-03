// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Draw animated spaceships with collision and shield
// Chapter 6 spacewar.cpp v1.0
// This class is the core of the game

#include "FallParadise.h"

//=============================================================================
// Constructor
//=============================================================================
FallParadise::FallParadise()
{}

//=============================================================================
// Destructor
//=============================================================================
FallParadise::~FallParadise()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void FallParadise::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError

	// nebula texture
	if (!nebulaTexture.initialize(graphics, NEBULA_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula texture"));

	// main game textures
	if (!gameTextures.initialize(graphics, TEXTURES_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing game textures"));

	// nebula image
	if (!nebula.initialize(graphics, 0, 0, 0, &nebulaTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing nebula"));

	// planet
	if (!planet.initialize(this, planetNS::WIDTH, planetNS::HEIGHT, 2, &gameTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing planet"));

	// player
	if (!player.initialize(this, PlayerNS::WIDTH, PlayerNS::HEIGHT, PlayerNS::TEXTURE_COLS, &gameTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Player"));
	player.setFrames(PlayerNS::PLAYER_START_FRAME, PlayerNS::PLAYER_END_FRAME);
	player.setCurrentFrame(PlayerNS::PLAYER_START_FRAME);
	player.setX(GAME_WIDTH / 4);
	player.setY(GAME_HEIGHT / 4);
	player.setVelocity(VECTOR2(PlayerNS::SPEED, -PlayerNS::SPEED)); // VECTOR2(X, Y)
	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void FallParadise::update()
{

	planet.update(frameTime);
	player.update(frameTime);
}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void FallParadise::ai()
{}

//=============================================================================
// Handle collisions
//=============================================================================
void FallParadise::collisions()
{
	VECTOR2 collisionVector;
	// if collision between ship and planet
	if (player.collidesWith(planet, collisionVector))
	{
	}
}

//=============================================================================
// Render game items
//=============================================================================
void FallParadise::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	nebula.draw();                          // add the orion nebula to the scene
	planet.draw();                          // add the planet to the scene
	player.draw();                           // add the spaceship to the scene

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void FallParadise::releaseAll()
{
	nebulaTexture.onLostDevice();
	gameTextures.onLostDevice();
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void FallParadise::resetAll()
{
	gameTextures.onResetDevice();
	nebulaTexture.onResetDevice();
	Game::resetAll();
	return;
}
