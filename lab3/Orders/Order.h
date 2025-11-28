#pragma once
#include "../pch.h"

class Customer;
class Restaurant;
class OrderItem;
class Delivery;
class Payment;

class Order{
    private:
        int orderId_;
        Customer* customer_;
        Restaurant* restaurant_;
        vector<OrderItem*> items_;
        double totalAmount_;
        string status_;
    public:
        Order(int orderId, Customer* customer, Restaurant* restaurant);
        ~Order();

        int getOrderId() const { return orderId_; }
        Customer* getCustomer() const { return customer_; }
        Restaurant* getRestaurant() const { return restaurant_; }
        vector<OrderItem*> getItems() const { return items_; }
        double getTotalAmount() const { return totalAmount_; }
        string getStatus() const { return status_; }

        void setStatus(const string& status) { status_ = status; }
        void addItem(OrderItem* item);
        void removeItem(OrderItem* item);
        void calculateTotal();

        void print() const;
};


