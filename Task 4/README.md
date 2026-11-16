# Task 4 – Savings Account Mini-Statement

## Aim

To design a `SavingsAccount` class that maintains the latest 10 transactions using a private fixed-size array and a circular buffer mechanism.

## Concepts Used

- Classes and objects
- Data encapsulation
- Private and public access specifiers
- Arrays inside classes
- Member functions defined inside and outside a class
- Scope resolution operator (`::`)
- Circular buffer
- Transaction management

## Class Specification

The `SavingsAccount` class contains the following private data members:

| Data Member | Purpose |
|---|---|
| `accountNumber` | Stores the account number |
| `balance` | Maintains the current account balance |
| `transactions[10]` | Stores the latest 10 transactions |
| `transactionCount` | Tracks the number of stored transactions |
| `nextIndex` | Identifies the next position for inserting a transaction |

The public member functions are:

- `deposit()` – Adds money to the account.
- `withdraw()` – Withdraws money after validating the balance.
- `miniStatement()` – Displays the latest 10 transactions.
- `getBalance()` – Returns the current account balance.

Some member functions are defined inside the class, while others are implemented outside using the scope resolution operator.

## Implementation Approach

A circular buffer is used to manage transaction history.

Each new transaction is stored at the position indicated by `nextIndex`. After insertion, the index advances using:

`nextIndex = (nextIndex + 1) % 10`

When the buffer becomes full, new transactions overwrite the oldest transactions.

The mini-statement uses the circular index to display transactions in chronological order.

## Why Is the Array Private?

The transaction array is declared private to protect the account's internal transaction records.

This prevents external code from directly modifying or deleting transaction details. Access is controlled through public member functions, ensuring data integrity and encapsulation.

## Handling the 11th Transaction

When the 11th transaction arrives, the circular buffer overwrites the oldest transaction.

Two possible approaches are:

| Approach | Insertion Time | Explanation |
|---|---|---|
| Shifting array | O(k) | Existing transactions must be shifted to make space. |
| Circular buffer | O(1) | The oldest transaction is overwritten directly. |

Here, `k` represents the number of stored transactions.

The circular buffer is more efficient because it avoids shifting elements.

## Design Decision: Increasing Capacity to 50

If the bank wants to store the latest 50 transactions instead of 10, the circular buffer design requires only a change in the array capacity and corresponding buffer limit.

The insertion and retrieval logic remains the same.

This makes the circular buffer easier to maintain and extend.

## Alternative Design: std::deque

A `std::deque` can also maintain the latest 10 transactions.

When the number of transactions reaches 10, the oldest transaction can be removed using `pop_front()`, and the new transaction can be added using `push_back()`.

| Feature | Fixed-Size Array | std::deque |
|---|---|---|
| Capacity | Fixed | Dynamic |
| Removing oldest transaction | Requires index management or shifting | `pop_front()` |
| Adding new transaction | Insert using circular index | `push_back()` |
| Memory management | Fixed allocation | Dynamic allocation |

The fixed-size circular buffer is selected for this implementation because it provides predictable memory usage and constant-time insertion without shifting existing transactions.

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Deposit | O(1) |
| Withdraw | O(1) |
| Insert transaction | O(1) |
| Display mini-statement | O(k) |

Here, `k` represents the number of stored transactions, with a maximum capacity of 10.

## Result

The `SavingsAccount` class successfully maintains the latest 10 transactions using a private fixed-size array and circular buffer. The implementation demonstrates encapsulation, array management and efficient transaction history updates.