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
	virtual char* GetMsgReceived() override;
	virtual void ShutDown() override;

	bool SendMessage(int serverId);
	bool ReceiveMessage(int serverId);
private:

	// Inherited via TCPConnection
	virtual Uint32 GetIp(TCPsocket sock) override;
};