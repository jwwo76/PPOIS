#include "OrderTracking.h"
#include "Order.h"
#include "../Delivery/Delivery.h"

OrderTracking::OrderTracking(int trackingId, Order* order, Delivery* delivery)
    : trackingId_(trackingId), order_(order), delivery_(delivery), status_("Preparing") {}

OrderTracking::~OrderTracking() {
    order_ = nullptr;
    delivery_ = nullptr;
}

void OrderTracking::updateLocation(const string& location) {
    currentLocation_ = location;
}

void OrderTracking::updateStatus(const string& status) {
    status_ = status;
}

void OrderTracking::addTrackingEvent(const string& event) {
    trackingHistory_.push_back(event);
}

void OrderTracking::print() const {
    cout << "Tracking ID: " << trackingId_ << endl;
    cout << "Status: " << status_ << endl;
    cout << "Current Location: " << currentLocation_ << endl;
    cout << "Estimated Arrival: " << estimatedArrival_ << endl;
    cout << "Tracking Events: " << trackingHistory_.size() << endl;
}


