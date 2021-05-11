#include "VendingMachine.hpp"

#include <iostream>

int main()
{
	VendingMachine vm;
	VendingMachine vm2(vm);
	
	Drink empty;
	Drink cola("cola", 150, 0.5, 1.6);
	Drink water("water", 0, 0.5, 0.6);
	Drink water2(water);
	Drink beer("beer", 5, 5, 5);

	bool exit = vm2.add_drink(cola);
	exit = vm2.add_drink(water);
	exit = vm2.add_drink(water2);
	exit = vm2.add_drink(beer);

	vm2.print();

	int res = vm2.buy_drink("cola", 1.2);
	res = vm2.buy_drink("water", 0.15);
	res = vm2.buy_drink("water", 0.6);

	vm2.print();

	beer = water;

	exit = vm2.add_drink(beer);

	vm = vm2;

	vm.print();

	return 0;
}