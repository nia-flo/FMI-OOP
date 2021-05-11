#pragma once

#include "drink.hpp"

class VendingMachine {
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);

    ~VendingMachine();

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;

    //To Delete this
    void print();
private:
    Drink* drinks;
    int drinksCount, drinksCapacity;
    double income;

    void Copy(const VendingMachine&);
    int findByName(const char*);
};
