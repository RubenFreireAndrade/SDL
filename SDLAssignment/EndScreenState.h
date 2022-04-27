#pragma once
#include <vector>
#include <iostream>
#include <SDL_ttf.h>
#include "Player.h"
#include "GameState.h"
#include "EndScreen.h"
#include "Background.h"
#include "TextToScreen.h"

class EndScreenState : public GameState
{
public:
	EndScreenState(ConditionState c);
	~EndScreenState();

	// Inherited via GameState
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;
	virtual bool OnEnter(Screen& screen);

private:

	Player m_player;
	//Background m_background;
	TextToScreen m_textToScreen;

	ConditionState m_enumState;
	int conditionState;

	std::unique_ptr<EndScreen> m_endScreen;
	std::unique_ptr<Background> m_background;
	std::vector<EndScreen> m_button;
};