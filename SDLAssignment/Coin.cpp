#include "Coin.h"
#include <SDL.h>

Coin::Coin(int x, int y)
{
	m_tag = "pickup";
	isStatic = true;

	this->SetPosition(x, y);
	this->SetSize(50, 50);
}

Coin::~Coin()
{

}

void Coin::Initialise(Screen& screen, std::list<GameObject*>* gameObjects)
{
	m_gameObjects = gameObjects;
	m_image.Load("Assets/Images/Coin_gold.png", screen);
	m_image.SetSpriteDimension(50, 50);
	m_image.SetImageDimension(6, 1, 3072, 512);
	m_image.SetAnimationSpeed(0.2f);

	m_image.IsAnimated(true);
	m_image.IsAnimationLooping(true);
}

void Coin::Update(Input& input)
{
	m_image.Update();
}

void Coin::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, screen);
}

void Coin::Pickup(Player* player)
{
	player->AddScore(2);

	this->FlagForDeletion();
}