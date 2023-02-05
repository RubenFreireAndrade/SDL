#pragma once
#include "TCPConnection.h"
#include "ChatBox.h"
#include "PlayState.h"
#include "ServerText.h"

class MultiplayerState : public PlayState, public TCPConnection
{

public:
	explicit MultiplayerState(Player* p, std::string onlineMode);
	~MultiplayerState() override {}
	virtual bool OnEnter(Screen& screen, Input& input);
	virtual GameState* Update(Input& input);
	virtual bool Render(Screen& screen);

	void ReceiveMessage(std::string message);
	void SentMessage(std::string message);
	void ToggleChatMode();
	void RecordChatInput(char key);

protected:
	std::string connectType;
	ChatBox* m_chatBox;
	ServerText* m_serverTxt;

private:
	std::string chatInput;
	std::string m_message;
};

