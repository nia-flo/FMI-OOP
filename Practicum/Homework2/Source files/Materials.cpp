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

#include "Materials.h"

Materials::Materials()
{
	for (int i = 0; i < this->MATERIALS_COUNT; i++)
	{
		this->materials[i] = this->MIN_QUANTITY;
	}
}

unsigned int Materials::GetQuantity(MaterialType type) const
{
	int res = this->materials[static_cast<int>(type)];
	return this->materials[static_cast<int>(type)];
}

bool Materials::isFull() const
{
	return this->FullSlotsCount() == this->SLOTS;
}

bool Materials::isEmpty() const
{
	return this->UsedSlotsCount() == 0;
}

unsigned int Materials::UsedSlotsCount() const
{
	int usedSlots = 0;
	for (int i = 0; i < this->MATERIALS_COUNT; i++)
	{
		usedSlots += this->SlotsCountForType(static_cast<MaterialType>(i));
	}

	return usedSlots;
}

bool Materials::Add(MaterialType type, unsigned int quantity)
{
	this->materials[static_cast<int>(type)] += quantity;

	if (this->UsedSlotsCount() > this->SLOTS)
	{
		this->materials[static_cast<int>(type)] -= quantity;
		return false;
	}

	return true;
}

bool Materials::Remove(MaterialType type)
{
	if (this->materials[static_cast<int>(type)] == this->MIN_QUANTITY)
	{
		return false;
	}

	this->materials[static_cast<int>(type)] = this->MIN_QUANTITY;

	return true;
}

void Materials::Clear()
{
	for (int i = 0; i < this->MATERIALS_COUNT; i++)
	{
		this->materials[i] = this->MIN_QUANTITY;
	}
}

std::string Materials::ToString() const
{
	std::string str = "Materials:\n";

	str += "Essence: " + std::to_string(this->materials[static_cast<int>(MaterialType::essence)]) + "\n";
	str += "Herbs: " + std::to_string(this->materials[static_cast<int>(MaterialType::herbs)]) + "\n";
	str += "Ores: " + std::to_string(this->materials[static_cast<int>(MaterialType::ores)]) + "\n";
	str += "Cloth: " + std::to_string(this->materials[static_cast<int>(MaterialType::cloth)]) + "\n";

	return str;
}

unsigned int Materials::SlotsCountForType(MaterialType type) const
{
	int maxPerSlot = (type == MaterialType::essence ? this->MAX_ESSENS_QUANTITY_PER_SLOT : this->MAX_HERBS_ORES_CLOTH_QUANTITY_PER_SLOT);

	int usedSlots = this->materials[static_cast<int>(type)] / maxPerSlot;

	if (this->materials[static_cast<int>(type)] % maxPerSlot != 0)
	{
		usedSlots++;
	}

	return usedSlots;
}

unsigned int Materials::FullSlotsCount() const
{
	int fullSlots = this->materials[0] / this->MAX_ESSENS_QUANTITY_PER_SLOT;
	for (int i = 1; i < this->MATERIALS_COUNT; i++)
	{
		fullSlots += this->materials[i] / this->MAX_HERBS_ORES_CLOTH_QUANTITY_PER_SLOT;
	}

	return fullSlots;
}