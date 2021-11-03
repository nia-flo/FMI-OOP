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

#include "Inventory.h"

#include <iostream>
#include <assert.h>

void TestMoney()
{
	Money defaultMoney;
	assert(defaultMoney.GetGold() == 0);
	assert(defaultMoney.GetSilver() == 0);

	Money money(5, 80);
	assert(money.GetGold() == 5);
	assert(money.GetSilver() == 80);

	money.Add(5, 0);
	assert(money.GetGold() == 10);
	assert(money.GetSilver() == 80);

	money.Add(0, 19);
	assert(money.GetGold() == 10);
	assert(money.GetSilver() == 99);

	money.Add(0, 1);
	assert(money.GetGold() == 11);
	assert(money.GetSilver() == 0);

	assert(money.Remove(11, 30) == false);
	assert(money.GetGold() == 11);
	assert(money.GetSilver() == 0);

	money.Add(5, 0);
	assert(money.GetGold() == 16);
	assert(money.GetSilver() == 0);

	assert(money.Remove(11, 30) == true);
	assert(money.GetGold() == 4);
	assert(money.GetSilver() == 70);
}

void TestMaterials()
{

	Materials materials;

	assert(materials.Add(MaterialType::essence, 500) == false);
	assert(materials.Add(MaterialType::essence, 60) == true);
	assert(materials.Add(MaterialType::ores, 20) == true);
	assert(materials.Add(MaterialType::herbs, 80) == true);
	assert(materials.Add(MaterialType::cloth, 100) == true);
	assert(materials.Add(MaterialType::cloth, 1) == false);

	assert(materials.GetQuantity(MaterialType::essence) == 60);
	assert(materials.GetQuantity(MaterialType::ores) == 20);
	assert(materials.GetQuantity(MaterialType::herbs) == 80);
	assert(materials.GetQuantity(MaterialType::cloth) == 100);
	assert(materials.isFull() == true);

	assert(materials.Remove(MaterialType::essence) == true);

	assert(materials.GetQuantity(MaterialType::essence) == 0);
	assert(materials.GetQuantity(MaterialType::ores) == 20);
	assert(materials.GetQuantity(MaterialType::herbs) == 80);
	assert(materials.GetQuantity(MaterialType::cloth) == 100);
}

void TestBackpack()
{
	std::cout << "Backpack with money:\n\n";

	Backpack<Money> moneyBackpack;

	assert(moneyBackpack.Add(1, 5) == true);
	assert(moneyBackpack.Add(0, 5) == true);
	assert(moneyBackpack.Add(1, 57) == true);

	assert(moneyBackpack.Remove(15, 0) == false);

	assert(moneyBackpack.IsEmpty() == false);
	assert(moneyBackpack.IsFull() == false);
	assert(moneyBackpack.UsedSlotsCount() == 1);

	Backpack<Money> moneyBackpackCopy = moneyBackpack;
	assert(moneyBackpack.Add(10, 20) == true);

	std::cout << moneyBackpack.ToString() << '\n';

	std::cout << moneyBackpack.ToString() << '\n';

	moneyBackpack.Clear();

	assert(moneyBackpack.IsEmpty() == true);
	assert(moneyBackpack.IsFull() == false);
	assert(moneyBackpack.UsedSlotsCount() == 0);

	std::cout << '\n';

	std::cout << "Backpack with materials:\n";

	Backpack<Materials> materialsBackpack;

	assert(materialsBackpack.Add(MaterialType::essence, 500) == false);
	assert(materialsBackpack.Add(MaterialType::essence, 60) == true);
	assert(materialsBackpack.Add(MaterialType::ores, 20) == true);
	assert(materialsBackpack.Add(MaterialType::herbs, 80) == true);
	assert(materialsBackpack.Add(MaterialType::cloth, 100) == true);
	assert(materialsBackpack.Add(MaterialType::cloth, 1) == false);

	assert(materialsBackpack.IsFull() == true);
	assert(materialsBackpack.UsedSlotsCount() == 16);

	assert(materialsBackpack.Remove(MaterialType::cloth) == true);

	assert(materialsBackpack.IsFull() == false);
	assert(materialsBackpack.UsedSlotsCount() == 11);

	Backpack<Materials> materialsCopy = materialsBackpack;
	assert(materialsCopy.Add(MaterialType::cloth, 10) == true);

	std::cout << materialsBackpack.ToString() << '\n';

	std::cout << materialsCopy.ToString() << '\n';

	materialsBackpack.Clear();

	assert(materialsBackpack.IsEmpty() == true);

	std::cout << '\n';
}

