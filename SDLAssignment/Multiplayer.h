#pragma once
#include<iostream>
#include<string>

#include"TCPConnection.h"

class Multiplayer : public TCPConnection
{
public:
	Multiplayer();
	~Multiplayer();
	// Inherited via TCPConnection
	virtual bool SDLNetInitialize() override;
	virtual bool OpenSocket() override;
	virtual void ShutDown() override;

private:



};

