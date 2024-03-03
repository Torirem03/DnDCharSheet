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
#include "background.h"
#include "hp.h"

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
class Dice {
private:
    int bonus;
    int sides;
public:
    Dice(int bonus, int sides) : bonus(bonus),sides(sides) {}

    int rollDice() {
        int roll = (std::rand() % sides) + 1;
        return roll + bonus;
    }
};

std::vector<int> rollAbilities(){
    std::vector<int> abilityScores;

    Dice d6(0,6);

    for (int i=0; i < 6; ++i) {
        int score = 0;
        //Roll 3 dice and sum the results
        for (int j=0; j < 3; ++j) {
            score += d6.rollDice();
        }
        abilityScores.push_back(score);
    }
    return abilityScores;
}

int main() {
    Background back; //character background
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<Spell> allSpells = Spell::parseCSV("dnd-spells.csv");
    std::vector<Spell> spellbook;
    int bonus; 
    string charName;

    if (allSpells.empty()) {
        std::cerr << "No spells found. Exiting." << std::endl;
        return 1;
    }

    cout << "Enter a name for your character: ";
    cin >> charName;
    cin.ignore();

    // tests calls for objects
    DnDClasses CharacterClass;
    HitDice Dice;
    //srand(time(0)); // random seed needed for dicerolls
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


    cout << "What is your character's history?" << endl;
    string history;
    std::cin >> history;
    back.setHistory(history);

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

    std::cout << "Enter your initiative bonus: ";
    std::cin >> bonus;

    class Dice initiative(bonus, 20);
    std::vector<int> abilityScores = rollAbilities();
    int Strength = abilityScores[0];
    int Dexterity = abilityScores[1];
    int Constitution = abilityScores[2];
    int Intelligence = abilityScores[3];
    int Wisdom = abilityScores[4];
    int Charisma = abilityScores[5];

    int initiativeRoll= initiative.rollDice();

    std::cout << "\nStrength: " << Strength;
    std::cout << "\nDexterity: " << Dexterity;
    std::cout << "\nConstitution: " << Constitution;
    std::cout << "\nIntelligence: " << Intelligence;
    std::cout << "\nWisdom: " << Wisdom;
    std::cout << "\nCharisma: " << Charisma << endl;

    std::cout << "Your initiative roll is: " << initiativeRoll << std::endl;
    std::cin.ignore();

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

    // Create an inventory and manage it
    Inventory inventory;
    inventory.manageInventory();

    printSheet(CharacterClass1, selectedRace, inventory,charName, initiativeRoll);
    return 0;
}
