#pragma once
#include <SDL.h>
#include <list>
#include <map>
#include <iostream>
#include <functional>

#include "Vector2D.h"

class Input
{

public:

	Input();
	void Update();
	void RegisterKeyBind(char key, std::function<void()> bind);
	void RegisterAnyKeyBind(std::function<void(char)> bind);

	bool IsKeyUp(char key);
	bool IsKeyDown(char key);

	int GetMouseButtonUp();
	int GetMouseButtonDown();

	bool IsKeyPressed();
	bool IsMouseClicked();
	bool IsWindowClosed();

	Vector2D& GetMousePosition();

private:

	std::list<char> m_keys;
	std::list<std::function<void(char)>> m_onAnyKeyBinds;
	std::map<char, std::list<std::function<void()>>> m_keyBinds;

	bool m_isMouseClicked;
	bool m_isWindowClosed;

	int m_mouseButtonUp;
	int m_mouseButtonDown;

	Vector2D m_mousePosition;
};
