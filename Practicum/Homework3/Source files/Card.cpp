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

#include "Card.hpp"

Card::Card(std::string name, std::string effect)
{
	this->name = name;
	this->effect = effect;
}

std::string Card::GetName() const
{
	return this->name;
}

std::string Card::GetEffect() const
{
	return this->effect;
}
