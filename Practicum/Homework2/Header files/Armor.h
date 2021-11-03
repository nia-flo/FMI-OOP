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
#include <map>
#include <vector>

enum class ArmorType
{
	cloth,
	leather,
	mail
};

class Armor
{
public:
	// Constructors
	Armor() = default;
	Armor(ArmorType, unsigned int);

	// Copy assignment operator
	Armor& operator=(const Armor&) = default;

	// Accessors
	ArmorType GetType() const;
	unsigned int GetDefence() const;
	std::vector <std::pair <std::string, double> > GetEffects() const;

	// Operations
	double Gearscore() const;
	int UsedSlots() const;
	bool AddEffect(const std::string&, double); // returns true if the opperation is successful, otherwise - false
	bool RemoveEffect(const std::string&); // returns true if the opperation is successful, otherwise - false
	std::string ToString() const;

private:
	// Constants
	static const int USED_SLOTS = 1;

	// Properties
	ArmorType type;
	unsigned int defence;
	std::map <std::string, double> effects;
};