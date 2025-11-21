#include "Person.h"

Person::Person(const string& firstName, const string& surname, int age)
    : firstName_(firstName), surname_(surname), age_(age) {}

void Person::setFirstName(const string& firstName) {
    firstName_ = firstName;
}

void Person::setSurname(const string& surname) {
    surname_ = surname;
}

void Person::setAge(int age) {
    this->age_ = age;
}

string Person::getFirstName() const {
    return firstName_;
}

string Person::getSurname() const {
    return surname_;
}

int Person::getAge() const {
    return age_;
}

void Person::print() const {
    cout << "First name: " << firstName_ << endl;
    cout << "Surname: " << surname_ << endl;
    cout << "Age: " << age_ << endl;
}