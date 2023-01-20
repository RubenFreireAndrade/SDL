#pragma once
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
	virtual bool GetListenSocket(TCPsocket sock) override;
	virtual void ShutDown() override;

	bool SendMessage(int serverId);
	bool ReceiveMessage(int serverId);

	int GetServerId();
	bool IsMsgReceived();
	std::string GetReceivedMessage();

private:
	int serverId = 0;
	bool isMsgReceived = false;

	// Inherited via TCPConnection
	virtual Uint32 GetIp(TCPsocket sock) override;
};