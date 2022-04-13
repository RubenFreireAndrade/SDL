#pragma once
#include <memory>
#include <vector>
#include "Screen.h"
#include "GameState.h"
#include "MainMenu.h"
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
	Screen m_screen;
	PlayState m_playState;
	TextToScreen m_textToScreen;

	Vector<int> buttonPos;

	std::unique_ptr<MainMenu> m_mainMenuBackground;
	std::vector<MenuButton> m_button;
};

