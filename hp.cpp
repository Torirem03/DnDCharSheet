#include "hp.h"
#include <iostream>
#include <string>

using namespace std;

HP::HP() {

}

void HP::setInitialHealth(int initialHealth) {
    this -> initialHealth = initialHealth;
}
void HP::setHealthPerLevel(int healthPerLevel) {
    this -> healthPerLevel = healthPerLevel;
}
void HP::setTempHitPoints(int tempHitPoints) {
    this -> tempHitPoints = tempHitPoints;
}
void HP::setNumberOfTurns(int numberOfTurns) {
    this -> numberOfTurns = numberOfTurns;
}
void HP::setHealthPotion(int healthPotion) {
    this -> healthPotion = healthPotion;
}
void HP::setCurrentHealth(int currentHealth) {
    this -> currentHealth = currentHealth;
}
void HP::setCurrentLevel(int currentLevel) {
    this -> currentLevel = currentLevel;
}
int HP::getInitialHealth() {
    return initialHealth;
}
int HP::getMaxHealth() {
    return maxHealth;
}
int HP::getHealthPerLevel() {
    return healthPerLevel;
}
int HP::getNumberOfTurns() {
    return numberOfTurns;
}
int HP::getHealthPotion() {
    return healthPotion;
}
int HP::getCurrentHealth() {
    return currentHealth;
}
int HP::getCurrentLevel() {
    return currentLevel;
}

int HP::MaxHealth(int initialHealth, int healthPerLevel, int currentLevel) {
    int maxHealth = initialHealth + (healthPerLevel * (currentLevel - 1));
    return maxHealth;
}
int HP::TempHealth(int maxHealth, int tempHitPoints) {
    int tempHealth = maxHealth + tempHitPoints;
    return tempHealth;
}

int HP::CurrentHealth(int healthPotion, int currentHealth, int maxHealth) {
    int healthRestoration;

    if (currentHealth == maxHealth) {
        cout << "HP is full. " << endl;
        return currentHealth;
    }
    else {
        if ((currentHealth + healthPotion) > maxHealth) {
            healthRestoration = (maxHealth - currentHealth);
            currentHealth = maxHealth;
            cout << "Health is now full. " << healthRestoration << " HP Restored" << endl;
            cout << "Current HP: ";
            return currentHealth;
        }
        else {
            healthRestoration = healthPotion;
            currentHealth += healthPotion;
            cout << healthRestoration << " HP Restored" << endl;
            cout << "Current HP: ";
            return currentHealth;
        }
    }
}

