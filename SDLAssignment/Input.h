#pragma once
#include <SDL.h>
#include <list>
#include <iostream>

#include "Vector2D.h"

class Input
{

public:

	Input();
	void Update();

	bool IsKeyUp(char key);
	bool IsKeyDown(char key);

	int GetMouseButtonUp();
	int GetMouseButtonDown();

	bool IsKeyPressed();
	bool IsMouseClicked();
	bool IsWindowClosed();

	Vector2D& GetMousePosition();
	std::string GetInput();

private:

	std::list<char> m_keys;

	bool m_isMouseClicked;
	bool m_isWindowClosed;

	int m_mouseButtonUp;
	int m_mouseButtonDown;

	Vector2D m_mousePosition;
};
