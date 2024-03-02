#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <map>

class Inventory {
public:
    void addItem(const std::string& item, int quantity = 1);
    void removeItem(const std::string& item, int quantity = 1);
    void listItems() const;
    void manageInventory();

private:
    std::map<std::string, int> items;
};

#endif
