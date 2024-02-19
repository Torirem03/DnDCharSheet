#ifndef HITDICE_H
#define HITDICE_H
using namespace std;

class HitDice {
protected:
    int diceType; // holds what number of sides the dice has
    int diceTotal; // the total number of hitdice the character has
    int diceUsed; // the number of exhausted hit dice that cannot be used
    int diceAvailable; // the number of hit dice the character can use currently
public:
    HitDice();
    virtual ~HitDice();
    // setters
    void setDiceType(int dicetype);
    void setDiceTotal(int dicetotal);
    void setDiceUsed(int diceused);
    void setDiceAvailable(int diceavailable);
    // getters
    int getDiceType() const;
    int getDiceTotal() const;
    int getDiceUsed() const;
    int getDiceAvailable() const;
    // rolls dice based on dicetype as parameter
    int rollDice(int dicetype);
};

#endif // HITDICE_H
