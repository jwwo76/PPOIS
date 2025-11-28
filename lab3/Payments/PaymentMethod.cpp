#include "PaymentMethod.h"
#include "../Exceptions/Exceptions.h"

PaymentMethod::PaymentMethod(int methodId, const string& methodType, const string& cardNumber, const string& cardHolderName, const string& expiryDate)
    : methodId_(methodId), methodType_(methodType), cardNumber_(cardNumber), cardHolderName_(cardHolderName), expiryDate_(expiryDate), isActive_(true) {
    if (methodId <= 0) {
        Exceptions::throwInvalidArgument("Payment Method ID должен быть положительным");
    }
    if (methodType.empty()) {
        Exceptions::throwInvalidPayment("Тип метода оплаты не может быть пустым");
    }
    if (cardNumber.empty() && methodType == "Credit Card") {
        Exceptions::throwInvalidCard("Номер карты не может быть пустым");
    }
}

void PaymentMethod::print() const {
    cout << "Payment Method ID: " << methodId_ << endl;
    cout << "Type: " << methodType_ << endl;
    cout << "Card Holder: " << cardHolderName_ << endl;
    cout << "Expiry Date: " << expiryDate_ << endl;
    cout << "Active: " << (isActive_ ? "Yes" : "No") << endl;
}


