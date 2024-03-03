#include "background.h"
#include <algorithm>
#include <iostream>

Background::Background() {}

void Background::setHistory(string history) {
    this -> history = history;
}
void Background::setLanguages(vector<string> language) {
    this ->language = language;
}
void Background::setSkills(vector<string> skill) {
    this -> skill = skill;
}
void Background::setWeapons(vector<string> weapon) {
    this -> weapon = weapon;
}
void Background::setArmors(vector<string> armor) {
    this -> armor = armor;
}
void Background::setEquipments(vector<string> equipment) {
    this -> equipment = equipment;
}

string Background::getHistory() {
    return history;
}
vector<string> Background::getLanguages() {
    return language;
}
vector<string> Background::getSkills() {
    return skill;
}
vector<string> Background::getWeapons() {
    return weapon;
}
vector<string> Background::getArmors() {
    return armor;
}
vector<string> Background::getEquipments() {
    return equipment;
}

 void Background::print() {
    sort(language.begin(), language.end());
    sort(skill.begin(), skill.end());


    cout << endl << "Character History: " << endl << endl;
    cout << history << endl << endl;

    cout << "Languages Known: " << language.size() << endl << endl;
    for (int i = 0; i < language.size(); i++) {
        cout << language.at(i) << endl;
    }

    cout << endl << "Skill Proficiency: " << skill.size() << endl << endl;
    for (int i = 0; i < skill.size(); i++) {
        cout << skill.at(i) << endl;
    }

    cout << endl << "Weapon Proficiency: " << weapon.size() << endl << endl;
    for (int i = 0; i < weapon.size(); i++) {
        cout << weapon.at(i) << endl;
    }

    cout << endl << "Armor Proficiency: " << armor.size() << endl << endl;
    for (int i = 0; i < armor.size(); i++) {
        cout << armor.at(i) << endl;
    }

    cout << endl << "Equipment on hand: " << equipment.size() << endl << endl;
    for (int i = 0; i < equipment.size(); i++) {
       cout << equipment.at(i) << endl;
    }

 }
