#pragma once

class Vector2D
{

public:

	Vector2D(double x = 0, double y = 0);

	Vector2D Add(const Vector2D& secondVector);
	Vector2D Subtract(const Vector2D& secondVector);
	Vector2D Scale(const Vector2D& scale);
	Vector2D Scale(int scale);
	Vector2D Negate();
	Vector2D Normalised();

	double Distance(const Vector2D& secondVector);
	double Magnitude();

	double x;
	double y;

private:

};