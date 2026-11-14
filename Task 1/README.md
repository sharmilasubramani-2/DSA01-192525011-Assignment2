# Task 1 – Function Parameters and References

## Aim

To understand and implement call by value, call by reference, and call by pointer in C++. This task also demonstrates reference returns, default arguments, and the effect of parameter passing on the original variables.

## Concepts Covered

- Call by Value
- Call by Reference
- Call by Pointer
- Reference Return
- Default Arguments
- Integer Arithmetic
- Parameter Passing and Memory Behaviour

## Implementation

The program demonstrates hostel fee concessions using three parameter-passing methods:

| Method | Concession | Initial Fee | Stored Fee |
|---|---:|---:|---:|
| Call by Value | 10% | 45000 | 45000 |
| Call by Reference | 15% | 45000 | 38250 |
| Call by Pointer | 25% | 45000 | 33750 |

### Explanation

**Call by Value:** A copy of the original fee is passed to the function. Changes affect only the local copy, so the original fee remains unchanged.

**Call by Reference:** The function receives a reference to the original variable. Changes made inside the function directly modify the original fee.

**Call by Pointer:** The address of the original variable is passed. Dereferencing the pointer allows the function to modify the original fee.

## Output Prediction

The `change()` function demonstrates the behaviour of value, reference, and pointer parameters.

The `bigger()` function returns a reference to the larger variable, allowing the returned variable to be modified directly.

The `show()` function demonstrates default arguments.

### Predicted Output

```text
1 12 13
1 100
16 13 6
```

### Explanation

- The first variable remains unchanged because it is passed by value.
- The second and third variables are modified through reference and pointer parameters.
- The `bigger()` function returns a reference to the larger variable.
- The `show()` function uses default values for omitted arguments.

## Completed Code

The `applyConcession()` function uses a reference parameter to update the hostel fee.

```cpp
void applyConcession(long long &fee, int percent) {
    fee -= fee * percent / 100;
}
```

### Expected Result

| Operation | Fee |
|---|---:|
| Initial Fee | 45000 |
| After Call by Value | 45000 |
| After Call by Reference | 40500 |

## Alternative Design

The concession function can also return the updated fee instead of modifying the original variable directly.

```cpp
long long applyConcession(long long fee, int percent) {
    return fee - fee * percent / 100;
}
```

The returned value can be stored using:

```cpp
hostelFee = applyConcession(hostelFee, 10);
```

Returning a new value makes the modification explicit, while reference-based modification is useful when the original variable must be updated directly.

## Complexity Analysis

| Operation | Time Complexity | Additional Space |
|---|---|---|
| Call by Value | O(1) for `long long` | O(1) |
| Call by Reference | O(1) | O(1) |
| Call by Pointer | O(1) | O(1) |
| Fee Calculation | O(1) | O(1) |

For a large object, passing by value requires copying the object, which takes time proportional to its size. Passing by reference or const reference avoids this copy.

A const reference is suitable when a function needs to read an object without modifying it.

## Compilation

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o task1.exe
```

## Execution

```powershell
.\task1.exe
```

## Result

The program successfully demonstrates call by value, call by reference, call by pointer, reference returns, and default arguments. The completed concession function correctly modifies the original fee through a reference parameter.