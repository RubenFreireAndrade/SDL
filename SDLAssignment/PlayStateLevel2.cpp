#include "PlayStateLevel2.h"

Enemy m_lvl2Enemy({ 1100, 500 }, { 100, 500 });

PlayStateLevel2::PlayStateLevel2(Player* p)
{
	m_player = p;
	m_score = new Score();
}

bool PlayStateLevel2::OnEnter(Screen& screen, Input& input)
{
	m_background = std::make_unique<Background>(Background("Moon", screen));
	m_rocket = std::make_unique<Rocket>();

	m_score->Initialise(screen, m_player);
	m_coin.Initialise(screen, &objects);
	m_coin2.Initialise(screen, &objects);
	m_platform.Initialise(screen, &objects);
	m_platform2.Initialise(screen, &objects);
	m_player->Initialise(screen, &objects, input);
	m_lvl2Enemy.Initialise(screen, &objects);
	m_rocket->Initialise(screen, &objects);

	objects.push_back(&m_coin);
	objects.push_back(&m_coin2);
	objects.push_back(&m_platform);
	objects.push_back(&m_platform2);
	objects.push_back(m_player);
	objects.push_back(&m_lvl2Enemy);
	objects.push_back(&*m_rocket);

	m_coin.SetPosition(450, 140);
	m_coin2.SetPosition(650, 350);
	m_platform.SetPosition(600, 400);
	m_platform2.SetPosition(400, 200);
	m_rocket->SetPosition(1000, 400);
	return true;
}

GameState* PlayStateLevel2::Update(Input& input)
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

	if (m_player->GetScore() >= 9)
	{
		return new EndScreenState(ConditionState::WIN);
	}
	if (m_player->IsFlaggedForDeletion())
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

bool PlayStateLevel2::Render(Screen& screen)
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
		m_rocket->Render(screen);
	}
	return true;
}

void PlayStateLevel2::OnExit()
{
	m_coin.ShutDown();
	m_coin2.ShutDown();
	m_rocket->ShutDown();
	m_background->ShutDown();
}