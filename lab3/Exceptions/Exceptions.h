#pragma once
#include "../pch.h"

class Exceptions {
public:
    // Существующие исключения (14)
    static void throwInvalidArgument(const string& message);
    static void throwInvalidPayment(const string& message);
    static void throwCapacityExceeded(const string& message);
    static void throwOrderNotFound(const string& message);
    static void throwVehicleUnavailable(const string& message);
    static void throwClientNotFound(const string& message);
    static void throwDriverNotFound(const string& message);
    static void throwRouteNotFound(const string& message);
    static void throwHubFull(const string& message);
    static void throwPaymentFailed(const string& message);
    static void throwInvalidCard(const string& message);
    static void throwInsufficientFunds(const string& message);
    static void throwDuplicateOrder(const string& message);
    static void throwInvalidWeight(const string& message);

    // Rating validation methods
    static void validateRating1to5(int rating, const string& context = "рейтинг");
    static void validateRating1to10(int rating, const string& context = "рейтинг");
};


