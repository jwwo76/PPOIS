#include "Order.h"
#include "../Persons/Customer.h"
#include "../Restaurants/Restaurant.h"
#include "OrderItem.h"
#include "../Delivery/Delivery.h"
#include "../Payments/Payment.h"
#include "../Exceptions/Exceptions.h"

Order::Order(int orderId, Customer* customer, Restaurant* restaurant)
    : orderId_(orderId), customer_(customer), restaurant_(restaurant), totalAmount_(0.0), status_("Pending") {
    if (orderId <= 0) {
        Exceptions::throwInvalidArgument("Order ID должен быть положительным");
    }
    if (!customer) {
        Exceptions::throwClientNotFound("Клиент не может быть nullptr");
    }
    if (!restaurant) {
        Exceptions::throwInvalidArgument("Ресторан не может быть nullptr");
    }
}

Order::~Order() {
    customer_ = nullptr;
    restaurant_ = nullptr;
}

void Order::addItem(OrderItem* item) {
    if (!item) {
        Exceptions::throwInvalidArgument("OrderItem не может быть nullptr");
    }
    items_.push_back(item);
    calculateTotal();
}

void Order::removeItem(OrderItem* item) {
    items_.erase(remove(items_.begin(), items_.end(), item), items_.end());
    calculateTotal();
}

void Order::calculateTotal() {
    totalAmount_ = 0.0;
    for (auto item : items_) {
        if (item) {
            totalAmount_ += item->getSubtotal();
        }
    }
}

void Order::print() const {
    cout << "Order ID: " << orderId_ << endl;
    cout << "Status: " << status_ << endl;
    cout << "Total Amount: $" << fixed << setprecision(2) << totalAmount_ << endl;
    cout << "Items: " << items_.size() << endl;
}


