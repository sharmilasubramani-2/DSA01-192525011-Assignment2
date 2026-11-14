# Task 1 – Call by Value, Reference and Pointer

## Aim

To demonstrate the differences between call by value, call by reference, and call by pointer using functions in OOPS.

## Problem Statement

Implement a program to demonstrate three methods of passing arguments to functions and observe their effects on the original variables.

## Concepts Used

- Functions
- Call by Value
- Call by Reference
- Pointers
- Dereferencing

## Algorithm

1. Start the program.
2. Declare three integer variables and initialize them to 10.
3. Define a function that accepts an integer by value and increments its local copy by 10.
4. Define a function that accepts an integer by reference and increments the original variable by 10.
5. Define a function that accepts an integer pointer and increments the value stored at the address by 10.
6. Display the initial values.
7. Call all three functions with their respective arguments.
8. Display the values after function execution.
9. Stop the program.

## Compilation Command

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o task1.exe