#pragma once
#include "Coin.h"
#include "Enemy.h"
#include "Score.h"
#include "Rocket.h"
#include "Platform.h"
#include "PlayState.h"
#include "Background.h"

class EndScreenState;

class Level2 : public PlayState
{
	using PlayState::PlayState;
public:
	virtual void CreateLevel(Screen& screen);
	virtual GameState* UpdateStateChange(Input& input);
};

