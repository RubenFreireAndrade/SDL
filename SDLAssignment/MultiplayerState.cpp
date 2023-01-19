#include "MultiplayerState.h"

MultiplayerState::MultiplayerState(Player* p, std::string connectType) : PlayState(p)
{
	this->connectType = connectType;
}

bool MultiplayerState::OnEnter(Screen& screen, Input& input)
{
	PlayState::OnEnter(screen, input);
	auto chatBox = new ChatBox("ChatBox", screen);

	chatBox->Initialise(screen);

	this->objects.push_back(chatBox);

	if (this->connectType == "host")
	{
		m_host = new Host();
		
		m_host->SDLNetInitialize();
		m_host->OpenSocket();
		//int clientId = m_host->ListenSocket();
		std::thread listenSockThr(&Host::ListenSocket, m_host);
		listenSockThr.detach();
		/* std::thread receiveMsgThr(&Host::ReceiveMessage, m_host, m_host->clientId);
		 receiveMsgThr.detach();*/
	}

	if (this->connectType == "client")
	{
		m_join = new Join();

		m_join->SDLNetInitialize();
		m_join->OpenSocket();
		int serverId = m_join->ListenSocket();
		/* std::thread listenSockThr(&Join::ListenSocket, m_join);
		 listenSockThr.detach();*/
		std::thread receiveMsgThr(&Join::ReceiveMessage, m_join, serverId);
		receiveMsgThr.detach();
	}
	return true;
}
