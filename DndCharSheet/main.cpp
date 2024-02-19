#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "CharacterSheet.h"
#include "spell.h"
#include "DnDClasses.h"
#include "HitDice.h"
#include "CharacterSheet.h"

using namespace std;

void addToSpellbook(const std::string& spellName, std::vector<Spell>& spellbook, const std::vector<Spell>& allSpells) {
    for (const Spell& spell : allSpells) {
        if (spell.getName() == spellName) {
            spellbook.push_back(spell);
            std::cout << "Added spell '" << spellName << "' to spellbook." << std::endl;
            return;
        }
    }
    std::cout << "Spell '" << spellName << "' not found." << std::endl;
}

// Function to display the spellbook
void displaySpellbook(const std::vector<Spell>& spellbook) {
    if (spellbook.empty()) {
        std::cout << "Spellbook is empty." << std::endl;
        return;
    }

    std::cout << "Spellbook:" << std::endl;
    for (const Spell& spell : spellbook) {
        std::cout << "Name: " << spell.getName() << std::endl;
        std::cout << "Level: " << spell.getLevel() << std::endl;
        std::cout << "School: " << spell.getSchool() << std::endl;
        std::cout << "Description: " << spell.getDescription() << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }
}
class Initiative {
private:
    int bonus;
public:
    Initiative(int bonus) : bonus(bonus) {}

    int rollInitiative() {
        // Seed the random number generator with the current time
        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        int roll = (std::rand() % 20) + 1;
        return roll + bonus;
    }
};

int main() {
    std::vector<Spell> allSpells = Spell::parseCSV("dnd-spells.csv");
    std::vector<Spell> spellbook;
    int bonus;

    if (allSpells.empty()) {
        std::cerr << "No spells found. Exiting." << std::endl;
        return 1;
    }
    std::cout << "Enter your initiative bonus: ";
    std::cin >> bonus;

    Initiative initiative(bonus);

    int initiativeRoll= initiative.rollInitiative();
    std::cout << "Your initiative roll is: " << initiativeRoll << std::endl;
    std::cin.ignore(); // ignores the \n character

    while (true) {
        std::string spellName;
        std::cout << "Enter the name of a spell to add to your spellbook (or type 'quit' to exit): ";
        std::getline(std::cin, spellName);

        if (spellName == "quit") {
            break;
        }

        addToSpellbook(spellName, spellbook, allSpells);
    }


    std::cout << std::endl;
    displaySpellbook(spellbook);
  
    // tests calls for objects
    DnDClasses Class;
    HitDice Dice;
    srand(time(0)); // random seed needed for dicerolls
    cout << Class.getclassname() << endl; // N/A
    for (int i =0; i < 10; i++) { // 10 numbers between 1 and 8 inclusive
        cout << Dice.rollDice(Dice.getDiceType()) << " ";
    }
    Artificer Character1;
    cout << "\nCharacter1 class type: " << Character1.getclassname() << endl;
    cout << "Character1 armor: " << Character1.getarmor() << endl;
    Character1.setarmor("Light Armor");
    cout << "Character1 armor: " << Character1.getarmor() << endl;
  
    printSheet();
    return 0;
}
