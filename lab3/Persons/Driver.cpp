#include "Driver.h"
#include "../Delivery/Vehicle.h"

Driver::Driver(const string& fName, int age, int id, double salary, Vehicle* vehicle)
    : Employee(fName, age, id, salary), vehicle_(vehicle), deliveriesCompleted_(0) {}

Driver::~Driver() {
    vehicle_ = nullptr;
}

void Driver::setVehicle(Vehicle* vehicle) {
    vehicle_ = vehicle;
}

void Driver::work() {
    cout << "Driver " << getFirstName() << " is driving delivery vehicle." << endl;
}

void Driver::print() const {
    Employee::print();
    cout << "Deliveries completed: " << deliveriesCompleted_ << endl;
}


