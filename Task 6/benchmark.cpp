#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

inline int inlineCalculation(int value) {
    return value * 3 + 1;
}

__attribute__((noinline))
int normalCalculation(int value) {
    return value * 3 + 1;
}

int main() {
    const int iterations = 10000000;
    volatile int input = 5;
    long long inlineSum = 0;
    long long normalSum = 0;

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++) {
        inlineSum += inlineCalculation(input);
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < iterations; i++) {
        normalSum += normalCalculation(input);
    }

    auto end2 = high_resolution_clock::now();

    auto inlineTime = duration_cast<microseconds>(end1 - start1).count();
    auto normalTime = duration_cast<microseconds>(end2 - start2).count();

    cout << "FUNCTION PERFORMANCE COMPARISON" << endl;
    cout << "Iterations: " << iterations << endl;
    cout << "Inline Function Time: " << inlineTime << " microseconds" << endl;
    cout << "Non-Inline Function Time: " << normalTime << " microseconds" << endl;
    cout << "Inline Result: " << inlineSum << endl;
    cout << "Non-Inline Result: " << normalSum << endl;

    return 0;
}