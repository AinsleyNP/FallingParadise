//#pragma once
//
//#ifndef _playerState_H                 // Prevent multiple definitions if this 
//#define _playerState_H                 // file is included in more than one place
//#define WIN32_LEAN_AND_MEAN
//#include "player.h"
//
//// defining playerStates
//class playerState
//{
//private:
//	playerState* state_;
//public:
//	static playerstand stand;
//	static playerjump jump;
//	virtual ~playerState() {}
//	virtual void handleInput(Player*& player, Input* input)
//	{
//		playerState* state = state_->handleInput(player, input);
//		if (state != NULL)
//		{
//			delete state_;
//			state_ = state;
//		}
//
//	}
//	virtual void update(Player*& player)
//	{
//		state_->update(player);
//	}
//};
//class playerstand : public playerState
//{
//public:
//	virtual void handleInput(Player*& player, Input* input)
//	{
//		if (input->isKeyDown(VK_SPACE))
//		{
//
//			//jump
//		}
//		//other codes
//	}
//
//};
//
//class playerjump : public playerState
//{
//
//};
//#endif