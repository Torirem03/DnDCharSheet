#include <iostream>
#include <DnDClasses.h>
#include <HitDice.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // tests calls for objects
    DnDClasses Class;
    HitDice Dice;
    srand(time(0)); // random seed needed for dicerolls
    cout << Class.getclassname() << endl; // N/A
    for (int i =0; i < 10; i++) { // 10 numbers between 1 and 8 inclusive
        cout << Dice.rollDice(Dice.getDiceType()) << " ";
    }
    Artificer Character1;
    cout << "\nCharacter1 class type: " << Character1.getclassname() << endl;
    cout << "Character1 armor: " << Character1.getarmor() << endl;
    Character1.setarmor("Light Armor");
    cout << "Character1 armor: " << Character1.getarmor() << endl;

    return 0;
}
