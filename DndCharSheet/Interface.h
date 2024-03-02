#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "charSheet.h" // Include the header file for characterSheet class

class interface {
private:
    characterSheet activeCharSheet;
    std::vector<characterSheet> savedCharSheets;
    int menuInput;
    std::string otherInput;
    std::string tempName;
    std::string tempPlayer;
    int tempStr;
    int tempCon;
    int tempDex;
    int tempCha;
    int tempInt;
    int tempWis;
    int tempLevel;
    int tempAge;
    std::string tempGender;
    std::string tempHeight;
    std::string tempWeight;
    std::string tempSkin;
    std::string tempHair;

public:
    // Constructors
    interface();

    // Methods
    void createCharSheet();
    void editCharSheet();
    void clearCharSheet();
    void saveCharSheet();
    void viewCurrentCharSheet();
    void viewAllCharSheets();
    void loadCharSheet();
    void start();
    void end();
    void runInterface();
};

#endif
