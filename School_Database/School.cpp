#include <vector>

#include "School.h"
#include "Person.h"

School::School() {

}

void School::addPerson(Person *p) {
    this->person.push_back(p);
}

void School::deletePerson(Person *p) {
    for (int i = 0; i < person.size(); i++) {
        if (person[i] == p) {
            person.erase(person.begin() + i);
            delete p;
        }
    }
}

Person* School::findPerson(std::string name) {
    for (Person *currentPerson : person) {
        std::string currentPersonName = currentPerson->getFirstName() + " " + currentPerson->getLastName();
        if (currentPersonName.compare(name) == 0) {
            return currentPerson;
        }
    }
    return new Person();
}
