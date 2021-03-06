#pragma once
#include <memory>
#include <vector>
#include "Music.h"
#include "Screen.h"
#include "GameState.h"
#include "TextToScreen.h"
#include "Background.h"
#include "PlayState.h"
#include "MenuButton.h"

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
	//PlayState m_playState;
	TextToScreen m_textToScreen;

	std::vector<MenuButton> m_button;
	std::unique_ptr<Background> m_background;
};

