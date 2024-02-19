#include "background.h"
#include <iostream>
#include <string>
using namespace std;

Background::Background() {}

void Background::setHistory(string history) {
    this -> history = history;
}
void Background::setLanguage(string language) {
    this -> language = language;
}
void Background::setSkill(string skill) {
    this -> skill = skill;
}
void Background::setWeapon(string weapon) {
    this -> weapon = weapon;
}
void Background::setArmor(string armor) {
    this -> armor = armor;
}
void Background::setEquipment(string equipment) {
    this -> equipment = equipment;
}


string Background::getLanguage() {
    return language;
}
string Background::getSkill() {
    return skill;
}
string Background::getWeapon() {
    return weapon;
}
string Background::getArmor() {
    return armor;
}
string Background::getEquipment() {
    return equipment;
}
/*
string Languages(vector<string> newLanguages, int numberOfLanguages) {
    for (int i = 0; i < numberOfLanguages; i++) {

        return ;
    }
}
*/
