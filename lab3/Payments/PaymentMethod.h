#pragma once
#include "../pch.h"

class PaymentMethod{
    private:
        int methodId_;
        string methodType_;
        string cardNumber_;
        string cardHolderName_;
        string expiryDate_;
        bool isActive_;
    public:
        PaymentMethod(int methodId, const string& methodType, const string& cardNumber, const string& cardHolderName, const string& expiryDate);

        int getMethodId() const { return methodId_; }
        string getMethodType() const { return methodType_; }
        bool getIsActive() const { return isActive_; }

        void setIsActive(bool active) { isActive_ = active; }
        bool isValid() const;

        void print() const;
};


