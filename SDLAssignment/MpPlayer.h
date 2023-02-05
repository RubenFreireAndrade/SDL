#pragma once
#include "Player.h"

class MpPlayer : public Player
{
public:

	// Inherited via GameObject
	virtual void Update(Input& input, GameState& state);

private:
};

