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

	//int clientId;
	bool SendMessage(int clientId, std::string message);
	bool ReceiveMessage(int clientId);
private:
	virtual Uint32 GetIp(TCPsocket sock) override;

};

