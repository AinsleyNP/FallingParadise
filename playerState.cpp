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
	
	if (input->wasKeyPressed(VK_SPACE)) 
	{
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
	player.setDeltaV(VECTOR2(0, 200));
}
void jumpingState::updateState(Player& player)
{
	
}