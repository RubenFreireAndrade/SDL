#pragma once
#include "GameState.h"
#include "EndScreen.h"
#include "Player.h"

class EndScreenState : public GameState
{
public:
	EndScreenState(ConditionState c/*Player p*/);

	// Inherited via GameState
	virtual GameState* Update(Input& input) override;
	virtual bool Render(Screen& screen) override;
	virtual void OnExit() override;
	virtual bool OnEnter(Screen& screen);

private:
	EndScreen m_endScreen;
	Player m_player;
	ConditionState m_enumState;
	
	int conditionState;
};