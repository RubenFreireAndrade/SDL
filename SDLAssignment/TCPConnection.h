#pragma once
#include<string>
#include<vector>
#include<thread>
#include<iostream>
#include<SDL_net.h>

class TCPConnection
{
public:
	~TCPConnection();
	virtual bool SDLNetInitialize();
	virtual bool ConnectToServer();
	virtual void ShutDown();
	
	void SendMessageToServer(std::string message);

	Uint32 GetIp(TCPsocket sock);

protected:
	virtual void SentMessage(std::string message) = 0;
	virtual void ReceiveMessage(std::string message) = 0;

	bool isListening = false;
	
	IPaddress ip{};
	const int port = 1234;

	TCPsocket serverSocket = nullptr;

private:
	std::thread serverListener;
	void ListenToServer();
};

