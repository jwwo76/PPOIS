#include "Cuisine.h"
#include "Restaurant.h"

Cuisine::Cuisine(int cuisineId, const string& name, const string& originCountry, const string& description)
    : cuisineId_(cuisineId), name_(name), originCountry_(originCountry), description_(description) {}

Cuisine::~Cuisine() {
    restaurants_.clear();
}

void Cuisine::addRestaurant(Restaurant* restaurant) {
    if (restaurant) {
        restaurants_.push_back(restaurant);
    }
}

void Cuisine::removeRestaurant(Restaurant* restaurant) {
    restaurants_.erase(remove(restaurants_.begin(), restaurants_.end(), restaurant), restaurants_.end());
}

void Cuisine::print() const {
    cout << "Cuisine ID: " << cuisineId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Origin Country: " << originCountry_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Restaurants: " << restaurants_.size() << endl;
}


