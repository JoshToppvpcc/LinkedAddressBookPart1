#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cassert>
#include "dateType.h"
#include "extPersonType.h"
#include "orderedLinkedList.h"
#include "linkedList.h"



class addressBookType : public orderedLinkedList<extPersonType> {
public:
    // Constructor (No need for maxSize anymore, as the linked list is dynamic)
    addressBookType() {}

    void addEntry(const extPersonType& newPerson) {
        insert(newPerson); // Insert into the ordered linked list
    }

    void deleteEntry(const std::string& firstName, const std::string& lastName) {
        std::string fName, lName;

        // Prompt the user for the first name of the entry to delete
        std::cout << "Enter first name of the entry to delete: ";
        std::cin >> fName;

        // Prompt the user for the last name of the entry to delete
        std::cout << "Enter last name of the entry to delete: ";
        std::cin >> lName;

        // Create a temporary extPersonType object to search for
        extPersonType searchPerson(fName, lName, "", dateType(), "", "", "", "", "");

        // Call deleteNode on the contactList member and check if it was successful
        deleteNode(searchPerson);

    }

    // Function to initialize entries from the file
    void initEntry(const std::string& filename) {
        std::ifstream infile("AddressData.txt");

        // Check if file opened successfully
        if (!infile.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
            return;
        }

        std::cout << "File opened successfully.\n"; // Debug output

        std::string fName, lName, rel;
        int month, day, year;
        std::string streetAddress, city, state, zipCode, phoneNumber;

        // Read until end of file
        while (std::getline(infile, fName)) {
            if (fName.empty()) continue; // Skip empty lines

            std::getline(infile, lName);
            infile >> month >> day >> year; infile.ignore(); // Read date and ignore newline
            std::getline(infile, streetAddress);
            std::getline(infile, city);
            std::getline(infile, state);
            std::getline(infile, zipCode);
            std::getline(infile, phoneNumber);
            std::getline(infile, rel);
            infile.ignore(); // Ignore the next newline

            // Debug output
            std::cout << "Read entry: " << fName << " " << lName << ", " << rel
                << ", " << month << "/" << day << "/" << year
                << ", " << streetAddress << ", " << city << ", "
                << state << ", " << zipCode << ", " << phoneNumber << std::endl;

            // Create the date object
            dateType birthDate(month, day, year);

            // Create the new person object
            extPersonType newPerson(fName, lName, rel, birthDate, streetAddress, city, state, zipCode, phoneNumber);

            // Insert into the address book
            addEntry(newPerson);
        }

        infile.close();
        std::cout << "File reading complete.\n";  // Debug output
    }

    
    // Function to find a person by last name
    void findPerson(const std::string& fName, std::string& lName) const {
        nodeType<extPersonType>* current = this->first;  // Start at the first node
        bool found = false;

        while (current != nullptr) {
            if (current->info.getLastName() == lName) {
                current->info.print();
                found = true;
                break;
            }
            current = current->link;
        }

        if (!found) {
            std::cout << "Person not found." << std::endl;
        }
    }

    // Function to find birthdays by month
    void findBirthdays(int month) const {
        nodeType<extPersonType>* current = this->first;

        while (current != nullptr) {
            if (current->info.getBirthDate().getMonth() == month) {
                current->info.print();
            }
            current = current->link;
        }
    }

    // Function to find people by relationship
    void findRelations(const std::string& rel) const {
        nodeType<extPersonType>* current = this->first;

        while (current != nullptr) {
            if (current->info.getRelationship() == rel) {
                current->info.print();
            }
            current = current->link;
        }
    }

    // Function to print all entries
    void print() const {
        nodeType<extPersonType>* current = this->first;

        while (current != nullptr) {
            current->info.print();
            current = current->link;
        }
    }

    // Override the delete function to delete by last name
    void deletePerson(const std::string& lName) {
        nodeType<extPersonType>* current = this->first;
        nodeType<extPersonType>* previous = nullptr;

        while (current != nullptr) {
            if (current->info.getLastName() == lName) {
                this->deleteNode(current->info);
                std::cout << "Person with last name " << lName << " deleted." << std::endl;
                return;
            }
            previous = current;
            current = current->link;
        }

        std::cout << "Person not found." << std::endl;
    }
};