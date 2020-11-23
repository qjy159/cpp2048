#pragma once

struct Vec2
{
	float x;
	float y;
	
public:
	void operator=(const POINT& _pt) 
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}
	Vec2 operator + (const Vec2& _vOther)
	{
		return Vec2(x + _vOther.x, y + _vOther.y);
	}
	Vec2 operator - (const Vec2& _vOther)
	{
		return Vec2(x - _vOther.x, y - _vOther.y);
	}
	Vec2 operator * (const Vec2& _vOther)
	{
		return Vec2(x * _vOther.x, y * _vOther.y);
	}
	Vec2 operator /(const Vec2& _vOther)
	{
		if (_vOther.x == 0 || _vOther.y == 0)
			assert(NULL);
		return Vec2(x / _vOther.x, y / _vOther.y);
	}

	Vec2& operator += (const Vec2& _vOther)
	{
		x += _vOther.x;
		y += _vOther.y;
		return *this;
	}
	Vec2& operator -= (const Vec2& _vOther)
	{
		x -= _vOther.x;
		y -= _vOther.y;
		return *this;
	}
	Vec2& operator *= (const Vec2& _vOther)
	{
		x *= _vOther.x;
		y *= _vOther.y;
		return *this;
	}
	Vec2& operator /= (const Vec2& _vOther)
	{
		if (_vOther.x == 0 || _vOther.y == 0)
			assert(NULL);
		x /= _vOther.x;
		y /= _vOther.y;
		return *this;
	}


	Vec2 operator / (int _iInput)
	{
		if (0 == _iInput)
			assert(NULL);
		return Vec2(x / _iInput, y / _iInput);
	}
	Vec2& operator /= (int _iInput)
	{
		if (0 == _iInput)
			assert(NULL);
		x /= _iInput;
		y /= _iInput;
		return *this;
	}

	bool operator ==(const Vec2& _vOther)
	{
		if (x == _vOther.x && y == _vOther.y)
			return true;
		return false;
	}

public:
	float Distance(const Vec2& _vOther) const
	{
		return sqrt(pow(x - _vOther.x, 2) + pow(y - _vOther.y, 2));
	}

	void Normalize()
	{
		float fDist = sqrt(x * x + y * y);
		if (0.f == fDist)
			return;
		x /= fDist;
		y /= fDist;
	}

public:
	Vec2()
		: x(0.f)
		, y(0.f)
	{}
	Vec2(float _x, float _y)
		: x(_x), y(_y)
	{}
	Vec2(UINT _x, UINT _y)
		: x((float)_x), y((float)_y)
	{}
	Vec2(int _x, int _y)
		: x((float)_x), y((float)_y)
	{}
};