#include "Employee.h"

Employee::Employee(const string& fName, const string& sName, int age, int id, const string& position, double salary, int experience) 
: Person(fName, sName, age), id_(id), position_(position), salary_(salary), experience_(experience) {};

void Employee::setSalary(double newSalary){
    if(newSalary>=0) salary_ = newSalary;
}

void Employee::print() const {
    
    Person::print();
    cout << "ID: " << id_ << endl;
    cout << "Position: " << position_ << endl;
    cout << "Salary: " << salary_ << endl;
    cout << "Experience: " << experience_ << " year(s)" << endl;
}