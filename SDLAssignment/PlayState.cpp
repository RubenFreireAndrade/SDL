#include "PlayState.h"

Enemy m_enemy({ 1100, 470 }, { 100, 470 });

PlayState::PlayState()
{
}

bool PlayState::OnEnter(Screen& screen)
{
	m_score = std::make_unique<Score>();

	m_background.Initialise(screen);
	m_coin1.Initialise(screen, &objects);
	m_coin2.Initialise(screen, &objects);
	m_platform1.Initialise(screen, &objects);
	m_platform2.Initialise(screen, &objects);
	m_player.Initialise(screen, &objects);
	m_enemy.Initialise(screen, &objects);

	objects.push_back(&m_background);
	objects.push_back(&m_coin1);
	objects.push_back(&m_coin2);
	objects.push_back(&m_platform1);
	objects.push_back(&m_platform2);
	objects.push_back(&m_player);
	objects.push_back(&m_enemy);

	m_coin1.SetPosition(750, 140);
	m_coin2.SetPosition(500, 350);
	m_platform1.SetPosition(400, 400);
	m_platform2.SetPosition(650, 200);
	return true;
}

GameState* PlayState::Update(Input& input)
{
	input.Update();
	m_background.Update(input);
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

bool PlayState::Render(Screen& screen)
{
	auto it = std::begin(objects);
	while (it != std::end(objects))
	{
		m_score->Render(screen);
		if ((*it)->IsFlaggedForDeletion())
		{
			it = objects.erase(it);
		}
		else
		{
			(*it)->Render(screen);
			++it;
		}
	}
	return true;
}

void PlayState::OnExit()
{
	
}