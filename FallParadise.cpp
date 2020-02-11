
#include "FallParadise.h"
#include <vector>
#include <time.h>

using namespace FallingParadiseNS;

//=============================================================================
// Constructor
//=============================================================================
FallParadise::FallParadise()
{
	mapX = 0;
	mapY = -GAME_HEIGHT;
}

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

	// main menu texture
	if (!mainMenuTexture.initialize(graphics, MAINMENU_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing main menu texture"));

	// main menu image
	if (!mainMenu.initialize(graphics, 0, 0, 0, &mainMenuTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing main menu"));
	// place main menu in center of screen
	mainMenu.setX(GAME_WIDTH * 0.5f - mainMenu.getWidth() * 0.5f);
	mainMenu.setY(GAME_HEIGHT * 0.5f - mainMenu.getHeight() * 0.5f);

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

	// map textures
	if (!tileTextures.initialize(graphics, TILE_TEXTURES))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing tile textures"));
	
	// tile image
	if (!tile.initialize(graphics, TEXTURE_SIZE, TEXTURE_SIZE, TEXTURE_COLS, &tileTextures))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing tile"));
	tile.setVisible(true);
	tile.setFrames(0, 0);
	tile.setCurrentFrame(0);
}

//=============================================================================
// Update all game items
//=============================================================================
void FallParadise::update()
{
	float playerX;
	float playerY;
	float scrollspeed = -200;
	

	// SCROLLING STUFF
	if (mapY >= GAME_HEIGHT)
	{
		mapY = -TEXTURE_SIZE * MAP_HEIGHT;
	}

	// Vertical "Scrolling"
	playerY = player.getY();
	if (playerY < GAME_HEIGHT / 2)
	{
		if (input->isKeyDown(VK_UP))
		{
			mapY -= scrollspeed * frameTime;
		}
		else
		{
			mapY -= scrollspeed * frameTime;
		}
	}
	else
	{
		mapY -= scrollspeed * frameTime;
	}

	// checks for return key press
	// game starts if key pressed
	if (input->wasKeyPressed(VK_RETURN))
	{
		menu = false;
	}
	// checks for escape key press
	// game application quits if key pressed
	if (input->wasKeyPressed(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}
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
	// if collision between player and "platform"
	if (player.collidesWith(planet, collisionVector))
	{
		player.bounce(collisionVector,planet);
	}
}

//=============================================================================
// Render game items
//=============================================================================
void FallParadise::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	// DRAW "TILES"
	for (int col = 0; col < MAP_WIDTH; col++)       // for each column of map
	{
		tile.setX((float)(col * TEXTURE_SIZE));	// set tile X
		for (int row = 0; row < MAP_HEIGHT; row++)    // for each row of map
		{
			if (tileMap[row][col] >= 0)          // if tile present
			{
				tile.setCurrentFrame(tileMap[row][col]);    // set tile texture
				tile.setY((float)(row * TEXTURE_SIZE) + mapY);   // set tile Y
				// if tile on screen
				if (tile.getY() > -TEXTURE_SIZE && tile.getY() < GAME_HEIGHT)
					tile.draw();
			}
		}
	}

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
	tileTextures.onLostDevice();
	mainMenuTexture.onLostDevice();

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
	tileTextures.onResetDevice();
	mainMenuTexture.onResetDevice();
	Game::resetAll();
	return;
}
