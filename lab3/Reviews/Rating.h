#pragma once
#include "../pch.h"

class Restaurant;
class DeliveryPerson;
class Customer;

class Rating{
    private:
        int ratingId_;
        Restaurant* restaurant_;
        DeliveryPerson* deliveryPerson_;
        Customer* customer_;
        int restaurantRating_;
        int deliveryRating_;
        string ratingDate_;
    public:
        Rating(int ratingId, Restaurant* restaurant, DeliveryPerson* deliveryPerson, Customer* customer, int restaurantRating, int deliveryRating, const string& ratingDate);
        ~Rating();

        int getRatingId() const { return ratingId_; }
        int getRestaurantRating() const { return restaurantRating_; }
        int getDeliveryRating() const { return deliveryRating_; }

        void setRestaurantRating(int rating);
        void setDeliveryRating(int rating);

        void print() const;
};


