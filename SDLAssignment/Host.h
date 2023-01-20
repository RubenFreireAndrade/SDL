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
	
	bool SendMessage(int clientId, std::string message);
	bool ReceiveMessage(int clientId);

	int GetClientId();
	std::string GetReceivedMessage();

private:
	int clientId = 0;
	virtual Uint32 GetIp(TCPsocket sock) override;

};

