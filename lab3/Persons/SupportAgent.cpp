#include "SupportAgent.h"

SupportAgent::SupportAgent(const string& fName, int age, int id, double salary)
    : Employee(fName, age, id, salary), ticketsResolved_(0) {}

void SupportAgent::work() {
    cout << "Support Agent " << getFirstName() << " is handling customer support requests." << endl;
}

void SupportAgent::print() const {
    Employee::print();
    cout << "Tickets resolved: " << ticketsResolved_ << endl;
}


