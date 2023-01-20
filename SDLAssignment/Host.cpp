#include "Host.h"

bool Host::SDLNetInitialize()
{
	std::cout << "This is Server" << std::endl;
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

bool Host::OpenSocket()
{
	if (SDLNet_ResolveHost(&ip, nullptr, port) == -1)
	{
		std::cout << "Could not create server" << std::endl;
		return false;
	}

	listenSocket = SDLNet_TCP_Open(&ip);
	if (!listenSocket)
	{
		std::cout << "Could not open socket" << std::endl;
		return false;
	}
	return true;
}

bool Host::ListenSocket()
{
	TCPsocket tempSock = SDLNet_TCP_Accept(listenSocket);
	if (!tempSock)
	{
		std::cout << ".";
		SDL_Delay(1000);
	}
	else
	{
		std::cout << "Client connected: ";
		std::cout << this->GetIp(tempSock) << std::endl;

		clients.push_back(tempSock);
		std::cout << "Number of Clients: " << clients.size() << std::endl;

		int clientId = clients.size() - 1;
		if (SendMessage(clientId, this->welcomeMessage))
		{
			std::cout << "Welcome message sent successfully!" << std::endl;
		}
		//ReceiveMessage(clientId);
		//return true;
		return clientId;
	}
}

bool Host::SendMessage(int clientId, std::string message)
{
	if (SDLNet_TCP_Send(clients[clientId], message.c_str(), message.length() + 1))
	{
		return true;
	}
	std::cout << "Could not send message" << std::endl;
	return false;
}

bool Host::ReceiveMessage(int clientId)
{
	TCPsocket sock = clients[clientId];
	while (SDLNet_TCP_Recv(sock, message, 100))
	{
		SDL_Delay(100);
		std::cout << "/ / / / / / / / / / / 'Funny Looking Chat Box' / / / / / / / / / / /" << std::endl;
		std::cout << this->GetIp(sock) << ":" << clientId << " Sent: " << message << "			|" << std::endl;
		std::cout << "/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /" << std::endl;

		// Relaying incoming messages from a Client to other Clients.
		for (int cId = 0; cId < clients.size(); cId++)
		{
			if (cId == clientId) continue;
			SendMessage(cId, message);
		}
		SDL_Delay(100);
	}
	std::cout << "Could not receive message" << std::endl;
	return false;
}

int Host::GetClientId()
{
	return clientId;
}

std::string Host::GetReceivedMessage()
{
	return message;
}

bool Host::GetListenSocket(TCPsocket sock)
{
    return false;
}

void Host::ShutDown()
{
	SDLNet_Quit();
	SDL_Quit();
}

Uint32 Host::GetIp(TCPsocket sock)
{
	IPaddress* clientIp = SDLNet_TCP_GetPeerAddress(sock);
	return SDLNet_Read32(&clientIp->host);
}
