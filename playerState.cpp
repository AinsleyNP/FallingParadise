#include "playerState.h"


//=============================================================================
// States
//=============================================================================

PlayerState::~PlayerState() {}

void PlayerState::setState(Player& player, PlayerState* state) {
	PlayerState* aux = player.state_;
	player.state_ = state;
	delete aux;
}

void PlayerState::updateState(Player& player) {}


// Standing State
standingState::~standingState(){}

void standingState::handleInput(Player& player, Input* input)
{
	if (input->isKeyDown(VK_SPACE)) 
	{
		player.setX(100);
		setState(player, new jumpingState());
	}
}
void standingState::updateState(Player& player)
{

}

//Jumping State
jumpingState::~jumpingState() {}

void jumpingState::handleInput(Player& player, Input* input) 
{

}
void jumpingState::updateState(Player& player)
{
	player.setDeltaV(VECTOR2(0, 200));
	float X = player.getX();
	if (X==0)
	{
		setState(player, new standingState());
	}

}