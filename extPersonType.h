#pragma once
#include <iostream>
#include <string>
#include "dateType.h"

class extPersonType {
private:
    std::string firstName;
    std::string lastName;
    std::string relationship;
    dateType birthDate;
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipCode;
    std::string phoneNumber;

public:
    // Default constructor
    extPersonType() : firstName(""), lastName(""), relationship(""),
        birthDate(), streetAddress(""), city(""),
        state(""), zipCode(""), phoneNumber("") {
    }

    // Constructor definition
    extPersonType(const std::string& fName, const std::string& lName, const std::string& rel,
        const dateType& birthDate, const std::string& streetAddress,
        const std::string& city, const std::string& state,
        const std::string& zipCode, const std::string& phoneNumber)
        : firstName(fName), lastName(lName), relationship(rel),
        birthDate(birthDate), streetAddress(streetAddress),
        city(city), state(state), zipCode(zipCode), phoneNumber(phoneNumber) { }


    // Overloading the '==' operator
    bool operator==(const extPersonType& other) const {
        std::string key = lastName + " " + firstName;
        std::string otherKey = other.lastName + " " + other.firstName;
        return key == otherKey;
    }

    // Overloading the '!=' operator
    bool operator!=(const extPersonType& other) const {
        return !(*this == other);
    }

    // Overloading the '>=' operator
    bool operator>=(const extPersonType& other) const {
        std::string key = lastName + " " + firstName;
        std::string otherKey = other.lastName + " " + other.firstName;
        return key >= otherKey;
    }
    // getter function for birthdate
    dateType getBirthDate() const {
        return birthDate;
    }
    // Getter for relationship
    std::string getRelationship() const {
        return relationship;
    }
    std::string getPhoneNumber() const {
        return phoneNumber;
    }
    std::string getStreetAddress() const {
        return streetAddress;
    }
    std::string getZipCode() const {
        return zipCode;
    }
    std::string getCity() const {
        return city;
    }
    std::string getState() const {
        return state;
    }
    // Getter functions for firstName and lastName
    std::string getFirstName() const { 
        return firstName; 
    }
    std::string getLastName() const { 
        return lastName; 
    }

    // Function to print the person info 
    void print() const {
        std::cout << firstName << " " << lastName << ", " << relationship
            << ", " << birthDate.getMonth() << "/" << birthDate.getDay()
            << "/" << birthDate.getYear() << std::endl;
    }

};

