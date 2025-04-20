#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include "Person.h"

class Student : public Person {
private:
    int grade;
    std::string studentId;
    int numLates = 0;

public:
    // Constructors
    Student(std::string first, std::string last);
    Student(std::string f, std::string l, std::string a, int g, std::string id);
    Student(std::string f, std::string l, int g, std::string id);

    // Getters
    int getGrade();
    std::string getId();
    int getNumLates();

    // Setters
    void setGrade(int n);
    void setStudentId(std::string id);
    void addLate();

    // Other methods
    bool isValidId(std::string id);
    std::string toString();
};

#endif // !STUDENT_H_
