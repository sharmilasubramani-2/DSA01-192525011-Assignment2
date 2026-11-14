# Task 2 – Return by Reference and Its Dangers

## Aim

To understand returning references from functions, modify original array elements through references, and examine the dangers of dangling references.

## Concepts Used

- Return by reference
- Return by const reference
- Return by value
- Dangling references
- Vector reallocation
- Pointers and array indexing

## Implementation

The program identifies the highest mark in an integer array and returns a reference to that element. The returned reference is used to apply a moderation increase directly to the original array.

The program also demonstrates returning a const reference, returning a copy, finding the highest element's index, and returning a pointer to the highest element.

A separate function demonstrates the danger of returning a reference to a local variable. The compiler warning is captured without executing the invalid function.

## Sample Output

```text
Original Marks: 78 91 84 91 67
Marks After Moderation: 78 93 84 91 67
Highest Mark through Const Reference: 93
Highest Mark through Copy: 93
Highest Index: 1
Highest Mark through Pointer: 93
Reference Before Vector Growth: 78
Vector Reallocation Occurred: true
```

## Return Method Comparison

| Method | Description |
|---|---|
| Reference | Provides access to the original object and allows modification. |
| Const Reference | Provides read-only access without creating a copy. |
| Value | Returns an independent copy of the value. |

## Dangling Reference

Returning a reference to a local variable is unsafe because the local variable's lifetime ends when its function returns. Accessing the returned reference results in undefined behaviour.

The compiler generated the warning `-Wreturn-local-addr` when compiling the demonstration function.

## Vector Reallocation

When a vector grows beyond its current capacity, it may allocate new memory and move its elements. Existing references and pointers to its elements become invalid after reallocation.

Therefore, the stored reference must not be accessed after the vector reallocates.

## Alternative Approaches

- Returning an index provides the position of the highest element. The element can be accessed using the index while the container remains valid.
- Returning a pointer provides direct access to the element but can become invalid if the underlying storage changes.
- Returning a reference provides direct access but also becomes invalid if the referenced object's lifetime ends or its storage is invalidated.

## Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
|---|---|---|
| Finding the highest mark | O(n) | O(1) |
| Returning a reference | O(1) | O(1) |
| Returning an index after finding the maximum | O(1) | O(1) |
| Returning a pointer after finding the maximum | O(1) | O(1) |

## Compilation

Main program:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o task2.exe
```

Execution:

```bash
./task2.exe
```

Compiler warning demonstration:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -fsyntax-only dangling_reference.cpp
```

## Result

The program successfully demonstrated returning references, modifying array elements through references, comparing reference and value returns, and identifying the risks of dangling references and vector reallocation.