#include "Address.h"

Address::Address(int addressId, const string& street, const string& city)
    : addressId_(addressId), street_(street), city_(city) {}

void Address::print() const {
    cout << street_ << ", " << city_ << endl;
}


