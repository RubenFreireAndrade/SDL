#pragma once
//#include<string>
//#include<iostream>

#include"TCPConnection.h"

class Join : public TCPConnection
{
public:
	Join();
	~Join();
	// Inherited via TCPConnection
	virtual bool SDLNetInitialize() override;
	virtual bool OpenSocket() override;
	virtual bool ListenSocket() override;
	virtual void ShutDown() override;
	virtual bool GetListenSocket(TCPsocket sock) override;

	bool SendMessage(int serverId);
	bool ReceiveMessage(int serverId);
private:

	// Inherited via TCPConnection
	virtual Uint32 GetIp(TCPsocket sock) override;
};