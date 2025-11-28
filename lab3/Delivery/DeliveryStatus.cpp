#include "DeliveryStatus.h"
#include "Delivery.h"
#include <ctime>

DeliveryStatus::DeliveryStatus(int statusId, Delivery* delivery, const string& statusName, const string& description)
    : statusId_(statusId), delivery_(delivery), statusName_(statusName), description_(description) {
    time_t now = time(0);
    timestamp_ = ctime(&now);
    if (!timestamp_.empty() && timestamp_.back() == '\n') {
        timestamp_.pop_back();
    }
}

DeliveryStatus::~DeliveryStatus() {
    delivery_ = nullptr;
}

void DeliveryStatus::setDelivery(Delivery* delivery) {
    delivery_ = delivery;
}

void DeliveryStatus::print() const {
    cout << "Status ID: " << statusId_ << endl;
    cout << "Status Name: " << statusName_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Timestamp: " << timestamp_ << endl;
}


