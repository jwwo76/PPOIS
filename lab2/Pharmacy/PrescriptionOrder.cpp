#include "PrescriptionOrder.h"

PrescriptionOrder::PrescriptionOrder(Prescription* prescription, Patient* patient, Doctor* doctor,
                                    const string& orderDate, double totalCost, int orderId)
    : orderId_(orderId), prescription_(prescription), patient_(patient), doctor_(doctor),
      orderDate_(orderDate), status_("Pending"), totalCost_(totalCost) {}

void PrescriptionOrder::processOrder() {
    status_ = "Processing";
    cout << "Prescription order #" << orderId_ << " is being processed" << endl;
}

void PrescriptionOrder::fulfillOrder() {
    status_ = "Fulfilled";
    if (prescription_) {
        prescription_->fillPrescription();
    }
    cout << "Prescription order #" << orderId_ << " fulfilled" << endl;
}

void PrescriptionOrder::print() const {
    cout << "=== Prescription Order #" << orderId_ << " ===" << endl;
    if (patient_ && doctor_) {
        cout << "Patient: " << patient_->getFirstName() << " " << patient_->getSurname() << endl;
        cout << "Doctor: " << doctor_->getFirstName() << " " << doctor_->getSurname() << endl;
    }
    cout << "Order Date: " << orderDate_ << endl;
    cout << "Status: " << status_ << endl;
    cout << "Total Cost: $" << totalCost_ << endl;
    if (prescription_) {
        cout << "Prescription ID: " << prescription_->getPrescriptionId() << endl;
    }
}

