#pragma once
#include "../pch.h"

class Restaurant;
class Address;

class Branch{
    private:
        int branchId_;
        Restaurant* restaurant_;
        Address* address_;
        string phoneNumber_;
        bool isOpen_;
        int capacity_;
    public:
        Branch(int branchId, Restaurant* restaurant, Address* address, const string& phoneNumber, int capacity);
        ~Branch();

        int getBranchId() const { return branchId_; }
        Restaurant* getRestaurant() const { return restaurant_; }
        bool getIsOpen() const { return isOpen_; }
        int getCapacity() const { return capacity_; }

        void setIsOpen(bool open) { isOpen_ = open; }
        void setCapacity(int capacity) { capacity_ = capacity; }

        void print() const;
};


