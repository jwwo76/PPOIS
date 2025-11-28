#pragma once
#include "Person.h"

class Address;
class Order;

class Customer: public Person{
    private:
        int customerId_;
        string email_;
        vector<Order*> orders_;
    public:
        Customer(const string& firstName, int age, int customerId, const string& email);
        ~Customer();

        int getCustomerId() const { return customerId_; }
        string getEmail() const { return email_; }
        vector<Order*> getOrders() const { return orders_; }

        void setEmail(const string& email) { email_ = email; }
        void addOrder(Order* order);

        virtual void print() const override;
};


