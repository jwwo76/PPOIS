#pragma once
#include "../pch.h"

class MenuItem;

class OrderItem{
    private:
        int orderItemId_;
        MenuItem* menuItem_;
        int quantity_;
        double price_;
        double subtotal_;
        string specialInstructions_;
    public:
        OrderItem(int orderItemId, MenuItem* menuItem, int quantity, const string& specialInstructions);
        ~OrderItem();

        int getOrderItemId() const { return orderItemId_; }
        MenuItem* getMenuItem() const { return menuItem_; }
        int getQuantity() const { return quantity_; }
        double getSubtotal() const { return subtotal_; }

        void setQuantity(int quantity);
        void calculateSubtotal();

        void print() const;
};


