#pragma once
#include <string>
#include <iostream>
#include <list>
#include <SDL.h>
#include "Screen.h"
#include "Input.h"
#include "Vector2D.h"
#include "Vector.h"
#include "Sprite.h"

class GameObject
{
	int gravitySpeed = 6;
	int groundLevel = 480;

public:

	GameObject();

	void PreUpdate(Input& input);
	virtual void Update(Input& input) = 0;
	virtual void Render(Screen& screen) = 0;
	virtual void CheckCollision(std::list<GameObject*> objects);

	void SetPosition(int x, int y);
	void SetPosition(const Vector2D& position);
	void SetPosition(const Vector<int>& position);
	void SetSize(const Vector2D& position);
	void SetSize(int width, int height);
	void SetAngle(float angle);
	void SetTag(const std::string& tag);

	const Vector2D& GetSize() const;
	const Vector2D& GetPosition() const;
	const std::string& GetTag() const;

	float GetAngle() const;

	void FlagForDeletion();
	bool IsFlaggedForDeletion();
	bool IsDead();
	void ShutDown();

protected:
	bool IsCollidingWith(GameObject* obj);

	bool deleteFlag;
	bool isStatic;
	bool isDead;
	bool isGrounded;
	bool isBlocked;

	Vector2D m_size;
	Vector2D m_position;
	Vector2D m_velocity;
	Sprite m_sprite;

	Vector<int> m_vectorPosition;

	int x = {};
	int y = {};
	int pointsPerCoin = 2;
	float m_angle;
	std::string m_tag;
};