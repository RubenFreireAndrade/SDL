#pragma once
#include <vector>
#include "GameState.h"
#include "EndScreen.h"
#include "Player.h"

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
	ConditionState m_enumState;
	
	int conditionState;
	std::unique_ptr<EndScreen> m_endScreen;
};