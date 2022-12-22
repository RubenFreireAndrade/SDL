#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<SDL_net.h>

class TCPConnection
{
public:
	virtual ~TCPConnection() = 0 {};
	virtual bool SDLNetInitialize() = 0;
	virtual bool OpenSocket() = 0;
	virtual bool ListenSocket() = 0;
	virtual void ShutDown() = 0;

	virtual char* GetMsgReceived() = 0;
	virtual Uint32 GetIp(TCPsocket sock) = 0;
	virtual bool GetListenSocket(TCPsocket sock) = 0;
protected:
	char message[100];
	const int port = 1234;
	bool isListening = true;
	std::string clientInput;
	const std::string welcomeMessage = "Hello! Welcome to the chat.";

	IPaddress ip{};
	std::vector<TCPsocket> clients;
	TCPsocket listenSocket = nullptr;
};

