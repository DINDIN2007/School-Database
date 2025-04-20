#include <iostream>
#include <string>

#include "Teacher.h"
#include "Student.h"


// Constructors
Teacher::Teacher(std::string first, std::string last) : Person(first, last) {
    teachables = "Unknown";
    employeeId = "Unknown";
}

Teacher::Teacher(std::string f, std::string l, std::string a, std::string t, std::string id) : Person(f, l, a) {
    teachables = t;
    if (isValidId(id)) employeeId = id;
    else {
        employeeId = "Unknown";
        std::cout << "This is not a valid id" << std::endl;
    }
}

Teacher::Teacher(std::string f, std::string l, std::string t, std::string id) : Person(f, l) {
    teachables = t;
    employeeId = id;
}

// Getters
std::string Teacher::getTeachables()
{return teachables;}

std::string Teacher::getId()
{return employeeId;}

// Setters
void Teacher::setTeachables(std::string t)
{teachables = t;}

void Teacher::setEmployeeId(std::string id)
{employeeId = id;}

// Other methods
bool Teacher::isValidId(std::string id) {
    if (id.size() != 6 || id[0] != 'C') return false;
    for (int i = 1; i < 6; i++) {
        int charValue = id[i] - '0';
        if (charValue < 0 || charValue > 9) {
            return false;
        }
    }
    return true;
}

void Teacher::markStudentLate(Student s)
{s.addLate();}

std::string Teacher::toString() {
    return firstName + " " + lastName + ", " + address
           + ", teaches " + teachables + ", and employee id is " + employeeId;
}
