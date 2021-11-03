/**
*Solution to homework assignment 2
*Object Oriented Programming Course
*Faculty of Mathematics and Informatics of Sofia University
*Summer semester 2020/2021
 *
*@author Stefania Tsvetkova
*@idnumber 62573
*@task 1
*@compiler VC
*/

#pragma once

#include <vector>

#include "Materials.h"
#include "Money.h"

template <typename T>
class Backpack
{
public:
	// Copy assignment operator
	Backpack& operator=(const Backpack&) = default;

	// Accessors
	T& GetContent() const;

	// Operations
	bool IsEmpty() const;
	bool IsFull() const;
	void Clear(); // removes everything from the backpack
	bool Add(MaterialType, unsigned int); // adding Materials - returns true if the opperation is successful, otherwise - false
	bool Add(unsigned int, unsigned int); // adding Money - returns true if the opperation is successful, otherwise - false
	bool Remove(MaterialType); // removing Materials - returns true if the opperation is successful, otherwise - false
	bool Remove(unsigned int, unsigned int); // removing Money - returns true if the opperation is successful, otherwise - false
	int UsedSlotsCount() const;
	std::string ToString() const;

private:
	// Properties
	T content;
};

template<typename T>
T& Backpack<T>::GetContent() const
{
	return this->content;
}

template<typename T>
bool Backpack<T>::IsEmpty() const
{
	return this->content.isEmpty();
}

template<typename T>
bool Backpack<T>::IsFull() const
{
	return this->content.isFull();
}

template<typename T>
void Backpack<T>::Clear()
{
	this->content.Clear();
}

template<>
bool Backpack<Materials>::Add(MaterialType type, unsigned int quantity)
{
	return this->content.Add(type, quantity);
}

template<>
bool Backpack<Money>::Add(unsigned int gold, unsigned int silver)
{
	this->content.Add(gold, silver);

	return true;
}

template<>
bool Backpack<Materials>::Remove(MaterialType type)
{
	return this->content.Remove(type);
}

template<>
bool Backpack<Money>::Remove(unsigned int gold, unsigned int silver)
{
	return this->content.Remove(gold, silver);
}

template<typename T>
int Backpack<T>::UsedSlotsCount() const
{
	return this->content.UsedSlotsCount();
}

template<typename T>
std::string Backpack<T>::ToString() const
{
	std::string str = "--- Backpack ---\n";

	str += this->content.ToString();

	return str;
}
