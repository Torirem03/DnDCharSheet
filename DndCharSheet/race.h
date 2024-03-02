#ifndef RACE_H
#define RACE_H

#include <string>
#include <vector>

class Race {
private:
    std::string race;
    std::string size;
    std::string speed;
    std::string str;
    std::string dex;
    std::string con;
    std::string intell;
    std::string wis;
    std::string cha;
    std::string languages;
    std::string extra;

public:
    // Constructor
    Race(const std::string& race, const std::string& size, const std::string& speed,
         const std::string& str, const std::string& dex, const std::string& con,
         const std::string& intell, const std::string& wis, const std::string& cha,
         const std::string& languages, const std::string& extra)
        : race(race), size(size), speed(speed), str(str), dex(dex), con(con),
        intell(intell), wis(wis), cha(cha), languages(languages), extra(extra) {}

    // Getter functions
    std::string getRace() const { return race; }
    std::string getSize() const { return size; }
    std::string getSpeed() const { return speed; }
    std::string getStr() const { return str; }
    std::string getDex() const { return dex; }
    std::string getCon() const { return con; }
    std::string getIntell() const { return intell; }
    std::string getWis() const { return wis; }
    std::string getCha() const { return cha; }
    std::string getLanguages() const { return languages; }
    std::string getExtra() const { return extra; }

    // Display function
    void display() const;
};

std::vector<std::string> parseCSVLine(const std::string& line);
std::vector<Race> loadRaceStats(const std::string& filePath);
Race selectRace(const std::vector<Race>& stats);

#endif
