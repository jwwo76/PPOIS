#pragma once
#include "Person.h"

class Restaurant;

class RestaurantOwner: public Person{
    private:
        int ownerId_;
        vector<Restaurant*> restaurants_;
    public:
        RestaurantOwner(const string& firstName, int age, int ownerId);
        ~RestaurantOwner();

        int getOwnerId() const { return ownerId_; }
        vector<Restaurant*> getRestaurants() const { return restaurants_; }

        void addRestaurant(Restaurant* restaurant);

        virtual void print() const override;
};


