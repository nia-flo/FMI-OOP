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

#include <map>
#include <string>
#include <vector>

enum class WeaponType
{
	one_handed,
	two_handed
};

enum class WeaponKind
{
	axe,
	sword,
	dagger,
	mace,
	staff
};

class Weapon
{
public:
	// Static operations
	static Weapon NewAxe(WeaponType, std::pair<unsigned int, unsigned int>);
	static Weapon NewSword(WeaponType, std::pair<unsigned int, unsigned int>);
	static Weapon NewDagger(std::pair<unsigned int, unsigned int>);
	static Weapon NewMace(WeaponType, std::pair<unsigned int, unsigned int>);
	static Weapon NewStaff(std::pair<unsigned int, unsigned int>);

	// Constructors
	Weapon() = default;

	// Copy assignment operator
	Weapon& operator=(const Weapon&);

	// Accessors
	WeaponKind GetKind() const;
	WeaponType GetType() const;
	std::pair<unsigned int, unsigned int> GetHitDamage() const;
	std::vector <std::pair <std::string, double> > GetEffects() const;

	// Operations
	double WeaponScore() const;
	int UsedSlots() const;
	bool ChangeType(WeaponType); // returns true if the opperation is successful, otherwise - false
	bool ChangeKind(WeaponKind); // returns true if the opperation is successful, otherwise - false
	bool AddEffect(const std::string&, double); // returns true if the opperation is successful, otherwise - false
	bool RemoveEffect(const std::string&); // returns true if the opperation is successful, otherwise - false
	std::string ToString() const;

private:
	// Constants
	const double ONE_HANDED_COEFFICIENT = 0.75;
	const double TWO_HANDED_COEFFICIENT = 1.5;
	static const int ONE_HANDED_USED_SLOTS = 1;
	static const int TWO_HANDED_USED_SLOTS = 2;

	// Properties
	WeaponType type;
	WeaponKind kind;
	std::pair<unsigned int, unsigned int> hitDamage; // .first is the lowest possible power, .second is the highest possible power
	std::map <std::string, double> effects;

	// Constructors
	Weapon(WeaponType, WeaponKind, std::pair<unsigned int, unsigned int>);
};