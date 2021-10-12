#include "Enemy.h"

Enemy::Enemy(Vector2D pos, Vector2D dest)
{
	m_tag = "enemy";

	m_position = pos;
	m_destination = dest;
	m_startingPos = pos;
	this->SetSize(150, 150);
}

Enemy::~Enemy()
{

}

void Enemy::Initialise(Screen& screen, std::list<GameObject*>* gameObjects)
{
	m_gameObjects = gameObjects;
	m_image.Load("Assets/Images/EnemyWalkingSheet.png", screen);
	m_image.SetSpriteDimension(150, 150);
	m_image.SetImageDimension(12, 1, 9600, 700);
	m_image.SetAnimationSpeed(0.2f);

	m_image.IsAnimated(true);
	m_image.IsAnimationLooping(true);
}

void Enemy::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, screen);
}

void Enemy::Update(Input& input)
{
	Vector2D toDest;
	if (toDestination)
	{
		toDest = m_destination.Subtract(m_position);
	}
	else
	{
		toDest = m_startingPos.Subtract(m_position);
	}
	m_velocity = toDest.Normalised().Scale(speed);

	if (toDest.Magnitude() < 10)
	{
		toDestination = !toDestination;
	}
	m_image.Update();
}

void Enemy::EnemyHit()
{
	this->FlagForDeletion();
	this->IsDead();
}
