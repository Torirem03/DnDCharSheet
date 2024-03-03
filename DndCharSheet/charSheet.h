#ifndef CHARSHEET_H
#define CHARSHEET_H

#include <string>

class characterSheet {
private:
    // Member variables
    std::string name;
    std::string dndClass;
    std::string race;
    std::string background;
    int strength;
    int dexterity;
    int charisma;
    int intelligence;
    int wisdom;
    int constitution;
    std::string playerName;
    int level;
    int age;
    std::string gender;
    std::string height;
    std::string weight;
    std::string skinColor;
    std::string hairColor;

public:
    // Constructors
    characterSheet();
    characterSheet(std::string name, std::string dndClass, std::string race, std::string background, int strength, int dexterity, int charisma, int intelligence, int wisdom, int constitution, std::string playerName, int level, int age, std::string gender, std::string height, std::string weight, std::string skinColor, std::string hairColor);

    // Mutators
    void setName(std::string name);
    void setDndClass(std::string dndClass);
    void setRace(std::string race);
    void setBackground(std::string background);
    void setStrength(int strength);
    void setDexterity(int dexterity);
    void setCharisma(int charisma);
    void setIntelligence(int intelligence);
    void setWisdom(int wisdom);
    void setConstitution(int constitution);
    void setPlayerName(std::string playerName);
    void setLevel(int level);
    void setAge(int age);
    void setGender(std::string gender);
    void setHeight(std::string height);
    void setWeight(std::string weight);
    void setSkinColor(std::string skinColor);
    void setHairColor(std::string hairColor);

    // Accessors
    std::string getName();
    std::string getDndClass();
    std::string getRace();
    std::string getBackground();
    int getStrength();
    int getDexterity();
    int getCharisma();
    int getIntelligence();
    int getWisdom();
    int getConstitution();
    std::string getPlayerName();
    int getLevel();
    int getAge();
    std::string getGender();
    std::string getHeight();
    std::string getWeight();
    std::string getSkinColor();
    std::string getHairColor();

    // additional methods
};

#endif
