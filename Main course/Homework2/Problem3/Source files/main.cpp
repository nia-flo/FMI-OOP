#include "Vector4D.hpp"

#include <iostream>

int main()
{
	Vector4D vector(1, 2, 3, 4), vector2(5, 6, 7, 8);
	Vector4D negative = -vector;

	Vector4D sum;
	sum = vector + vector2;

	vector[0] = 99;

	vector += negative;

	vector -= vector2;

	vector = Vector4D(1, 2, 3, 4);
	vector *= vector2;

	vector /= vector2;


	bool res = vector == vector2;
	res = vector != vector2;
	res = vector < vector2;
	res = vector <= vector2;
	res = vector > vector2;
	res = vector >= vector2;
	res = !vector;
	res = !Vector4D(0, 0, 0, 0);
	res = Vector4D(-2, 0, 0, 0) < Vector4D(-1, 0, 0, 0);

	return 0;
}