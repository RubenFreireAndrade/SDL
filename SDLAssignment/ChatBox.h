#pragma once
#include"GameObject.h"

class ChatBox : public GameObject
{
public:
	// Inherited via GameObject
	void Update(Input& input);
	void Render(Screen& screen);
	void Shutdown();

private:

};