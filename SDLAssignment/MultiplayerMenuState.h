#pragma once
#include"PlayState.h"
#include"GameState.h"
#include"Background.h"
#include"MenuButtonText.h"

#include<thread>

class MultiplayerLevel1;

class MultiplayerMenuState : public GameState
{
public:
	// Inherited via GameState
	virtual bool OnEnter(Screen& screen, Input& input);
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;

private:
	std::vector<MenuButtonText> m_btnText;
	std::unique_ptr<Background> m_background;
};

