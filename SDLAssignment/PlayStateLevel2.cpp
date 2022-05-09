#include "PlayStateLevel2.h"

Enemy m_lvl2Enemy({ 1100, 470 }, { 100, 470 });

PlayStateLevel2::PlayStateLevel2()
{
}

bool PlayStateLevel2::OnEnter(Screen& screen)
{
	m_background = std::make_unique<Background>(Background("Moon", screen));
	m_score = std::make_unique<Score>();

	m_score->Initialise(screen, &m_player);
	m_coin.Initialise(screen, &objects);
	m_coin2.Initialise(screen, &objects);
	m_platform.Initialise(screen, &objects);
	m_platform2.Initialise(screen, &objects);
	m_player.Initialise(screen, &objects);
	m_lvl2Enemy.Initialise(screen, &objects);

	m_rocket.Load("Assets/Images/rocket.png", screen);
	m_rocket.SetImageDimension(1, 1, 512, 512);
	m_rocket.SetSpriteDimension(100, 100);

	objects.push_back(&m_coin);
	objects.push_back(&m_coin2);
	objects.push_back(&m_platform);
	objects.push_back(&m_platform2);
	objects.push_back(&m_player);
	objects.push_back(&m_lvl2Enemy);

	m_coin.SetPosition(500, 140);
	m_coin2.SetPosition(650, 350);
	m_platform.SetPosition(600, 400);
	m_platform2.SetPosition(400, 200);
	return true;
}

GameState* PlayStateLevel2::Update(Input& input)
{
	input.Update();
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
	if (m_player.GetScore() >= 4)
	{
		return new EndScreenState(ConditionState::WIN);
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
		m_rocket.Render(0, 0, screen, m_rocket.NO_FLIP);
	}
	return true;
}

void PlayStateLevel2::OnExit()
{
	m_background->ShutDown();
}