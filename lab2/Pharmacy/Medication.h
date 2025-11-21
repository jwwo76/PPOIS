#pragma once
#include "../pch.h"

class Medication {
private:
    string name_;
    string genericName_;
    string manufacturer_;
    int quantity_;
    double price_;
    string expiryDate_;
    string prescriptionRequired_;

public:
    Medication(const string& name, const string& genericName, const string& manufacturer,
              int quantity, double price, const string& expiryDate, const string& prescriptionRequired = "Yes");
    
    string getName() const { return name_; }
    int getQuantity() const { return quantity_; }
    double getPrice() const { return price_; }
    string getExpiryDate() const { return expiryDate_; }

    void setQuantity(int quantity) { if(quantity >= 0) quantity_ = quantity; }
    void setPrice(double price) { if(price >= 0) price_ = price; }

    void dispense(int amount);
    void restock(int amount);
    bool isExpired() const;
    void print() const;
};



