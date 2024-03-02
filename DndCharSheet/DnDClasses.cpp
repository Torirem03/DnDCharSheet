/*
Logun V.
lvanluong@dmacc.edu
2/18/24
The file that contains bodies for all methods
and classes of DnDClasses. Multiple classes inherit from the
main parent class of DnDClasses containing variables that
hold information regarding what DnD sub classes need for
character creation.*/
#include "DnDClasses.h"
#include <iostream>
#include <algorithm>
unsigned int i;

// Parent DnDClasses
DnDClasses::DnDClasses() { // constructor
    classname = "N/A";
    level = 0;
    proficiencybonus = 2;
    features = {"N/A"};
    hitDiceType = 0;
    hp = 0;
    armor = "N/A";
    weapons = "N/A";
    tools = "N/A";
    savingthrows = {"N/A"};
    skills = {"N/A"};
    equipment = {"N/A"};
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
void DnDClasses::setfeatures() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Features..." << endl;
        cin >> input;
        features.push_back(input);
    }
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
void DnDClasses::setsavingthrows() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Saving Throws..." << endl;
        cin >> input;
        savingthrows.push_back(input);
    }
}
void DnDClasses::setskills() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Skills..." << endl;
        cin >> input;
        skills.push_back(input);
    }
}
void DnDClasses::setequipment() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Equipment..." << endl;
        cin >> input;
        equipment.push_back(input);
    }
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
string DnDClasses::getfeatures() const {
    string result = "";
    for (i = 0; i < features.size(); i++) {
        result.append(features.at(i) + ", ");
    }
    return result;
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
string DnDClasses::getsavingthrows() const {
    string result = "";
    for (i = 0; i < savingthrows.size(); i++) {
        result.append(savingthrows.at(i) + ", ");
    }
    return result;
}
string DnDClasses::getskills() const {
    string result = "";
    for (i = 0; i < skills.size(); i++) {
        result.append(skills.at(i) + ", ");
    }
    return result;
}
string DnDClasses::getequipment() const {
    string result = "";
    for (i = 0; i < equipment.size(); i++) {
        result.append(equipment.at(i) + ", ");
    }
    return result;
}
string DnDClasses::getpath() const {
    return specialpath;
}
// Returns DnD Child class based on user string-input
DnDClasses setCharClass() {
    string charclass = "";
    //vector of sub classes
    vector<string> Classes = {
                              "artificer","barbarian",
                              "bard","bloodhunter",
                              "cleric","druid",
                              "fighter","monk",
                              "paladin","ranger",
                              "rogue","sorcerer",
                              "warlock","wizard"};
    int caseNum = -1;
    unsigned int i;
    // gets user input and displays prompt
    cout << "\nEnter Class Type from options..." << endl;
    for (i = 0; i < Classes.size(); i++) {
        cout << Classes.at(i) << ", ";
    }
    cout << endl;
    cin >> charclass;
    // transforms input to lowercase and checks with vector for valid input
    transform(charclass.begin(), charclass.end(), charclass.begin(), ::tolower);
    for(i = 0; i < Classes.size(); i++) {
        if (charclass == Classes.at(i)) {
            caseNum = i;
            break;
        }
    }
    // asks user in a loop until valid input
    while (caseNum == -1) {
        cout << "No match found. Try again." << endl;
        cin >> charclass;
        transform(charclass.begin(), charclass.end(), charclass.begin(), ::tolower);
        for(i = 0; i < Classes.size(); i++) {
            if (charclass == Classes.at(i)) {
                caseNum = i;
                break;
            }
        }
    }
    // switch case for the 14 subclasses
    switch (caseNum) {
    case 0: {
        Artificer Character;
        cout << "Artificer Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 1:{
        Barbarian Character;
        cout << "Barbarian Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 2: {
        Bard Character;
        cout << "Bard Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 3:{
        BloodHunter Character;
        cout << "BloodHunter Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 4:{
        Cleric Character;
        cout << "Cleric Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 5:{
        Druid Character;
        cout << "Druid Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 6:{
        Fighter Character;
        cout << "Fighter Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 7:{
        Monk Character;
        cout << "Monk Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 8:{
        Paladin Character;
        cout << "Paladin Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 9:{
        Ranger Character;
        cout << "Ranger Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 10:{
        Rogue Character;
        cout << "Rogue Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 11:{
        Sorcerer Character;
        cout << "Sorcerer Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 12:{
        Warlock Character;
        cout << "Warlock Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    case 13:{
        Wizard Character;
        cout << "Wizard Character made." << endl;
        DnDClasses temp = Character;
        return temp;
    }
    default:{
        cout << "No match found. Try again." << endl;
        DnDClasses Character;
        return Character;
    }
    }
    // returns parent class if no subclass could be chosen
    DnDClasses Character;
    return Character;
}

// Child class Artificer
Artificer::Artificer() {
    classname = "Artificer";
    level = 1;
    proficiencybonus = 2;
    features = {"Magical Tinkering", "Spellcasting"};
    hitDiceType = 8;
    hp = 8;// without constitution modifier
    armor = "Light armor, medium armor, shields";// options
    weapons = "Simple weapons";// options
    tools = "Thieves' tools, tinker's tools, one type of artisan's tools of your choice";// options
    savingthrows = {"Constitution", "Intelligence"};
    skills = {"Choose two from Arcana, History, Investigation, Medicine, Nature, Perception, Sleight of Hand"};// options
    equipment = {// options
    "any two simple weapons",
    "a light crossbow and 20 bolts",
    "(a) studded leather armor or (b) scale mail",
    "thieves' tools and a dungeoneer's pack"
    };
    specialpath = "N/A";
    Infusions = {"N/A"};
    InfusedItems = {"N/A"};
    Cantrips = {"2 cantrips from artificer spell list"};// options
    Spells = {"N/A"}; // artificer spell list
}
Artificer::~Artificer() {}
//setters that use loop to add user string-input to vectors
void Artificer::setInfusions() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Infusion..." << endl;
        cin >> input;
        Infusions.push_back(input);
    }
}
void Artificer::setInfusedItems() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Infused Item..." << endl;
        cin >> input;
        InfusedItems.push_back(input);
    }
}
void Artificer::setCantrips() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Cantrip..." << endl;
        cin >> input;
        Cantrips.push_back(input);
    }
}
void Artificer::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
//getters that use loop to return single string with all vector values
string Artificer::getInfusions() const {
    string result = "";
    for (i = 0; i < Infusions.size(); i++) {
        result.append(Infusions.at(i) + ", ");
    }
    return result;
}
string Artificer::getInfusedItems() const {
    string result = "";
    for (i = 0; i < InfusedItems.size(); i++) {
        result.append(InfusedItems.at(i) + ", ");
    }
    return result;
}
string Artificer::getCantrips() const {
    string result = "";
    for (i = 0; i < Cantrips.size(); i++) {
        result.append(Cantrips.at(i) + ", ");
    }
    return result;
}
string Artificer::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
// Child class Barbarian
Barbarian::Barbarian() {
    classname = "Barbarian";
    level = 1;
    proficiencybonus = 2;
    features = {"Rage", "Unarmored Defense"};
    hitDiceType = 12;
    hp = 12;// without constitution modifier
    armor = "Light armor, medium armor, shields";// options
    weapons = "Simple weapons, martial weapons";// options
    tools = "None";
    savingthrows = {"Strength", "Constitution"};
    skills = {"Choose two from Animal Handling, Athletics, Intimidation, Nature, Perception, and Survival"};// options
    equipment = {// options
    "(a) a greataxe or (b) any martial melee weapon",
    "(a) two handaxes or (b) any simple weapon",
    "An explorer's pack and four javelins"
    };
    specialpath = "N/A";
    Rages = 2; // special attack for barbarians
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
int Barbarian::getRages() const{
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
    hp = 8;// without constitution modifier
    armor = "Light armor";
    weapons = "Simple weapons, hand crossbows, longswords, rapiers, shortswords";// options
    tools = "Three musical instruments of your choice";// options
    savingthrows = {"Dexterity", "Charisma"};
    skills = {"Choose any three"};// options
    equipment = {// options
                 "(a) a rapier, (b) a longsword, or (c) any simple weapon",
                 "(a) a diplomat's pack or (b) an entertainer's pack",
                 "(a) a lute or (b) any other musical instrument",
                 "Leather armor and a dagger"
    };
    specialpath = "N/A";
    Cantrips = {"2 cantrips from bard spell list"};// options
    Spells = {"4 1st level spells from bard spell list"};// options
}
Bard::~Bard() {}
//setters
void Bard::setCantrips() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Cantrip..." << endl;
        cin >> input;
        Cantrips.push_back(input);
    }
}
void Bard::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
//getters
string Bard::getCantrips() const {
    string result = "";
    for (i = 0; i < Cantrips.size(); i++) {
        result.append(Cantrips.at(i) + ", ");
    }
    return result;
}
string Bard::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
// Child class BloddHunter
BloodHunter::BloodHunter() {
    classname = "BloodHunter";
    level = 1;
    proficiencybonus = 2;
    features = {"Hunter's Bane", "Blood Maledict"};
    hitDiceType = 10;
    hp = 10;// without constitution modifier
    armor = "Light armor, medium armor, shields";// options
    weapons = "Simple weapons, martial weapons";// options
    tools = "Alchemist's supplies";// options
    savingthrows = {"Dexterity", "Intelligence"};
    skills = {"Choose three from Acrobatics, Arcana, Athletics, History, Insight, Investigation, Religion, and Survival"};// options
    equipment = {// options
    "(a) a martial weapon or (b) two simple weapons",
    "(a) a light crossbow and 20 bolts or (b) hand crossbow and 20 bolts",
    "(a) studded leather armor or (b) scale mail armor",
    "an explorer's pack and alchemist's supplies"
    };
    specialpath = "N/A";
    HemocraftDieType = 4;
    BloodCurses = {"Choose one blood curse"}; // options
}
BloodHunter::~BloodHunter() {}
//setters
void BloodHunter::setHemocraftDieType(int di) {
    HemocraftDieType = di;
}
void BloodHunter::setBloodCurses() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Blood Curse..." << endl;
        cin >> input;
        BloodCurses.push_back(input);
    }
}
//getters
int BloodHunter::getHemocraftDieType() const {
    return HemocraftDieType;
}
string BloodHunter::getBloodCurses() const {
    string result = "";
    for (i = 0; i < BloodCurses.size(); i++) {
        result.append(BloodCurses.at(i) + ", ");
    }
    return result;
}
// Child class Cleric
Cleric::Cleric() {
    classname = "Cleric";
    level = 1;
    proficiencybonus = 2;
    features = {"Spellcasting", "Divine Domain"};
    hitDiceType = 8;
    hp = 8;// without constitution modifier
    armor = "Light armor, Medium armor, shields"; // options
    weapons = "All simple weapons";// options
    tools = "None";
    savingthrows = {"Wisdom", "Charisma"};
    skills = {"Choose two from History, Insight, Medicine, Persuasion, and Religion"};// options
    equipment = {// options
        "(a) a mace or (b) a warhammer (if proficient)",
        "(a) scale mail, (b) leather armor, or (c) chain mail (if proficient)",
        "(a) a light crossbow and 20 bolts or (b) any simple weapon",
        "(a) a priest's pack or (b) an explorer's pack",
        "A shield and a holy symbol"
    };
    specialpath = "N/A";
    Cantrips = {"3 cantrips from cleric spell list"};// options
    Spells = {"2 1st level spells from cleric spell list"};// options
}
Cleric::~Cleric() {}
//setters
void Cleric::setCantrips() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Cantrip..." << endl;
        cin >> input;
        Cantrips.push_back(input);
    }
}
void Cleric::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
//getters
string Cleric::getCantrips() const {
    string result = "";
    for (i = 0; i < Cantrips.size(); i++) {
        result.append(Cantrips.at(i) + ", ");
    }
    return result;
}
string Cleric::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
// Child class Druid
Druid::Druid() {
    classname = "Druid";
    level = 1;
    proficiencybonus = 2;
    features = {"Druidic", "Spellcasting"};
    hitDiceType = 8;
    hp = 8;// without constitution modifier
    armor = "Light armor, medium armor, shields (druids will not wear armor or use shields made of metal)"; // options
    weapons = "Clubs, daggers, darts, javelins, maces, quarterstaffs, scimitars, sickles, slings, spears";// options
    tools = "Herbalism kit";
    savingthrows = {"Intelligence", "Wisdom"};
    skills = {"Choose two from Arcana, Animal Handling, Insight, Medicine, Nature, Perception, Religion, and Survival"};// options
    equipment = {// options
        "(a) a wooden shield or (b) any simple weapon",
        "(a) a scimitar or (b) any simple melee weapon",
        "Leather armor, an explorer's pack, and a druidic focus"
    };
    specialpath = "N/A";
    Cantrips = {"2 cantrips from druid spell list"};// options
    Spells = {"2 1st level spells from druid spell list"};// options
}
Druid::~Druid() {}
//setters
void Druid::setCantrips() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Cantrip..." << endl;
        cin >> input;
        Cantrips.push_back(input);
    }
}
void Druid::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
//getters
string Druid::getCantrips() const {
    string result = "";
    for (i = 0; i < Cantrips.size(); i++) {
        result.append(Cantrips.at(i) + ", ");
    }
    return result;
}
string Druid::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
// Child class Fighter
Fighter::Fighter() {
    classname = "Fighter";
    level = 1;
    proficiencybonus = 2;
    features = {"Fighting Style", "Second Wind"};
    hitDiceType = 10;
    hp = 10;// without constitution modifier
    armor = "All armor, shields"; // options
    weapons = "Simple weapons, martial weapons";// options
    tools = "None";
    savingthrows = {"Strength", "Constitution"};
    skills = {"Choose two skills from Acrobatics, Animal Handling, Athletics, History, Insight, Intimidation, Perception, and Survival"};// options
    equipment = {// options
        "(a) chain mail or (b) leather, longbow, and 20 arrows",
        "(a) a martial weapon and a shield or (b) two martial weapons",
        "(a) a light crossbow and 20 bolts or (b) two handaxes",
        "(a) a dungeoneer's pack or (b) an explorer's pack"
    };
    specialpath = "N/A";
    FightingStyle = "N/A"; //special style
}
Fighter::~Fighter() {}
//setters
void Fighter::setFightingStyle() {
    cout << "Pick one option to use..." << endl;
    cout << "Archery, Blind Fighting, Defense, Dueling, Great Weapon Fighting, \n"<<
        "Interception, Protection, Superior Technique, Thrown Weapon Fighting, \n" <<
            " Unarmed Fighting, Close Quarters Shooter, Mariner, Tunnel Fighter \n" << endl;
    cin >> FightingStyle;
}
//getters
string Fighter::getFightingStyle() const {
    return FightingStyle;
}
// Child class Monk
Monk::Monk() {
    classname = "Monk";
    level = 1;
    proficiencybonus = 2;
    features = {"Unarmored Defense", "Martial Arts"};
    hitDiceType = 8;
    hp = 8;// without constitution modifier
    armor = "None";
    weapons = "Simple weapons, shortswords";// options
    tools = "Choose one type of artisan's tools or one musical instrument";// options
    savingthrows = {"Strength", "Dexterity"};
    skills = {"Choose two from Acrobatics, Athletics, History, Insight, Religion, and Stealth"};// options
    equipment = {// options
        "(a) a shortsword or (b) any simple weapon",
        "(a) a dungeoneer's pack or (b) an explorer's pack",
        "10 darts"
    };
    specialpath = "N/A";
    MartialArtDieType = 4;
    KiPoints = 0;
    UnarmoredMovement = 0;
}
Monk::~Monk() {}
//setters
void Monk::setMartialArtDieType(int di) {
    MartialArtDieType = di;
}
void Monk::setKiPoints(int ki) {
    KiPoints = ki;
}
void Monk::setUnarmoredMovement(int movement) {
    UnarmoredMovement = movement;
}
//getters
int Monk::getMartialArtDieType() const {
    return MartialArtDieType;
}
int Monk::getKiPoints() const {
    return KiPoints;
}
int Monk::getUnarmoredMovement() const {
    return UnarmoredMovement;
}
// Child class Paladin
Paladin::Paladin() {
    classname = "Paladin";
    level = 1;
    proficiencybonus = 2;
    features = {"Divine Sense", "Lay on Hands"};
    hitDiceType = 10;
    hp = 10;// without constitution modifier
    armor = "All armor, shields"; // options
    weapons = "Simple weapons, martial weapons";// options
    tools = "None";
    savingthrows = {"Wisdom", "Charisma"};
    skills = {"Choose two from Athletics, Insight, Intimidation, Medicine, Persuasion, and Religion"};// options
    equipment = {// options
        "(a) a martial weapon and a shield or (b) two martial weapons",
        "(a) five javelins or (b) any simple melee weapon",
        "(a) a priest's pack or (b) an explorer's pack",
        "Chain mail and a holy symbol"
    };
    specialpath = "N/A";
    Spells = {"N/A"}; // paladin spell list
}
Paladin::~Paladin() {}
//setters
void Paladin::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
//getters
string Paladin::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
// Child class Ranger
Ranger::Ranger() {
    classname = "Ranger";
    level = 1;
    proficiencybonus = 2;
    features = {"Favored Enemy", "Natural Explorer"};
    hitDiceType = 10;
    hp = 10;// without constitution modifier
    armor = "Light armor, medium armor, shields"; // options
    weapons = "Simple weapons, martial weapons";// options
    tools = "None";
    savingthrows = {"Strength", "Dexterity"};
    skills = {"Choose three from Animal Handling, Athletics, Insight, Investigation, Nature, Perception, Stealth, and Survival"};// options
    equipment = {// options
        "(a) scale mail or (b) leather armor",
        "(a) two shortswords or (b) two simple melee weapons",
        "(a) a dungeoneer's pack or (b) an explorer's pack",
        "A longbow and a quiver of 20 arrows"
    };
    specialpath = "N/A";
    Spells = {"N/A"}; // ranger spell list
}
Ranger::~Ranger() {}
//setters
void Ranger::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
void Ranger::setFavoredEnemy(string enemy) {
    FavoredEnemy = enemy;
}
void Ranger::setFavoredEnvironment(string biome) {
    FavoredEnvironment = biome;
}
//getters
string Ranger::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
string Ranger::getFavoredEnemy() const {
    return FavoredEnemy;
}
string Ranger::getFavoredEnvironment() const {
    return FavoredEnvironment;
}
// Child class Rogue
Rogue::Rogue() {
    classname = "Rogue";
    level = 1;
    proficiencybonus = 2;
    features = {"Expertise", "Sneak Attack, Thieves' Cant"};
    hitDiceType = 8;
    hp = 8;// without constitution modifier
    armor = "Light armor";
    weapons = "Simple weapons, hand crossbows, longswords, rapiers, shortswords";// options
    tools = "Thieves' tools";
    savingthrows = {"Dexterity", "Intelligence"};
    skills = {"Choose four from Acrobatics, Athletics, Deception, Insight, Intimidation, Investigation, Perception, Performance, Persuasion, Sleight of Hand, and Stealth"};// options
    equipment = {// options
        "(a) a rapier or (b) a shortsword",
        "(a) a shortbow and quiver of 20 arrows or (b) a shortsword",
        "(a) a burglar's pack, (b) dungeoneer's pack, or (c) an explorer's pack",
        "Leather armor, two daggers, and thieves' tools"
    };
    specialpath = "N/A";
    SneakAttackDieType = 6; // does not change
    SneakAttackDieAmount = 1;
}
Rogue::~Rogue() {}
//setters
void Rogue::setSneakAttackDieAmount(int di) {
    SneakAttackDieAmount = di;
}
//getters
int Rogue::getSneakAttackDieAmount() const {
    return SneakAttackDieAmount;
}
int Rogue::getSneakAttackDieType() const {
    return SneakAttackDieType;
}
// Child class Sorcerer
Sorcerer::Sorcerer() {
    classname = "Sorcerer";
    level = 1;
    proficiencybonus = 2;
    features = {"Spellcasting", "Sorcerous Origin"};
    hitDiceType = 6;
    hp = 6;// without constitution modifier
    armor = "None";
    weapons = "Daggers, darts, slings, quarterstaffs, light crossbows";// options
    tools = "None";
    savingthrows = {"Constitution", "Charisma"};
    skills = {"Choose two from Arcana, Deception, Insight, Intimidation, Persuasion, and Religion"};// options
    equipment = {// options
        "(a) a light crossbow and 20 bolts or (b) any simple weapon",
        "(a) a component pouch or (b) an arcane focus",
        "(a) a dungeoneer's pack or (b) an explorer's pack",
        "Two daggers"
    };
    specialpath = "N/A";
    Cantrips = {"4 cantrips from sorcerer spell list"};// options
    Spells = {"2 1st level spells from sorcerer spell list"};// options
}
Sorcerer::~Sorcerer() {}
//setters
void Sorcerer::setCantrips() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Cantrip..." << endl;
        cin >> input;
        Cantrips.push_back(input);
    }
}
void Sorcerer::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
//getters
string Sorcerer::getCantrips() const {
    string result = "";
    for (i = 0; i < Cantrips.size(); i++) {
        result.append(Cantrips.at(i) + ", ");
    }
    return result;
}
string Sorcerer::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
// Child class Warlock
Warlock::Warlock() {
    classname = "Warlock";
    level = 1;
    proficiencybonus = 2;
    features = {"Otherworldy Patron", "Pact Magic"};
    hitDiceType = 8;
    hp = 8;// without constitution modifier
    armor = "Light armor";
    weapons = "Simple weapons";// options
    tools = "None";
    savingthrows = {"Wisdom", "Charisma"};
    skills = {"Choose two from Arcana, Deception, History, Intimidation, Investigation, Nature, and Religion"};// options
    equipment = {// options
                 "(a) a light crossbow and 20 bolts or (b) any simple weapon",
                 "(a) a component pouch or (b) an arcane focus",
                 "(a) a scholar's pack or (b) a dungeoneer's pack",
                 "Leather armor, any simple weapon, and two daggers"
    };
    specialpath = "N/A";
    Invocations = {"N/A"};
    Cantrips = {"2 cantrips from warlock spell list"};// options
    Spells = {"2 1st level spells from warlock spell list"};// options
}
Warlock::~Warlock() {}
//setters that use loop to add user string-input to vectors
void Warlock::setInvocations() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Invocations..." << endl;
        cin >> input;
        Invocations.push_back(input);
    }
}
void Warlock::setCantrips() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Cantrip..." << endl;
        cin >> input;
        Cantrips.push_back(input);
    }
}
void Warlock::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
//getters that use loop to return single string with all vector values
string Warlock::getInvocations() const {
    string result = "";
    for (i = 0; i < Invocations.size(); i++) {
        result.append(Invocations.at(i) + ", ");
    }
    return result;
}
string Warlock::getCantrips() const {
    string result = "";
    for (i = 0; i < Cantrips.size(); i++) {
        result.append(Cantrips.at(i) + ", ");
    }
    return result;
}
string Warlock::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
// Child class Wizard
Wizard::Wizard() {
    classname = "Wizard";
    level = 1;
    proficiencybonus = 2;
    features = {"Spellcasting", "Arcane Recovery"};
    hitDiceType = 6;
    hp = 6;// without constitution modifier
    armor = "None";
    weapons = "Daggers, darts, slings, quarterstaffs, light crossbows";// options
    tools = "None";
    savingthrows = {"Intelligence", "Wisdom"};
    skills = {"Choose two from Arcana, History, Insight, Investigation, Medicine, and Religion"};// options
    equipment = {// options
        "(a) a quarterstaff or (b) a dagger",
        "(a) a component pouch or (b) an arcane focus",
        "(a) a scholar's pack or (b) an explorer's pack",
        "A spellbook"
    };
    specialpath = "N/A";
    Cantrips = {"3 cantrips from wizard spell list"};// options
    Spells = {"2 1st level spells from wizard spell list"};// options
}
Wizard::~Wizard() {}
//setters that use loop to add user string-input to vectors
void Wizard::setCantrips() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Cantrip..." << endl;
        cin >> input;
        Cantrips.push_back(input);
    }
}
void Wizard::setSpells() {
    string input;
    while (input != "q") {
        cout << "Input 'q' to quit. \nEnter Spell..." << endl;
        cin >> input;
        Spells.push_back(input);
    }
}
//getters that use loop to return single string with all vector values
string Wizard::getCantrips() const {
    string result = "";
    for (i = 0; i < Cantrips.size(); i++) {
        result.append(Cantrips.at(i) + ", ");
    }
    return result;
}
string Wizard::getSpells() const {
    string result = "";
    for (i = 0; i < Spells.size(); i++) {
        result.append(Spells.at(i) + ", ");
    }
    return result;
}
