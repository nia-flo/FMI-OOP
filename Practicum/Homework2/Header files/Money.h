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

#include <string>

class Money
{
public:
	// Constructors
	Money();
	Money(unsigned int, unsigned int);

	// Copy assignment operator
	Money& operator=(const Money&) = default;

	// Accessors
	unsigned int GetGold() const;
	unsigned int GetSilver() const;

	// Operations
	bool isEmpty() const;
	bool isFull() const;
	unsigned int UsedSlotsCount() const;
	void Add(unsigned int, unsigned int);
	bool Remove(unsigned int, unsigned int); // returns true if the opperation is successful, otherwise - false
	void Clear(); // removes all money
	std::string ToString() const;

private:
	// Constants
	static const int MIN_MONEY = 0;
	static const int GOLD_VALUE_IN_SILVER = 100;
	static const int EMPTY_USED_SLOTS = 0;
	static const int NOT_EMPTY_USED_SLOTS = 1;

	// Properties
	double money;
};