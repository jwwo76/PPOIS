#include "DeliveryZone.h"
#include "../Locations/Address.h"
#include "Delivery.h"

DeliveryZone::DeliveryZone(int zoneId, const string& zoneName, double deliveryFee, int estimatedDeliveryTime)
    : zoneId_(zoneId), zoneName_(zoneName), deliveryFee_(deliveryFee), estimatedDeliveryTime_(estimatedDeliveryTime) {}

DeliveryZone::~DeliveryZone() {
    coveredAreas_.clear();
}

void DeliveryZone::addCoveredArea(Address* address) {
    if (address) {
        coveredAreas_.push_back(address);
    }
}

void DeliveryZone::addDelivery(Delivery* delivery) {
    if (delivery) {
        activeDeliveries_.push_back(delivery);
    }
}

void DeliveryZone::removeDelivery(Delivery* delivery) {
    activeDeliveries_.erase(remove(activeDeliveries_.begin(), activeDeliveries_.end(), delivery), activeDeliveries_.end());
}

void DeliveryZone::print() const {
    cout << "Zone ID: " << zoneId_ << endl;
    cout << "Zone Name: " << zoneName_ << endl;
    cout << "Delivery Fee: $" << fixed << setprecision(2) << deliveryFee_ << endl;
    cout << "Estimated Delivery Time: " << estimatedDeliveryTime_ << " minutes" << endl;
    cout << "Covered Areas: " << coveredAreas_.size() << endl;
    cout << "Active Deliveries: " << activeDeliveries_.size() << endl;
}


