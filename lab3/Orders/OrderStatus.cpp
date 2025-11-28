#include "OrderStatus.h"
#include "Order.h"
#include <ctime>

OrderStatus::OrderStatus(int statusId, const string& statusName, const string& description, Order* order)
    : statusId_(statusId), statusName_(statusName), description_(description), order_(order) {
    time_t now = time(0);
    timestamp_ = ctime(&now);
    if (!timestamp_.empty() && timestamp_.back() == '\n') {
        timestamp_.pop_back();
    }
}

OrderStatus::~OrderStatus() {
    order_ = nullptr;
}

void OrderStatus::setOrder(Order* order) {
    order_ = order;
}

void OrderStatus::print() const {
    cout << "Status ID: " << statusId_ << endl;
    cout << "Status Name: " << statusName_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Timestamp: " << timestamp_ << endl;
}


