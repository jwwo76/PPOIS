#pragma once
#include "Employee.h"

class Vehicle;
class Delivery;

class Driver: public Employee{
    private:
        Vehicle* vehicle_;
        int deliveriesCompleted_;
    public:
        Driver(const string& fName, int age, int id, double salary, Vehicle* vehicle);
        ~Driver();

        Vehicle* getVehicle() const { return vehicle_; }
        int getDeliveriesCompleted() const { return deliveriesCompleted_; }

        void setVehicle(Vehicle* vehicle);
        void completeDelivery() { deliveriesCompleted_++; }

        virtual void work() override;
        virtual void print() const override;
};


