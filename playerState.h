// MachineStates.h
#pragma once

#include "player.h"
#include <exception>
#include <stdexcept>

class Player;

class PlayerState
{
public:
	virtual void handleInput(Player& player, Input* input) = 0;
	virtual void updateState(Player& player);
	virtual ~PlayerState();
protected:
	void setState(Player& player, PlayerState* st);
};

class standingState : public PlayerState
{
public:
	virtual void handleInput(Player& player, Input* input);
	virtual void updateState(Player& player);
	virtual ~standingState();
};

class jumpingState : public PlayerState
{
public:
	virtual void handleInput(Player& player, Input* input);
	virtual void updateState(Player& player);
	virtual ~jumpingState();
};