#include "PlayState.h"

Enemy m_enemy({ 1100, 500 }, { 100, 500 });

PlayState::PlayState()
{
	m_score = new Score();
}

bool PlayState::OnEnter(Screen& screen)
{
	m_background = std::make_unique<Background>(Background("DarkYellowMoon", screen));

	m_score->Initialise(screen, &m_player);
	m_coin1.Initialise(screen, &objects);
	m_coin2.Initialise(screen, &objects);
	m_platform1.Initialise(screen, &objects);
	m_platform2.Initialise(screen, &objects);
	m_platform3.Initialise(screen, &objects);
	m_player.Initialise(screen, &objects);
	m_enemy.Initialise(screen, &objects);

	objects.push_back(&m_coin1);
	objects.push_back(&m_coin2);
	objects.push_back(&m_platform1);
	objects.push_back(&m_platform2);
	objects.push_back(&m_platform3);
	objects.push_back(&m_player);
	objects.push_back(&m_enemy);

	m_coin1.SetPosition(1000, 140);
	m_coin2.SetPosition(550, 350);
	m_platform1.SetPosition(500, 400);
	m_platform2.SetPosition(950, 200);
	m_platform3.SetPosition(700, 300);
	return true;
}

GameState* PlayState::Update(Input& input)
{
	auto it = std::begin(objects);
	while (it != std::end(objects))
	{
		if ((*it)->IsFlaggedForDeletion())
		{
			it = objects.erase(it);
		}
		else
		{
			(*it)->CheckCollision(objects);
			(*it)->PreUpdate(input);
			++it;
		}
	}
	if (m_player.GetScore() >= maxCoinPoints)
	{
		return new PlayStateLevel2(m_score);
	}
	if (m_player.IsFlaggedForDeletion())
	{
		return new EndScreenState(ConditionState::LOSS);
	}
	// Quiting Game
	if (input.IsKeyDown(SDLK_ESCAPE))
	{
		return 0;
	}
	return this;
}

bool PlayState::Render(Screen& screen)
{
	m_background->Render(screen);
	auto it = std::begin(objects);
	while (it != std::end(objects))
	{
		if ((*it)->IsFlaggedForDeletion())
		{
			it = objects.erase(it);
		}
		else
		{
			(*it)->Render(screen);
			++it;
		}
		m_score->Render(screen);
	}
	return true;
}

void PlayState::OnExit()
{
	m_coin1.ShutDown();
	m_coin2.ShutDown();
	m_enemy.ShutDown();
	m_platform1.ShutDown();
	m_platform2.ShutDown();
	m_player.ShutDown();
	m_background->ShutDown();
}