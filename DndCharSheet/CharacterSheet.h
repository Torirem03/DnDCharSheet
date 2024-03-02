#ifndef CHARACTERSHEET_H
#include <iostream>
#include <iomanip>
#include "DnDClasses.h"
#include "race.h"
#include "inventory.h"
using namespace std;
#define CHARACTERSHEET_H


void printSheet(DnDClasses dClass, Race dRace, Inventory dInventory,string dName, int dInitroll){
    cout << "                                            .---------------------------------. " << endl;
    cout << "DUNGEONS & DRAGONS                         [        NAME: " << setw(20) << dName << " ]" << endl;
    cout << "5E CHARACTER SHEET                         [        RACE: " << setw(20) << dRace.getRace() << " ]" << endl;
    cout << "                                           [  BACKGROUND: ____________________ ]" << endl;
    cout << "                                           [   ALIGNMENT: ____________________ ]" << endl;
    cout << "                                           [ CLASS: " << setw(16) << dClass.getclassname()<< " LEVEL: " << setw(2) << dClass.getlevel() << " ]" << endl;
    cout << "                                           [ EXPERIENCE POINTS: ______________ ]" << endl;
    cout << "                                           \\___________________________________/" << endl;
    cout << endl;
    cout << "/------\\                                    ___    .------------. .-----------." << endl;
    cout << "| STR: |  .--------------------------.    _/   \\_  |/          \\| |/         \\|" << endl;
    cout << "[  __  ] {   __   INSPIRATION         }  |   AC  | | INITIATIVE | |   SPEED   |" << endl;
    cout << "[ (__) ] {   __   PROFICIENCY BONUS   }  |   __  | |     " << setw(2) << dInitroll << "     | | " << setw(6) << dRace.getSpeed() << " ft |" << endl;
    cout << " *----*  {                            }  \\       / |\\          /| |\\         /|" << endl;
    cout << "/------\\  \\__________________________/    \\_____/   ------------   -----------" << endl;
    cout << "| DEX: |  .--------------------------.    .-----------------------------------." << endl;
    cout << "[  __  ] {       SAVING  THROWS       }  { HIT POINTS:  [**********]  __ / __  }" << endl;
    cout << "[ (__) ] { _ STR __  .:/\\:.  __ INT _ }  { TEMP HIT POINTS:                    }" << endl;
    cout << " *----*  | _ DEX __ :\\/20\\/: __ WIS _ |  '-------------------------------------'" << endl;
    cout << "/------\\ { _ CON __ :/\\--/\\: __ CHA _ }  .-------------. .---------------------." << endl;
    cout << "| CON: | {           ._\\/_.           }  |/           \\| |/                   \\|" << endl;
    cout << "[  __  ] '----------------------------'  |  HIT DICE   | |     DEATH SAVES     |" << endl;
    cout << "[ (__) ]  .--------------------------.   |     ___     | |  < - - - + - - - >  |" << endl;
    cout << " *----*  {           SKILLS           }  |\\           /| |\\ death        life /|" << endl;
    cout << "| INT: | | _ Animal Handling __ (wis) |  '-------------' '---------------------'" << endl;
    cout << "[  __  ] | _ Arcana          __ (int) |   .-----------------------------------." << endl;
    cout << "[ (__) ] | _ Athletics       __ (str) |  {       ATTACKS & SPELLCASTING        }" << endl;
    cout << " *----*  | _ Deception       __ (cha) |  | ___________________________________ |" << endl;
    cout << "/------\\ | _ History         __ (int) |  | ___________________________________ |" << endl;
    cout << "| WIS: | | _ Insight         __ (wis) |  | ___________________________________ |" << endl;
    cout << "[  __  ] | _ Intimidation    __ (cha) |  | ___________________________________ |" << endl;
    cout << "[ (__) ] | _ Investigation   __ (int) |  | ___________________________________ |" << endl;
    cout << " *----*  | _ Medicine        __ (wis) |  | ___________________________________ |" << endl;
    cout << "| CHA: | | _ Perception      __ (wis) |  | ___________________________________ |" << endl;
    cout << "[  __  ] | _ Performance     __ (cha) |  | ___________________________________ |" << endl;
    cout << "[ (__) ] | _ Persuasion      __ (cha) |  | ___________________________________ |" << endl;
    cout << " *----*  | _ Religion        __ (int) |  | ___________________________________ |" << endl;
    cout << "/------\\ | _ Sleight of Hand __ (dex) |  | ___________________________________ |" << endl;
    cout << "| PAS. | | _ Stealth         __ (dex) |  | ___________________________________ |" << endl;
    cout << "| WIS: | | _ Survival        __ (wis) |  | ___________________________________ |" << endl;
    cout << "[  __  ] {                            }  '-------------------------------------'" << endl;
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
