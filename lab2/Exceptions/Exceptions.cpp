#include "Exceptions.h"

void Exceptions::throwInvalidArgument(const string& message) {
    throw invalid_argument("Invalid argument: " + message);
}

void Exceptions::throwInvalidPayment(const string& message) {
    throw runtime_error("Invalid payment method: " + message);
}

void Exceptions::throwCapacityExceeded(const string& message) {
    throw runtime_error("Capacity exceeded: " + message);
}

void Exceptions::throwAppointmentNotFound(const string& message) {
    throw runtime_error("Appointment not found: " + message);
}

void Exceptions::throwPatientNotFound(const string& message) {
    throw runtime_error("Patient not found: " + message);
}

void Exceptions::throwDoctorNotFound(const string& message) {
    throw runtime_error("Doctor not found: " + message);
}

void Exceptions::throwDepartmentNotFound(const string& message) {
    throw runtime_error("Department not found: " + message);
}

void Exceptions::throwEquipmentUnavailable(const string& message) {
    throw runtime_error("Equipment unavailable: " + message);
}

void Exceptions::throwInsufficientFunds(const string& message) {
    throw runtime_error("Insufficient funds: " + message);
}

void Exceptions::throwInvalidPrescription(const string& message) {
    throw runtime_error("Invalid prescription: " + message);
}

void Exceptions::throwRoomUnavailable(const string& message) {
    throw runtime_error("Room unavailable: " + message);
}

void Exceptions::throwInvalidOperation(const string& message) {
    throw runtime_error("Invalid operation: " + message);
}
