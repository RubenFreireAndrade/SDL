#pragma once
#include "Coin.h"
#include "Enemy.h"
#include "Score.h"
#include "Sprite.h"
#include "Player.h"
#include "Platform.h"
#include "GameState.h"
#include "Background.h"
#include "EndScreenState.h"

class PlayStateLevel2 : public GameState
{

public:
	PlayStateLevel2();
	// Inherited via GameState
	virtual bool OnEnter(Screen& screen);
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;

private:
	Sprite m_rocket;
	Player m_player;
	Coin m_coin, m_coin2;
	Platform m_platform, m_platform2;

	std::list<GameObject*> objects{};
	std::unique_ptr<Background> m_background;
	std::unique_ptr<Score> m_score;
};

