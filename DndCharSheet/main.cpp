#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <DnDClasses.h>
#include <HitDice.h>
#include <CharacterSheet.h>

using namespace std;

struct Spell {
private:
    std::string name;
    std::string classes;
    int level;
    std::string school;
    std::string cast_time;
    std::string range;
    std::string duration;
    bool verbal;
    bool somatic;
    bool material;
    std::string material_cost;
    std::string description;

public:
    std::string getName() const { return name; }
    std::string getClasses() const { return classes; }
    int getLevel() const { return level; }
    std::string getSchool() const { return school; }
    std::string getCastTime() const { return cast_time; }
    std::string getRange() const { return range; }
    std::string getDuration() const { return duration; }
    bool hasVerbalComponent() const { return verbal; }
    bool hasSomaticComponent() const { return somatic; }
    bool hasMaterialComponent() const { return material; }
    std::string getMaterialCost() const { return material_cost; }
    std::string getDescription() const { return description; }

    void setName(const std::string& newName) { name = newName; }
    void setClasses(const std::string& newClasses) { classes = newClasses; }
    void setLevel(int newLevel) { level = newLevel; }
    void setSchool(const std::string& newSchool) { school = newSchool; }
    void setCastTime(const std::string& newCastTime) { cast_time = newCastTime; }
    void setRange(const std::string& newRange) { range = newRange; }
    void setDuration(const std::string& newDuration) { duration = newDuration; }
    void setVerbalComponent(bool hasVerbal) { verbal = hasVerbal; }
    void setSomaticComponent(bool hasSomatic) { somatic = hasSomatic; }
    void setMaterialComponent(bool hasMaterial) { material = hasMaterial; }
    void setMaterialCost(const std::string& newMaterialCost) { material_cost = newMaterialCost; }
    void setDescription(const std::string& newDescription) { description = newDescription; }
};

// Function to parse CSV file and store spells in a vector
std::vector<Spell> parseCSV(const std::string& filename) {
    std::vector<Spell> spells;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return spells;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, classes, school, cast_time, range, duration, verbal_str, somatic_str, material_str, material_cost, description;
        int level;
        bool verbal, somatic, material;
        char delimiter = ',';

        std::getline(iss, name, delimiter);
        std::getline(iss, classes, delimiter);
        iss >> level; iss.ignore();
        std::getline(iss, school, delimiter);
        std::getline(iss, cast_time, delimiter);
        std::getline(iss, range, delimiter);
        std::getline(iss, duration, delimiter);
        std::getline(iss, verbal_str, delimiter);
        std::getline(iss, somatic_str, delimiter);
        std::getline(iss, material_str, delimiter);
        std::getline(iss, material_cost, delimiter);
        std::getline(iss, description);

        verbal = (verbal_str == "true");
        somatic = (somatic_str == "true");
        material = (material_str == "true");

        Spell newSpell;
        newSpell.setName(name);
        newSpell.setClasses(classes);
        newSpell.setLevel(level);
        newSpell.setSchool(school);
        newSpell.setCastTime(cast_time);
        newSpell.setRange(range);
        newSpell.setDuration(duration);
        newSpell.setVerbalComponent(verbal);
        newSpell.setSomaticComponent(somatic);
        newSpell.setMaterialComponent(material);
        newSpell.setMaterialCost(material_cost);
        newSpell.setDescription(description);

        spells.push_back(newSpell);
    }

    file.close();
    return spells;
}

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
    std::vector<Spell> allSpells = parseCSV("dnd-spells.csv");
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
