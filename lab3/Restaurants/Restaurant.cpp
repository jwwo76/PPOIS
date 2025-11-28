#include "Restaurant.h"
#include "../Persons/RestaurantOwner.h"
#include "../Restaurants/Menu.h"
#include "../Locations/Address.h"
#include "../Orders/Order.h"
#include "../Persons/Employee.h"
#include "../Exceptions/Exceptions.h"

Restaurant::Restaurant(int restaurantId, const string& name, RestaurantOwner* owner)
    : restaurantId_(restaurantId), name_(name), owner_(owner), isOpen_(false) {
    if (restaurantId <= 0) {
        Exceptions::throwInvalidArgument("Restaurant ID должен быть положительным");
    }
    if (name.empty()) {
        Exceptions::throwInvalidArgument("Название ресторана не может быть пустым");
    }
    if (!owner) {
        Exceptions::throwInvalidArgument("Владелец ресторана не может быть nullptr");
    }
}

Restaurant::~Restaurant() {
    owner_ = nullptr;
    menu_ = nullptr;
}

void Restaurant::setMenu(Menu* menu) {
    menu_ = menu;
}

void Restaurant::addOrder(Order* order) {
    if (!order) {
        Exceptions::throwOrderNotFound("Заказ не может быть nullptr");
    }
    orders_.push_back(order);
}

void Restaurant::print() const {
    cout << "Restaurant ID: " << restaurantId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Status: " << (isOpen_ ? "Open" : "Closed") << endl;
    cout << "Total orders: " << orders_.size() << endl;
}


