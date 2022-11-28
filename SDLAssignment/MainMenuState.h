#pragma once
#include <memory>
#include <vector>
#include "Music.h"
#include "Screen.h"
#include "GameState.h"
#include "PlayState.h"
#include "Background.h"
#include "MenuButton.h"
#include "Multiplayer.h"
#include "TextToScreen.h"

class MainMenuState : public GameState
{
public:
	MainMenuState();
	~MainMenuState();
	// Inherited via GameState
	virtual bool OnEnter(Screen& screen);
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;

private:
	Music m_music;
	Screen m_screen;
	Multiplayer m_multiplayer;
	TextToScreen m_textToScreen;

	std::vector<MenuButton> m_button;
	std::unique_ptr<Background> m_background;
};

