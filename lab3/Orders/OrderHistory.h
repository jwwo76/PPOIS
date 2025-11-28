#pragma once
#include "../pch.h"

class Customer;
class Order;

class OrderHistory{
    private:
        int historyId_;
        Customer* customer_;
        vector<Order*> orders_;
        int totalOrders_;
        double totalSpent_;
    public:
        OrderHistory(int historyId, Customer* customer);
        ~OrderHistory();

        int getHistoryId() const { return historyId_; }
        Customer* getCustomer() const { return customer_; }
        vector<Order*> getOrders() const { return orders_; }
        int getTotalOrders() const { return totalOrders_; }
        double getTotalSpent() const { return totalSpent_; }

        void setHistoryId(int id) { historyId_ = id; }
        void setCustomer(Customer* customer);
        void addOrder(Order* order);
        void removeOrder(Order* order);
        void calculateStatistics();

        void print() const;
};


