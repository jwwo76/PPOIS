#include "Cashier.h"
#include "../Restaurants/Restaurant.h"

Cashier::Cashier(const string& fName, int age, int id, double salary, Restaurant* restaurant)
    : Employee(fName, age, id, salary), restaurant_(restaurant), transactionsProcessed_(0) {}

Cashier::~Cashier() {
    restaurant_ = nullptr;
}

void Cashier::processTransaction(double amount) {
    if (amount > 0) {
        transactionsProcessed_++;
    }
}

void Cashier::work() {
    cout << "Cashier " << getFirstName() << " is processing payments." << endl;
}

void Cashier::print() const {
    Employee::print();
    cout << "Transactions processed: " << transactionsProcessed_ << endl;
}


