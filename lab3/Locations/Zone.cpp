#include "Zone.h"
#include "Address.h"

Zone::Zone(int zoneId, const string& zoneName, double deliveryFee, int estimatedDeliveryTime)
    : zoneId_(zoneId), zoneName_(zoneName), deliveryFee_(deliveryFee), estimatedDeliveryTime_(estimatedDeliveryTime) {}

Zone::~Zone() {
    addresses_.clear();
}

void Zone::addAddress(Address* address) {
    if (address) {
        addresses_.push_back(address);
    }
}

void Zone::removeAddress(Address* address) {
    addresses_.erase(remove(addresses_.begin(), addresses_.end(), address), addresses_.end());
}

void Zone::print() const {
    cout << "Zone ID: " << zoneId_ << endl;
    cout << "Zone Name: " << zoneName_ << endl;
    cout << "Delivery Fee: $" << fixed << setprecision(2) << deliveryFee_ << endl;
    cout << "Estimated Delivery Time: " << estimatedDeliveryTime_ << " minutes" << endl;
    cout << "Addresses: " << addresses_.size() << endl;
}


