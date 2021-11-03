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

#include "Duelist.hpp"

#include <iostream>

int main()
{
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, Type::spell);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, Type::trap);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, Type::spell);

	std::cout << (dragon < timegazer) << ' ' << (timegazer > cylinder) << '\n';

	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.GetDeck().SetName("Magician Deck");

	firstDuelist.GetDeck().AddCard(&dragon);
	firstDuelist.GetDeck().AddCard(&swords);
	firstDuelist.GetDeck().AddCard(&magician);
	firstDuelist.GetDeck().AddCard(&cylinder);
	firstDuelist.GetDeck().AddCard(&timegazer);

	firstDuelist.GetDeck().Shuffle();

	firstDuelist.SaveDeck("magician_deck.txt");

	MagicCard box("Mystic Box", "Destroy one monster.", 0, Type::spell);
	firstDuelist.GetDeck().ChangeCard(&box, 1);

	Duelist secondDuelist("Gosho Goshev");
	secondDuelist.GetDeck().AddCard(&dragon);
	secondDuelist.GetDeck().AddCard(&swords);
	secondDuelist.GetDeck().AddCard(&magician);
	secondDuelist.GetDeck().AddCard(&cylinder);
	secondDuelist.GetDeck().AddCard(&timegazer);

	std::cout << firstDuelist.Duel(secondDuelist) << '\n';

	firstDuelist.LoadDeck("inputFile.txt");

	std::cout << firstDuelist;

	std::cin >> swords;
	std::cout << swords << '\n';



	return 0;
}