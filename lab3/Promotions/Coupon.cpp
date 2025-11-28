#include "Coupon.h"
#include "../Persons/Customer.h"
#include "../Restaurants/Restaurant.h"

Coupon::Coupon(int couponId, const string& couponCode, Customer* customer, Restaurant* restaurant, double discountValue, const string& discountType, const string& expiryDate)
    : couponId_(couponId), couponCode_(couponCode), customer_(customer), restaurant_(restaurant), discountValue_(discountValue), discountType_(discountType), expiryDate_(expiryDate), isUsed_(false) {}

Coupon::~Coupon() {
    customer_ = nullptr;
    restaurant_ = nullptr;
}

bool Coupon::isExpired() const {
    return false;
}

void Coupon::print() const {
    cout << "Coupon ID: " << couponId_ << endl;
    cout << "Code: " << couponCode_ << endl;
    cout << "Discount Value: $" << fixed << setprecision(2) << discountValue_ << endl;
    cout << "Discount Type: " << discountType_ << endl;
    cout << "Expiry Date: " << expiryDate_ << endl;
    cout << "Used: " << (isUsed_ ? "Yes" : "No") << endl;
    cout << "Expired: " << (isExpired() ? "Yes" : "No") << endl;
}


