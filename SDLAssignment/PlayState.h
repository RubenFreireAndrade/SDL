#pragma once
#include "Coin.h"
#include "Enemy.h"
#include "Score.h"
#include "Player.h"
#include "Platform.h"
#include "GameState.h"
#include "Background.h"
#include "EndScreenState.h"
#include "PlayStateLevel2.h"

class PlayState : public GameState
{
public: 
	// Inherited via GameState
	PlayState();
	~PlayState() override {}

	virtual bool OnEnter(Screen& screen);
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;

private:

	Score* m_score;
	Player m_player;
	Coin m_coin1, m_coin2;
	Platform m_platform1, m_platform2, m_platform3;

	std::list<GameObject*> objects{};
	std::unique_ptr<Background> m_background;
};

