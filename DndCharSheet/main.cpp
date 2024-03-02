#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "CharacterSheet.h"
#include "spell.h"
#include "DnDClasses.h"
#include "HitDice.h"
#include "race.h"
#include "inventory.h"
#include "attack.h"

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
    DnDClasses CharacterClass;
    HitDice Dice;
    srand(time(0)); // random seed needed for dicerolls
    //cout << CharacterClass.getclassname() << endl; // N/A
    //for (int i =0; i < 10; i++) { // 10 numbers between 1 and 8 inclusive
    //    cout << Dice.rollDice(Dice.getDiceType()) << " ";
    //}

    // sets CharacterClass1 object to whatever dndclass user entered
    DnDClasses CharacterClass1 = setCharClass();
    cout << "Character class type: " << CharacterClass.getclassname() << endl;
    cout << "Character armor: " << CharacterClass.getarmor() << endl;
    CharacterClass.setarmor("Light Armor");
    cout << "Character armor: " << CharacterClass.getarmor() << endl;
    // available methods from DnDClasses CharacterClass1
    cout << "Character Classname: " << CharacterClass1.getclassname() << endl;
    cout << "Character Level: " << CharacterClass1.getlevel() << endl;
    cout << "Character Proficiency Bonus: " << CharacterClass1.getbonus() << endl;
    cout << "Character Features: " << CharacterClass1.getfeatures() << endl;
    cout << "Character Hit Dice Type: " << CharacterClass1.gethitDiceType() << endl;
    cout << "Character HP: " << CharacterClass1.gethp() << endl;
    cout << "Character Armor: " << CharacterClass1.getarmor() << endl;
    cout << "Character Weapons: " << CharacterClass1.getweapons() << endl;
    cout << "Character Tools: " << CharacterClass1.gettools() << endl;
    cout << "Character Saving Throws: " << CharacterClass1.getsavingthrows() << endl;
    cout << "Character Skills: " << CharacterClass1.getskills() << endl;
    cout << "Character Equipment: " << CharacterClass1.getequipment() << endl;
    cout << "Character Special Path: " << CharacterClass1.getpath() << endl;
    // wizard object test
    //Wizard temp;
    //cout << "Wizard spells: " << temp.getSpells() << endl;
  

    //Artificer Character1;
    //cout << "\nCharacter1 class type: " << Character1.getclassname() << endl;
    //cout << "Character1 armor: " << Character1.getarmor() << endl;
    //Character1.setarmor("Light Armor");
    //cout << "Character1 armor: " << Character1.getarmor() << endl;



    // Load race stats and select a race
    std::string raceFilePath = "D&D 5e Approved Race Stats Chart - Sheet1.csv";
    auto raceStats = loadRaceStats(raceFilePath);
    Race selectedRace = selectRace(raceStats);
    std::cout << "You have selected: " << selectedRace.getRace() << std::endl;

    // Create an inventory and manage it
    Inventory inventory;
    inventory.manageInventory();

    printSheet();
    return 0;
}
