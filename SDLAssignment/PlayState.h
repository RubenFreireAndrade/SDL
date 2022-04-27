#pragma once
#include "GameState.h"
#include "EndScreenState.h"
#include "Background.h"
#include "Coin.h"
#include "Platform.h"
#include "Player.h"
#include "Enemy.h"
#include "Score.h"

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

	Score m_score;
	Player m_player;
	Coin m_coin1, m_coin2;
	Platform m_platform1, m_platform2;

	std::list<GameObject*> objects{};
	std::unique_ptr<Background> m_background;
};

