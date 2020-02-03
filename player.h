// Programming 2D Games
// Copyright (c) 2011 by: 
// Charles Kelly
// Chapter 6 ship.h v1.0

#ifndef _Player_H                 // Prevent multiple definitions if this 
#define _Player_H                 // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "entity.h"
#include "constants.h"

namespace PlayerNS
{
	const int WIDTH = 32;                   // image width
	const int HEIGHT = 32;                  // image height
	const int X = GAME_WIDTH / 2 - WIDTH / 2;   // location on screen
	const int Y = GAME_HEIGHT / 2 - HEIGHT / 2;
	const float ROTATION_RATE = (float)PI / 4; // radians per second
	const float SPEED = 200;                // 100 pixels per second
	const float MASS = 300.0f;              // mass
	const int   TEXTURE_COLS = 8;           // texture has 8 columns
	const int   PLAYER_START_FRAME = 0;      // ship1 starts at frame 0
	const int   PLAYER_END_FRAME = 3;        // ship1 animation frames 0,1,2,3
	const int	PLAYER_ANIMATION_DELAY = 0.7;
}

// inherits from Entity class
class Player : public Entity
{
private:
	bool    shieldOn;
	Image   shield;

public:
	// constructor
	Player();

	// inherited member functions
	virtual void draw();
	virtual bool initialize(Game* gamePtr, int width, int height, int ncols,
		TextureManager* textureM);
	void update(float frameTime);
	void damage(WEAPON);

	//virtual void handleInput(Input* input)
	//{
	//	state_->handleInput(this, input);
	//}
	//virtual void update()
	//{
	//	state_->update(this);
	//}


};




#endif

