#include "DeliveryPerson.h"
#include "../Delivery/Vehicle.h"
#include "../Delivery/Delivery.h"

DeliveryPerson::DeliveryPerson(const string& fName, int age, int id, double salary, Vehicle* vehicle)
    : Employee(fName, age, id, salary), vehicle_(vehicle), deliveriesCompleted_(0) {}

DeliveryPerson::~DeliveryPerson() {
    vehicle_ = nullptr;
}

void DeliveryPerson::setVehicle(Vehicle* vehicle) {
    vehicle_ = vehicle;
}

void DeliveryPerson::work() {
    cout << "Delivery person " << getFirstName() << " is delivering orders." << endl;
}

void DeliveryPerson::print() const {
    Employee::print();
    cout << "Deliveries completed: " << deliveriesCompleted_ << endl;
}


