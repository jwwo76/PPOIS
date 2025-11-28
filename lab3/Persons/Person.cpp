#include "Person.h"

Person::Person(const string& firstName, int age)
    : firstName_(firstName), age_(age) {}

void Person::setFirstName(const string& firstName) {
    firstName_ = firstName;
}

string Person::getFirstName() const {
    return firstName_;
}

int Person::getAge() const {
    return age_;
}

void Person::print() const {
    cout << "First name: " << firstName_ << endl;
    cout << "Age: " << age_ << endl;
}


