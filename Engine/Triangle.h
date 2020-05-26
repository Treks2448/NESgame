#pragma once

template<typename T>
class Triangle_
{
public:
	Triangle_(T x1, T y1, T x2, T y2, T x3, T y3)
		:
		x1(x1),
		y1(y1),
		x2(x2),
		y2(y2),
		x3(x3),
		y3(y3)
	{ }

	// TODO: encapsulate

	T x1;
	T y1;
	T x2;
	T y2;
	T x3;
	T y3;
};

typedef Triangle_<float> Triangle;
typedef Triangle_<int> intTriangle;