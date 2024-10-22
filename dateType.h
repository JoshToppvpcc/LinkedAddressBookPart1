#pragma once

#ifndef DATETYPE_H
#define DATETYPE_H

#include <iostream>

class dateType {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    dateType() : day(1), month(1), year(1900) {}

    // Parameterized constructor
    dateType(int m, int d, int y) : day(d), month(m), year(y) {}

    // Accessor functions
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

#endif // DATETYPE_H
