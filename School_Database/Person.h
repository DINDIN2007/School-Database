#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>

class Person {
protected:
    std::string firstName, lastName, address;
public:
    // Constructors
    Person();
    Person(std::string first, std::string last);
    Person(std::string first, std::string last, std::string add);

    // Getters
    std::string getFirstName();
    std::string getLastName();
    std::string getAddress();
    virtual std::string getId();

    // Setters
    void setFirstName(std::string n);
    void setLastName(std::string n);
    void setAddress(std::string a);

    // Rule of Three
    Person& operator = (Person& person);

    // Other methods
    std::string toString();
};

#endif
