#ifndef TEACHER_H_
#define TEACHER_H_

#include "Person.h"
#include "Student.h"

class Teacher : public Person {
private:
    std::string teachables, employeeId;

public:
    // Constructors
    Teacher(std::string first, std::string last);
    Teacher(std::string f, std::string l, std::string a, std::string t, std::string id);
    Teacher(std::string f, std::string l, std::string t, std::string id);

    // Getters
    std::string getId();
    std::string getTeachables();

    // Setters
    void setTeachables(std::string t);
    void setEmployeeId(std::string id);

    // Other methods
    bool isValidId(std::string id);
    void markStudentLate(Student s);
    std::string toString();
};

#endif
