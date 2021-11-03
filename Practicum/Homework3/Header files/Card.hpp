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

#include <string>

class Card
{
public:
	// Constructors
	Card() = default;
	Card(std::string name, std::string effect);

	// Accessors
	virtual std::string GetName() const;
	virtual std::string GetEffect() const;

protected:
	// Properties
	std::string name;
	std::string effect;
};