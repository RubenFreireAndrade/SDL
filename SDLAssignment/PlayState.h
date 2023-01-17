#pragma once
#include "Player.h"
#include "GameState.h"

class PlayState : public GameState
{
public: 
	// Inherited via GameState
	explicit PlayState(Player* p);
	~PlayState() override {}

	virtual bool OnEnter(Screen& screen, Input& input);
	virtual void CreateLevel(Screen& screen);
	virtual GameState* UpdateStateChange(Input& input);
	virtual GameState* Update(Input& input);
	virtual bool Render(Screen& screen);
	virtual void OnExit();

protected:
	Player* m_player;
	std::list<GameObject*> objects{};

private:
};

