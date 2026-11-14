#include <iostream>
using namespace std;

void callByValue(int x) {
    x += 10;
    cout << "Inside Call by Value: " << x << endl;
}

void callByReference(int &x) {
    x += 10;
    cout << "Inside Call by Reference: " << x << endl;
}

void callByPointer(int *x) {
    *x += 10;
    cout << "Inside Call by Pointer: " << *x << endl;
}

int main() {
    int a = 10;
    int b = 10;
    int c = 10;

    cout << "Initial Values:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "\nFunction Execution:" << endl;

    callByValue(a);
    callByReference(b);
    callByPointer(&c);

    cout << "\nValues After Function Calls:" << endl;
    cout << "Call by Value: " << a << endl;
    cout << "Call by Reference: " << b << endl;
    cout << "Call by Pointer: " << c << endl;

    return 0;
}