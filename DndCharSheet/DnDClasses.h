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
    void setfeatures(vector<string> features);
    void sethitDiceType(int hitDice);
    void sethp(double hp);
    void setarmor(string armor);
    void setweapons(string weapons);
    void settools(string tools);
    void setsavingthrows(vector<string> savignthrows);
    void setskills(vector<string> skills);
    void setequipment(vector<string> equipment);
    void setspecialpath(string path);


    // getters
    string getclassname() const;
    int getlevel() const;
    int getbonus() const;
    vector<string> getfeatures() const;
    int gethitDiceType() const;
    double gethp() const;
    string getarmor() const;
    string getweapons() const;
    string gettools() const;
    vector<string> getsavingthrows() const;
    vector<string> getskills() const;
    vector<string> getequipment() const;
    string getpath() const;
};


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
    void setInfusions(vector<string> infusions);
    void setInfusedItems(vector<string> infuseditems);
    void setCantrips(vector<string> cantrips);
    void setSpells(vector<string> spells);
    vector<string> getInfusions() const;
    vector<string> getInfusedItems() const;
    vector<string> getCantrips() const;
    vector<string> getSpells() const;

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
    int SpellsKnown;
public:
    Bard();
    virtual ~Bard();
    void setCantrips(vector<string> cantrips);
    void setSpells(vector<string> spells);
    void setSpellsKnown(int spellsknown);
    vector<string> getCantrips() const;
    vector<string> getSpells() const;
    int getSpellsKnown() const;
};
class BloodHunter : public DnDClasses {
protected:
    int HemocraftDie;
    int BloodCurses;
};
class Cleric : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Cleric();
    virtual ~Cleric();
};
class Druid : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Druid();
    virtual ~Druid();
};
class Fighter : DnDClasses {
public:
    Fighter();
    virtual ~Fighter();
};
class Monk : DnDClasses {
protected:
    int MartialArtDie;
    int KiPoints;
    int UnarmoredMovement;
public:
    Monk();
    virtual ~Monk();
};
class Paladin : public DnDClasses {
protected:
    vector<string> Spells;
public:
    Paladin();
    virtual ~Paladin();
};
class Ranger : public DnDClasses {
protected:
    vector<string> Spells;
public:
    Ranger();
    virtual ~Ranger();
};
class Rogue : public DnDClasses {
protected:
    int SneakAttackDie;
public:
    Rogue();
    virtual ~Rogue();
};
class Sorcerer : public DnDClasses {
protected:
    int SorceryPoints;
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Sorcerer();
    virtual ~Sorcerer();
};
class Warlock : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
    vector<string> Invocations;
public:
    Warlock();
    virtual ~Warlock();
};
class Wizard : public DnDClasses {
protected:
    vector<string> Cantrips;
    vector<string> Spells;
public:
    Wizard();
    virtual ~Wizard();
};
