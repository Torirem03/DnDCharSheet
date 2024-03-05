#ifndef CHARACTERSHEET_H
#include <iostream>
#include <iomanip>
#include "DnDClasses.h"
#include "race.h"
#include "background.h"
#include "inventory.h"
using namespace std;
#define CHARACTERSHEET_H

string profCheck(string modifier){
    string result = (stoi(modifier) > 0) ? "X" : "_";
    return result;
}

int savingThrowCalc(string modifier, int bonus){
    if (profCheck(modifier) == "X") {
        int total = bonus + stoi(modifier);
        return total;
    }
    else{
        return stoi(modifier);
    }
}

void printSheet(DnDClasses dClass, Race dRace, Inventory dInventory,string dName, int dInitroll, int Strength, int Dexterity, int Constitution, int Intelligence, int Wisdom, int Charisma, Background dBack){
    cout << "                                            .---------------------------------. " << endl;
    cout << "DUNGEONS & DRAGONS                         [        NAME: " << setw(20) << dName << " ]" << endl;
    cout << "5E CHARACTER SHEET                         [        RACE: " << setw(20) << dRace.getRace() << " ]" << endl;
    cout << "                                           [  BACKGROUND: " << setw(20) << dBack.getHistory() << " ]" << endl;
    cout << "                                           [   ALIGNMENT: ____________________ ]" << endl;
    cout << "                                           [ CLASS: " << setw(16) << dClass.getclassname()<< " LEVEL: " << setw(2) << dClass.getlevel() << " ]" << endl;
    cout << "                                           [ EXPERIENCE POINTS:              0 ]" << endl;
    cout << "                                           \\___________________________________/" << endl;
    cout << endl;
    cout << "/------\\                                    ___    .------------. .-----------." << endl;
    cout << "| STR: |  .--------------------------.    _/   \\_  |/          \\| |/         \\|" << endl;
    cout << "[  " << setw(2) << Strength << "  ] {   __   INSPIRATION         }  |   AC  | | INITIATIVE | |   SPEED   |" << endl;
    cout << "[ (" << setw(2) << dRace.getStr() << ") ] {   "<< setw(2) << dClass.getbonus() << "   PROFICIENCY BONUS   }  |   " << setw(2) << to_string(10 + stoi(dRace.getDex())) <<"  | |     " << setw(2) << dInitroll << "     | | " << setw(6) << dRace.getSpeed() << " ft |" << endl;
    cout << " *----*  {                            }  \\       / |\\          /| |\\         /|" << endl;
    cout << "/------\\  \\__________________________/    \\_____/   ------------   -----------" << endl;
    cout << "| DEX: |  .--------------------------.    .-----------------------------------." << endl;
    cout << "[  " << setw(2) << Dexterity << "  ] {       SAVING  THROWS       }  { HIT POINTS:                " << setw(2) << dClass.gethp() <<" / " << setw(2) << dClass.gethp() << "  }" << endl;
    cout << "[ (" << setw(2) << dRace.getDex() << ") ] { " << profCheck(dRace.getStr()) << " STR " << setw(2) << savingThrowCalc(dRace.getStr(), dClass.getbonus()) << "  .:/\\:.  " << setw(2) <<savingThrowCalc(dRace.getIntell(), dClass.getbonus()) << " INT " << profCheck(dRace.getIntell()) << " }  { TEMP HIT POINTS:                    }" << endl;
    cout << " *----*  | " << profCheck(dRace.getDex()) << " DEX " << setw(2) << savingThrowCalc(dRace.getDex(), dClass.getbonus()) << " :\\/20\\/: " << setw(2) << savingThrowCalc(dRace.getWis(), dClass.getbonus()) << " WIS " << profCheck(dRace.getWis()) << " |  '-------------------------------------'" << endl;
    cout << "/------\\ { " << profCheck(dRace.getCon()) << " CON " << setw(2) << savingThrowCalc(dRace.getCon(), dClass.getbonus()) << " :/\\--/\\: " << setw(2) << savingThrowCalc(dRace.getCha(), dClass.getbonus()) << " CHA " << profCheck(dRace.getCha()) << " }  .-------------. .---------------------." << endl;
    cout << "| CON: | {           ._\\/_.           }  |/           \\| |/                   \\|" << endl;
    cout << "[  " << setw(2) << Constitution << "  ] '----------------------------'  |  HIT DICE   | |     DEATH SAVES     |" << endl;
    cout << "[ (" << setw(2) << dRace.getCon() << ") ]  .--------------------------.   |     " << dClass.getlevel() << "d" << dClass.gethitDiceType() <<"     | |  < - - - + - - - >  |" << endl;
    cout << " *----*  {           SKILLS           }  |\\           /| |\\ death        life /|" << endl;
    cout << "| INT: | | " << profCheck(dRace.getWis()) << " Animal Handling " << setw(2) << stoi(dRace.getWis()) + dClass.getbonus() << " (wis) |  '-------------' '---------------------'" << endl;
    cout << "[  " << setw(2) << Intelligence << "  ] | " << profCheck(dRace.getIntell()) << " Arcana          " << setw(2) << stoi(dRace.getIntell()) + dClass.getbonus() << " (int) |   .-----------------------------------." << endl;
    cout << "[ (" << setw(2) << dRace.getIntell() << ") ] | " << profCheck(dRace.getStr()) << " Athletics       " << setw(2) << stoi(dRace.getStr()) + dClass.getbonus() << " (str) |  {       ATTACKS & SPELLCASTING        }" << endl;
    cout << " *----*  | " << profCheck(dRace.getCha()) << " Deception       " << setw(2) << stoi(dRace.getCha()) + dClass.getbonus() << " (cha) |  | ___________________________________ |" << endl;
    cout << "/------\\ | " << profCheck(dRace.getIntell()) << " History         " << setw(2) << stoi(dRace.getIntell()) + dClass.getbonus() << " (int) |  | ___________________________________ |" << endl;
    cout << "| WIS: | | " << profCheck(dRace.getWis()) << " Insight         " << setw(2) << stoi(dRace.getWis()) + dClass.getbonus() << " (wis) |  | ___________________________________ |" << endl;
    cout << "[  " << setw(2) << Wisdom << "  ] | " << profCheck(dRace.getCha()) << " Intimidation    " << setw(2) << stoi(dRace.getCha()) + dClass.getbonus() << " (cha) |  | ___________________________________ |" << endl;
    cout << "[ (" << setw(2) << dRace.getWis() << ") ] | " << profCheck(dRace.getIntell()) << " Investigation   " << setw(2) << stoi(dRace.getIntell()) + dClass.getbonus() << " (int) |  | ___________________________________ |" << endl;
    cout << " *----*  | " << profCheck(dRace.getWis()) << " Medicine        " << setw(2) << stoi(dRace.getWis()) + dClass.getbonus() << " (wis) |  | ___________________________________ |" << endl;
    cout << "| CHA: | | " << profCheck(dRace.getWis()) << " Perception      " << setw(2) << stoi(dRace.getWis()) + dClass.getbonus() << " (wis) |  | ___________________________________ |" << endl;
    cout << "[  " << setw(2) << Charisma << "  ] | " << profCheck(dRace.getCha()) << " Performance     " << setw(2) << stoi(dRace.getCha()) + dClass.getbonus() << " (cha) |  | ___________________________________ |" << endl;
    cout << "[ (" << setw(2) << dRace.getCha() << ") ] | " << profCheck(dRace.getCha()) << " Persuasion      " << setw(2) << stoi(dRace.getCha()) + dClass.getbonus() << " (cha) |  | ___________________________________ |" << endl;
    cout << " *----*  | " << profCheck(dRace.getIntell()) << " Religion        " << setw(2) << stoi(dRace.getIntell()) + dClass.getbonus() << " (int) |  | ___________________________________ |" << endl;
    cout << "/------\\ | " << profCheck(dRace.getDex()) << " Sleight of Hand " << setw(2) << stoi(dRace.getDex()) + dClass.getbonus() << " (dex) |  | ___________________________________ |" << endl;
    cout << "| PAS. | | " << profCheck(dRace.getDex()) << " Stealth         " << setw(2) << stoi(dRace.getDex()) + dClass.getbonus() << " (dex) |  | ___________________________________ |" << endl;
    cout << "| WIS: | | " << profCheck(dRace.getWis()) << " Survival        " << setw(2) << stoi(dRace.getWis()) + dClass.getbonus() << " (wis) |  | ___________________________________ |" << endl;
    cout << "[  " << setw(2) << stoi(dRace.getWis()) + 10 << "  ] {                            }  '-------------------------------------'" << endl;
    cout << " *----*  '----------------------------'  /------._______________________,------\\" << endl;
    cout << "+-------------------------------------+  [              APPEARANCE             ]" << endl;
    cout << "|   OTHER PROFICIENCIES & LANGUAGES   |  [    AGE: ___________________________ ]" << endl;
    cout << "| ___________________________________ |  [ GENDER: ___________________________ ]" << endl;
    cout << "| ___________________________________ |  [ HEIGHT: ___________________________ ]" << endl;
    cout << "| ___________________________________ |  [ WEIGHT: ___________________________ ]" << endl;
    cout << "| ___________________________________ |  [   SKIN: ___________________________ ]" << endl;
    cout << "| ___________________________________ |  [   HAIR: ___________________________ ]" << endl;
    cout << "+-------------------------------------+   \\______,---------------------.______/ " << endl;
 }

#endif // CHARACTERSHEET_H
