#include "Cart.h"
#include "../Persons/Customer.h"
#include "OrderItem.h"
#include "../Restaurants/Restaurant.h"
#include "../Exceptions/Exceptions.h"

Cart::Cart(int cartId, Customer* customer)
    : cartId_(cartId), customer_(customer), restaurant_(nullptr), totalAmount_(0.0) {
    if (cartId <= 0) {
        Exceptions::throwInvalidArgument("Cart ID должен быть положительным");
    }
    if (!customer) {
        Exceptions::throwClientNotFound("Клиент не может быть nullptr");
    }
}

Cart::~Cart() {
    customer_ = nullptr;
    restaurant_ = nullptr;
}

void Cart::setRestaurant(Restaurant* restaurant) {
    restaurant_ = restaurant;
}

void Cart::addItem(OrderItem* item) {
    if (!item) {
        Exceptions::throwInvalidArgument("OrderItem не может быть nullptr");
    }
    items_.push_back(item);
    calculateTotal();
}

void Cart::removeItem(OrderItem* item) {
    items_.erase(remove(items_.begin(), items_.end(), item), items_.end());
    calculateTotal();
}

void Cart::clearCart() {
    items_.clear();
    totalAmount_ = 0.0;
}

void Cart::calculateTotal() {
    totalAmount_ = 0.0;
    for (auto item : items_) {
        if (item) {
            totalAmount_ += item->getSubtotal();
        }
    }
}

void Cart::print() const {
    cout << "Cart ID: " << cartId_ << endl;
    cout << "Items: " << items_.size() << endl;
    cout << "Total Amount: $" << fixed << setprecision(2) << totalAmount_ << endl;
}


