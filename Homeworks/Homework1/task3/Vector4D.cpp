#include "Vector4D.hpp"

Vector4D::Vector4D()
{
	for (int i = 0; i < 4; i++) {
		vec[i] = 0;
	}
}

Vector4D::Vector4D(double x, double y, double z, double t)
{
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
	vec[3] = t;

}

Vector4D::Vector4D(const Vector4D& v)
{
	for (int i = 0; i < 4; i++) {
		vec[i] = v.vec[i];
	}
	
}

Vector4D& Vector4D::operator=(const Vector4D& rhs)
{
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			vec[i] = rhs.vec[i];
		}
	}
	return *this;
}

double& Vector4D::operator[](unsigned int index) 
{
	//if (index > 3)return;
	return this->vec[index];
}

Vector4D Vector4D::operator+(const Vector4D& rhs) const
{
	Vector4D v;
	for (int i = 0; i < 4; i++) {
		v.vec[i] = vec[i] + rhs.vec[i];
	}
	return v;
}

Vector4D& Vector4D::operator+=(const Vector4D& rhs)
{
	for (int i = 0; i < 4; i++) {
		vec[i] = vec[i] + rhs.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& rhs) const
{
	Vector4D v;
	for (int i = 0; i < 4; i++) {
		v.vec[i] = vec[i] - rhs.vec[i];
	}
	return v;
}

Vector4D& Vector4D::operator-=(const Vector4D& rhs)
{
	for (int i = 0; i < 4; i++) {
		vec[i] = vec[i] - rhs.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& rhs) const
{
	Vector4D v;
	for (int i = 0; i < 4; i++) {
		v.vec[i] = vec[i] * rhs.vec[i];
	}
	return v;
}

Vector4D& Vector4D::operator*=(const Vector4D& rhs)
{
	for (int i = 0; i < 4; i++) {
		vec[i] = vec[i] * rhs.vec[i];
	}
	return *this;
}

Vector4D Vector4D::operator*(double a) const
{
	Vector4D v;
	for (int i = 0; i < 4; i++) {
		v.vec[i] = vec[i] * a;
	}
	return v;
}

Vector4D& Vector4D::operator*=(double a)
{
	for (int i = 0; i < 4; i++) {
		vec[i] = vec[i] * a;
	}
	return *this;
}
Vector4D Vector4D::operator/(const Vector4D& rhs) const
{
	Vector4D v;
	for (int i = 0; i < 4; i++) {
		v.vec[i] = vec[i] / rhs.vec[i];
	}
	return v;
}

Vector4D& Vector4D::operator/=(const Vector4D& rhs)
{
	for (int i = 0; i < 4; i++) {
		vec[i] = vec[i] / rhs.vec[i];
	}
	return *this;
}

bool Vector4D::operator==(const Vector4D rhs) const
{
	for (int i = 0; i < 4; i++) {
		if (vec[i] != rhs.vec[i])return 0;
	}
	return 1;
}

bool Vector4D::operator!=(const Vector4D rhs) const
{
	return !(*this == rhs);
	
}

bool Vector4D::operator<(const Vector4D rhs) const
{
	for (int i = 0; i < 4; i++) {
		if (vec[i] < rhs.vec[i])return 1;
		else if (vec[i] > rhs.vec[i])return 0;
	}
	return 0;
}

bool Vector4D::operator>(const Vector4D rhs) const
{
	return rhs < *this;
}

bool Vector4D::operator<=(const Vector4D rhs) const
{
	for (int i = 0; i < 4; i++) {
		if (vec[i] < rhs.vec[i])return 1;
		else if (vec[i] > rhs.vec[i])return 0;
	}
	return 1;
}

bool Vector4D::operator>=(const Vector4D rhs) const
{
	return rhs <= *this;
}

bool Vector4D::operator!() const
{
	for (int i = 0; i < 4; i++) {
		if (vec[i] != 0)return 0;
	}
	return 1;
}

Vector4D Vector4D::operator-() const
{
	Vector4D v;
	for (int i = 0; i < 4; i++) {
		v.vec[i] = -vec[i];
	}
	return v;
	
}

std::ostream& operator<<(std::ostream& out, const Vector4D& v)
{
	out << v.vec[0] << ", " << v.vec[1] << ", " << v.vec[2] << ", " << v.vec[3];
	return out;
}
