#pragma once
class Vector {
public:
	float X, Y;
	Vector(float x = 0,float y = 0)
	{
		this->X = x;
		this->Y = y;
	};
	Vector operator+(const Vector v)
	{
		return Vector(X + v.X, Y + v.Y);
	}
	Vector operator-(const Vector v)
	{
		return Vector(X - v.X, Y - v.Y);
	}
	Vector operator*(const float v)
	{
		return Vector(X * v, Y * v);
	}
};