#include "MultiplayerState.h"

MultiplayerState::MultiplayerState(Player* p, std::string connectType) : PlayState(p)
{
	this->connectType = connectType;
}

bool MultiplayerState::OnEnter(Screen& screen, Input& input)
{
	PlayState::OnEnter(screen, input);

	if (this->connectType == "HOST")
	{
		m_host = new Host();
		
		auto chatBox = new ChatBox("ChatBox", "Listening For Clients", screen);

		chatBox->Initialise(screen);

		this->objects.push_back(chatBox);

		m_host->SDLNetInitialize();
		m_host->OpenSocket();
	}

	if (this->connectType == "CLIENT")
	{
		m_join = new Join();

		auto chatBox = new ChatBox("ChatBox", "Attempting To Find Server", screen);

		chatBox->Initialise(screen);

		this->objects.push_back(chatBox);

		m_join->SDLNetInitialize();
		m_join->OpenSocket();
	}
	return true;
}

GameState* MultiplayerState::Update(Input& input)
{
	PlayState::Update(input);

	if (this->connectType == "HOST")
	{
		std::thread listenSockThr(&Host::ListenSocket, m_host);
		listenSockThr.detach();

		if (m_host->GetClientId() > 0)
		{
			std::thread receiveMsgThr(&Host::ReceiveMessage, m_host, m_host->GetClientId());
			receiveMsgThr.detach();
		}
	}

	if (this->connectType == "CLIENT")
	{
		std::thread listenSockThr(&Join::ListenSocket, m_join);
		listenSockThr.detach();

		if (m_join->GetServerId() > 0)
		{
			std::thread receiveMsgThr(&Join::ReceiveMessage, m_join, m_join->GetServerId());
			receiveMsgThr.detach();
		}

		if (m_join->IsMsgReceived() == true)
		{
			std::thread sendMsgThr(&Join::SendMessage, m_join, m_join->GetServerId());
			sendMsgThr.detach();
		}
	}
	return this;
}
