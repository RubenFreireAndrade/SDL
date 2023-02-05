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

class GameState;

class GameObject
{
	int gravitySpeed = 6;
	int groundLevel = 480;

public:

	GameObject();

	void PreUpdate(Input& input, GameState& state);
	virtual void Update(Input& input, GameState& state) = 0;
	virtual void Render(Screen& screen) = 0;
	virtual void CheckCollision(std::list<GameObject*> objects);
	virtual void Instantiate(Screen& screen, GameState& state);

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

	bool IsDead();
	bool IsFlaggedForDeletion();
	void ShutDown();
	void FlagForDeletion();

protected:
	bool IsCollidingWith(GameObject* obj);

	bool isDead;
	bool isStatic;
	bool isBlocked;
	bool isGrounded;
	bool deleteFlag;

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