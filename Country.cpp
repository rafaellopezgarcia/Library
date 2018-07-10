#include "Country.h"

/* Countries definitions */
void Countries::add(cstring & name, cstring & nationality, eContinent continent, float population, float GDP){
    Country country(name, nationality, continent, population, GDP);
    countries.emplace_back(country);
}

Country * Countries::find(const std::string & name){
    std::vector<Country>::iterator it;
    it = std::find_if(countries.begin(),countries.end(), [name](Country c){return c.name == name;});

    if (it != countries.end())
        return  it.base();
    else
        return nullptr;
}

/* Countries getters */
const std::string &Country::getNationality() const {
    return nationality;
}

/* ostream overloads*/
std::ostream &operator<<(std::ostream &os, const Country &country) {
    os << std::setw(25) << std::left << country.name
       << std::setw(25) << std::left << country.population
       << country.GDP;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Countries &countries) {
    os << std::setw(25) << std::left << "name"
       << std::setw(25) << std::left << "Population (millions)"
       << "GDP (trillions)\n";

    for (auto && c : countries.countries){
        os << c << "\n";
    }
    return os;
}
