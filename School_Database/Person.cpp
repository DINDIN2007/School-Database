#include <iostream>
#include <string>

#include "Person.h"

// Constructors
Person::Person() {
    firstName = "John";
    lastName = "Doe";
    address = "Unknown";
}

Person::Person(std::string first, std::string last) {
    firstName = first;
    lastName = last;
    address = "Unknown";
}

Person::Person(std::string first, std::string last, std::string add) {
    firstName = first;
    lastName = last;
    address = add;
}

// Getters
std::string Person::getFirstName()
{return firstName;}

std::string Person::getLastName()
{return lastName;}

std::string Person::getAddress()
{return address;}

std::string Person::getId()
{return "Something's wrong";}

// Setters
void Person::setFirstName(std::string n)
{firstName = n;}

void Person::setLastName(std::string n)
{lastName = n;}

void Person::setAddress(std::string a)
{address = a;}

// Rule of Three
Person& Person::operator = (Person& person) {
    if (this != &person) {
        this->firstName = person.firstName;
        this->lastName = person.lastName;
    }
    return *this;
}

// Other methods
std::string Person::toString()
{return firstName + " " + lastName + ", " + address;}
