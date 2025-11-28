#include "Delivery.h"
#include "../Orders/Order.h"
#include "../Persons/DeliveryPerson.h"
#include "../Locations/Address.h"
#include "Vehicle.h"
#include "../Exceptions/Exceptions.h"

Delivery::Delivery(int deliveryId, Order* order, DeliveryPerson* deliveryPerson, Address* deliveryAddress, double deliveryFee)
    : deliveryId_(deliveryId), order_(order), deliveryPerson_(deliveryPerson), deliveryAddress_(deliveryAddress), vehicle_(nullptr), status_("Pending"), deliveryFee_(deliveryFee) {
    if (deliveryId <= 0) {
        Exceptions::throwInvalidArgument("Delivery ID должен быть положительным");
    }
    if (!order) {
        Exceptions::throwOrderNotFound("Заказ не может быть nullptr");
    }
    if (!deliveryPerson) {
        Exceptions::throwDriverNotFound("Курьер не может быть nullptr");
    }
    if (deliveryFee < 0) {
        Exceptions::throwInvalidArgument("Стоимость доставки не может быть отрицательной");
    }
}

Delivery::~Delivery() {
    order_ = nullptr;
    deliveryPerson_ = nullptr;
    deliveryAddress_ = nullptr;
    vehicle_ = nullptr;
}

void Delivery::completeDelivery() {
    status_ = "Completed";
}

void Delivery::print() const {
    cout << "Delivery ID: " << deliveryId_ << endl;
    cout << "Status: " << status_ << endl;
    cout << "Delivery Fee: $" << fixed << setprecision(2) << deliveryFee_ << endl;
}


