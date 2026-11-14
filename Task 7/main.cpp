#include <iostream>
#include <memory>
#include <chrono>
using namespace std;
using namespace chrono;

struct Transaction {
    int id;
    double amount;
};

class FixedHistory {
    static const int CAPACITY = 10;
    Transaction transactions[CAPACITY];
    int count = 0;
    int next = 0;

public:
    void add(Transaction transaction) {
        transactions[next] = transaction;
        next = (next + 1) % CAPACITY;

        if (count < CAPACITY) {
            count++;
        }
    }

    int size() const {
        return count;
    }

    Transaction oldest() const {
        return transactions[count == CAPACITY ? next : 0];
    }

    Transaction newest() const {
        return transactions[(next - 1 + CAPACITY) % CAPACITY];
    }
};

class DynamicHistory {
    unique_ptr<Transaction[]> transactions;
    int capacity;
    int count = 0;
    int next = 0;

    void resize() {
        int newCapacity = capacity * 2;
        unique_ptr<Transaction[]> newTransactions(
            new Transaction[newCapacity]
        );

        for (int i = 0; i < count; i++) {
            newTransactions[i] =
                transactions[(next - count + i + capacity) % capacity];
        }

        transactions = move(newTransactions);
        capacity = newCapacity;
        next = count;
    }

public:
    explicit DynamicHistory(int initialCapacity = 10)
        : transactions(new Transaction[initialCapacity]),
          capacity(initialCapacity) {}

    void add(Transaction transaction) {
        if (count == capacity) {
            resize();
        }

        transactions[next] = transaction;
        next = (next + 1) % capacity;
        count++;
    }

    int size() const {
        return count;
    }

    Transaction oldest() const {
        return transactions[(next - count + capacity) % capacity];
    }

    Transaction newest() const {
        return transactions[(next - 1 + capacity) % capacity];
    }

    int getCapacity() const {
        return capacity;
    }
};

int main() {
    const int TOTAL = 100000;

    FixedHistory original;
    DynamicHistory redesigned;

    auto start1 = high_resolution_clock::now();

    for (int i = 1; i <= TOTAL; i++) {
        original.add({i, i * 100.0});
    }

    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();

    for (int i = 1; i <= TOTAL; i++) {
        redesigned.add({i, i * 100.0});
    }

    auto end2 = high_resolution_clock::now();

    auto originalTime =
        duration_cast<microseconds>(end1 - start1).count();

    auto redesignedTime =
        duration_cast<microseconds>(end2 - start2).count();

    cout << "TRANSACTION HISTORY REDESIGN" << endl;
    cout << "Total Transactions Inserted: " << TOTAL << endl;

    cout << "\nORIGINAL FIXED CAPACITY DESIGN" << endl;
    cout << "Stored Transactions: " << original.size() << endl;
    cout << "Oldest Transaction ID: " << original.oldest().id << endl;
    cout << "Newest Transaction ID: " << original.newest().id << endl;
    cout << "Insertion Time: " << originalTime << " microseconds" << endl;

    cout << "\nREDESIGNED DYNAMIC CAPACITY" << endl;
    cout << "Stored Transactions: " << redesigned.size() << endl;
    cout << "Final Capacity: " << redesigned.getCapacity() << endl;
    cout << "Oldest Transaction ID: " << redesigned.oldest().id << endl;
    cout << "Newest Transaction ID: " << redesigned.newest().id << endl;
    cout << "Insertion Time: " << redesignedTime << " microseconds" << endl;

    cout << "\nVALIDATION" << endl;
    cout << "Original Retains Latest 10: "
         << boolalpha << (original.size() == 10) << endl;

    cout << "Redesigned Retains All Transactions: "
         << (redesigned.size() == TOTAL) << endl;

    cout << "Oldest Transaction Preserved: "
         << (redesigned.oldest().id == 1) << endl;

    cout << "Newest Transaction Correct: "
         << (redesigned.newest().id == TOTAL) << endl;

    return 0;
}