#include"Join.h"

Join::Join()
{
}

Join::~Join()
{
}

bool Join::SDLNetInitialize()
{
	std::cout << "This is Client" << std::endl;
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL2 is not initialize properly" << std::endl;
		return false;
	}
	else if (SDLNet_Init() == -1)
	{
		std::cout << "SDL_net is not initialize properly" << std::endl;
		return false;
	}
	return true;
}

bool Join::OpenSocket()
{
	if (SDLNet_ResolveHost(&ip, "localhost", port) == -1)
	{
		std::cout << "Could not connect to server" << std::endl;
		return false;
	}

	listenSocket = SDLNet_TCP_Open(&ip);
	if (!listenSocket)
	{
		std::cout << "Could not find server" << std::endl;
		return false;
	}
	return true;
}

bool Join::ListenSocket()
{
	if (!listenSocket)
	{
		std::cout << ".";
	}
	else
	{
		clients.push_back(listenSocket);
		serverId = clients.size() - 1;
		//ReceiveMessage(serverId);
		/*if (SendMessage(serverId))
		{
			std::cout << "Message sent successfully!" << std::endl;
		}*/
		return true;
	}
}

bool Join::SendMessage(int serverId)
{
	std::cout << "Type Your Message: " << std::endl;
	std::getline(std::cin, clientInput);

	if (SDLNet_TCP_Send(clients[serverId], clientInput.c_str(), clientInput.length() + 1))
	{
		return true;
	}
	std::cout << "Could not send message" << std::endl;
	return false;
}

bool Join::ReceiveMessage(int serverId)
{
	TCPsocket serverSock = clients[serverId];
	while (SDLNet_TCP_Recv(serverSock, message, 100))
	{
		std::cout << "/ / / / / / / / / / / 'Funny Looking Chat Box' / / / / / / / / / / /" << std::endl;
		std::cout << this->GetIp(serverSock) << " Sent: " << message << "			|" << std::endl;
		std::cout << "/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /" << std::endl;
		isMsgReceived = true;
		//isClientConnected = true;
	}
	std::cout << "Could not receive message" << std::endl;
	return false;
}

std::string Join::GetReceivedMessage()
{
	return message;
}

int Join::GetServerId()
{
	return serverId;
}

bool Join::IsMsgReceived()
{
	return isMsgReceived;
}

void Join::ShutDown()
{
	SDLNet_Quit();
}

Uint32 Join::GetIp(TCPsocket sock)
{
	IPaddress* clientIp = SDLNet_TCP_GetPeerAddress(sock);
	return SDLNet_Read32(&clientIp->host);
}

bool Join::GetListenSocket(TCPsocket sock)
{
	return listenSocket;
}
