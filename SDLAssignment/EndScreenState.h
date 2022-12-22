#pragma once
#include <vector>
#include <iostream>
#include <SDL_ttf.h>
#include "Player.h"
#include "GameState.h"
#include "EndScreen.h"
#include "MenuButton.h"
#include "Background.h"
#include "TextToScreen.h"
#include "MainMenuState.h"

class EndScreenState : public GameState
{
public:
	EndScreenState(ConditionState c);
	~EndScreenState();

	// Inherited via GameState
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;
	virtual bool OnEnter(Screen& screen, Input& input);

private:
	TextToScreen m_textToScreen;

	ConditionState m_enumState;
	int conditionState;

	std::unique_ptr<EndScreen> m_endScreen;
	std::unique_ptr<Background> m_background;
	std::vector<MenuButton> m_button;
};