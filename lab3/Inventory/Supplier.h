#pragma once
#include "../pch.h"

class Address;
class Ingredient;

class Supplier{
    private:
        int supplierId_;
        string name_;
        string contactPerson_;
        string phoneNumber_;
        string email_;
        Address* address_;
        vector<Ingredient*> ingredients_;
    public:
        Supplier(int supplierId, const string& name, const string& contactPerson, const string& phoneNumber, const string& email, Address* address);
        ~Supplier();

        int getSupplierId() const { return supplierId_; }
        string getName() const { return name_; }
        string getContactPerson() const { return contactPerson_; }
        string getPhoneNumber() const { return phoneNumber_; }
        vector<Ingredient*> getIngredients() const { return ingredients_; }

        void addIngredient(Ingredient* ingredient);
        void removeIngredient(Ingredient* ingredient);

        void print() const;
};


