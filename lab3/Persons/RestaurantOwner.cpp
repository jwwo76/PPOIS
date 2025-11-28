#include "RestaurantOwner.h"
#include "../Restaurants/Restaurant.h"

RestaurantOwner::RestaurantOwner(const string& firstName, int age, int ownerId)
    : Person(firstName, age), ownerId_(ownerId) {}

RestaurantOwner::~RestaurantOwner() {
    restaurants_.clear();
}

void RestaurantOwner::addRestaurant(Restaurant* restaurant) {
    if (restaurant) {
        restaurants_.push_back(restaurant);
    }
}

void RestaurantOwner::print() const {
    Person::print();
    cout << "Owner ID: " << ownerId_ << endl;
    cout << "Restaurants owned: " << restaurants_.size() << endl;
}


