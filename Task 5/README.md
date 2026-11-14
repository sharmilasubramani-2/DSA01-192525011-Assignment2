# Task 5 – Static Members and Arrays of Objects

## Aim
To implement static data members, static member functions, and arrays of objects using a college bus ticket reservation system.

## Concepts Used
- Static data members
- Static member functions
- Arrays of objects
- Constructor initialization
- Class-level data sharing
- Object creation inside functions

## Implementation

The `BusTicket` class maintains a static data member named `issued`, which stores the total number of seats allocated. The static constant `CAPACITY` specifies the maximum number of available seats.

When a ticket object is created, the constructor checks whether seats are available. If capacity is available, the issued count is incremented and a seat number is assigned. Otherwise, the passenger is placed on the waiting list.

The static member function `count()` returns the total number of issued tickets without requiring an object.

## Token Output Prediction

The `Token` class contains a static variable `next`, initialized to 100. Each constructor call increments this shared variable and assigns the resulting value to the object's ID.

Three objects are created in the array, followed by one additional object. Therefore, the predicted output is:

```text
101 103 104 4
```

The output confirms that the static counter is shared among all objects.

## Sample Output

```text
TOKEN OUTPUT PREDICTION
101 103 104 4

COLLEGE BUS TICKET SYSTEM
Asha: Seat 1
Bala: Seat 2
Chitra: Seat 3
Dev: Waiting
Issued: 3

CREATING TICKETS INSIDE A FUNCTION
Extra Passenger 1: Waiting
Extra Passenger 2: Waiting
Issued inside function: 3
Extra Passenger 1: Waiting
Extra Passenger 2: Waiting
Issued inside function: 3
Final Issued Count: 3
```

## Observations and Analysis

1. Static data members are shared by all objects of a class.
2. A static data member is declared inside the class and defined outside the class using the scope resolution operator.
3. A static member function can directly access static members but cannot access non-static members because it does not have a `this` pointer.
4. An array of objects invokes the constructor for each element.
5. Creating objects inside a function does not reset static data members when the function returns.
6. The waiting list is used when the maximum seat capacity is reached.

## Alternative Design

A global variable could maintain the ticket count, but it would reduce encapsulation. A separate `TicketOffice` class could also manage ticket allocation.

The static member approach keeps the shared counter within the `BusTicket` class. For multiple buses, a separate counter per bus or a dedicated ticket management object would be more suitable.

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Ticket creation | O(1) |
| Seat allocation check | O(1) |
| Static count retrieval | O(1) |
| Printing one ticket | O(1) |
| Printing an array of n tickets | O(n) |

The static counter requires O(1) additional space.

## Result

The program was successfully implemented and executed. Static members, static member functions, arrays of objects, seat allocation, waiting-list handling, and persistence of static data across function calls were verified.