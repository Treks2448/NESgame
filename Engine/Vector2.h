#pragma once
#include <cmath>

template<typename T>
class Vector2_
{
public:
	Vector2_() = default;
	Vector2_(T x, T y) : x(x), y(y) {}
	template<typename Q>
	explicit Vector2_(Vector2_<Q>& original) : x((Q)original.x), y((Q)original.y) {}

	// Vector-vector operations ///////////////////////////
	Vector2_& operator+=(const Vector2_<T>& rhs)
	{
		x += (T)rhs.x;
		y += (T)rhs.y;
		return *this;
	}
	Vector2_& operator-=(const Vector2_<T>& rhs)
	{
		x -= (T)rhs.x;
		y -= (T)rhs.y;
		return *this;
	}
	Vector2_ operator+(const Vector2_<T>& rhs) const
	{
		return Vector2_<T>(T(rhs.x + x), T(rhs.y + y));
	}
	Vector2_ operator-(const Vector2_<T>& rhs) const
	{
		return Vector2_<T>(T(x - rhs.x), T(y - rhs.y));
	}

	// Vector-scalar operations ///////////////////////////
	Vector2_& operator*=(T multiplier)
	{
		x *= (T)multiplier;
		y *= (T)multiplier;
		return *this;
	}
	Vector2_& operator/=(T divisor)
	{
		x /= (T)divisor;
		y /= (T)divisor;
		return *this;
	}
	Vector2_ operator*(T multiplier) const
	{
		return Vector2_<T>(T(x * multiplier), T(y * multiplier));
	}
	Vector2_ operator/(T divisor) const
	{
		return Vector2_<T>(T(x / divisor), T(y / divisor));
	}

	// Vector algebra /////////////////////////////////////

	// returns the magnitude of the vector
	T Magnitude() const
	{
		T mag = (T)std::sqrt(x * x + y * y);
		return mag;
	}

	// returns the normalised version of this vector
	Vector2_<T> Normalised() const
	{
		return *this / Magnitude();
	}

	// returns the dot product of this and rhs
	T Dot(const Vector2_<T>& rhs) const
	{
		return x * rhs.x + y * rhs.y;
	}

	// returns the dot product of lhs and rhs
	static T Dot(const Vector2_<T>& lhs, const Vector2_<T>& rhs)
	{
		return lhs.x * rhs.x + lhs.y * rhs.y;
	}

	// returns the angle between lhs and rhs
	static T AngleBetween(const Vector2_<T>& lhs, const Vector2_<T>& rhs)
	{
		T mag1 = lhs.Magnitude();
		T mag2 = rhs.Magnitude();
		T dot = Vector2_<T>::Dot(lhs, rhs);
		T theta = std::acos(dot / (mag1 * mag2));

		if (theta <= T(180)) return theta;
		else return T(180) - theta;
	}

	// returns a vector going from lhs to rhs
	static Vector2_<T>& FromToVector(const Vector2_<T>& lhs, const Vector2_<T>& rhs)
	{
		return rhs - lhs;
	}

	// returns a vector going from (x1,y1) to (x2, y2)
	static Vector2_<T>& FromToVector(T x1, T y1, T x2, T y2)
	{
		return Vector2_<T>(T(x2 - x1), T(y2- y1));
	}

	// returns distance between lhs and rhs
	static T Dist(const Vector2_<T>& lhs, const Vector2_<T>& rhs)
	{
		return Vector2_<T>::FromToVector(lhs, rhs).Magnitude();
	}

	// Getters ////////////////////////////////////////////
	T GetX() const { return x; }
	T GetY() const { return y; }

private:
	T x;
	T y;
};

typedef Vector2_<float> Vector2;
typedef Vector2_<int> IntVector2;
