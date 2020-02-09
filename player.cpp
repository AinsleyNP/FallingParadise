
#include "player.h"

Player::~Player()
{
}

float Yaccel = 0;
//==========================================================================================================================================================
//==========================================================================================================================================================
// default constructor
//==========================================================================================================================================================
//==========================================================================================================================================================
Player::Player() : Entity()
{
	spriteData.width = PlayerNS::WIDTH;           // size of player
	spriteData.height = PlayerNS::HEIGHT;
	spriteData.x = PlayerNS::X;                   // location on screen
	spriteData.y = PlayerNS::Y;
	spriteData.rect.bottom = PlayerNS::HEIGHT;    // rectangle to select parts of an image
	spriteData.rect.right = PlayerNS::WIDTH;
	velocity.x = 0;                             // velocity X
	velocity.y = 0;                             // velocity Y
	frameDelay = PlayerNS::PLAYER_ANIMATION_DELAY;
	startFrame = PlayerNS::PLAYER_START_FRAME;     // first frame of player animation
	endFrame = PlayerNS::PLAYER_END_FRAME;     // last frame of player animation
	currentFrame = startFrame;
	radius = PlayerNS::WIDTH / 2.0;
	shieldOn = false;
	mass = PlayerNS::MASS;
	collisionType = entityNS::CIRCLE;
	state_=(new standingState);
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Player::initialize(Game* gamePtr, int width, int height, int ncols,
	TextureManager* textureM)
{
	return(Entity::initialize(gamePtr, width, height, ncols, textureM));
}

//=============================================================================
// draw the ship
//=============================================================================
void Player::draw()
{
	Image::draw();              // draw ship

}

//=============================================================================
// update
// typically called once per frame
// frameTime is used to regulate the speed of movement and animation
//=============================================================================
void Player::update(float frameTime)
{
	float vely;
	vely = velocity.y;
	float velx;
	velx = velocity.x ;

	// Screen movement restriction
	//===============================================================================
	if (spriteData.x < 0)
	{
		spriteData.x = 0;
	}
	if (spriteData.x > GAME_WIDTH - spriteData.width)
	{
		spriteData.x = GAME_WIDTH - spriteData.width;
	}

	if (spriteData.y < 0)
	{
		spriteData.y = 0;
	}

	if (spriteData.y > GAME_HEIGHT - spriteData.height) //Ported into states
	{
		spriteData.y = GAME_HEIGHT - spriteData.height;
		velocity.y = -PlayerNS::SPEED;
		deltaV.y = 0;
		Yaccel = 0;
		vely = 0;
	}

	//Horizontal Movement		--- to be changed to changing velocity instead of sprite position -- Ported into states
	//======================================================================================
	if (input->isKeyDown(VK_LEFT)) // Move left
	{
		velx -= 100;         // move player along x
	}
	else if (input->isKeyDown(VK_RIGHT)) // Move right
	{
		velx += 100;         // move player along x
	}
	else
	{
		velx = 0;
	}

	//Vertical Movement / Gravity   --- DeltaV.y = acceleration	 --- Will be ported into states
	//======================================================================================

	if (input->isKeyDown(VK_DOWN))
	{
		Yaccel -= 200 * frameTime;
	}

	if (vely==0) // "AT REST"
	{
		if (input->wasKeyPressed(VK_UP)) //Jump
		{
			Yaccel += 5000*frameTime;
		}
	}
	if (Yaccel != 0)
	{
		Yaccel -= 1;
		if (velocity.y <-750)	// Terminal Velocity
		{
			vely = -750;
			Yaccel = 0;
		}
		else					//Gravity
		{
			deltaV.y = Yaccel;
		}
	}


	//Movement based on velocity
	spriteData.x += frameTime * velx;
	spriteData.y -= frameTime * (vely);

	Entity::update(frameTime);

}

//=============================================================================
// damage
//=============================================================================
void Player::damage(WEAPON weapon)
{

}

void Player::handleInput(Player*& player, Input* input)
{
	state_->handleInput(*this, input);
}

void Player::updateState(Player*& player)	//From Player
{
	state_->updateState(*this);				//From PlayerState
}
