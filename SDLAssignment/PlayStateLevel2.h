#pragma once
#include "Coin.h"
#include "Enemy.h"
#include "Score.h"
#include "Sprite.h"
#include "Player.h"
#include "Rocket.h"
#include "Platform.h"
#include "GameState.h"
#include "Background.h"
#include "EndScreenState.h"

class PlayStateLevel2 : public GameState
{

public:
	PlayStateLevel2(Player* p);
	// Inherited via GameState
	virtual bool OnEnter(Screen& screen, Input& input);
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;

private:
	Player* m_player;
	Score* m_score;
	Coin m_coin, m_coin2;
	Platform m_platform, m_platform2;

	std::list<GameObject*> objects{};
	std::unique_ptr<Background> m_background;
	std::unique_ptr<Rocket> m_rocket;
};

