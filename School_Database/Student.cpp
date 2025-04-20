#include <iostream>
#include <string>

#include "Person.h"
#include "Student.h"

// Constructors
Student::Student(std::string first, std::string last) : Person(first, last) {
    grade = -1;
    studentId = "Unknown";
}

Student::Student(std::string f, std::string l, std::string a, int g, std::string id) : Person(f, l, a) {
    grade = g;
    if (isValidId(id)) studentId = id;
    else {
        studentId = "Unknown";
        std::cout << "This is not a valid id" << std::endl;
    }
}

Student::Student(std::string f, std::string l, int g, std::string id) : Person(f, l) {
    grade = g;
    if (isValidId(id)) studentId = id;
    else {
        studentId = "Unknown";
        std::cout << "This is not a valid id" << std::endl;
    }
}

// Getters
int Student::getGrade()
{return grade;}

std::string Student::getId()
{return studentId;}

int Student::getNumLates()
{return numLates;}

// Setters
void Student::setGrade(int n)
{grade = n;}

void Student::setStudentId(std::string id) {
    if (isValidId(id)) studentId = id;
    else {
        studentId = "Unknown";
        std::cout << "This is not a valid id";
    }
}

void Student::addLate()
{numLates++;std::cout << "ran";}

// Other methods
bool Student::isValidId(std::string id) {
    if (id.size() != 10 || id[0] != 'S') return false;
    for (int i = 1; i < 10; i++) {
        int charValue = id[i] - '0';
        if (charValue < 0 || charValue > 9) {
            return false;
        }
    }
    return true;
}

std::string Student::toString() {
    return firstName + " " + lastName + ", " + address
           + ", grade " + std::to_string(grade) + " student, id is " + studentId
           + " and has " + std::to_string(numLates) + " lates.";
}
