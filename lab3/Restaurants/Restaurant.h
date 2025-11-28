#pragma once
#include "../pch.h"

class RestaurantOwner;
class Menu;
class Address;
class Order;
class Employee;

class Restaurant{
    private:
        int restaurantId_;
        string name_;
        RestaurantOwner* owner_;
        Menu* menu_;
        vector<Order*> orders_;
        bool isOpen_;
    public:
        Restaurant(int restaurantId, const string& name, RestaurantOwner* owner);
        ~Restaurant();

        int getRestaurantId() const { return restaurantId_; }
        string getName() const { return name_; }
        RestaurantOwner* getOwner() const { return owner_; }
        Menu* getMenu() const { return menu_; }
        vector<Order*> getOrders() const { return orders_; }
        bool getIsOpen() const { return isOpen_; }

        void setMenu(Menu* menu);
        void setIsOpen(bool open) { isOpen_ = open; }
        void addOrder(Order* order);

        void print() const;
};


