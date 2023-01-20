#pragma once
#include"TCPConnection.h"

class Host : public TCPConnection
{
public:
	// Inherited via TCPConnection
	virtual bool SDLNetInitialize() override;
	virtual bool OpenSocket() override;
	virtual bool ListenSocket() override;
	virtual bool GetListenSocket(TCPsocket sock) override;
	virtual void ShutDown() override;
	
	int clientId = 0;
	bool SendMessage(int clientId, std::string message);
	bool ReceiveMessage(int clientId);

	std::string GetReceivedMessage();

private:
	virtual Uint32 GetIp(TCPsocket sock) override;

};

