# Homework 3

### `MonsterCard`

Карта чудовище

* Име (низ)
* Ефект (низ)
* Атакуващи точки (неотрицателно целочислено число)
* Защитни точки (неотрицателно целочислено число)

### `MagicCard`

Магическа карта

* Име (низ)
* Ефект (низ)
* Тип (може да е един от следните 3: "trap", "buff", "spell")

### `PendulumCard`

Пендулум карта - представлява комбинация от Карта чудовище и Магическа карта

* Име (низ)
* Ефект (низ)
* Атакуващи точки (неотрицателно целочислено число)
* Защитни точки (неотрицателно целочислено число)
* Тип (може да е един от следните 3: "trap", "buff", "spell")
* Пендулум скала ( число ∈ [ 1 ; 13 ] )

### `Deck`

Тесте

* Има име (низ);
* Съхранява неограничен брой карти чудовища;
* Съхранява неограничен брой магически карти;
* Съхранява неограничен брой пендулум карти;
* Има метод, който да връща като резултат броя на картите чудовища в тестето;
* Има метод, който да връща като резултат броя на магическитете карти в тестето;
* Има метод, който да връща като резултат броя на пендулум картите в тестето;
* Има метод, който добавя карта чудовище към тестето;
* Има метод, който добавя магическа карта към тестето;
* Има метод, който добавя пендулум карта към тестето;
* Има метод, който променя карта чудовище към тестето, като за параметри приема индекс и нова карта чудовище.
* Има метод, който променя магическа карта от тестето, като за параметри приема индекс и нова магическа карта.
* Има метод, който променя пендулум карта от тестето, като за параметри приема индекс и нова пендулум карта.
* Има метод, който премахва съдържанието на тестето и тестето остава празно.

### `Duelist`

Дуелист

* Име (низ)
* Тесте (Deck)
* Метод, който дава достъп до тестето.
* Булев метод, който по подаден аргумент име на файл записва съдържанието на тестето във файл. 
    * Връща true, ако операцията е успешна и false, ако не е.
* Булев метод, който по подаден артумент име на файл чете съдържанието му и обновява тестето както е записано във файла. 
    * Връща true, ако операцията е успешна и false, ако не е.

#### Файлът има следния формат:
* Заглавен ред, който съдържа метаданни за името на тестето, броя карти чудовища, броя магически карти и броя пендулум карти: <br>
`<deckname>|<monsterCardsCount>|<magicCardsCount>|<pendulumCardsCount>`
* monsterCardsCount на брой редове, като всеки представлява информация за карта чудовище в следния вид: <br>
`<name>|<effect>|<attackPoints>|<defencePoints>`
* magicCardsCount на брой редове, като всеки прдставлява информация за магическа карта в следния вид: <br>
`<name>|<effect>|<type>`
* pendulumCardsCount на брой редове, като всеки представлява информация за магическа карта в следния вид: <br>
`<name>|<effect>|<attackPoints>|<defencePoints>|<pendulumScale>|<type>`

Примерен файл, който представялява тесте "Magician deck" с 2 карти чудовища, 2 магически карти и 1 пендулум карта:
<pre>
Magician Deck|2|2|1
Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|3000|2500
Dark Magician|The ultimate wizard.|2500|2100
Swords of Revealing Light|Your opponent's monsters cannot declare an attack.|SPELL
Magic Cylinder|Inflict damage to your opponent equal to its ATK.|TRAP
Timegazer Magician|Your opponent cannot activate Trap Magic Cards|1200|600|8|SPELL
</pre>

### Пример

<pre>
//Examples/Example main

MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);

MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);

MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::SPELL);

MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", CardType::TRAP);

PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, CardType::SPELL);

Duelist firstDuelist("Ivan Ivanov");

firstDuelist.getDeck().setDeckname("Magician Deck");

firstDuelist.getDeck().addMonsterCard(dragon);
firstDuelist.getDeck().addMagicCard(swords);
firstDuelist.getDeck().addMonsterCard(magician);
firstDuelist.getDeck().addMagicCard(cylinder);
firstDuelist.getDeck().addPendulumCard(timegazer);

firstDuelist.display();

firstDuelist.saveDeck("magician_deck.txt");

firstDuelist.loadDeck("magician_deck.txt");
firstDuelist.display();

MagicCard box("Mystic Box", "Destroy one monster.", CardType::SPELL);
firstDuelist.getDeck().setMagicCard(1, box);

//End of Examples/Example main
</pre>
