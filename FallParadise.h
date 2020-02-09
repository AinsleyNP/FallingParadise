
#ifndef _FallParadise_H             // Prevent multiple definitions if this 
#define _FallParadise_H             // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"
#include "planet.h"
#include "player.h"

namespace FallingParadiseNS
{
	const int TEXTURE_SIZE = 128;
	const int TEXTURE_COLS = 4;
	const int MAP_HEIGHT = 15;
	const int MAP_WIDTH = 5;
	const float SCROLL_RATE = 10;
	const int __ = -1;                  // empty tile

	const int tileMap[MAP_HEIGHT][MAP_WIDTH] = { // TILEMAP
		3,__,__,1,__,		//Starting row
		__,__,3,__,__,
		__,__,__,__,__,
		__,0,__,__,__,
		__,__,__,__,__,	//Row 5
		__,__,2,__,__,
		__,__,1,__,2,
		__,__,__,__,__,
		__,0,__,__,__,
		__,__,__,__,__,	//Row 10
		__,__,__,1,__,
		__,__,__,__,__,
		__,__,2,__,__,
		__,1,__,__,__,
		0,__,__,__,3		//Row 15
	};
}
//=============================================================================
// This class is the core of the game
//=============================================================================
class FallParadise : public Game
{
private:
	// game items
	TextureManager nebulaTexture;   // nebula texture
	TextureManager gameTextures;    // game texture
	TextureManager tileTextures;
	Player  player;           // player
	Planet  planet;         // the planet
	Image   nebula;         // backdrop image
	Image tile;
	float mapX;
	float mapY;
	
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
