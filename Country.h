#pragma once

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

enum class eContinent{
    AMERICA,
    AFRICA,
    ASIA,
    AUSTRALIA,
    EUROPE
};

struct Countries;
struct Country{
private:
    std::string name;
    std::string nationality;
    eContinent continent;
    float population;// in millions.
    float GDP;// in trillions.

    Country()= default;
    Country(std::string name, std::string nationality, eContinent continent, float population, float GDP) :
            name(std::move(name)),
            nationality(std::move(nationality)),
            continent(continent),
            population(population),
            GDP(GDP) {}

public:
    const std::string &getNationality() const;

    friend Countries;
    friend std::ostream &operator<<(std::ostream &os, const Country &country);
};

struct Countries{
private:
    using cstring = const std::string;
    std::vector<Country> countries;

public:
    Countries& operator=(const Countries &) {
        int a ;
    };
    //Countries(const Countries &) = delete;
    Countries(){}

    Country * find(const std::string & name);
    void add(cstring & name, cstring & nationality, eContinent continent, float population, float GDP);
    friend std::ostream &operator<<(std::ostream &os, const Countries &countries);
};

struct CountriesSingleton{
    CountriesSingleton(CountriesSingleton const &) = delete;
    Countries& operator=(Countries const &) = delete;
    static Countries &list(){
        static Countries countries;
        return countries;
    };
};
