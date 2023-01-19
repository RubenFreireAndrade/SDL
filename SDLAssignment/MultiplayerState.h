#pragma once
#include "Host.h"
#include "Join.h"
#include "ChatBox.h"
#include "PlayState.h"

#include <thread>

class MultiplayerState : public PlayState
{

public:
	explicit MultiplayerState(Player* p, std::string onlineMode);
	~MultiplayerState() override {}
	virtual bool OnEnter(Screen& screen, Input& input);

protected:
	std::string connectType;
	Host* m_host;
	Join* m_join;
	ChatBox* m_chatBox;

private:
};

