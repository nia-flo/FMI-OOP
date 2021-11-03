#include "Vector4D.hpp"

Vector4D::Vector4D()
{
	for (int i = 0; i < this->ELEMENTS_COUNT; i++)
	{
		this->elements[i] = this->DEFAULT_ELEMENT_VALUE;
	}
}

Vector4D::Vector4D(double firstElement, double secondElement, double thirdElement, double fourthElement)
{
	this->elements[0] = firstElement;
	this->elements[1] = secondElement;
	this->elements[2] = thirdElement;
	this->elements[3] = fourthElement;
}

double& Vector4D::operator[](unsigned int index)
{
	if (index >= this->ELEMENTS_COUNT)
	{
		return this->elements[this->ELEMENTS_COUNT - 1];
	}

	return this->elements[index];
}

Vector4D Vector4D::operator+(const Vector4D& other) const
{
	Vector4D result(this->elements[0] + other.elements[0], this->elements[1] + other.elements[1], 
		this->elements[2] + other.elements[2], this->elements[3] + other.elements[3]);

	return result;
}

Vector4D& Vector4D::operator+=(const Vector4D& other)
{
	*this = *this + other;

	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& other) const
{
	Vector4D result(this->elements[0] - other.elements[0], this->elements[1] - other.elements[1],
		this->elements[2] - other.elements[2], this->elements[3] - other.elements[3]);

	return result;
}

Vector4D& Vector4D::operator-=(const Vector4D& other)
{
	*this = *this - other;

	return *this;
}

Vector4D Vector4D::operator*(const Vector4D& other) const
{
	Vector4D result(this->elements[0] * other.elements[0], this->elements[1] * other.elements[1],
		this->elements[2] * other.elements[2], this->elements[3] * other.elements[3]);

	return result;
}

Vector4D Vector4D::operator*(double x) const
{
	Vector4D result(this->elements[0] * x, this->elements[1] * x, this->elements[2] * x, this->elements[3] * x);

	return result;
}

Vector4D& Vector4D::operator*=(const Vector4D& other)
{
	*this = *this * other;

	return *this;
}

Vector4D& Vector4D::operator*=(double x)
{
	*this = *this * x;

	return *this;
}

Vector4D Vector4D::operator/(const Vector4D& other) const
{
	Vector4D result(this->elements[0] / other.elements[0], this->elements[1] / other.elements[1],
		this->elements[2] / other.elements[2], this->elements[3] / other.elements[3]);

	return result;
}

Vector4D& Vector4D::operator/=(const Vector4D& other)
{
	*this = *this / other;

	return *this;
}

bool Vector4D::operator==(const Vector4D& other) const
{
	for (int i = 0; i < this->ELEMENTS_COUNT; i++)
	{
		if (this->elements[i] != other.elements[i])
		{
			return false;
		}
	}
	return true;
}

bool Vector4D::operator!=(const Vector4D& other) const
{
	return !(*this == other);
}

bool Vector4D::operator<(const Vector4D& other) const
{
	for (int i = 0; i < this->ELEMENTS_COUNT; i++)
	{
		if (this->elements[i] < other.elements[i])
		{
			return true;
		}
		else if (this->elements[i] > other.elements[i])
		{
			return false;
		}
	}
	return false;
}

bool Vector4D::operator>(const Vector4D& other) const
{
	for (int i = 0; i < this->ELEMENTS_COUNT; i++)
	{
		if (this->elements[i] > other.elements[i])
		{
			return true;
		}
		else if (this->elements[i] < other.elements[i])
		{
			return false;
		}
	}
	return false;
}

bool Vector4D::operator<=(const Vector4D& other) const
{
	return !(*this > other);
}

bool Vector4D::operator>=(const Vector4D& other) const
{
	return !(*this < other);
}

Vector4D operator-(const Vector4D& vector)
{
	Vector4D negative(-vector.elements[0], -vector.elements[1], -vector.elements[2], -vector.elements[3]);

	return negative;
}

bool operator!(const Vector4D& vector)
{
	return (vector == Vector4D(0, 0, 0, 0));
}

