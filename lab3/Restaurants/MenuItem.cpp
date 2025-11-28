#include "MenuItem.h"
#include "Category.h"
#include "../Exceptions/Exceptions.h"

MenuItem::MenuItem(int itemId, const string& name, double price, Category* category)
    : itemId_(itemId), name_(name), price_(price), category_(category) {
    if (itemId <= 0) {
        Exceptions::throwInvalidArgument("Item ID должен быть положительным");
    }
    if (name.empty()) {
        Exceptions::throwInvalidArgument("Название позиции не может быть пустым");
    }
    if (price < 0) {
        Exceptions::throwInvalidArgument("Цена не может быть отрицательной");
    }
}

MenuItem::~MenuItem() {
    category_ = nullptr;
}

void MenuItem::setPrice(double price) {
    if (price < 0) {
        Exceptions::throwInvalidArgument("Цена не может быть отрицательной");
    }
    price_ = price;
}

void MenuItem::print() const {
    cout << "Item ID: " << itemId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Price: $" << fixed << setprecision(2) << price_ << endl;
}


