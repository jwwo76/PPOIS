#pragma once
#include "../pch.h"

class Customer;
class OrderItem;
class Restaurant;

class Cart{
    private:
        int cartId_;
        Customer* customer_;
        Restaurant* restaurant_;
        vector<OrderItem*> items_;
        double totalAmount_;
    public:
        Cart(int cartId, Customer* customer);
        ~Cart();

        int getCartId() const { return cartId_; }
        Customer* getCustomer() const { return customer_; }
        vector<OrderItem*> getItems() const { return items_; }
        double getTotalAmount() const { return totalAmount_; }

        void setRestaurant(Restaurant* restaurant);
        void addItem(OrderItem* item);
        void removeItem(OrderItem* item);
        void clearCart();
        void calculateTotal();

        void print() const;
};


