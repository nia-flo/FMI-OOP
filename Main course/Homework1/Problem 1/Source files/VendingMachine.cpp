#include "VendingMachine.hpp"

#include <cstring>
#include <iostream>

VendingMachine::VendingMachine()
{
	this->drinksCount = 0;
	this->drinksCapacity = 1;
	this->income = 0;

	this->drinks = new Drink[drinksCapacity];
}

VendingMachine::VendingMachine(const VendingMachine& from)
{
	this->Copy(from);
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (this != &from)
	{
		delete[] this->drinks;
		this->Copy(from);
	}

	return *this;
}

VendingMachine::~VendingMachine()
{
	delete[] this->drinks;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
	if (this->findByName(to_add.get_name()) != -1)
	{
		return false;
	}

	if (this->drinksCount < this->drinksCapacity)
	{
		this->drinks[this->drinksCount] = to_add;
		this->drinksCount++;

		return true;
	}

	Drink* newDrinks = new Drink[this->drinksCapacity + 1];
	this->drinksCapacity++;

	for (int i = 0; i < this->drinksCount; i++)
	{
		newDrinks[i] = this->drinks[i];
	}
	newDrinks[this->drinksCount] = to_add;
	this->drinksCount++;

	delete[] this->drinks;
	this->drinks = newDrinks;

	return true;
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
	int drinkIndex = this->findByName(drink_name);

	if (drinkIndex == -1)
	{
		return 2;
	}

	this->income += money;

	if (money >= this->drinks[drinkIndex].get_price())
	{
		for (int i = drinkIndex; i < this->drinksCount - 1; i++)
		{
			this->drinks[i] = this->drinks[i + 1];
		}
		this->drinksCount--;

		return 0;
	}

	return 1;
}

double VendingMachine::get_income() const
{
	return this->income;
}

void VendingMachine::print()
{

	for (int i = 0; i < this->drinksCount; i++)
	{
		std::cout << this->drinks[i].get_name() << ' ';
	}
	std::cout << '\n';
}

void VendingMachine::Copy(const VendingMachine& vendingMachine)
{
	this->drinksCount = vendingMachine.drinksCount;
	this->drinksCapacity = vendingMachine.drinksCapacity;

	this->drinks = new Drink[drinksCapacity];

	for (int i = 0; i < this->drinksCount; i++)
	{
		this->drinks[i] = vendingMachine.drinks[i];
	}

	this->income = vendingMachine.income;
}

int VendingMachine::findByName(const char* drinkName)
{
	for (int i = 0; i < this->drinksCount; i++)
	{
		if (strcmp(this->drinks[i].get_name(), drinkName) == 0)
		{
			return i;
		}
	}

	return -1;
}




