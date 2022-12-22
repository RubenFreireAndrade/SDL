#include "GameObject.h"


GameObject::GameObject()
{
	m_angle = 0.0f;
	m_velocity = { 0, 0 };

	deleteFlag = false;
	isStatic = false;
	isDead = false;
	isGrounded = false;
	isBlocked = false;
}

void GameObject::PreUpdate(Input& input) // Adding gravity to objects before Update();
{
	m_velocity = { 0, m_velocity.y };
	this->Update(input);
	if (!isStatic)
	{
		m_velocity.y += gravitySpeed;
		if (m_velocity.y > gravitySpeed)
		{
			m_velocity.y = gravitySpeed;
		}
		// Apply velocity after each button or velocity change is calculated.
		m_position = m_position.Add(m_velocity);
		isGrounded = m_position.y >= groundLevel || isBlocked;
		
		if (isGrounded)
		{
			m_position.y -= m_velocity.y;
		}
	}
}

void GameObject::Update(Input& input)
{	
}

void GameObject::Render(Screen& screen)
{
}

void GameObject::CheckCollision(std::list<GameObject*> objects)
{
}

void GameObject::SetTag(const std::string& tag)
{
	m_tag = tag;
}

void GameObject::SetAngle(float angle)
{
	m_angle = angle;
}

void GameObject::SetSize(const Vector2D& size)
{
	m_size = size;
}

void GameObject::SetSize(int width, int height)
{
	m_size = Vector2D(width, height);
}

void GameObject::SetPosition(int x, int y)
{
	m_position = Vector2D(x, y);
}

void GameObject::SetPosition(const Vector2D& position)
{
	m_position = position;
}

void GameObject::SetPosition(const Vector<int>& position)
{
	m_vectorPosition = position;
}

const Vector2D& GameObject::GetSize() const
{
	return m_size;
}

const Vector2D& GameObject::GetPosition() const
{
	return m_position;
}

const std::string& GameObject::GetTag() const
{
	return m_tag;
}

float GameObject::GetAngle() const
{
	return m_angle;
}

void GameObject::FlagForDeletion()
{
	deleteFlag = true;
}

bool GameObject::IsFlaggedForDeletion()
{
	return deleteFlag;
}

bool GameObject::IsDead()
{
	return isDead;
}

bool GameObject::GetIsChatting()
{
	return isChatting;
}

bool GameObject::IsCollidingWith(GameObject* obj)
{
	Vector2D obj1Pos = this->GetPosition();
	Vector2D obj1Size = this->GetSize();
	Vector2D obj2Pos = obj->GetPosition();
	Vector2D obj2Size = obj->GetSize();

	bool horizontalCheck = obj1Pos.x + obj1Size.x >= obj2Pos.x && obj1Pos.x <= obj2Pos.x + obj2Size.x;
	bool verticalCheck = obj1Pos.y + obj1Size.y >= obj2Pos.y && obj1Pos.y <= obj2Pos.y + obj2Size.y;

	return horizontalCheck && verticalCheck;
}

void GameObject::ShutDown()
{
	m_sprite.Unload();
}
