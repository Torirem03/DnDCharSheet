#include "hp.h"
#include <iostream>
#include <string>
using namespace std;

HP::HP(int maxHP, int currentHP): maxHP(maxHP), currentHP(currentHP) {}

void HP::setMaxHP(int maxHP) {
    this -> maxHP = maxHP;
}
void HP::setCurrentHP(int currentHP) {
    this -> currentHP = currentHP;
}
int HP::getMaxHP() {
    return maxHP;
}
int HP::getCurrentHP() {
    return currentHP;
}
void HP::PrintHP(int maxHP, int currentHP) {
    cout << "    Max HP: " << maxHP << endl;
    cout << "Current HP: " << currentHP << endl;
}
