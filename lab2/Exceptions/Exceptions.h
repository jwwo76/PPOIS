#pragma once
#include "../pch.h"

class Exceptions {
public:
    static void throwInvalidArgument(const string& message);
    static void throwInvalidPayment(const string& message);
    static void throwCapacityExceeded(const string& message);
    static void throwAppointmentNotFound(const string& message);
    static void throwPatientNotFound(const string& message);
    static void throwDoctorNotFound(const string& message);
    static void throwDepartmentNotFound(const string& message);
    static void throwEquipmentUnavailable(const string& message);
    static void throwInsufficientFunds(const string& message);
    static void throwInvalidPrescription(const string& message);
    static void throwRoomUnavailable(const string& message);
    static void throwInvalidOperation(const string& message);
};

