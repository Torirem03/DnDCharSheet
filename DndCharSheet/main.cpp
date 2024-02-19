#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <CharacterSheet.h>

using namespace std;

struct Spell {
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

        spells.push_back({name, classes, level, school, cast_time, range, duration, verbal, somatic, material, material_cost, description});
    }

    file.close();
    return spells;
}

void addToSpellbook(const std::string& spellName, std::vector<Spell>& spellbook, const std::vector<Spell>& allSpells) {
    for (const Spell& spell : allSpells) {
        if (spell.name == spellName) {
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
        std::cout << "Name: " << spell.name << std::endl;
        std::cout << "Level: " << spell.level << std::endl;
        std::cout << "School: " << spell.school << std::endl;
        std::cout << "Description: " << spell.description << std::endl;
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
    printSheet();
    return 0;
}
