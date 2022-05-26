#include "Coin.h"

Coin::Coin()
{
	isStatic = true;
	this->SetTag("pickup");
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
	m_image.Render(this->m_position.x, this->m_position.y, screen, Sprite::Flip::NO_FLIP);
}

void Coin::Pickup(Player* player)
{
	player->AddScore(pointsPerCoin);
	this->FlagForDeletion();
}

void Coin::ShutDown()
{
	m_image.Unload();
}
