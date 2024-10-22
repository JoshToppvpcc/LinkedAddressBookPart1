#include <iostream>
#include <string>
#include "addressBookType.h"

void displayMenu() {
    std::cout << "\n--- Address Book Menu ---" << std::endl;
    std::cout << "1. Search by name" << std::endl;
    std::cout << "2. Search by relationship" << std::endl;
    std::cout << "3. Print all entries" << std::endl;
    std::cout << "4. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    // Initialize address book
    addressBookType myAddressBook;

    // Load data from file
    std::string fileName = "AddressData.txt";
    myAddressBook.initEntry(fileName);

    bool exitProgram = false;
    int choice;

    while (!exitProgram) {
        displayMenu(); // Show the menu

        std::cin >> choice; // Get user choice

        switch (choice) {
        case 1: {
            // Search by name
            std::string firstName, lastName;
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            myAddressBook.findPerson(firstName, lastName);
            break;
        }
        case 2: {
            // Search by relationship
            std::string relationship;
            std::cout << "Enter relationship: ";
            std::cin >> relationship;
            myAddressBook.findRelations(relationship);
            break;
        }
        case 3: {
            // Print all entries
            myAddressBook.print();
            break;
        }
        case 4: {
            // Exit
            exitProgram = true;
            std::cout << "Exiting program." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }

    return 0;
}
