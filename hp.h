#ifndef HP_H
#define HP_H

class HP
{
public:
    HP();
    void setInitialHealth(int initialHealth);
    void setHealthPerLevel(int healthPerLevel);
    void setTempHitPoints(int tempHitPoints);
    void setNumberOfTurns(int numberOfTurns);
    void setHealthPotion(int healthPotion);
    void setCurrentHealth(int currentHealth);
    void setCurrentLevel(int currentLevel);

    int getInitialHealth();
    int getMaxHealth();
    int getHealthPerLevel();
    int getTempHitPoints();
    int getNumberOfTurns();
    int getHealthPotion();
    int getCurrentHealth();
    int getCurrentLevel();

    int MaxHealth(int initialHealth, int heathPerLevel, int currentLevel);
    int TempHealth(int maxHealth, int tempHitPoints);
    int CurrentHealth(int healthPotion, int currentHealth, int maxHealth);

private:
    int initialHealth;
    int maxHealth;
    int tempHealth;
    int healthPerLevel;
    int tempHitPoints;
    int numberOfTurns;
    int healthPotion;
    int currentHealth;
    int currentLevel;

};

#endif // HP_H
