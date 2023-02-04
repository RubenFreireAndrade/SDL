#pragma once
#include "TCPConnection.h"
#include "ChatBox.h"
#include "PlayState.h"

class MultiplayerState : public PlayState, public TCPConnection
{

public:
	explicit MultiplayerState(Player* p, std::string onlineMode);
	~MultiplayerState() override {}
	virtual bool OnEnter(Screen& screen, Input& input);
	virtual GameState* Update(Input& input);

	void ReceiveMessage(std::string message);
	void SentMessage(std::string message);
	void ToggleChatMode();
	void RecordChatInput(char key);

protected:
	std::string connectType;
	ChatBox* m_chatBox;

private:
	std::string chatInput;
	std::string m_message;

	//bool isChatting = false;
};

