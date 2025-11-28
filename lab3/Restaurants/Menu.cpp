#include "Menu.h"
#include "MenuItem.h"
#include "Category.h"

Menu::Menu(int menuId, const string& name)
    : menuId_(menuId), name_(name) {}

Menu::~Menu() {
    items_.clear();
}

void Menu::addItem(MenuItem* item) {
    if (item) {
        items_.push_back(item);
    }
}

void Menu::print() const {
    cout << "Menu ID: " << menuId_ << endl;
    cout << "Name: " << name_ << endl;
    cout << "Items: " << items_.size() << endl;
}


