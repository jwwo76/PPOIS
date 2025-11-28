#include "DeliveryTime.h"
#include "Delivery.h"

DeliveryTime::DeliveryTime(int timeId, Delivery* delivery, const string& estimatedTime, int estimatedMinutes)
    : timeId_(timeId), delivery_(delivery), estimatedTime_(estimatedTime), estimatedMinutes_(estimatedMinutes), actualTime_(""), actualMinutes_(0) {}

DeliveryTime::~DeliveryTime() {
    delivery_ = nullptr;
}

int DeliveryTime::calculateDelay() const {
    if (actualMinutes_ > estimatedMinutes_) {
        return actualMinutes_ - estimatedMinutes_;
    }
    return 0;
}

void DeliveryTime::print() const {
    cout << "Time ID: " << timeId_ << endl;
    cout << "Estimated Time: " << estimatedTime_ << " (" << estimatedMinutes_ << " minutes)" << endl;
    if (!actualTime_.empty()) {
        cout << "Actual Time: " << actualTime_ << " (" << actualMinutes_ << " minutes)" << endl;
    }
}


