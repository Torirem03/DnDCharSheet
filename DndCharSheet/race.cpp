#include "race.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Race::display() const {
    std::cout << "Race: " << race << "\nSize: " << size << "\nSpeed: " << speed
              << "\nSTR: " << str << "\nDEX: " << dex << "\nCON: " << con
              << "\nINT: " << intell << "\nWIS: " << wis << "\nCHA: " << cha
              << "\nLanguages: " << languages << "\nExtra: " << extra << std::endl << std::endl;
}

std::vector<std::string> parseCSVLine(const std::string& line) {
    std::vector<std::string> fields;
    std::string field;
    bool inQuotes = false;
    for (char c : line) {
        if (c == '"') {
            inQuotes = !inQuotes;
        } else if (c == ',' && !inQuotes) {
            fields.push_back(field);
            field.clear();
        } else {
            field += c;
        }
    }
    fields.push_back(field);
    return fields;
}

std::vector<Race> loadRaceStats(const std::string& filePath) {
    std::vector<Race> stats;
    std::ifstream file(filePath);
    std::string line;
    std::getline(file, line); // Skip the header
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::vector<std::string> fields = parseCSVLine(line);
        if (fields.empty()) continue;
        Race stat(fields[0], fields[1], fields[2], fields[3], fields[4], fields[5],
                  fields[6], fields[7], fields[8], fields[9], fields[10]);
        stats.push_back(stat);
    }
    return stats;
}

Race selectRace(const std::vector<Race>& races) {
    while (true) {
        std::cout << "Available Races:" << std::endl;
        for (size_t i = 0; i < races.size(); ++i) {
            std::cout << i + 1 << ". " << races[i].getRace() << std::endl;
        }

        std::cout << "\nEnter the number of the race to view details, or 0 to exit: ";
        int choice;
        std::cin >> choice;

        if (choice == 0) {
            exit(0);
        } else if (choice > 0 && choice <= races.size()) {
            races[choice - 1].display();
            std::cout << "Select this race? (y/n): ";
            char confirm;
            std::cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                return races[choice - 1];
            }
        } else {
            std::cout << "Invalid selection. Please try again." << std::endl;
        }
    }
}
