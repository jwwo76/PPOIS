#include "Cook.h"
#include "../Restaurants/Restaurant.h"
#include "../Orders/Order.h"

Cook::Cook(const string& fName, int age, int id, double salary, Restaurant* restaurant)
    : Employee(fName, age, id, salary), restaurant_(restaurant), ordersPrepared_(0) {}

Cook::~Cook() {
    restaurant_ = nullptr;
}

void Cook::prepareOrder(Order* order) {
    if (order) {
        ordersPrepared_++;
        cout << "Cook " << getFirstName() << " is preparing order #" << order->getOrderId() << endl;
    }
}

void Cook::work() {
    cout << "Cook " << getFirstName() << " is cooking dishes." << endl;
}

void Cook::print() const {
    Employee::print();
    cout << "Orders prepared: " << ordersPrepared_ << endl;
}


