/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefania Tsvetkova
* @idnumber 62573
* @task 2
* @compiler VC
*/

#pragma once

class MonsterCard
{
public:
	MonsterCard(); //Default Constructor
	MonsterCard(const char*, unsigned int, unsigned int); //Constructor
	MonsterCard(const MonsterCard&); //Copy constructor

	MonsterCard& operator=(const MonsterCard&); //Copy assignment operator

	~MonsterCard(); //Destructor

	//Accessors
	char* GetName();
	unsigned int GetAttackPoints();
	unsigned int GetDefencePoints();

private:
	//Constants
	static const int MAX_NAME_LENGHT = 25;

	//Properties
	char name[MAX_NAME_LENGHT + 1];
	unsigned int attackPoints;
	unsigned int defencePoints;

	//Operations
	void Copy(const MonsterCard&);
};