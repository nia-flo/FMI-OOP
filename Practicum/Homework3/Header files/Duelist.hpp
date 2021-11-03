/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefania Tsvetkova
* @idnumber 62573
* @task 1
* @compiler VC
*/

#pragma once

#include "Deck.hpp"

#include <string>

class Duelist
{
public:
	// Constructors
	Duelist(std::string name);

	// Accessors
	Deck& GetDeck();

	// Operations
	bool SaveDeck(std::string fileName);
	bool LoadDeck(std::string fileName);

	// Operators
	friend std::ostream& operator<<(std::ostream& stream, Duelist& duelist);

private:
	//Properties
	std::string name;
	Deck deck;
};

