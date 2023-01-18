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
	std::cout << "Trying to connect" << std::endl;
	while (isListening)
	{
		if (!listenSocket)
		{
			std::cout << ".";
			SDL_Delay(1000);
		}
		else
		{
			clients.push_back(listenSocket);
			int serverId = clients.size() - 1;
			//ReceiveMessage(serverId);
			if (SendMessage(serverId))
			{
				//this->SetConsoleTextColor(6);
				std::cout << "Message sent successfully!" << std::endl;
				//this->SetConsoleTextColor(7);
			}
			return serverId;
		}
	}
}

bool Join::SendMessage(int serverId)
{
	//std::cout << "Say Something Or I'm Giving Up On You!" << std::endl;
	std::cout << "Type Your Message: " << std::endl;
	//this->SetConsoleTextColor(3);
	std::getline(std::cin, clientInput);
	//this->SetConsoleTextColor(7);

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
	//char message[100];
	while (SDLNet_TCP_Recv(serverSock, message, 100))
	{
		SDL_Delay(100);
		std::cout << "/ / / / / / / / / / / 'Funny Looking Chat Box' / / / / / / / / / / /" << std::endl;
		//this->SetConsoleTextColor(3);
		std::cout << this->GetIp(serverSock) << " Sent: " << message << "			|" << std::endl;
		//this->SetConsoleTextColor(7);
		std::cout << "/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /" << std::endl;
		SDL_Delay(100);
	}
	std::cout << "Could not receive message" << std::endl;
	return false;
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
