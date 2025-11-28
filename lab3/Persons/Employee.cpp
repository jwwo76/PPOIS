#include "Employee.h"

Employee::Employee(const string& fName, int age, int id, double salary) 
: Person(fName, age), id_(id), salary_(salary) {}

void Employee::setSalary(double newSalary){
    if(newSalary>=0) salary_ = newSalary;
}

void Employee::print() const {
    Person::print();
    cout << "ID: " << id_ << endl;
    cout << "Salary: " << salary_ << endl;
}


