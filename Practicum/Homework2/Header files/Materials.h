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

enum class MaterialType
{
	essence,
	herbs,
	ores,
	cloth
};

class Materials
{
public:
	// Constructors
	Materials();

	// Copy assignment operator
	Materials& operator=(const Materials&) = default;

	// Accessors
	unsigned int GetQuantity(MaterialType) const;

	// Operations
	bool isFull() const;
	bool isEmpty() const;
	unsigned int UsedSlotsCount() const;
	bool Add(MaterialType, unsigned int);  // returns true if the opperation is successful, otherwise - false
	bool Remove(MaterialType); // returns true if the opperation is successful, otherwise - false
	void Clear(); // removes all materials
	std::string ToString() const;

private:
	// Constants
	static const int MIN_QUANTITY = 0;
	static const int MATERIALS_COUNT = 4;
	static const int MAX_ESSENS_QUANTITY_PER_SLOT = 10;
	static const int MAX_HERBS_ORES_CLOTH_QUANTITY_PER_SLOT = 20;
	static const int SLOTS = 16;

	// Properties
	unsigned int materials[MATERIALS_COUNT];

	// Operations
	unsigned int SlotsCountForType(MaterialType) const;
	unsigned int FullSlotsCount() const;
};