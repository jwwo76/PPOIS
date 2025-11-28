#include "Exceptions.h"
#include <stdexcept>

// Существующие исключения (14)

void Exceptions::throwInvalidArgument(const string& message) {
    throw invalid_argument("Недопустимый аргумент: " + message);
}

void Exceptions::throwInvalidPayment(const string& message) {
    throw runtime_error("Недопустимый метод оплаты: " + message);
}

void Exceptions::throwCapacityExceeded(const string& message) {
    throw runtime_error("Пропускная способность превышена: " + message);
}

void Exceptions::throwOrderNotFound(const string& message) {
    throw runtime_error("Заказ не найден: " + message);
}

void Exceptions::throwVehicleUnavailable(const string& message) {
    throw runtime_error("Транспорт недоступен: " + message);
}

void Exceptions::throwClientNotFound(const string& message) {
    throw runtime_error("Клиент не найден: " + message);
}

void Exceptions::throwDriverNotFound(const string& message) {
    throw runtime_error("Водитель не найден: " + message);
}

void Exceptions::throwRouteNotFound(const string& message) {
    throw runtime_error("Маршрут не найден: " + message);
}

void Exceptions::throwHubFull(const string& message) {
    throw runtime_error("Хаб переполнен: " + message);
}

void Exceptions::throwPaymentFailed(const string& message) {
    throw runtime_error("Оплата не удалась: " + message);
}

void Exceptions::throwInvalidCard(const string& message) {
    throw invalid_argument("Некорректная карта: " + message);
}

void Exceptions::throwInsufficientFunds(const string& message) {
    throw runtime_error("Недостаточно средств: " + message);
}

void Exceptions::throwDuplicateOrder(const string& message) {
    throw runtime_error("Дубликат заказа: " + message);
}

void Exceptions::throwInvalidWeight(const string& message) {
    throw invalid_argument("Недопустимый вес груза: " + message);
}

// Rating validation methods
void Exceptions::validateRating1to5(int rating, const string& context) {
    if (rating < 1 || rating > 5) {
        throwInvalidArgument(context + " должен быть от 1 до 5");
    }
}

void Exceptions::validateRating1to10(int rating, const string& context) {
    if (rating < 1 || rating > 10) {
        throwInvalidArgument(context + " должен быть от 1 до 10");
    }
}


