/*
Logun V.
lvanluong@dmacc.edu
2/18/24
Header file that contains declarations
for all methods and variables for DnDClasses
*/
#ifndef DNDCLASSES_H
#define DNDCLASSES_H
#include <string>
#include <vector>
using namespace std;

class DnDClasses {
protected:
    string classname; // holds class name
    int level; // holds level of character
    int proficiencybonus; // holds proficiency bonus
    vector<string> features; // vector of class features
    int hitDiceType; // hitdicetype
    double hp; // hit points of character
    string armor; // armor as string
    string weapons; // weapons as string
    string tools; // tools as string
    vector<string> savingthrows; // vector for saving throws
    vector<string> skills; // vector for skills
    vector<string> equipment; // vector for equipment
    string specialpath; // special path for sub classes

public:
    DnDClasses(); // constructor
    virtual ~DnDClasses(); // deconstructor
    // setters
    void setclassname(string name);
    void setlevel(int level);
    void setproficiencybonus(int bonus);
    void setfeatures();
    void sethitDiceType(int hitDice);
    void sethp(double hp);
    void setarmor(string armor);
    void setweapons(string weapons);
    void settools(string tools);
    void setsavingthrows();
    void setskills();
    void setequipment();
    void setspecialpath(string path);
    // getters
    string getclassname() const;
    int getlevel() const;
    int getbonus() const;
    string getfeatures() const;
    int gethitDiceType() const;
    double gethp() const;
    string getarmor() const;
    string getweapons() const;
    string gettools() const;
    string getsavingthrows() const;
    string getskills() const;
    string getequipment() const;
    string getpath() const;
};
// Creates character object in main
DnDClasses setCharClass();

// 14 sub classes of DnD that inherit from DnDClasses that each have unique fields in additon to base class fields
class Artificer : public DnDClasses {
protected:
    vector<string> Infusions;
    vector<string> InfusedItems;
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Artificer();
    virtual ~Artificer();
    void setInfusions();
    void setInfusedItems();
    void setCantrips();
    void setSpells();
    string getInfusions() const;
    string getInfusedItems() const;
    string getCantrips() const;
    string getSpells() const;

};
class Barbarian : public DnDClasses {
protected:
    int Rages;
    int RageDamagePlus;
public:
    Barbarian();
    virtual ~Barbarian();
    void setRages(int rages);
    void setRageDamagePlus(int ragedamage);
    int getRages() const;
    int getRageDamage() const;

};
class Bard : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Bard();
    virtual ~Bard();
    void setCantrips();
    void setSpells();
    string getCantrips() const;
    string getSpells() const;
};
class BloodHunter : public DnDClasses {
protected:
    int HemocraftDieType;
    vector<string> BloodCurses;
public:
    BloodHunter();
    virtual ~BloodHunter();
    void setHemocraftDieType(int di);
    void setBloodCurses();
    int getHemocraftDieType() const;
    string getBloodCurses() const;
};
class Cleric : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Cleric();
    virtual ~Cleric();
    void setCantrips();
    void setSpells();
    string getCantrips() const;
    string getSpells() const;
};
class Druid : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Druid();
    virtual ~Druid();
    void setCantrips();
    void setSpells();
    string getCantrips() const;
    string getSpells() const;
};
class Fighter : public DnDClasses {
protected:
    string FightingStyle;
public:
    Fighter();
    virtual ~Fighter();
    void setFightingStyle();
    string getFightingStyle() const;
};
class Monk : public DnDClasses {
protected:
    int MartialArtDieType;
    int KiPoints;
    int UnarmoredMovement;
public:
    Monk();
    virtual ~Monk();
    void setMartialArtDieType(int di);
    void setKiPoints(int ki);
    void setUnarmoredMovement(int movement);
    int getMartialArtDieType() const;
    int getKiPoints() const;
    int getUnarmoredMovement() const;
};
class Paladin : public DnDClasses {
protected:
    vector<string> Spells;
public:
    Paladin();
    virtual ~Paladin();
    void setSpells();
    string getSpells() const;
};
class Ranger : public DnDClasses {
protected:
    vector<string> Spells;
    string FavoredEnemy;
    string FavoredEnvironment;
public:
    Ranger();
    virtual ~Ranger();
    void setSpells();
    void setFavoredEnemy(string enemy);
    void setFavoredEnvironment(string biome);
    string getSpells() const;
    string getFavoredEnemy() const;
    string getFavoredEnvironment() const;
};
class Rogue : public DnDClasses {
protected:
    int SneakAttackDieType;
    int SneakAttackDieAmount;
public:
    Rogue();
    virtual ~Rogue();
    void setSneakAttackDieAmount(int di);
    int getSneakAttackDieType() const;
    int getSneakAttackDieAmount() const;
};
class Sorcerer : public DnDClasses {
protected:
    int SorceryPoints;
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Sorcerer();
    virtual ~Sorcerer();
    void setCantrips();
    void setSpells();
    string getCantrips() const;
    string getSpells() const;
};
class Warlock : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
    vector<string> Invocations;
public:
    Warlock();
    virtual ~Warlock();
    void setCantrips();
    void setSpells();
    void setInvocations();
    string getCantrips() const;
    string getSpells() const;
    string getInvocations() const;
};
class Wizard : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Wizard();
    virtual ~Wizard();
    void setCantrips();
    void setSpells();
    string getCantrips() const;
    string getSpells() const;
};

#endif // DNDCLASSES_H
