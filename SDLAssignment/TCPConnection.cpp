#include "TCPConnection.h"

TCPConnection::~TCPConnection()
{
	ShutDown();
}

bool TCPConnection::SDLNetInitialize()
{
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

bool TCPConnection::ConnectToServer()
{
	if (SDLNet_ResolveHost(&ip, "localhost", port) == -1)
	{
		std::cout << "Could not connect to server" << std::endl;
		return false;
	}

	serverSocket = SDLNet_TCP_Open(&ip);
	if (!serverSocket)
	{
		std::cout << "Could not find server" << std::endl;
		return false;
	}

	serverListener = std::thread(&TCPConnection::ListenToServer, this);
	serverListener.detach();

	std::cout << "Connected to server: " << this->GetIp(serverSocket) << std::endl;
	return true;
}

void TCPConnection::ShutDown()
{
	isListening = false;
	SDLNet_Quit();
}

void TCPConnection::ListenToServer()
{
	isListening = true;
	while (isListening)
	{
		char message[100];
		while (SDLNet_TCP_Recv(serverSocket, message, 100))
		{
			std::string str(message);
			ReceiveMessage(str);
		}
	}
}

void TCPConnection::SendMessageToServer(std::string message)
{
	if (SDLNet_TCP_Send(serverSocket, message.c_str(), message.length() + 1))
	{
		this->SentMessage(message);
		return;
	}
	std::cout << "Could not send message" << std::endl;
}

Uint32 TCPConnection::GetIp(TCPsocket sock)
{
	IPaddress* ip = SDLNet_TCP_GetPeerAddress(sock);
	return SDLNet_Read32(&ip->host);
}
