#pragma once
#include"GameState.h"
#include"Multiplayer.h"

class MultiplayerState : public GameState
{
public:
	// Inherited via GameState
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;
	virtual bool OnEnter(Screen& screen);
private:
	Multiplayer m_multiplayer;
};

