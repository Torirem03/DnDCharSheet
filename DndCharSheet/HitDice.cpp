#include <HitDice.h>
#include <cstdlib>
#include <ctime>
// constructor&destructor
HitDice::HitDice() {
    diceType = 8;
    diceTotal = 1;
    diceUsed = 0;
    diceAvailable = 1;
}
HitDice::~HitDice() {}
// setters
void HitDice::setDiceType (int dicetype) {
    diceType = dicetype;
}
void HitDice::setDiceTotal (int dicetotal) {
    diceTotal = dicetotal;
}
void HitDice::setDiceUsed (int diceused) {
    diceUsed = diceused;
}
void HitDice::setDiceAvailable (int diceavailable) {
    diceAvailable = diceavailable;
}
// getters
int HitDice::getDiceType() const {
    return diceType;
}
int HitDice::getDiceTotal() const {
    return diceTotal;
}
int HitDice::getDiceUsed() const {
    return diceUsed;
}
int HitDice::getDiceAvailable() const {
    return diceAvailable;
}
// rolls dice from 1 to dicetype inclusive and returns result
int HitDice::rollDice (int dicetype) {
    int result;
    result = (rand() % dicetype) + 1;
    return result;
}
