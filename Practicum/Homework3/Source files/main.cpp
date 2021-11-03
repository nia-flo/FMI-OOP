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

#include "Duelist.hpp"

#include <iostream>

int main()
{
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", Type::spell);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", Type::trap);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, Type::buff);
	
	Deck deck("test deck");
	deck.AddMonsterCard(dragon);
	deck.AddMonsterCard(magician);
	deck.AddMagicCard(swords);
	deck.AddMagicCard(cylinder);
	deck.AddPendulumCard(timegazer);

	std::cout << deck << '\n';

	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.GetDeck().SetName("Magician Deck");
	firstDuelist.GetDeck().AddMonsterCard(dragon);
	firstDuelist.GetDeck().AddMagicCard(swords);
	firstDuelist.GetDeck().AddMonsterCard(magician);
	firstDuelist.GetDeck().AddMagicCard(cylinder);
	firstDuelist.GetDeck().AddPendulumCard(timegazer);
	std::cout << firstDuelist << '\n';
	firstDuelist.SaveDeck("magician_deck.txt");
	firstDuelist.LoadDeck("testInput.txt");
	firstDuelist.SaveDeck("magician_deck.txt");
	std::cout << firstDuelist << '\n';
	
	MagicCard box("Mystic Box", "Destroy one monster.", Type::spell);

	firstDuelist.GetDeck().ChangeMagicCard(box, 1);

	return 0;
}