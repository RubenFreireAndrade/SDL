#pragma once
#include "GameState.h"
#include "EndScreenState.h"
#include "WriteToScreen.h"
#include "Background.h"
#include "Coin.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"

class PlayState : public GameState
{
public: 
	PlayState();

	// Inherited via GameState
	~PlayState() override {}

	virtual bool OnEnter(Screen& screen);
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;

private:

	Background m_background;
	Coin m_coin1, m_coin2;
	Player m_player;
	Platform m_platform1, m_platform2;
	WriteToScreen m_writeToScreen;

	std::list<GameObject*> objects{};
};

