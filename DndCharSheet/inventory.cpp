#include "inventory.h"
#include <iostream>
#include <limits>

void Inventory::addItem(const std::string& item, int quantity) {
    items[item] += quantity;
    std::cout << quantity << " " << item << "(s) added to the inventory.\n";
}

void Inventory::removeItem(const std::string& item, int quantity) {
    auto it = items.find(item);
    if (it != items.end() && it->second >= quantity) {
        it->second -= quantity;
        std::cout << quantity << " " << item << "(s) removed from the inventory.\n";
        if (it->second <= 0) {
            items.erase(it);
        }
    } else {
        std::cout << "Unable to remove " << quantity << " " << item << "(s) from the inventory.\n";
    }
}

void Inventory::listItems() const {
    if (items.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    std::cout << "Inventory items:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.first << ": " << item.second << std::endl;
    }
}

void Inventory::manageInventory() {
    while (true) {
        std::cout << "\nInventory Management:\n"
                  << "1. View Inventory\n"
                  << "2. Add Item\n"
                  << "3. Remove Item\n"
                  << "4. Exit\n"
                  << "Enter choice: ";
        int choice;
        std::cin >> choice;

        // Clear the input buffer to handle the newline character after the integer input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string item;
        int quantity;
        switch (choice) {
        case 1:
            listItems();
            break;
        case 2:
            std::cout << "Enter item name to add: ";
            std::getline(std::cin, item); // Get the full line for item name
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            // Again, clear the input buffer after reading an integer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            addItem(item, quantity);
            break;
        case 3:
            std::cout << "Enter item name to remove: ";
            std::getline(std::cin, item); // Get the full line for item name
            std::cout << "Enter quantity: ";
            std::cin >> quantity;
            // Clear the input buffer after reading an integer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            removeItem(item, quantity);
            break;
        case 4:
            return; // This should exit the loop and return control to the calling function
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break; // Make sure to break after default case as well
        }
    }
}

