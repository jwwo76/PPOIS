#include "Review.h"
#include "../Persons/Customer.h"
#include "../Restaurants/Restaurant.h"
#include "../Orders/Order.h"

Review::Review(int reviewId, Customer* customer, Restaurant* restaurant, Order* order, int rating, const string& comment, const string& reviewDate)
    : reviewId_(reviewId), customer_(customer), restaurant_(restaurant), order_(order), rating_(rating), comment_(comment), reviewDate_(reviewDate) {}

Review::~Review() {
    customer_ = nullptr;
    restaurant_ = nullptr;
    order_ = nullptr;
}

void Review::setRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        rating_ = rating;
    }
}

void Review::print() const {
    cout << "Review ID: " << reviewId_ << endl;
    cout << "Rating: " << rating_ << "/5" << endl;
    cout << "Comment: " << comment_ << endl;
    cout << "Review Date: " << reviewDate_ << endl;
}


