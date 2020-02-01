
#include "player.h"



class playerstand : public playerState
{
public:
	virtual void handleInput(Player*& player, Input* input)
	{
		if (input->isKeyDown(VK_SPACE))
		{
			player->state_ = &(playerState.jump);
			//jump
		}
		//other codes
	}

};

class playerjump : public playerState
{

};

//==========================================================================================================================================================
//==========================================================================================================================================================
// default constructor
//==========================================================================================================================================================
//==========================================================================================================================================================
Player::Player() : Entity()
{
    spriteData.width = PlayerNS::WIDTH;           // size of Ship1
    spriteData.height = PlayerNS::HEIGHT;
    spriteData.x = PlayerNS::X;                   // location on screen
    spriteData.y = PlayerNS::Y;
    spriteData.rect.bottom = PlayerNS::HEIGHT;    // rectangle to select parts of an image
    spriteData.rect.right = PlayerNS::WIDTH;
    velocity.x = 0;                             // velocity X
    velocity.y = 0;                             // velocity Y
    frameDelay = PlayerNS::PLAYER_ANIMATION_DELAY;
    startFrame = PlayerNS::PLAYER_START_FRAME;     // first frame of ship animation
    endFrame     = PlayerNS::PLAYER_END_FRAME;     // last frame of ship animation
    currentFrame = startFrame;
    radius = PlayerNS::WIDTH/2.0;
    shieldOn = false;
    mass = PlayerNS::MASS;
    collisionType = entityNS::CIRCLE;
}

//=============================================================================
// Initialize the Ship.
// Post: returns true if successful, false if failed
//=============================================================================
bool Player::initialize(Game *gamePtr, int width, int height, int ncols,
    TextureManager *textureM)
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
	//Movement
	//======================================================================================
	if (input->isKeyDown(VK_LEFT)) // Move left
	{
		spriteData.x -= frameTime * 2 * velocity.x;         // move player along x
	}
	if (input->isKeyDown(VK_RIGHT)) // Move right
	{
		spriteData.x += frameTime * 2 * velocity.x;         // move player along x
	}

	// Screen movement restriction
	//===============================================================================
	if (spriteData.x < 0)
	{
		spriteData.x=0;
	}
	if (spriteData.x > GAME_WIDTH - spriteData.width)
	{
		spriteData.x = GAME_WIDTH - spriteData.width;
	}

    Entity::update(frameTime);
	
	//// Bounce off walls
 //   if (spriteData.x > GAME_WIDTH- PlayerNS::WIDTH)    // if hit right screen edge
 //   {
 //       spriteData.x = GAME_WIDTH- PlayerNS::WIDTH;    // position at right screen edge
 //       velocity.x = -velocity.x;                   // reverse X direction
 //   } else if (spriteData.x < 0)                    // else if hit left screen edge
 //   {
 //       spriteData.x = 0;                           // position at left screen edge
 //       velocity.x = -velocity.x;                   // reverse X direction
 //   }
 //   if (spriteData.y > GAME_HEIGHT- PlayerNS::HEIGHT)  // if hit bottom screen edge
 //   {
 //       spriteData.y = GAME_HEIGHT- PlayerNS::HEIGHT;  // position at bottom screen edge
 //       velocity.y = -velocity.y;                   // reverse Y direction
 //   } else if (spriteData.y < 0)                    // else if hit top screen edge
 //   {
 //       spriteData.y = 0;                           // position at top screen edge
 //       velocity.y = -velocity.y;                   // reverse Y direction
 //   }
}

//=============================================================================
// damage
//=============================================================================
void Player::damage(WEAPON weapon)
{

}

