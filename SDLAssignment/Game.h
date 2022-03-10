#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "GameState.h"
#include "Screen.h"
#include "Music.h"
#include "Input.h"

class Game
{
public:

	Game(GameState* initialState);
	bool Initialize();
	bool Run();
	void Shutdown();

private:
	Screen m_screen;
	Music m_music;
	Input m_input;
	std::unique_ptr<GameState> m_gameState;
};

