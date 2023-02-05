#include "Rocket.h"

Rocket::Rocket()
{
	isStatic = true;
	this->SetTag("rocket");
	this->SetSize(200, 200);
}

Rocket::~Rocket()
{
}

void Rocket::Initialise(Screen& screen, std::list<GameObject*>* gameObjects)
{
	m_gameObjects = gameObjects;
	m_rocket.Load("Assets/Images/GoldShip.png", screen);
	m_rocket.SetSpriteDimension(250, 250);
	m_rocket.SetImageDimension(1, 1, 566, 512);
}

void Rocket::Update(Input& input, GameState& state)
{
	m_rocket.Update();
}

void Rocket::Render(Screen& screen)
{
	m_rocket.Render(m_position.x, m_position.y, screen, Sprite::Flip::NO_FLIP);
}

void Rocket::ShutDown()
{
	m_rocket.Unload();
}