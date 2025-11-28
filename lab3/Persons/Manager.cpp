#include "Manager.h"
#include "../Restaurants/Restaurant.h"

Manager::Manager(const string& fName, int age, int id, double salary, Restaurant* restaurant)
    : Employee(fName, age, id, salary), restaurant_(restaurant) {}

Manager::~Manager() {
    restaurant_ = nullptr;
}

void Manager::setRestaurant(Restaurant* restaurant) {
    restaurant_ = restaurant;
}

void Manager::work() {
    cout << "Manager " << getFirstName() << " is managing restaurant." << endl;
}

void Manager::print() const {
    Employee::print();
}


