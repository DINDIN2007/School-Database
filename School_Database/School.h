#ifndef SCHOOL_H
#define SCHOOL_H

#include <vector>
#include "Person.h"

class School {
private:
    // Stores the people (Student and Teachers) inside of the instance's vector
    std::vector<Person*> person;
public:
    // Default constructor for School instance with no people
    School();

    // Vector Modifier Class Methods
    void addPerson(Person *p);
    void deletePerson(Person *p);
    Person* findPerson(std::string name);

    //void sortPerson();
};

#endif // SCHOOL_H
