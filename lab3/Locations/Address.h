#pragma once
#include "../pch.h"

class Address{
    private:
        int addressId_;
        string street_;
        string city_;
    public:
        Address(int addressId, const string& street, const string& city);

        int getAddressId() const { return addressId_; }
        string getStreet() const { return street_; }
        string getCity() const { return city_; }

        void print() const;
};


