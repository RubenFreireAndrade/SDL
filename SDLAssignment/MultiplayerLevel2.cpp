#include "MultiplayerLevel2.h"
#include "EndScreenState.h"

void MultiplayerLevel2::CreateLevel(Screen& screen)
{
	auto background = new Background("Moon", screen);
	auto rocket = new Rocket();
	auto score = new Score();
	auto coin = new Coin();
	auto coin2 = new Coin();
	auto platform = new Platform();
	auto platform2 = new Platform();
	auto enemy = new Enemy({ 1100, 500 }, { 100, 500 });

	score->Initialise(screen, m_player);
	coin->Initialise(screen, &objects);
	coin2->Initialise(screen, &objects);
	platform->Initialise(screen, &objects);
	platform2->Initialise(screen, &objects);
	enemy->Initialise(screen, &objects);
	rocket->Initialise(screen, &objects);

	objects.push_back(background);
	objects.push_back(score);
	objects.push_back(coin);
	objects.push_back(coin2);
	objects.push_back(platform);
	objects.push_back(platform2);
	objects.push_back(enemy);
	objects.push_back(rocket);

	coin->SetPosition(450, 140);
	coin2->SetPosition(650, 350);
	platform->SetPosition(600, 400);
	platform2->SetPosition(400, 200);
	rocket->SetPosition(1000, 400);
}

GameState* MultiplayerLevel2::UpdateStateChange(Input& input)
{
	if (m_player->GetScore() >= 9)
	{
		return new EndScreenState(ConditionState::WIN);
	}
	if (m_player->IsFlaggedForDeletion())
	{
		return new EndScreenState(ConditionState::LOSS);
	}
	return nullptr;
}