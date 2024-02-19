#include <iostream>
#include "hp.h"

using namespace std;

int main() {
    HP character;
    int initialHealth;
    int healthPerLevel;
    int currentLevel;
    int currentHealth;
    int healthPotion;


    cout << "What is your character's starting HP?" << endl;
    cin >> initialHealth;
    character.setInitialHealth(initialHealth);

    cout << "What is the HP increase per level?" << endl;
    cin >> healthPerLevel;
    character.setHealthPerLevel(healthPerLevel);

    cout << "What is your current level?" << endl;
    cin >> currentLevel;
    character.setCurrentLevel(currentLevel);

    cout << "Current Max HP: " << character.MaxHealth(initialHealth, healthPerLevel, currentLevel) << endl;

    cout << "Current Health: " << endl;
    cin >> currentHealth;
    character.setCurrentHealth(currentHealth);

    cout << "Health Potion: " << endl;
    cin >> healthPotion;
    character.setHealthPotion(healthPotion);

    cout << character.CurrentHealth(healthPotion, currentHealth, character.MaxHealth(initialHealth, healthPerLevel, currentLevel)) << endl << endl;







    return 0;
}
