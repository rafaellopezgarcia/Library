#pragma once

#include <iostream>
#include "Date.h"
#include "Country.h"


enum class eMembership{
    GOLD,
    PLATE,
    BRONZE
};

struct PersonAddressBuilder;
struct PersonBuilder;

struct Address{
private:
    std::string street, city;
    unsigned short number, postal_code;

public:
    friend class PersonAddressBuilder;

    friend std::ostream &operator<<(std::ostream &os, const Address &address);

};

struct Person{
private:
    std::string name;
    Country * pCountry;
    short int age;
    Address address;
public:
    static PersonBuilder create(const std::string & name);

    friend PersonAddressBuilder;
    friend PersonBuilder;
    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};

struct PersonBuilderBase{
    Person &p;
    explicit PersonBuilderBase(Person &p);
    PersonAddressBuilder lives();
    operator Person() const
    {
        return std::move(p);
    }
};

struct PersonAddressBuilder : public PersonBuilderBase{
    Address * address;
    PersonAddressBuilder& at(const unsigned short & number, const std::string & street);
    PersonAddressBuilder& in(const std::string & city);
    PersonAddressBuilder& with_postal_code(const unsigned short & postal_code);

    explicit PersonAddressBuilder(Person * person);
};




struct PersonBuilder : public PersonBuilderBase{
    Person p;
    PersonBuilder& is(const short int age);
    PersonBuilder& from(const std::string country_name);

    explicit PersonBuilder(const std::string & name);
};

struct Employee :  Person{
    unsigned int anual_salary;
    unsigned int number_holidays;
    unsigned int number_taken_holidays;
    unsigned short seniority;
};

struct Membership{
    eMembership membership_type;
    Date joined_date;
    Date expiration_date;
    short int limit_borrowed_books;
    short int borrowed_period;

protected:
    void renew_membership(const eMembership nmbrshp_type, const Date until){
        membership_type = nmbrshp_type;
        expiration_date = until;
    };
};

struct Librarian : public Employee{

};

struct Member : public Person, public Membership{

};