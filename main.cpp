#include <iostream>
#include "Member.h"
#include "Country.h"
int main() {
    CountriesSingleton::list().add("USA", "American", eContinent::AMERICA, 325.7f, 18.57f);
    CountriesSingleton::list().add("Mexico", "Mexican", eContinent::AMERICA, 127.5f, 1.05f);
    CountriesSingleton::list().add("Germany", "German", eContinent::EUROPE, 82.67f, 3.47f);
    CountriesSingleton::list().add("Japan", "Japanese", eContinent::ASIA, 127.f, 4.94f);
    CountriesSingleton::list().add("South Africa", "South african", eContinent::AFRICA, 55.91f, 0.29f);
    std::cout << CountriesSingleton::list() << std::endl;

    Countries ctrs= CountriesSingleton::list();

    Country * country, * country2;
    country = CountriesSingleton::list().find("USA");
    country2 = CountriesSingleton::list().find("USA");

    std::cout << *country << std::endl;

    std::cout << "Hello, World!" << std::endl;
    Person p = Person::create("Karly Kloss").from("USA").is(25)
            .lives().at(123, "Spring St.").in("New York City").with_postal_code(10013);

    std::cout << p << std::endl;


    return 0;
}