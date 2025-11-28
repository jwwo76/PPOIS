#include "Complaint.h"
#include "../Persons/Customer.h"
#include "../Orders/Order.h"

Complaint::Complaint(int complaintId, Customer* customer, Order* order, const string& complaintType, const string& description, const string& complaintDate)
    : complaintId_(complaintId), customer_(customer), order_(order), complaintType_(complaintType), description_(description), complaintDate_(complaintDate), status_("Open") {}

Complaint::~Complaint() {
    customer_ = nullptr;
    order_ = nullptr;
}

void Complaint::resolve(const string& resolution) {
    status_ = "Resolved";
    resolution_ = resolution;
}

void Complaint::print() const {
    cout << "Complaint ID: " << complaintId_ << endl;
    cout << "Type: " << complaintType_ << endl;
    cout << "Description: " << description_ << endl;
    cout << "Date: " << complaintDate_ << endl;
    cout << "Status: " << status_ << endl;
    if (!resolution_.empty()) {
        cout << "Resolution: " << resolution_ << endl;
    }
}


