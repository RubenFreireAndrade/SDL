#pragma once
#include "Screen.h"
#include "Input.h"
#include <memory>
#include <list>

class GameState
{
public:
	virtual ~GameState() = 0 {}

	virtual bool OnEnter(Screen& screen) = 0;
	virtual GameState* Update(Input& input) = 0;
	virtual bool Render(Screen& screen) = 0;
	virtual void OnExit() = 0;

	enum class ConditionState
	{
		WIN,
		LOSS
	};
private:
};

