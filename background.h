#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <string>
#include <vector>

using namespace std;

class Background
{
public:
    Background();
    void setHistory(string history);
    void setLanguage(string language);
    void setSkill(string skill);
    void setWeapon(string weapon);
    void setArmor(string armor);
    void setEquipment(string equipment);

    string getHistory();
    string getLanguage();
    string getSkill();
    string getWeapon();
    string getArmor();
    string getEquipment();

    string Languages(string language, int numberOfLanguages);

private:
    string history;
    string language;
    string skill;
    string weapon;
    string armor;
    string equipment;
    int numberOfLanguages;
    vector<string> newLanguages;


};

#endif // BACKGROUND_H
