#include "Input.h"
#include "Sprite.h"

Input::Input()
{
	m_isMouseClicked = false;
	m_isWindowClosed = false;
	m_mouseButtonUp = 0;
	m_mouseButtonDown = 0;
}

int Input::GetMouseButtonUp()
{
	return m_mouseButtonUp;
}

int Input::GetMouseButtonDown()
{
	return m_mouseButtonDown;
}

bool Input::IsKeyPressed()
{
	return m_keys.size() > 0;
}

bool Input::IsMouseClicked()
{
	return m_isMouseClicked;
}

bool Input::IsWindowClosed()
{
	return m_isWindowClosed;
}

Vector2D& Input::GetMousePosition()
{
	return m_mousePosition;
}

std::string Input::GetInput()
{
	std::string str = "";
	for (auto it = m_keys.begin(); it != m_keys.end(); it++)
	{
		str += *it;
	}
	return str;
}

void Input::Update()
{
	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		if (events.type == SDL_QUIT)
		{
			m_isWindowClosed = true;
		}

		else if (events.type == SDL_KEYDOWN) //Key has been pressed.
		{
			auto input = events.key.keysym.sym;
			m_keys.push_back(input);
			std::cout << "down" << input << std::endl;
		}

		else if (events.type == SDL_KEYUP) //Key has been released.
		{
			auto input = events.key.keysym.sym;
			auto k = std::begin(m_keys);
			while (k != std::end(m_keys))
			{
				if (*k == input)
				{
					k = m_keys.erase(k);
				}
				else
				{
					++k;
				}
			}
			std::cout << "up" << input << std::endl;
		}

		else if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			m_isMouseClicked = true;
			m_mouseButtonDown = events.button.button;
		}

		else if (events.type == SDL_MOUSEBUTTONUP)
		{
			m_isMouseClicked = false;
			m_mouseButtonUp = events.button.button;
		}

		else if (events.type == SDL_MOUSEMOTION)
		{
			m_mousePosition.x = events.motion.x;
			m_mousePosition.y = events.motion.y;
		}
	}
}

bool Input::IsKeyUp(char key)
{
	bool result = true;
	auto k = std::begin(m_keys);

	while (k != std::end(m_keys))
	{
		if (*k == key)
		{
			result = false;
		}
		++k;
	}
	return result;
}

bool Input::IsKeyDown(char key)
{
	bool result = false;
	auto k = std::begin(m_keys);

	while (k != std::end(m_keys))
	{
		if (*k == key)
		{
			result = true;
		}
		++k;
	}
	return result;
}
