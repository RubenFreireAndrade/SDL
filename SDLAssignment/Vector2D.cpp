#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::Add(const Vector2D& secondVector)
{
	Vector2D result;

	result.x = x + secondVector.x;
	result.y = y + secondVector.y;

	return result;
}

Vector2D Vector2D::Subtract(const Vector2D& secondVector)
{
	Vector2D result;

	result.x = x - secondVector.x;
	result.y = y - secondVector.y;

	return result;
}

Vector2D Vector2D::Scale(const Vector2D& scale)
{
	Vector2D result;

	result.x = x * scale.x;
	result.y = y * scale.y;

	return result;
}

Vector2D Vector2D::Scale(int scale)
{
	Vector2D result;

	result.x = x * scale;
	result.y = y * scale;

	return result;
}

int Vector2D::Distance(const Vector2D& secondVector)
{
	Vector2D temp = Subtract(secondVector);

	return temp.Magnitude();
}

Vector2D Vector2D::Negate()
{
	Vector2D result;

	result.x = x * -1;
	result.y = y * -1;

	return result;
}

Vector2D Vector2D::Normalised()
{
	int mag = this->Magnitude();
	int x = this->x / mag;
	int y = this->y / mag;

	return Vector2D(x, y);
}

int Vector2D::Magnitude()
{
	double x = this->x;
	double y = this->y;

	return sqrt((x * x) + (y * y));
}