#include "DeliveryRoute.h"
#include "../Locations/Address.h"
#include "Delivery.h"

DeliveryRoute::DeliveryRoute(int routeId, Address* startPoint, Address* endPoint, double distance, int estimatedTime)
    : routeId_(routeId), startPoint_(startPoint), endPoint_(endPoint), distance_(distance), estimatedTime_(estimatedTime) {}

DeliveryRoute::~DeliveryRoute() {
    startPoint_ = nullptr;
    endPoint_ = nullptr;
}

void DeliveryRoute::addWaypoint(Address* waypoint) {
    if (waypoint) {
        waypoints_.push_back(waypoint);
    }
}

void DeliveryRoute::addDelivery(Delivery* delivery) {
    if (delivery) {
        deliveries_.push_back(delivery);
    }
}

void DeliveryRoute::calculateDistance() {
    // Calculate distance based on waypoints
}

void DeliveryRoute::removeDelivery(Delivery* delivery) {
    deliveries_.erase(remove(deliveries_.begin(), deliveries_.end(), delivery), deliveries_.end());
}

void DeliveryRoute::print() const {
    cout << "Route ID: " << routeId_ << endl;
    cout << "Distance: " << distance_ << " km" << endl;
    cout << "Estimated Time: " << estimatedTime_ << " minutes" << endl;
    cout << "Waypoints: " << waypoints_.size() << endl;
    cout << "Deliveries: " << deliveries_.size() << endl;
}


