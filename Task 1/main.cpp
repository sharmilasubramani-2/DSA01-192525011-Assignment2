#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
    cout << "Fee inside call by value: " << fee << endl;
}

void applyByReference(long long &fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByPointer(long long *fee, int percent) {
    *fee -= *fee * percent / 100;
}

void change(int a, int &b, int *c) {
    a += 10;
    b += 10;
    *c += 10;
    (void)a;
}

int &bigger(int &p, int &q) {
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << ' ';
}

void applyConcession(long long &fee, int percent) {
    fee -= fee * percent / 100;
}

int main() {
    cout << "HOSTEL FEE CONCESSION" << endl;

    long long valueFee = 45000;
    long long referenceFee = 45000;
    long long pointerFee = 45000;

    cout << "Initial Fee: 45000" << endl;

    applyByValue(valueFee, 10);
    cout << "Stored Fee after Call by Value: " << valueFee << endl;

    applyByReference(referenceFee, 15);
    cout << "Stored Fee after Call by Reference: " << referenceFee << endl;

    applyByPointer(&pointerFee, 25);
    cout << "Stored Fee after Call by Pointer: " << pointerFee << endl;

    cout << "\nPREDICT THE OUTPUT" << endl;

    int a = 1, b = 2, c = 3;

    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';

    cout << "\nCOMPLETE THE CODE" << endl;

    long long hostelFee = 45000;

    applyByValue(hostelFee, 10);
    cout << "after call by value : " << hostelFee << '\n';

    applyConcession(hostelFee, 10);
    cout << "after call by reference: " << hostelFee << '\n';

    return 0;
}