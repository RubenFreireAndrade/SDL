#include "PlayState.h"
#include "GameObject.h"

PlayState::PlayState(Player* p)
{
	if (p != nullptr)
	{
		m_player = p;
	}
	else
	{
		m_player = new Player();
	}
}

bool PlayState::OnEnter(Screen& screen, Input& input)
{
	m_screen = screen;
	CreateLevel(screen);

	SpawnObject(m_player);
	return true;
}

void PlayState::CreateLevel(Screen& screen)
{
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
			(*it)->PreUpdate(input, *this);
			++it;
		}
	}

	GameState* stateChange = UpdateStateChange(input);
	if (stateChange != nullptr) return stateChange;

	// Quiting Game
	if (input.IsKeyDown(SDLK_ESCAPE))
	{
		return 0;
	}
	return this;
}

GameState* PlayState::UpdateStateChange(Input& input)
{
	return nullptr;
}

bool PlayState::Render(Screen& screen)
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
			(*it)->Render(screen);
			++it;
		}
	}
	return true;
}

void PlayState::OnExit(Screen& screen, Input& input)
{
	for (auto obj = objects.begin(); obj != objects.end(); obj++)
	{
		(*obj)->ShutDown();
	}
}

void PlayState::SpawnObject(GameObject* gObj)
{
	gObj->Instantiate(m_screen, *this);
	objects.push_back(gObj);
}
