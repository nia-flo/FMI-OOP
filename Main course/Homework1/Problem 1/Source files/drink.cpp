#pragma warning (disable : 4996)

#include "drink.hpp"

#include <cstring>

Drink::Drink()
{
	this->name = new char[1];
	strcpy(this->name, "");

	this->calories = 0;
	this->quantity = 0;
	this->price = 0;
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
{
	this->name = new char[strlen(init_name) + 1];
	strcpy(this->name, init_name);
	this->calories = init_calories;
	this->quantity = init_quantity;
	this->price = init_price;
}

Drink::Drink(const Drink& drink)
{
	this->name = nullptr;
	this->Copy(drink);
}

Drink& Drink::operator=(const Drink& drink)
{
	this->Copy(drink);

	return *this;
}

Drink::~Drink()
{
	delete[] this->name;
}

const char* Drink::get_name() const
{
	return this->name;
}

int Drink::get_calories() const
{
	return this->calories;
}

double Drink::get_quantity() const
{
	return this->quantity;
}

double Drink::get_price() const
{
	return this->price;
}

void Drink::set_name(const char* new_name)
{
	if (&(this->name) != &new_name)
	{
		delete[] this->name;
		this->name = new char[strlen(new_name) + 1];
		strcpy(this->name, new_name);
	}
}

void Drink::Copy(const Drink& drink)
{
	if (this != &drink)
	{
		this->set_name(drink.name);
		this->calories = drink.calories;
		this->quantity = drink.quantity;
		this->price = drink.price;
	}
}


