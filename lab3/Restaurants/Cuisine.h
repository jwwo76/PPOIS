#pragma once
#include "../pch.h"

class Restaurant;

class Cuisine{
    private:
        int cuisineId_;
        string name_;
        string originCountry_;
        vector<Restaurant*> restaurants_;
        string description_;
    public:
        Cuisine(int cuisineId, const string& name, const string& originCountry, const string& description);
        ~Cuisine();

        int getCuisineId() const { return cuisineId_; }
        string getName() const { return name_; }
        string getOriginCountry() const { return originCountry_; }
        vector<Restaurant*> getRestaurants() const { return restaurants_; }

        void addRestaurant(Restaurant* restaurant);
        void removeRestaurant(Restaurant* restaurant);

        void print() const;
};


