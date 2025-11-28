#pragma once
#include "Employee.h"

class Restaurant;

class Cashier: public Employee{
    private:
        Restaurant* restaurant_;
        int transactionsProcessed_;
    public:
        Cashier(const string& fName, int age, int id, double salary, Restaurant* restaurant);
        ~Cashier();

        Restaurant* getRestaurant() const { return restaurant_; }
        int getTransactionsProcessed() const { return transactionsProcessed_; }

        void processTransaction(double amount);

        virtual void work() override;
        virtual void print() const override;
};


