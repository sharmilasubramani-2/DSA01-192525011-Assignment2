# Task 7 – Diagnose, Redesign and Validate

## 1. Aim

To identify a limitation in the Savings Account Mini-Statement program from Task 4, redesign its transaction history management, and compare the original and redesigned implementations using the same test data.

## 2. Selected Program

Task 4 – Savings Account Mini-Statement.

The original implementation uses a fixed-capacity circular buffer to store the latest 10 transactions.

## 3. Diagnosis of the Limitation

The original transaction history has a fixed capacity of 10. When a new transaction is inserted after the buffer becomes full, the oldest transaction is overwritten.

This approach works for displaying recent transactions but cannot preserve complete transaction history as the number of transactions grows.

For example, after inserting 100,000 transactions, only the latest 10 transactions remain available.

## 4. Measurable Objective

Redesign the transaction history system to:

- Preserve all 100,000 inserted transactions.
- Maintain transactions in their original insertion order.
- Support efficient insertion using dynamic capacity.
- Validate the oldest and newest transaction records.

## 5. Redesigned Solution

A custom dynamically resizable circular buffer was implemented using a dynamic array and `unique_ptr`.

### Design Changes

- Introduced a `DynamicHistory` class.
- Added dynamic capacity management.
- Doubled the storage capacity whenever the buffer becomes full.
- Copied existing transactions into the new storage in chronological order.
- Used `unique_ptr` for automatic memory management.

### Pseudocode

```text
IF count equals capacity:
    Allocate a new array with double capacity
    Copy existing transactions in chronological order
    Replace the old storage
    Update capacity
    Set next insertion position

Insert the new transaction
Advance the insertion position
Increase transaction count
```

### C++ Features Used

- Classes and objects
- Dynamic memory management
- `unique_ptr`
- Circular buffer logic
- Encapsulation

## 6. Prediction Before Implementation

The redesigned solution was expected to preserve all inserted transactions instead of overwriting older records.

However, dynamic memory allocation and resizing could increase insertion time compared with the original fixed-capacity implementation.

## 7. Implementation and Experimental Results

Both implementations were tested using the same input of 100,000 transactions.

### Comparison

| Measurement | Original Design | Redesigned Design |
|---|---:|---:|
| Total transactions inserted | 100,000 | 100,000 |
| Transactions retained | 10 | 100,000 |
| Final capacity | 10 | 163,840 |
| Oldest transaction ID | 99,991 | 1 |
| Newest transaction ID | 100,000 | 100,000 |
| Insertion time | 429 µs | 3,086 µs |

### Validation Results

| Validation | Result |
|---|---|
| Original retains latest 10 transactions | Passed |
| Redesigned retains all transactions | Passed |
| Oldest transaction preserved | Passed |
| Newest transaction correct | Passed |

All four validation checks returned `true`.

### Experimental Observation

The original implementation completed insertion in 429 microseconds, while the redesigned implementation required 3,086 microseconds in this test.

The redesigned implementation took longer because it performs dynamic allocation and resizing. However, it successfully retained all 100,000 transactions instead of only 10.

The measured execution times are indicative and may vary depending on system conditions.

## 8. Complexity Analysis

| Operation | Original Design | Redesigned Design |
|---|---|---|
| Insertion | O(1) | O(1) amortized |
| Resizing | Not required | O(n) |
| Access oldest transaction | O(1) | O(1) |
| Access newest transaction | O(1) | O(1) |
| Storage | O(1) fixed | O(n) dynamic |

## 9. Memory and Performance Trade-offs

The original implementation uses a fixed amount of memory and provides predictable insertion time, but older transactions are lost.

The redesigned implementation requires additional memory as the transaction history grows. During resizing, temporary additional memory is also required to copy existing records.

Although resizing occasionally takes O(n) time, insertion has amortized O(1) complexity.

The redesigned solution prioritizes complete transaction preservation over minimum memory usage.

## 10. Final Conclusion

The redesigned dynamic transaction history successfully addressed the fixed-capacity limitation of the original implementation.

Testing with 100,000 transactions demonstrated that the original design retained only the latest 10 records, whereas the redesigned implementation preserved all 100,000 records in chronological order.

Although the redesigned version required more memory and had a higher measured insertion time, it achieved the primary objective of scalable transaction history storage.

The dynamic design is more suitable when complete transaction records must be maintained, while the original fixed-capacity design remains suitable for applications that require only a limited number of recent transactions.

## 11. Compilation and Execution

Compiler: GCC

Compilation command:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -O2 main.cpp -o task7.exe
```

Execution command:

```bash
.\task7.exe
```

## 12. Evidence

Screenshot: `screenshots/task7_comparison.png`