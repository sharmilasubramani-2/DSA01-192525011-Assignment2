#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

int minutesBetween(const Time& a, const Time& b) {
    int first = a.h * 60 + a.m;
    int second = b.h * 60 + b.m;
    return abs(first - second);
}

bool earlier(const Time& a, const Time& b) {
    return a.h * 60 + a.m < b.h * 60 + b.m;
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);
    Time morning(8, 30);
    Time afternoon(14, 15);
    Time sameTime1(11, 30);
    Time sameTime2(11, 30);

    cout << "TRAIN JOURNEY TIME PLANNER" << endl;

    cout << "Minutes Between Departure and Arrival: "
         << minutesBetween(departure, arrival) << endl;

    cout << "Is Arrival Earlier Than Departure: "
         << boolalpha << earlier(arrival, departure) << endl;

    cout << "Minutes Between Morning and Afternoon: "
         << minutesBetween(morning, afternoon) << endl;

    cout << "Is Morning Earlier Than Afternoon: "
         << earlier(morning, afternoon) << endl;

    cout << "Minutes Between Same Times: "
         << minutesBetween(sameTime1, sameTime2) << endl;

    cout << "Is First Same Time Earlier: "
         << earlier(sameTime1, sameTime2) << endl;

    return 0;
}