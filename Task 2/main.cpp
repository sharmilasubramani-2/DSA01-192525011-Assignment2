#include <iostream>
#include <vector>
using namespace std;

int& highestMark(int marks[], int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return marks[highest];
}

const int& highestMarkConst(const int marks[], int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return marks[highest];
}

int highestMarkCopy(const int marks[], int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return marks[highest];
}

int highestIndex(const int marks[], int size) {
    int highest = 0;

    for (int i = 1; i < size; i++) {
        if (marks[i] > marks[highest]) {
            highest = i;
        }
    }

    return highest;
}

int* highestMarkPointer(int marks[], int size) {
    int highest = highestIndex(marks, size);
    return &marks[highest];
}

void displayMarks(const int marks[], int size) {
    for (int i = 0; i < size; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

int main() {
    int marks[] = {78, 91, 84, 91, 67};
    int size = 5;

    cout << "Original Marks: ";
    displayMarks(marks, size);

    highestMark(marks, size) += 2;

    cout << "Marks After Moderation: ";
    displayMarks(marks, size);

    cout << "Highest Mark through Const Reference: "
         << highestMarkConst(marks, size) << endl;

    cout << "Highest Mark through Copy: "
         << highestMarkCopy(marks, size) << endl;

    int index = highestIndex(marks, size);

    cout << "Highest Index: " << index << endl;

    int* pointer = highestMarkPointer(marks, size);

    cout << "Highest Mark through Pointer: "
         << *pointer << endl;

    vector<int> growingMarks = {78, 91};
    growingMarks.reserve(2);

    int& savedReference = growingMarks[0];

    cout << "Reference Before Vector Growth: "
         << savedReference << endl;

    size_t oldCapacity = growingMarks.capacity();

    growingMarks.push_back(84);

    cout << "Vector Reallocation Occurred: "
         << boolalpha
         << (growingMarks.capacity() > oldCapacity)
         << endl;

    return 0;
}