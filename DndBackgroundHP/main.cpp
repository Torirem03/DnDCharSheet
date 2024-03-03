#include <iostream>
#include "background.h"
#include "hp.h"
#include <string>
#include <vector>
using namespace std;

int main() {

    int maxHP = 0;
    int currentHP = 0;
    HP hitPoints (maxHP, currentHP);
    Background back;
    int numberOfLanguages;
    string history;
    vector<string> languages;
    vector<string> skills;
    vector<string> weapons;
    vector<string> armors;
    vector<string> equipments;
    string language;
    string skill;
    string weapon;
    string armor;
    string equipment;
    int i;
    int numberOfSkills;
    int numberOfWeapons;
    int numberOfArmors;
    int numberOfEquipments;


    //  cin >> maxHP;
    // hitPoints.setMaxHP(maxHP);

    //  cin >> currentHP;
    // hitPoints.setCurrentHP(currentHP);

    // cout << hitPoints.getCurrentHP();

    //  //hitPoints.PrintHP(maxHP, currentHP);

    cout << "What is your character's history?" << endl;
    getline(cin, history);
    back.setHistory(history);

    cout << "Number of languages: " << endl;
    cin >> numberOfLanguages;

    for (i = 0; i < numberOfLanguages; i++) {
        cout << "Language: " << endl;
        cin >> language;
        languages.push_back(language);
    }
    back.setLanguages(languages);

    cout << "Number of Skills: " << endl;
    cin >> numberOfSkills;

    for (i = 0; i < numberOfSkills; i++) {
        cout << "Skill: " << endl;
        cin >> skill;
        skills.push_back(skill);
    }
    back.setSkills(skills);

    cout << "Number of Weapon Proficiencies: " << endl;
    cin >> numberOfWeapons;

    for (i = 0; i < numberOfWeapons; i++) {
        cout << "Weapon: " << endl;
        cin >> weapon;
        weapons.push_back(weapon);
    }
    back.setWeapons(weapons);

    cout << "Number of Armor Proficiencies: " << endl;
    cin >> numberOfArmors;

    for (i = 0; i < numberOfArmors; i++) {
        cout << "Armor: " << endl;
        cin >> armor;
        armors.push_back(armor);
    }
    back.setArmors(armors);

    cout << "Number of Equipment : " << endl;
    cin >> numberOfEquipments;

    for (i = 0; i < numberOfEquipments; i++) {
        cout << "Equipment: " << endl;
        cin >> equipment;
        weapons.push_back(equipment);
    }
    back.setWeapons(equipments);

    back.print();






    return 0;
}
