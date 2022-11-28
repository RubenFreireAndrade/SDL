#pragma once
#include<string>
#include<iostream>
#include<SDL_net.h>

class TCPConnection
{
public:
	virtual ~TCPConnection() = 0 {};
	virtual bool SDLNetInitialize() = 0;
	virtual bool OpenSocket() = 0;
	virtual void ShutDown() = 0;

protected:
	const int port = 1234;

	IPaddress ip;
	TCPsocket listenSocket;
};

