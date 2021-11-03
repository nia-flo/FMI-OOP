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

#include <string>

class Card
{
public:
	// Constructors
	Card();
	Card(const std::string& name, const std::string& effect, unsigned rarity);

	// Destructor
	virtual ~Card();

	// Accessors
	const std::string& GetName() const;
	const std::string& GetEffect() const;
	unsigned GetRarity() const;

	// Operations
	virtual Card* Copy() const = 0;

	// Operators
	bool operator<(const Card& other) const;
	bool operator>(const Card& other) const;

protected:
	// Constants
	static std::string DEFAULT_NAME;
	static std::string DEFAULT_EFFECT;
	static const unsigned DEFAULT_RARITY = 0;

	// Properties
	std::string name;
	std::string effect;
	unsigned rarity;
};