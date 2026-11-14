#include <iostream>
#include <string>
using namespace std;

struct Parcel {
    double weight;
};

double calculateCharge(double weight, bool express = false, bool insured = false) {
    double amount = weight * 50;

    if (express) {
        amount += 100;
    }

    if (insured) {
        amount += 50;
    }

    return amount;
}

void charge(int weightInGrams, bool express = false, bool insured = false) {
    cout << "Integer overload (grams): "
         << calculateCharge(weightInGrams / 1000.0, express, insured)
         << endl;
}

void charge(double weightInKg, bool express = false, bool insured = false) {
    cout << "Double overload (kg): "
         << calculateCharge(weightInKg, express, insured)
         << endl;
}

void charge(const Parcel& parcel, bool express = false, bool insured = false) {
    cout << "Parcel overload: "
         << calculateCharge(parcel.weight, express, insured)
         << endl;
}

int main() {
    Parcel parcel = {3.5};

    cout << "Courier Charge Calculator" << endl;

    charge(2);
    charge(2.0f);
    charge(2.0);
    charge(500, true);
    charge(1.5, false, true);
    charge(parcel);

    return 0;
}