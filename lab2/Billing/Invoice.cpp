#include "Invoice.h"

Invoice::Invoice(Patient* patient, const string& issueDate, const string& dueDate, double amount, int invoiceId)
    : invoiceId_(invoiceId), patient_(patient), issueDate_(issueDate), dueDate_(dueDate),
      amount_(amount), status_("Pending"), paymentMethod_("") {}

void Invoice::markAsPaid(const string& paymentMethod) {
    status_ = "Paid";
    paymentMethod_ = paymentMethod;
    cout << "Invoice #" << invoiceId_ << " marked as paid via " << paymentMethod_ << endl;
}

void Invoice::markAsOverdue() {
    status_ = "Overdue";
    cout << "Invoice #" << invoiceId_ << " marked as overdue" << endl;
}

bool Invoice::isOverdue() const {
    return status_ == "Overdue";
}

void Invoice::print() const {
    cout << "=== Invoice #" << invoiceId_ << " ===" << endl;
    if (patient_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
    }
    cout << "Issue Date: " << issueDate_ << endl;
    cout << "Due Date: " << dueDate_ << endl;
    cout << "Amount: $" << amount_ << endl;
    cout << "Status: " << status_ << endl;
    if (!paymentMethod_.empty())
        cout << "Payment Method: " << paymentMethod_ << endl;
}

