#include "Payment.h"
#include "../Orders/Order.h"
#include "../Persons/Customer.h"
#include "PaymentMethod.h"
#include "../Exceptions/Exceptions.h"

Payment::Payment(int paymentId, Order* order, double amount)
    : paymentId_(paymentId), order_(order), amount_(amount), status_("Pending") {
    if (paymentId <= 0) {
        Exceptions::throwInvalidArgument("Payment ID должен быть положительным");
    }
    if (!order) {
        Exceptions::throwOrderNotFound("Заказ не может быть nullptr");
    }
    if (amount <= 0) {
        Exceptions::throwInvalidPayment("Сумма оплаты должна быть положительной");
    }
}

Payment::~Payment() {
    order_ = nullptr;
}

void Payment::processPayment() {
    if (amount_ <= 0) {
        Exceptions::throwInvalidPayment("Сумма оплаты должна быть положительной");
    }
    status_ = "Completed";
    cout << "Payment processed: $" << fixed << setprecision(2) << amount_ << endl;
}

void Payment::print() const {
    cout << "Payment ID: " << paymentId_ << endl;
    cout << "Amount: $" << fixed << setprecision(2) << amount_ << endl;
    cout << "Status: " << status_ << endl;
}


