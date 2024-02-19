#include "DnDClasses.h"

// Parent DnDClasses
DnDClasses::DnDClasses() { // constructor
    classname = "N/A";
    level = 0;
    proficiencybonus = 2;
    features = {};
    hitDiceType = 0;
    hp = 0;
    armor = "N/A";
    weapons = "N/A";
    tools = "N/A";
    savingthrows = {};
    skills = {};
    equipment = {};
    specialpath = "N/A";
}

DnDClasses::~DnDClasses() {} // destructor
// setters
void DnDClasses::setclassname(string name) {
    classname = name;
}
void DnDClasses::setlevel(int level) {
    this->level = level;
}
void DnDClasses::setproficiencybonus(int bonus) {
    proficiencybonus = bonus;
}
void DnDClasses::setfeatures(vector<string> features) {
    this->features = features;
}
void DnDClasses::sethitDiceType(int hitDice) {
    this->hitDiceType = hitDice;
}
void DnDClasses::sethp(double hp) {
    this->hp = hp;
}
void DnDClasses::setarmor(string armor) {
    this->armor = armor;
}
void DnDClasses::setweapons(string weapons) {
    this->weapons = weapons;
}
void DnDClasses::settools(string tools) {
    this->tools = tools;
}
void DnDClasses::setsavingthrows(vector<string> savingthrows) {
    this->savingthrows = savingthrows;
}
void DnDClasses::setskills(vector<string> skills) {
    this->skills = skills;
}
void DnDClasses::setequipment(vector<string> equipment) {
    this->equipment = equipment;
}
void DnDClasses::setspecialpath(string path) {
    specialpath = path;
}
// getters
string DnDClasses::getclassname() const {
    return classname;
}
int DnDClasses::getlevel() const {
    return level;
}
int DnDClasses::getbonus() const {
    return proficiencybonus;
}
vector<string> DnDClasses::getfeatures() const {
    return features;
}
int DnDClasses::gethitDiceType() const {
    return hitDiceType;
}
double DnDClasses::gethp() const {
    return hp;
}
string DnDClasses::getarmor() const {
    return armor;
}
string DnDClasses::getweapons() const {
    return weapons;
}
string DnDClasses::gettools() const {
    return tools;
}
vector<string> DnDClasses::getsavingthrows() const {
    return savingthrows;
}
vector<string> DnDClasses::getskills() const {
    return skills;
}
vector<string> DnDClasses::getequipment() const {
    return equipment;
}
string DnDClasses::getpath() const {
    return specialpath;
}


// Child class artificer
Artificer::Artificer() {
    classname = "Artificer";
    level = 1;
    proficiencybonus = 2;
    features = {"Magical Tinkering", "Spellcasting"};
    hitDiceType = 8;
    hp = 8;// needs addition from constitution modifier
    armor = "Light armor, medium armor, shields";// pick later options?
    weapons = "Simple weapons";// pick later options?
    tools = "Thieves’ tools, tinker’s tools, one type of artisan’s tools of your choice";// pick later options?
    savingthrows = {"Constitution","Intelligence"};
    skills = {"Choose two from Arcana, History, Investigation, Medicine, Nature, Perception, Sleight of Hand"};// pick later options?
    equipment = {// pick later options?
    "any two simple weapons",
    "a light crossbow and 20 bolts",
    "(a) studded leather armor or (b) scale mail",
    "thieves’ tools and a dungeoneer’s pack"
    };
    specialpath = "N/A";// might be needed for higher levels
    Infusions = {}; // needed for higher levels
    InfusedItems = {}; // needed for higher levels
    Cantrips = {};// 2 cantrips from artificer spell list
    Spells = {};// probably needed for later
}
Artificer::~Artificer() {}
//setters
void Artificer::setInfusions(vector<string> infusions) {
    Infusions = infusions;
}
void Artificer::setInfusedItems(vector<string> infuseditems) {
    InfusedItems = infuseditems;
}
void Artificer::setCantrips(vector<string> cantrips) {
    Cantrips = cantrips;
}
void Artificer::setSpells(vector<string> spells) {
    Spells = spells;
}
//getters
vector<string> Artificer::getInfusions() const {
    return Infusions;
}
vector<string> Artificer::getInfusedItems() const {
    return InfusedItems;
}
vector<string> Artificer::getCantrips() const {
    return Cantrips;
}
vector<string> Artificer::getSpells() const {
    return Spells;
}
// Child class Barbarian
Barbarian::Barbarian() {
    classname = "Barbarian";
    level = 1;
    proficiencybonus = 2;
    features = {"Rage", "Unarmored Defense"};
    hitDiceType = 12;
    hp = 12;// needs addition from constitution modifier
    armor = "Light armor, medium armor, shields";// pick later options?
    weapons = "Simple weapons, martial weapons";// pick later options?
    tools = "None";
    savingthrows = {"Strength","Constitution"};
    skills = {"Choose two from Animal Handling, Athletics, Intimidation, Nature, Perception, and Survival"};// pick later options?
    equipment = {// pick later options?
    "(a) a greataxe or (b) any martial melee weapon",
    "(a) two handaxes or (b) any simple weapon",
    "An explorer's pack and four javelins"
    };
    specialpath = "N/A";// needed for later levels
    Rages = 2; // special attack for barbarians?
    RageDamagePlus = 2; // damage modifier
}
Barbarian::~Barbarian() {}
//setters
void Barbarian::setRages(int rages) {
    Rages = rages;
}
void Barbarian::setRageDamagePlus(int ragedamage) {
    RageDamagePlus = ragedamage;
}
//getters
int Barbarian::getRages() const {
    return Rages;
}
int Barbarian::getRageDamage() const {
    return RageDamagePlus;
}
// Child class Bard
Bard::Bard() {
    classname = "Bard";
    level = 1;
    proficiencybonus = 2;
    features = {"Bardic Inspiration(d6)", "Spellcasting"};
    hitDiceType = 8;
    hp = 8;// needs addition from constitution modifier
    armor = "Light armor";
    weapons = "Simple weapons, hand crossbows, longswords, rapiers, shortswords";// pick later options?
    tools = "Three musical instruments of your choice";// pick later options
    savingthrows = {"Dexterity","Charisma"};
    skills = {"Choose any three"};// pick later options
    equipment = {// pick later options?
                 "(a) a rapier, (b) a longsword, or (c) any simple weapon",
                 "(a) a diplomat's pack or (b) an entertainer's pack",
                 "(a) a lute or (b) any other musical instrument",
                 "Leather armor and a dagger"
    };
    specialpath = "N/A";// Needed for higher level?
    Cantrips = {};// 2 cantrips from bard spell list
    Spells = {};// 4 1st level spells from bard spell list
    SpellsKnown = 4;
}
Bard::~Bard() {}
//setters
void Bard::setCantrips(vector<string> cantrips) {
    Cantrips = cantrips;
}
void Bard::setSpells(vector<string> spells) {
    Spells = spells;
}
void Bard::setSpellsKnown(int spellsknown) {
    SpellsKnown = spellsknown;
}
//getters
vector<string> Bard::getCantrips() const {
    return Cantrips;
}
vector<string> Bard::getSpells() const {
    return Spells;
}
int Bard::getSpellsKnown() const {
    return SpellsKnown;
}
