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

#include "PendulumCard.hpp"

PendulumCard::PendulumCard()
{
    this->pendelumScale = this->DEFAULT_PENDELUM_SCALE;
}

PendulumCard::PendulumCard(std::string name, std::string effect, unsigned int attackPoints,
    unsigned int defencePoints, short pendelumScale, Type type)
    : MonsterCard(name, effect, attackPoints, defencePoints),
      MagicCard(name, effect, type)
{
    this->SetPendelumScale(pendelumScale);
}

std::string PendulumCard::GetName() const
{
    return this->MonsterCard::name;
}

std::string PendulumCard::GetEffect() const
{
    return this->MonsterCard::effect;
}

short PendulumCard::GetPendelumScale() const
{
    return this->pendelumScale;
}

void PendulumCard::SetPendelumScale(short value)
{
    if (value < this->MIN_PENDELUM_SCALE)
    {
        this->pendelumScale = this->MIN_PENDELUM_SCALE;
        return;
    }

    if (value > this->MAX_PENDELUM_SCALE)
    {
        this->pendelumScale = this->MAX_PENDELUM_SCALE;
        return;
    }

    this->pendelumScale = value;
}

std::ostream& operator<<(std::ostream& stream, PendulumCard& card)
{
    MonsterCard* monsterCard = &card;

    stream << (*monsterCard) << '|' << card.pendelumScale << '|' << card.GetTypeAsString();

    return stream;
}
