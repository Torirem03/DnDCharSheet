#ifndef HP_H
#define HP_H

class HP {
private:
    int maxHP;
    int currentHP;


public:
    HP(int maxHP, int currentHP);
    void setMaxHP(int maxHP);
    void setCurrentHP(int currentHP);
    int getMaxHP();
    int getCurrentHP();

    void PrintHP(int maxHP, int currentHP);
};

class Healing: public HP {
private:
    int healthPotion;

public:


};

class TemporaryHP: public HP {
private:
    int tempHP;
    int numberOfTurns;

public:

};

class Damage: public HP {
private:
    int damage;
    int damageReduction;
public:

};

class CalculateHP: public HP {
private:
    int initialHP;
    int HPPerLevel;
public:

};




#endif // HP_H
