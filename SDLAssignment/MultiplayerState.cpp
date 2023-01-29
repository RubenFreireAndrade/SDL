#include "MultiplayerState.h"

MultiplayerState::MultiplayerState(Player* p, std::string connectType) : PlayState(p)
{
	this->m_player = p;
	this->connectType = connectType;
}

bool MultiplayerState::OnEnter(Screen& screen, Input& input)
{
	PlayState::OnEnter(screen, input);

	if (this->connectType == "CLIENT")
	{
		m_chatBox = new ChatBox("ChatBox", "Attempting To Find Server", screen);

		m_chatBox->Initialise(screen);

		this->objects.push_back(m_chatBox);

		this->SDLNetInitialize();
		this->ConnectToServer();
	}
	return true;
}

GameState* MultiplayerState::Update(Input& input)
{
	// TODO - Delete Update func if not using it.
	PlayState::Update(input);
	return this;
}

void MultiplayerState::SentMessage(std::string message)
{
	std::cout << "You Sent: " << message << std::endl;
	m_chatBox->SetChatInput(message);
}

void MultiplayerState::ReceiveMessage(std::string message)
{
	std::cout << this->GetIp(serverSocket) << " Sent: " << message << std::endl;
	m_chatBox->SetIncomingText(message);
}
