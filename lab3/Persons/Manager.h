#pragma once
#include "Employee.h"

class Restaurant;

class Manager: public Employee{
    private:
        Restaurant* restaurant_;
    public:
        Manager(const string& fName, int age, int id, double salary, Restaurant* restaurant);
        ~Manager();

        Restaurant* getRestaurant() const { return restaurant_; }

        void setRestaurant(Restaurant* restaurant);

        virtual void work() override;
        virtual void print() const override;
};