void TestArmor()
{

	Armor defaultArmor;

	Armor armorLeather(ArmorType::leather, 15);
	assert(armorLeather.GetType() == ArmorType::leather);
	assert(armorLeather.GetDefence() == 15);

	Armor armorCloth(ArmorType::cloth, 15);
	assert(armorCloth.GetType() == ArmorType::cloth);
	assert(armorCloth.GetDefence() == 15);

	assert(armorCloth.AddEffect("effect 1", -5) == false);
	assert(armorCloth.AddEffect("effect 1", 5.5) == true);
	assert(armorCloth.AddEffect("effect 1", 8.99) == true);
	assert(armorCloth.AddEffect("effect 2", 10.6) == true);;
	assert(armorCloth.AddEffect("effect 3", 44) == true);

	assert(armorCloth.RemoveEffect("nonexistent") == false);
	assert(armorCloth.RemoveEffect("effect 3") == true);

	std::vector<std::pair<std::string, double>> armorClothEffects = armorCloth.GetEffects();
	assert(armorClothEffects.size() == 2);
	assert(armorClothEffects[0].first == "effect 1");
	assert(armorClothEffects[0].second == 8.99);
	assert(armorClothEffects[1].first == "effect 2");
	assert(armorClothEffects[1].second == 10.6);

	assert(armorCloth.Gearscore() == 19.59);
}

void TestWeapon()
{
	Weapon defaultWeapon;

	Weapon axe = Weapon::NewAxe(WeaponType::one_handed, { 10, 100 });
	assert(axe.GetKind() == WeaponKind::axe);
	assert(axe.GetType() == WeaponType::one_handed);
	assert(axe.GetHitDamage().first == 10);
	assert(axe.GetHitDamage().second == 100);
	assert(axe.WeaponScore() == 55);

	Weapon dagger = Weapon::NewDagger({ 100, 200 });
	assert(dagger.GetKind() == WeaponKind::dagger);
	assert(dagger.GetType() == WeaponType::one_handed);
	assert(dagger.GetHitDamage().first == 100);
	assert(dagger.GetHitDamage().second == 200);
	assert(dagger.WeaponScore() == 150);

	Weapon mace = Weapon::NewMace(WeaponType::two_handed, { 120, 700 });
	assert(mace.GetKind() == WeaponKind::mace);
	assert(mace.GetType() == WeaponType::two_handed);
	assert(mace.GetHitDamage().first == 120);
	assert(mace.GetHitDamage().second == 700);
	assert(mace.WeaponScore() == 410);

	Weapon staff = Weapon::NewStaff({ 0, 15 });
	assert(staff.GetKind() == WeaponKind::staff);
	assert(staff.GetType() == WeaponType::two_handed);
	assert(staff.GetHitDamage().first == 0);
	assert(staff.GetHitDamage().second == 15);
	assert(staff.WeaponScore() == 7.5);

	Weapon sword = Weapon::NewSword(WeaponType::one_handed, { 50, 700 });
	assert(sword.GetKind() == WeaponKind::sword);
	assert(sword.GetType() == WeaponType::one_handed);
	assert(sword.GetHitDamage().first == 50);
	assert(sword.GetHitDamage().second == 700);
	assert(sword.WeaponScore() == 375);

	assert(axe.AddEffect("effect 1", -5) == false);
	assert(axe.AddEffect("effect 1", 5.5) == true);
	assert(axe.AddEffect("effect 1", 8.99) == true);
	assert(axe.AddEffect("effect 2", 10.6) == true);
	assert(axe.AddEffect("effect 3", 44) == true);

	assert(axe.RemoveEffect("nonexistent") == false);
	assert(axe.RemoveEffect("effect 3") == true);

	std::vector<std::pair<std::string, double>> axeEffects = axe.GetEffects();
	assert(axeEffects.size() == 2);
	assert(axeEffects[0].first == "effect 1");
	assert(axeEffects[0].second == 8.99);
	assert(axeEffects[1].first == "effect 2");
	assert(axeEffects[1].second == 10.6);

	assert(axe.WeaponScore() == 69.6925);

	assert(axe.ChangeType(WeaponType::two_handed) == true);
	assert(axe.GetType() == WeaponType::two_handed);
	assert(axe.ChangeKind(WeaponKind::dagger) == false);
	assert(axe.GetKind() == WeaponKind::axe);
	assert(axe.ChangeKind(WeaponKind::staff) == true);
	assert(axe.GetKind() == WeaponKind::staff);
	assert(axe.ChangeType(WeaponType::one_handed) == false);
	assert(axe.GetType() == WeaponType::two_handed);
}

