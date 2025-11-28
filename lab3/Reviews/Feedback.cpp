#include "Feedback.h"
#include "../Persons/Customer.h"
#include "../Orders/Order.h"

Feedback::Feedback(int feedbackId, Customer* customer, Order* order, const string& feedbackType, const string& message, const string& feedbackDate)
    : feedbackId_(feedbackId), customer_(customer), order_(order), feedbackType_(feedbackType), message_(message), feedbackDate_(feedbackDate), isResolved_(false) {}

Feedback::~Feedback() {
    customer_ = nullptr;
    order_ = nullptr;
}

void Feedback::print() const {
    cout << "Feedback ID: " << feedbackId_ << endl;
    cout << "Type: " << feedbackType_ << endl;
    cout << "Message: " << message_ << endl;
    cout << "Date: " << feedbackDate_ << endl;
    cout << "Resolved: " << (isResolved_ ? "Yes" : "No") << endl;
}


