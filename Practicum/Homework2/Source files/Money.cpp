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

#include "Money.h"

#include <cmath>

Money::Money()
{
    this->money = this->MIN_MONEY;
}

Money::Money(unsigned int gold, unsigned int silver)
{
    this->money = gold + (double)silver / this->GOLD_VALUE_IN_SILVER;
}

unsigned int Money::GetGold() const
{
    return (int)this->money;
}

unsigned int Money::GetSilver() const
{
    return (int)(std::round(this->money * this->GOLD_VALUE_IN_SILVER)) % this->GOLD_VALUE_IN_SILVER;
}

bool Money::isEmpty() const
{
    return this->money == this->MIN_MONEY;
}

bool Money::isFull() const
{
    return false;
}

unsigned int Money::UsedSlotsCount() const
{
    if (this->isEmpty())
    {
        return this->EMPTY_USED_SLOTS;
    }

    return this->NOT_EMPTY_USED_SLOTS;
}

void Money::Add(unsigned int gold, unsigned int silver)
{
    this->money += gold + (double)silver / this->GOLD_VALUE_IN_SILVER;
}

bool Money::Remove(unsigned int gold, unsigned int silver)
{
    double toRemove = gold + (double)silver / this->GOLD_VALUE_IN_SILVER;

    if (this->money < toRemove)
    {
        return false;
    }

    this->money -= toRemove;

    return true;
}

void Money::Clear()
{
    this->money = this->MIN_MONEY;
}

std::string Money::ToString() const
{
    std::string str = "Money:\n";

    str += "Gold: " + std::to_string(this->GetGold()) + "\n";
    str += "Silver: " + std::to_string(this->GetSilver()) + "\n";

    return str;
}
