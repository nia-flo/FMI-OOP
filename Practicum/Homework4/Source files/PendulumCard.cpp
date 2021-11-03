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

#include "PendulumCard.hpp"
#include "HelperFunctions.h"

#include <algorithm>
#include <vector>

PendulumCard::PendulumCard()
{
    this->pendelumScale = this->DEFAULT_PENDELUM_SCALE;
}

PendulumCard::PendulumCard(const std::string& name, const std::string& effect, unsigned rarity, unsigned  attackPoints,
    unsigned  defencePoints, short pendelumScale, Type type)
    : Card(name, effect, rarity),
      MonsterCard(name, effect, rarity, attackPoints, defencePoints),
      MagicCard(name, effect, rarity, type)
{
    this->SetPendelumScale(pendelumScale);
}

PendulumCard::PendulumCard(const PendulumCard& pendulumCard)
    : Card(pendulumCard.name, pendulumCard.effect, pendulumCard.rarity),
      MagicCard(static_cast<MagicCard>(pendulumCard)),
      MonsterCard(static_cast<MonsterCard>(pendulumCard))
{
    this->pendelumScale = pendulumCard.pendelumScale;
}

short PendulumCard::GetPendelumScale() const
{
    return this->pendelumScale;
}

Card* PendulumCard::Copy() const
{
    return new PendulumCard(*this);
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

std::ostream& operator<<(std::ostream& stream, const PendulumCard& card)
{
    MonsterCard monsterCard = static_cast<MonsterCard>(card);

    stream << monsterCard << '|' << card.pendelumScale << '|' << card.GetTypeAsString();

    return stream;
}

std::istream& operator>>(std::istream& stream, PendulumCard& card)
{
    std::string line;
    std::getline(stream, line);

    std::vector<std::string> splittedLine = HelperFunctions::SplitLine(line, '|');

    card = HelperFunctions::CreatePendulumCard(splittedLine);

    return stream;
}
