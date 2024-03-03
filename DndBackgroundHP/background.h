#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <vector>
#include <string>
using namespace std;

class Background
{
private:
    string history;
    vector<string> language;
    vector<string> skill;
    vector<string> weapon;
    vector<string> armor;
    vector<string> equipment;

public:
    Background();
    void setHistory(string history);
    void setLanguages(vector<string> language);
    void setSkills(vector<string> skill);
    void setWeapons(vector<string> weapon);
    void setArmors(vector<string> armor);
    void setEquipments(vector<string> equipment);

    string getHistory();
    vector<string> getLanguages();
    vector<string> getSkills();
    vector<string> getWeapons();
    vector<string> getArmors();
    vector<string> getEquipments();

    void print();
};

#endif // BACKGROUND_H
