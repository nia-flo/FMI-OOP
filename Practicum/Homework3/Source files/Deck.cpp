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

#include "Deck.hpp"

Deck::Deck(std::string name)
{
    this->name = name;
}

std::vector<MagicCard> Deck::GetMagicCards() const
{
    return this->magicCards;
}

std::vector<MonsterCard> Deck::GetMonsterCards() const
{
    return this->monsterCards;
}

std::vector<PendulumCard> Deck::GetPendulumCards() const
{
    return this->pendulumCards;
}

void Deck::SetName(std::string name)
{
    this->name = name;
}

int Deck::MagicCardsCount() const
{
    return this->magicCards.size();
}

int Deck::MonsterCardsCount() const
{
    return this->monsterCards.size();
}

int Deck::PendulumCardsCount() const
{
    return this->pendulumCards.size();
}

void Deck::AddMagicCard(const MagicCard& magicCard)
{
    this->magicCards.push_back(magicCard);
}

void Deck::AddMonsterCard(const MonsterCard& monsterCard)
{
    this->monsterCards.push_back(monsterCard);
}

void Deck::AddPendulumCard(const PendulumCard& pendulumCard)
{
    this->pendulumCards.push_back(pendulumCard);
}

void Deck::ChangeMagicCard(const MagicCard magicCard, int index)
{
    if (index < 0 || index >= this->magicCards.size())
    {
        return;
    }

    magicCards[index] = magicCard;
}

void Deck::ChangeMonsterCard(const MonsterCard monsterCard, int index)
{
    if (index < 0 || index >= this->monsterCards.size())
    {
        return;
    }

    monsterCards[index] = monsterCard;
}

void Deck::ChangePendulumCard(const PendulumCard pendulumCard, int index)
{
    if (index < 0 || index >= this->pendulumCards.size())
    {
        return;
    }

    pendulumCards[index] = pendulumCard;
}

void Deck::Clear()
{
    this->magicCards.clear();
    this->monsterCards.clear();
    this->pendulumCards.clear();
}

std::ostream& operator<<(std::ostream& stream, Deck& deck)
{
    stream << deck.name << '|' << deck.MonsterCardsCount() << '|' << deck.MagicCardsCount() << '|' << deck.PendulumCardsCount() << '\n';

    for (int i = 0; i < deck.monsterCards.size(); i++)
    {
        stream << deck.monsterCards[i] << '\n';
    }

    for (int i = 0; i < deck.magicCards.size(); i++)
    {
        stream << deck.magicCards[i] << '\n';
    }

    for (int i = 0; i < deck.pendulumCards.size(); i++)
    {
        stream << deck.pendulumCards[i] << '\n';
    }

    return stream;
}

std::vector<std::string> SplitLine(std::string line, char separator)
{
    std::vector<std::string> result;

    std::string current;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == separator) {
            result.push_back(current);
            current = "";

            continue;
        }

        current += line[i];
    }
    result.push_back(current);

    return result;
}

int StringToInt(std::string number)
{
    int result = 0;
    
    for (int i = 0; i < number.size(); i++)
    {
        result *= 10;
        result += number[i] - '0';
    }

    return result;
}

MonsterCard CreateMonsterCard(const std::vector<std::string>& data)
{
    MonsterCard monsterCard(data[0], data[1], StringToInt(data[2]), StringToInt(data[3]));
    return monsterCard;
}

Type GetType(std::string typeString)
{
    if (typeString == "buff")
    {
        return Type::buff;
    }

    if (typeString == "spell")
    {
        return Type::spell;
    }

    if (typeString == "trap")
    {
        return Type::trap;
    }

    return Type::unknown;
}

MagicCard CreateMagicCard(const std::vector<std::string>& data)
{
    MagicCard magicCard(data[0], data[1], GetType(data[2]));
    return magicCard;
}

PendulumCard CreatePendulumCard(const std::vector<std::string>& data)
{
    PendulumCard pendulumCard(data[0], data[1], StringToInt(data[2]), StringToInt(data[3]), StringToInt(data[4]), GetType(data[5]));
    return pendulumCard;
}

std::istream& operator>>(std::istream& stream, Deck& deck)
{
    deck.Clear();

    std::string line;
    std::getline(stream, line);

    std::string name;
    for (int i = 0; line[i] != '|'; i++)
    {
        name += line[i];
    }

    deck.name = name;

    while (std::getline(stream, line))
    {
        std::vector<std::string> splittedLine = SplitLine(line, '|');

        if (splittedLine.size() == deck.MONSTER_CARD_PROPERTIES_IN_FILE_COUNT)
        {
            deck.AddMonsterCard(CreateMonsterCard(splittedLine));
            continue;
        }

        if (splittedLine.size() == deck.MAGIC_CARD_PROPERTIES_IN_FILE_COUNT)
        {
            deck.AddMagicCard(CreateMagicCard(splittedLine));
            continue;
        }

        if (splittedLine.size() == deck.PENDELUM_CARD_PROPERTIES_IN_FILE_COUNT)
        {
            deck.AddPendulumCard(CreatePendulumCard(splittedLine));
            continue;
        }
    }

    return stream;
}
