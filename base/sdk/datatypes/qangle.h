#pragma once
// used: isfinite, fmodf, remainderf
#include <cmath>

class QAngle
{
public:
	QAngle()
	{
		Init();
	}

	QAngle(float x, float y, float z)
	{
		Init(x, y, z);
	}

	QAngle(const float* angles)
	{
		Init(angles[0], angles[1], angles[2]);
	}

	const void Init(float x = 0.f, float y = 0.f, float z = 0.f)
	{
		this->x = x; this->y = y; this->z = z;
	}

	float operator[](std::size_t nIndex) const
	{
		return ((float*)this)[nIndex];
	}

	float& operator[](std::size_t nIndex)
	{
		return ((float*)this)[nIndex];
	}

	bool operator==(const QAngle& v) const
	{
		return (this->x == v[0] &&
			this->y == v[1] &&
			this->z == v[2]);
	}

	bool operator!=(const QAngle& v) const
	{
		return !(this->x == v[0] &&
			this->y == v[1] &&
			this->z == v[2]);
	}

	QAngle& operator=(const QAngle& v)
	{
		this->x = v.x; this->y = v.y; this->z = v.z; return *this;
	}

	QAngle& operator+=(const QAngle& v)
	{
		this->x += v.x; this->y += v.y; this->z += v.z; return *this;
	}

	QAngle& operator-=(const QAngle& v)
	{
		this->x -= v.x; this->y -= v.y; this->z -= v.z; return *this;
	}

	QAngle& operator*=(const QAngle& v)
	{
		this->x *= v.x; this->y *= v.y; this->z *= v.z; return *this;
	}

	QAngle& operator/=(const QAngle& v)
	{
		this->x /= v.x; this->y /= v.y; this->z /= v.z; return *this;
	}

	QAngle& operator+=(float v)
	{
		this->x += v; this->y += v; this->z += v; return *this;
	}

	QAngle& operator-=(float v)
	{
		this->x -= v; this->y -= v; this->z -= v; return *this;
	}

	QAngle& operator*=(float v)
	{
		this->x *= v; this->y *= v; this->z *= v; return *this;
	}

	QAngle& operator/=(float v)
	{
		this->x /= v; this->y /= v; this->z /= v; return *this;
	}

	QAngle operator+(float v) const
	{
		return QAngle(this->x + v, this->y + v, this->z + v);
	}

	QAngle operator-(float v) const
	{
		return QAngle(this->x - v, this->y - v, this->z - v);
	}

	QAngle operator*(float v) const
	{
		return QAngle(this->x * v, this->y * v, this->z * v);
	}

	QAngle operator/(float v) const
	{
		return QAngle(this->x / v, this->y / v, this->z / v);
	}

	QAngle operator+(const QAngle& v) const
	{
		return QAngle(this->x + v.x, this->y + v.y, this->z + v.z);
	}

	QAngle operator-(const QAngle& v) const
	{
		return QAngle(this->x - v.x, this->y - v.y, this->z - v.z);
	}

	QAngle operator*(const QAngle& v) const
	{
		return QAngle(this->x * v.x, this->y * v.y, this->z * v.z);
	}

	QAngle operator/(const QAngle& v) const
	{
		return QAngle(this->x / v.x, this->y / v.y, this->z / v.z);
	}

	bool IsZero(float flErrorMargin = 0.01f) const
	{
		return (this->x > -flErrorMargin && this->x < flErrorMargin &&
				this->y > -flErrorMargin && this->y < flErrorMargin &&
				this->z > -flErrorMargin && this->z < flErrorMargin);
	}

	float Length() const
	{
		return std::sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	float LengthSqr() const
	{
		return this->x * this->x + this->y * this->y + this->z * this->z;
	}

	void Clamp()
	{
		std::clamp(this->x, -89.f, 89.f);
		std::clamp(this->y, -180.f, 180.f);
		this->z = 0.f; // @note: i think doesnt need clamp it at -50, 50 cuz it stay useless long ago
	}

	QAngle Normalize()
	{
		this->x = std::isfinite(this->x) ? std::remainderf(this->x, 360.f) : 0.f;
		this->y = std::isfinite(this->y) ? std::remainderf(this->y, 360.f) : 0.f;
		this->z = 0.f;
		return *this;
	}

	QAngle Mod(float flValue)
	{
		this->x = std::fmodf(this->x, flValue);
		this->y = std::fmodf(this->y, flValue);
		this->z = std::fmodf(this->z, flValue);
		return *this;
	}

public:
	float x, y, z;
};
