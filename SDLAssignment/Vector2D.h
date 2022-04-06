#pragma once

class Vector2D
{

public:

	Vector2D(int x = 0, int y = 0);

	Vector2D Add(const Vector2D& secondVector);
	Vector2D Subtract(const Vector2D& secondVector);
	Vector2D Scale(const Vector2D& scale);
	Vector2D Scale(int scale);
	Vector2D Negate();
	Vector2D Normalised();

	int Distance(const Vector2D& secondVector);
	int Magnitude();

	int x;
	int y;

private:

};