#include "spell.h"
#include <iostream>
#include <fstream>
#include <sstream>

Spell::Spell() {}

Spell::Spell(const std::string& name, const std::string& class_, int level,
             const std::string& school, const std::string& cast_time, const std::string &range,
             const std::string& duration, bool verbal, bool somatic, bool material,
             const std::string& material_cost, std::string& description)
    : name(name), class_(class_), level(level), school(school), cast_time(cast_time),
      range(range), duration(duration), verbal(verbal), somatic(somatic), material(material),
      material_cost(material_cost), description(description) {}

std::string Spell::getName() const { return name; }
std::string Spell::getClass_() const { return class_; }
int Spell::getLevel() const { return level; }
std::string Spell::getSchool() const { return school; }
std::string Spell::getCastTime() const { return cast_time; }
std::string Spell::getRange() const { return range; }
std::string Spell::getDuration() const { return duration; }
bool Spell::hasVerbal() const {return verbal; }
bool Spell::hasSomatic() const { return somatic; }
bool Spell::hasMaterial() const { return material; }
std::string Spell::getMaterialCost() const {return material_cost; }
std::string Spell::getDescription() const { return description; }

void Spell::setName(const std::string& newName) { name = newName; }
void Spell::setClass_(const std::string& newClass_) { class_ = newClass_; }
void Spell::setLevel(int newLevel) { level = newLevel; }
void Spell::setSchool(const std::string& newSchool) { school = newSchool; }
void Spell::setCastTime(const std::string& newCastTime) { cast_time = newCastTime; }
void Spell::setRange(const std::string& newRange) { range = newRange;}
void Spell::setDuration(const std::string& newDuration) { duration = newDuration; }
void Spell::setVerbal(const bool newVerbal) { verbal = newVerbal; }
void Spell::setSomatic(const bool newSomatic) { somatic = newSomatic; }
void Spell::setMaterial(const bool newMaterial) { material = newMaterial; }
void Spell:: setMaterialCost(const std::string& newMaterialCost) { material_cost = newMaterialCost; }
void Spell:: setDescription(const std::string& newDescription) { description = newDescription; }

std::vector<Spell> Spell::parseCSV(const std::string& filename) {
    std::vector<Spell> spells;
    std::ifstream file(filename);
    if (file.fail()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return spells;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, class_, school, cast_time, range, duration, material_cost, description, verbal_str, somatic_str, material_str;
        int level;
        bool verbal, somatic, material;
        char delimiter = ',';


        std::getline(iss, name, delimiter);
        std::getline(iss, class_, delimiter);
        iss >> level; iss.ignore(); //ignore comma
        std::getline(iss, school, delimiter);
        std::getline(iss, cast_time, delimiter);
        std::getline(iss, range, delimiter);
        std::getline(iss, duration, delimiter);
        std::getline(iss, verbal_str, delimiter);
        std::getline(iss, somatic_str, delimiter);
        std::getline(iss, material_str, delimiter);
        std::getline(iss, material_cost, delimiter);
        std::getline(iss, description);
        //getline can't retrieve bool
        verbal = (verbal_str == "true");
        somatic = (somatic_str == "true");
        material = (material_str == "true");

        Spell newSpell(name, class_, level, school, cast_time, range, duration, verbal, somatic, material, material_cost, description);
        spells.push_back(newSpell);
    }

    file.close();
    return spells;
}
