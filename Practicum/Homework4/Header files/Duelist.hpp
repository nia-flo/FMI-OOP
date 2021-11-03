/**
* Solution to homework assignment 4
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
	Duelist(const std::string& name);

	// Accessors
	Deck& GetDeck();

	// Operations
	bool SaveDeck(const std::string& fileName); // returns true if the operation is successful, otherwise - false
	bool LoadDeck(const std::string& fileName); // returns true if the operation is successful, otherwise - false
	std::string Duel(Duelist& other); // returns the name of the winner or "no winner" if the two players are equal
	friend std::string Duel(Duelist& first, Duelist& second); // returns the name of the winner or "no winner" if the two players are equal

	// Operators
	friend std::ostream& operator<<(std::ostream& stream, const Duelist& duelist);
	friend std::istream& operator>>(std::istream& stream, Duelist& duelist);

private:
	//Properties
	std::string name;
	Deck deck;
};

