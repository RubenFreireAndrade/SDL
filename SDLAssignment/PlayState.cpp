#include "PlayState.h"

PlayState::PlayState()
{
}

bool PlayState::OnEnter(Screen& screen)
{
	m_background.Initialise(screen);
	m_coin1.Initialise(screen, &objects);
	m_coin2.Initialise(screen, &objects);
	m_platform1.Initialise(screen, &objects);
	m_platform2.Initialise(screen, &objects);

	objects.push_back(&m_background);
	objects.push_back(&m_coin1);
	objects.push_back(&m_coin2);
	objects.push_back(&m_platform1);
	objects.push_back(&m_platform2);

	m_coin1.SetPosition(750, 140);
	m_coin2.SetPosition(500, 350);
	m_platform1.SetPosition(400, 400);
	m_platform2.SetPosition(650, 200);
	return true;
}

GameState* PlayState::Update(Input& input)
{
	//input.Update();
	//m_background.Update(input);
	auto it = std::begin(objects);
	while (it != std::end(objects))
	{
		//text.RenderScore(screen);

		if ((*it)->IsFlaggedForDeletion())
		{
			it = objects.erase(it);
		}
		else
		{
			(*it)->CheckCollision(objects);
			(*it)->PreUpdate(input);
			//(*it)->Render(screen);
			++it;
		}
	}
	/*if (player.GetScore() >= 4)
	{
		endScreen.RenderEndScreen(screen, 0);
	}*/
	/*else if (player.IsFlaggedForDeletion())
	{
		endScreen.RenderEndScreen(screen, 1);
	}*/
	return this;
}

bool PlayState::Render(Screen& screen)
{
	auto it = std::begin(objects);
	while (it != std::end(objects))
	{
		(*it)->Render(screen);
		//m_background.Render(screen);
		++it;
	}
	/*SDL_SetRenderDrawColor(screen.GetRenderer(), 0, 0, 0, 255);
	SDL_RenderPresent(screen.GetRenderer());*/

	return true;
}

void PlayState::OnExit()
{
}
