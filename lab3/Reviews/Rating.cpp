#include "Rating.h"
#include "../Restaurants/Restaurant.h"
#include "../Persons/DeliveryPerson.h"
#include "../Persons/Customer.h"
#include "../Exceptions/Exceptions.h"

Rating::Rating(int ratingId, Restaurant* restaurant, DeliveryPerson* deliveryPerson, Customer* customer, int restaurantRating, int deliveryRating, const string& ratingDate)
    : ratingId_(ratingId), restaurant_(restaurant), deliveryPerson_(deliveryPerson), customer_(customer), restaurantRating_(restaurantRating), deliveryRating_(deliveryRating), ratingDate_(ratingDate) {}

Rating::~Rating() {
    restaurant_ = nullptr;
    deliveryPerson_ = nullptr;
    customer_ = nullptr;
}

void Rating::setRestaurantRating(int rating) {
    Exceptions::validateRating1to5(rating, "Рейтинг ресторана");
    restaurantRating_ = rating;
}

void Rating::setDeliveryRating(int rating) {
    Exceptions::validateRating1to5(rating, "Рейтинг доставки");
    deliveryRating_ = rating;
}

void Rating::print() const {
    cout << "Rating ID: " << ratingId_ << endl;
    cout << "Restaurant Rating: " << restaurantRating_ << "/5" << endl;
    cout << "Delivery Rating: " << deliveryRating_ << "/5" << endl;
    cout << "Date: " << ratingDate_ << endl;
}


