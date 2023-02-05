#include "Level1.h"
#include "Level2.h"
#include "EndScreenState.h"

void Level1::CreateLevel(Screen& screen)
{
	auto background = new Background("DarkYellowMoon", screen);
	auto score = new Score();
	auto coin1 = new Coin();
	auto coin2 = new Coin();
	auto platform1 = new Platform();
	auto platform2 = new Platform();
	auto platform3 = new Platform();
	auto enemy = new Enemy({ 1100, 500 }, { 100, 500 });

	score->Initialise(screen, m_player);
	coin1->Initialise(screen, &objects);
	coin2->Initialise(screen, &objects);
	platform1->Initialise(screen, &objects);
	platform2->Initialise(screen, &objects);
	platform3->Initialise(screen, &objects);
	enemy->Initialise(screen, &objects);

	objects.push_back(background);
	objects.push_back(score);
	objects.push_back(coin1);
	objects.push_back(coin2);
	objects.push_back(platform1);
	objects.push_back(platform2);
	objects.push_back(platform3);
	objects.push_back(enemy);

	coin1->SetPosition(1000, 140);
	coin2->SetPosition(550, 550);
	platform1->SetPosition(500, 400);
	platform2->SetPosition(950, 200);
	platform3->SetPosition(700, 300);
}

GameState* Level1::UpdateStateChange(Input& input)
{
	if (m_player->GetScore() >= maxCoinPoints)
	{
		return new Level2(m_player);
	}
	if (m_player->IsFlaggedForDeletion())
	{
		return new EndScreenState(ConditionState::LOSS);
	}
	return nullptr;
}
