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

enum Type
{
	trap,
	buff,
	spell,
	unknown
};

class MagicCard
{
public:
	MagicCard(); //Default Constructor
	MagicCard(const char*, const char*, Type); //Constructor
	MagicCard(const MagicCard&); //Copy constructor

	MagicCard& operator=(const MagicCard&); //Copy assignment operator

	~MagicCard(); //Destructor

	//Accessors
	char* GetName();
	char* GetEffect();
	Type GetType();

private:
	//Constants
	static const int MAX_NAME_LENGHT = 25;
	static const int MAX_EFFECT_LENGHT = 100;

	//Properties
	char name[MAX_NAME_LENGHT + 1];
	char effect[MAX_EFFECT_LENGHT + 1];
	Type type;

	//Operations
	void Copy(const MagicCard&);
};