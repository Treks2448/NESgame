#pragma once
#include <cmath>

template<typename T>
class Vector2
{
public:
	Vector2() = default;
	Vector2(T x, T y) : x(x), y(y) {}
	template<typename Q>
	explicit Vector2(Vector2<Q>& original) : x((Q)original.x), y((Q)original.y) {}

	// Vector-vector operations ///////////////////////////
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

	// Vector-scalar operations ///////////////////////////
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

	// Vector algebra /////////////////////////////////////

	// returns the magnitude of the vector
	T Magnitude() const
	{
		T mag = (T)std::sqrt(x * x + y * y);
		return mag;
	}

	// returns the normalised version of this vector
	Vector2<T> Normalised() const
	{
		return *this / Magnitude();
	}

	// returns the dot product of this and rhs
	T Dot(const Vector2<T>& rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}

	// returns the dot product of lhs and rhs
	static T Dot(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	// returns the angle between lhs and rhs
	static T AngleBetween(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		T mag1 = lhs.Magnitude();
		T mag2 = rhs.Magnitude();
		T dot = Vector2<T>::Dot(lhs, rhs);
		T theta = std::acos(dot / (mag1 * mag2));

		if (theta <= T(180)) return theta;
		else return T(180) - theta;
	}

	// returns a vector going from lhs to rhs
	static Vector2<T>& FromToVector(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return rhs - lhs;
	}

	// returns a vector going from (x1,y1) to (x2, y2)
	static Vector2<T>& FromToVector(T x1, T y1, T x2, T y2)
	{
		return Vector2<T>(T(x2 - x1), T(y2- y1));
	}

	// returns distance between lhs and rhs
	static T Dist(const Vector2<T>& lhs, const Vector2<T>& rhs)
	{
		return Vector2<T>::FromToVector(lhs, rhs).Magnitude();
	}

	// Getters ////////////////////////////////////////////
	T GetX() const { return x; }
	T GetY() const { return y; }

private:
	T x;
	T y;
};

