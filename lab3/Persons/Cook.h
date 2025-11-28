#pragma once
#include "Employee.h"

class Restaurant;
class Order;

class Cook: public Employee{
    private:
        Restaurant* restaurant_;
        int ordersPrepared_;
    public:
        Cook(const string& fName, int age, int id, double salary, Restaurant* restaurant);
        ~Cook();

        Restaurant* getRestaurant() const { return restaurant_; }
        int getOrdersPrepared() const { return ordersPrepared_; }

        void prepareOrder(Order* order);

        virtual void work() override;
        virtual void print() const override;
};


