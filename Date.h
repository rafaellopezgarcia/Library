#pragma once

#include <iostream>
using Day = unsigned short;
using Year = unsigned short;
using Month = std::string;

struct Date{
    Day day;
    Month month;
    Year year;
};
