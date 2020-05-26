#pragma once

template<typename T>
class Vector2
{
public:
	Vector2() = default;
	Vector2(T x, T y) : x(x), y(y) {}
	template<typename Q>
	Vector2(Vector2<Q>& original) : x((Q)original.x), y((Q)original.y) {}

	// Vector-vector operations
	Vector2& operator=(const Vector2<T>& rhs)
	{
		x = (T)rhs.x;
		y = (T)rhs.y;
		return *this;
	}
	Vector2& operator+=(const Vector2<T>& rhs)
	{
		x += (T)rhs.x;
		y += (T)rhs.y;
		return *this;
	}
	Vector2& operator-=(const Vector2<T>& rhs)
	{
		x -= (T)rhs.x;
		y -= (T)rhs.y;
		return *this;
	}
	Vector2 operator+(const Vector2<T>& rhs) const
	{
		return Vector2<T>(T(rhs.x + x), T(rhs.y + y));
	}
	Vector2 operator-(const Vector2<T>& rhs) const
	{
		return Vector2<T>(T(x - rhs.x), T(y - rhs.y));
	}

	// Vector-scalar operations
	Vector2& operator*=(T multiplier)
	{
		x *= (T)multiplier;
		y *= (T)multiplier;
		return *this;
	}
	Vector2& operator/=(T divisor)
	{
		x /= (T)divisor;
		y /= (T)divisor;
		return *this;
	}
	Vector2 operator*(T multiplier) const
	{
		return Vector2<T>(T(x * multiplier), T(y * multiplier));
	}
	Vector2 operator/(T divisor) const
	{
		return Vector2<T>(T(x / divisor), T(y / divisor));
	}

	// TODO: magnitude, normalise, scalar product, angle between

public:
	T x;
	T y;
};