void TestEquipment()
{
	std::cout << "Equipment with armor:\n";

	Equipment<Armor> armorEquipment;

	assert(armorEquipment.IsEmpty() == true);

	Armor armorCloth(ArmorType::cloth, 15);
	armorCloth.AddEffect("effect 1", 8.99);
	armorCloth.AddEffect("effect 2", 10.6);
	assert(armorEquipment.Add(armorCloth) == true);

	armorCloth.AddEffect("effect 3", 10);
	assert(armorEquipment.Add(armorCloth) == true);

	for (int i = 0; i < 22; i++)
	{
		assert(armorEquipment.Add(armorCloth) == true);
	}
	assert(armorEquipment.Add(armorCloth) == false);

	std::pair<bool, Armor&> best = armorEquipment.Best();

	assert(armorEquipment.Best().first == true);
	assert(armorEquipment.Best().second.GetType() == ArmorType::cloth);
	assert(armorEquipment.Best().second.Gearscore() == 29.59);

	assert(armorEquipment.IsFull() == true);

	Equipment<Armor> armorEquipmentCopy = armorEquipment;

	assert(armorEquipmentCopy.Remove(ArmorType::cloth) == true);
	assert(armorEquipmentCopy.Remove(ArmorType::cloth) == false);

	std::cout << armorEquipment.ToString() << '\n';
	std::cout << armorEquipmentCopy.ToString() << '\n';

	assert(armorEquipment.UsedSlotsCount() == 24);
	assert(armorEquipment.IsEmpty() == false);
	assert(armorEquipment.IsFull() == true);


	std::cout << "Equipment with weapon\n";

	Equipment<Weapon> weaponEquipment;

	assert(weaponEquipment.IsEmpty() == true);

	Weapon axe = Weapon::NewAxe(WeaponType::one_handed, { 10, 100 });
	assert(weaponEquipment.Add(axe) == true);

	Weapon dagger = Weapon::NewDagger({ 100, 200 });
	assert(weaponEquipment.Add(dagger) == true);

	Weapon mace = Weapon::NewMace(WeaponType::two_handed, { 120, 700 });
	assert(weaponEquipment.Add(mace) == true);

	Weapon staff = Weapon::NewStaff({ 0, 15 });
	assert(weaponEquipment.Add(staff) == true);

	Weapon sword = Weapon::NewSword(WeaponType::one_handed, { 50, 700 });
	assert(weaponEquipment.Add(sword) == true);

	for (int i = 0; i < 8; i++)
	{
		assert(weaponEquipment.Add(mace) == true);
	}
	assert(weaponEquipment.Add(mace) == false);

	assert(weaponEquipment.UsedSlotsCount() == 23);
	assert(weaponEquipment.IsEmpty() == false);
	assert(weaponEquipment.IsFull() == false);

	assert(weaponEquipment.Add(sword) == true);

	assert(weaponEquipment.UsedSlotsCount() == 24);
	assert(weaponEquipment.IsEmpty() == false);
	assert(weaponEquipment.IsFull() == true);

	assert(weaponEquipment.Remove(WeaponKind::mace) == true);
	assert(weaponEquipment.Remove(WeaponKind::mace) == false);

	std::cout << weaponEquipment.ToString() << '\n';
}

void TestInventory()
{
	Backpack<Money> moneyBackpack;
	moneyBackpack.Add(1, 5);
	moneyBackpack.Add(0, 5);
	moneyBackpack.Add(1, 57);

	Inventory<Backpack<Money>> moneyInventory(moneyBackpack);

	std::cout << moneyInventory << '\n';

	Backpack<Materials> materialsBackpack;
	materialsBackpack.Add(MaterialType::essence, 60);
	materialsBackpack.Add(MaterialType::ores, 20);
	materialsBackpack.Add(MaterialType::herbs, 80);
	materialsBackpack.Add(MaterialType::cloth, 100);

	Inventory<Backpack<Materials>> materialsInventory(materialsBackpack);

	std::cout << materialsInventory << '\n';

	Backpack<Materials> materialsBackpack2;
	materialsBackpack2.Add(MaterialType::essence, 5);
	materialsBackpack2.Add(MaterialType::ores, 6);
	materialsBackpack2.Add(MaterialType::herbs, 7);
	materialsBackpack2.Add(MaterialType::cloth, 8);

	materialsInventory.ChangeContent(materialsBackpack2);

	std::cout << materialsInventory << '\n';

	assert(materialsInventory.Add(MaterialType::cloth, 100) == true);
	assert(materialsInventory.Remove(MaterialType::cloth) == true);
	assert(materialsInventory.Remove(MaterialType::cloth) == false);
}

int main()
{

	TestMoney();

	TestMaterials();

	TestBackpack();

	TestArmor();

	TestWeapon();

	TestEquipment();

	TestInventory();

	return 0;
}