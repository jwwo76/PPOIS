#include "Category.h"
#include "MenuItem.h"

Category::Category(int categoryId, const string& name, const string& description)
    : categoryId_(categoryId), name_(name), description_(description) {}

Category::~Category() {
    items_.clear();
}

void Category::addItem(MenuItem* item) {
    if (item) {
        items_.push_back(item);
    }
}

void Category::removeItem(MenuItem* item) {
    items_.erase(remove(items_.begin(), items_.end(), item), items_.end());
}

void Category::print() const {
    cout << "Category ID: " << categoryId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Items: " << items_.size() << endl;
}


