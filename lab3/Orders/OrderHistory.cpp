#include "OrderHistory.h"
#include "../Persons/Customer.h"
#include "Order.h"

OrderHistory::OrderHistory(int historyId, Customer* customer)
    : historyId_(historyId), customer_(customer), totalOrders_(0), totalSpent_(0.0) {}

OrderHistory::~OrderHistory() {
    customer_ = nullptr;
}

void OrderHistory::setCustomer(Customer* customer) {
    customer_ = customer;
}

void OrderHistory::addOrder(Order* order) {
    if (order) {
        orders_.push_back(order);
        calculateStatistics();
    }
}

void OrderHistory::removeOrder(Order* order) {
    orders_.erase(remove(orders_.begin(), orders_.end(), order), orders_.end());
    calculateStatistics();
}

void OrderHistory::calculateStatistics() {
    totalOrders_ = orders_.size();
    totalSpent_ = 0.0;
    for (auto order : orders_) {
        if (order) {
            totalSpent_ += order->getTotalAmount();
        }
    }
}

void OrderHistory::print() const {
    cout << "History ID: " << historyId_ << endl;
    cout << "Total Orders: " << totalOrders_ << endl;
    cout << "Total Spent: $" << fixed << setprecision(2) << totalSpent_ << endl;
}


