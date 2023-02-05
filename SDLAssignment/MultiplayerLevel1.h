#pragma once
#include "Coin.h"
#include "Enemy.h"
#include "Score.h"
#include "Platform.h"
#include "Background.h"
#include "MultiplayerState.h"

class EndScreenState;

class MultiplayerLevel1 : public MultiplayerState
{
	using MultiplayerState::MultiplayerState;

public:
	virtual void CreateLevel(Screen& screen);
	virtual GameState* UpdateStateChange(Input& input);
};