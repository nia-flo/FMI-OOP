# Problem 1
A program for managing vending machine with drinks

## Drink
Every drink has a name, quantity, calories and price.

## VendingMachine
Every vending machine can:
* add a drink to the machine
  * if there is already a drink with the new drink's name, the new drink is not added
* buy a drink
  * if the drink exists in the machine and the amount of money for it is enough, the drink is removed from the machine and the money is added to the machine's income
  * if the drink exists in the machine but the amount of money for it isn't enough, the drink isn't removed from the machine but the money is added to the machine's income
  * if the drink doesn't exist in the machine, the amount of money for it isn't added to the machine's income
* get the machine's income

