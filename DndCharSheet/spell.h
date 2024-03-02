#ifndef SPELL_H
#define SPELL_H

#include <string>
#include <vector>

class Spell
{
private:
    std::string name;
    std::string class_;
    int level;
    std::string school;
    std::string cast_time;
    std::string range;
    std::string duration;
    bool verbal;
    bool somatic;
    bool material;
    std::string material_cost;
    std::string description;
public:
    Spell();
    Spell(const std::string& name, const std::string& class_, int level,
          const std::string& school, const std::string& cast_time, const std::string &range,
          const std::string& duration, bool verbal, bool somatic, bool material,
          const std::string& material_cost, std::string& description);

    std::string getName() const;
    std::string getClass_() const;
    int getLevel() const;
    std::string getSchool() const;
    std::string getCastTime() const;
    std::string getRange() const;
    std::string getDuration() const;
    bool hasVerbal() const;
    bool hasSomatic() const;
    bool hasMaterial() const;
    std::string getMaterialCost() const;
    std::string getDescription() const;

    void setName(const std::string& newName);
    void setClass_(const std::string& newClass);
    void setLevel(const int newLevel);
    void setSchool(const std::string& newSchool);
    void setCastTime(const std::string& newCastTime);
    void setRange(const std::string& newRange);
    void setDuration(const std::string& newDuration);
    void setVerbal(bool hasVerbal);
    void setSomatic(bool hasSomatic);
    void setMaterial(bool hasMaterial);
    void setMaterialCost(const std::string& newMaterialCost);
    void setDescription(const std::string& newDescription);
    //member function needs to be static
    static std::vector<Spell> parseCSV(const std::string& filename);
};

#endif // SPELL_H
