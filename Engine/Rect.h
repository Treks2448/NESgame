#pragma once

template<typename T> 
class Rect_
{
public:
	Rect_(T left, T right, T bottom, T top) 
		: 
		left((T)left), 
		right((T)right), 
		top((T)top), 
		bottom((T)bottom) 
	{}
	Rect_(const Rect_<T>& original)
		:
		left((T)original.left), 
		right((T)original.right), 
		top((T)original.top), 
		bottom((T)original.bottom) 
	{}

	// Checks if the rect contains the point
	bool Contains(T x, T y)
	{
		if (x >= left || x <= right || y >= top || y <= bottom ) { return true; }
		else { return false; }
	}

	T GetWidth() const { return right - left; }
	T GetHeight() const { return bottom - top; }

	T left;
	T right;
	T top;
	T bottom;
};

typedef Rect_<float> Rect;
typedef Rect_<int> IntRect;