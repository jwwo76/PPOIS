#include "Customer.h"
#include "../Locations/Address.h"
#include "../Orders/Order.h"
#include "../Exceptions/Exceptions.h"

Customer::Customer(const string& firstName, int age, int customerId, const string& email)
    : Person(firstName, age), customerId_(customerId), email_(email) {
    if (customerId <= 0) {
        Exceptions::throwInvalidArgument("Customer ID должен быть положительным");
    }
    if (email.empty()) {
        Exceptions::throwInvalidArgument("Email адрес не может быть пустым");
    }
    size_t atPos = email.find('@');
    if (atPos == string::npos || atPos == 0 || atPos == email.length() - 1) {
        Exceptions::throwInvalidArgument("Некорректный email адрес - должен содержать '@' не в начале или конце");
    }
    size_t dotPos = email.find('.', atPos);
    if (dotPos == string::npos || dotPos == email.length() - 1) {
        Exceptions::throwInvalidArgument("Некорректный email адрес - должен содержать домен после '@'");
    }
}

Customer::~Customer() {
}

void Customer::addOrder(Order* order) {
    if (order) {
        orders_.push_back(order);
    }
}

void Customer::print() const {
    Person::print();
    cout << "Customer ID: " << customerId_ << endl;
    cout << "Email: " << email_ << endl;
    cout << "Total orders: " << orders_.size() << endl;
}


