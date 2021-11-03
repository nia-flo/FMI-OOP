# Homework 4

### `Card`

Карта – абстрактен клас

* Име (низ)
* Ефект (низ)
* Рядкост/Rarity(неотрицателно целочислено число)
* Предефинирайте operator> и operator<, като картите се сравняват по тяхното rarity.

### `MonsterCard`

Карта чудовище

* Име (низ)
* Ефект (низ)
* Рядкост/Rarity(неотрицателно целочислено число)
* Атакуващи точки (неотрицателно целочислено число)
* Защитни точки (неотрицателно целочислено число)

### `MagicCard`

Магическа карта

* Име (низ)
* Ефект (низ)
* Рядкост/Rarity(неотрицателно целочислено число)
* Тип (може да е един от следните 3: "trap", "buff", "spell")

### `PendulumCard`

Пендулум карта - представлява комбинация от Карта чудовище и Магическа карта:

* Име (низ)
* Ефект (низ)
* Рядкост/Rarity(неотрицателно целочислено число)
* Атакуващи точки (неотрицателно целочислено число)
* Защитни точки (неотрицателно целочислено число)
* Тип (може да е един от следните 3: "trap", "buff", "spell")
* Пендулум скала ( число ∈ [ 1 ; 13 ] )

### `Deck`

Тесте

* Име (низ);
* Хетерогенен контейнер за картите
* Има методи, които да връщат като резултат броя на:
    * картите чудовища в тестето;
    * магическитете карти в тестето;
    * пендулум картите в тестето;
    * всички карти в тестето;
* Има метод, който добавя карта към тестето
* Има метод, който променя карта към тестето, като за параметри приема индекс и нова картa. (Пояснение: може да се променя само карта от същия тип)
* Има метод, който премахва съдържанието на тестето и тестето остава празно.
* Има метод, който разбърква съдържанието на тестето (shuffle).

### `Duelist`

Дуелист

* Име (низ)
* Тесте (Deck)
* Метод, който дава достъп до тестето.
* Булев метод, който по подаден аргумент име на файл записва съдържанието на тестето във файл. 
    * Връща true, ако операцията е успешна и false, ако не е.
* Булев метод, който по подаден артумент име на файл чете съдържанието му и обновява тестето както е записано във файла. 
    * Връща true, ако операцията е успешна и false, ако не е.
* Метод duel, който симулира дуел между двама дуелисти:
    * Дуел може да се състои между дуелисти, чиито тестета имат равен брой карти, иначе дуелът не може да се проведе.
    * Преди да започне, тестетата на дуелистите трябва да се разбъркат.
    * Тестетата се сравняват карта по карта, посредством предефинираните оператори > и <.
    * Когато карта от тестето на първия дуелист е > от карта от тестето на втория, се брои като точка за първия, а когато карта от тестето на първия е < от карта от тестето на втория, се брои като точка за втория
    * Ако имат еднакво rarity, не се отчита точка за нито един от дуелистите.
    * Дуелът се печели от играчът с повече точки. Ако точките им са равни, дуелът завършва с равенство.

#### Файлът има следния формат:
* Заглавен ред, който съдържа метаданни за името на тестето, броя карти, броя карти чудовища, броя магически карти и броя пендулум карти:
`<deckname>|<CardsCount>|<monsterCardsCount>|<magicCardsCount>|<pendulumCardsCount>`
* monsterCardsCount на брой редове, като всеки представлява информация за карта чудовище в следния вид:
`<name>|<effect>|<rarity>|<attackPoints>|<defencePoints>`
* magicCardsCount на брой редове, като всеки прдставлява информация за магическа карта в следния вид:
`<name>|<effect>|<rarity> |<type>`
* pendulumCardsCount на брой редове, като всеки представлява информация за магическа карта в следния вид:
`<name>|<effect>|<rarity>|<attackPoints>|<defencePoints>|<pendulumScale>|<type>`

Примерен файл, който представялява тесте "Magician deck" с 2 карти чудовища, 2 магически карти и 1 пендулум карта (общо 5 карти):

<pre>
Magician Deck|5|2|2|1
Blue-Eyes White Dragon|This legendary dragon is a powerful engine of destruction.|0|3000|2500
Dark Magician|The ultimate wizard.|1|2500|2100
Swords of Revealing Light|Your opponent's monsters cannot declare an attack.|2|SPELL
Magic Cylinder|Inflict damage to your opponent equal to its ATK.|3|TRAP
Timegazer Magician|Your opponent cannot activate Trap Magic Cards|4|1200|600|8|SPELL
</pre>

### Пример

<pre>
//Examples/Example main

MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
MonsterCard magician("Dark Magician", "The ultimate wizard.", 23, 2500, 2100);
MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 123, CardType::SPELL);
MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 9, CardType::TRAP);
PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 3, 1200, 600, 8, CardType::SPELL);
Duelist firstDuelist("Ivan Ivanov");
firstDuelist.getDeck().setDeckname("Magician Deck");

firstDuelist.getDeck().addCard(&dragon);
firstDuelist.getDeck().addCard(&swords);
firstDuelist.getDeck().addCard(&magician);
firstDuelist.getDeck().addCard(&cylinder);
firstDuelist.getDeck().addCard(&timegazer);

firstDuelist.getDeck().shuffle();

firstDuelist.safeDeck("magician_deck.txt");

MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
firstDuelist.getDeck().setCard(1, &box);

Duelist secondDuelist("Gosho Goshev");
secondDuelist.getDeck().addCard(&dragon);
secondDuelist.getDeck().addCard(&swords);
secondDuelist.getDeck().addCard(&magician);
secondDuelist.getDeck().addCard(&cylinder);
secondDuelist.getDeck().addCard(&timegazer);

//End of Examples/Example main
</pre>
