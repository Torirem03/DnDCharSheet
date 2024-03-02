#ifndef ATTACK_H
#define ATTACK_H

#include <string>

class attack {
private:
    std::string atkMethod;
    std::string dmgType;
    std::string dmgAmount;
    int toHitMod;
    int dmgMod;
public:
    attack();
    attack(std::string a, std::string t, std::string d, int h, int m);
    attack(std::string a, std::string t, std::string d);

    std::string getAtkMethod();
    std::string getDmgType();
    std::string getDmgAmount();
    int getToHitMod();
    int getDmgMod();

    void setAtkMethod(std::string a);
    void setDmgType(std::string t);
    void setDmgAmount(std::string d);
    void setToHitMod(int h);
    void setDmgMod(int m);
};

#endif // ATTACK_H
