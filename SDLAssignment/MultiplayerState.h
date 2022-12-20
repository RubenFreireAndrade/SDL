#pragma once
#include"Host.h"
#include"Join.h"
#include"PlayState.h"
#include"GameState.h"
#include"Background.h"
#include"MenuButtonText.h"

#include<thread>

class MultiplayerState : public GameState
{
public:
	// Inherited via GameState
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;
	virtual bool OnEnter(Screen& screen);
private:
	Host* m_host;
	Join* m_join;

	std::vector<MenuButtonText> m_btnText;
	std::unique_ptr<Background> m_background;
};

