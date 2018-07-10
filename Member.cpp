#include "Member.h"

/* Person definitions*/
PersonBuilder Person::create(const std::string & name){
    return PersonBuilder(name);
}

/* PersonBuilderBase definitions*/
PersonBuilderBase::PersonBuilderBase(Person &p) : p(p) {

}

PersonAddressBuilder PersonBuilderBase::lives() {
    return PersonAddressBuilder(&p);
}

/* AddressBuilder definition*/
PersonAddressBuilder::PersonAddressBuilder(Person * person) : PersonBuilderBase(*person), address(&person->address) {

}

PersonAddressBuilder & PersonAddressBuilder::at(const unsigned short & number, const std::string & street){
    address->street = street;
    address->number = number;
    return *this;
}

PersonAddressBuilder & PersonAddressBuilder::in(const std::string &city) {
    address->city = city;
    return *this;
}

PersonAddressBuilder & PersonAddressBuilder::with_postal_code(const unsigned short &postal_code) {
    address->postal_code = postal_code;
    return *this;
}

/* PersonBuilder definitions*/
PersonBuilder::PersonBuilder(const std::string & name) : PersonBuilderBase(p){
    p.name = name;
}

PersonBuilder & PersonBuilder::from(const std::string country_name) {
    p.pCountry = CountriesSingleton::list().find(country_name);
    return *this;
}

PersonBuilder & PersonBuilder::is(const short int age) {
    p.age = age;
    return *this;
}

/* ostream overloads*/
std::ostream &operator<<(std::ostream &os, const Person &person) {
    if (person.pCountry != nullptr) {
        auto nationality{person.pCountry->getNationality()};
        os << person.name << ", " << person.age << " years old, is " << nationality
           << ", lives in " << person.address;
    }

    else{
        os << person.name << ", " << person.age << " years old"
           << ", lives in " << person.address;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Address &address) {
    os << address.number << " " << address.street << ", " << address.city << ", "
       << address.postal_code;
    return os;
}

