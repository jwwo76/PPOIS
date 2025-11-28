#include "City.h"
#include "Zone.h"

City::City(int cityId, const string& name, const string& state, const string& country)
    : cityId_(cityId), name_(name), state_(state), country_(country) {}

City::~City() {
    zones_.clear();
}

void City::addZone(Zone* zone) {
    if (zone) {
        zones_.push_back(zone);
    }
}

void City::removeZone(Zone* zone) {
    zones_.erase(remove(zones_.begin(), zones_.end(), zone), zones_.end());
}

void City::print() const {
    cout << "City ID: " << cityId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "State: " << state_ << endl;
    cout << "Country: " << country_ << endl;
    cout << "Zones: " << zones_.size() << endl;
}


