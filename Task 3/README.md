# Task 3 – Default Arguments and Function Overloading

## Course
DSA0111 OOPS

## Aim
To implement a courier charge calculator using function overloading and default arguments. The program demonstrates overload resolution for integer weights, floating-point weights, and Parcel objects.

## Problem Description
A courier service calculates delivery charges based on parcel weight. Additional charges may apply for express delivery and insurance.

The program supports three types of inputs:
- Integer weight in grams.
- Double weight in kilograms.
- Parcel object containing weight information.

## Concepts Used

1. **Function Overloading:** Multiple functions share the same name but accept different parameter types.
2. **Default Arguments:** Optional parameters provide default values when arguments are omitted.
3. **Overload Resolution:** The compiler selects the most suitable function based on argument types.
4. **Const Reference:** Parcel objects are passed by constant reference to avoid unnecessary copying.

## Implementation

The program defines a `Parcel` structure containing the parcel weight in kilograms.

The overloaded `charge()` functions handle:
- `int` – weight in grams.
- `double` – weight in kilograms.
- `const Parcel&` – Parcel object.

The default arguments `express = false` and `insured = false` allow optional delivery services.

The charge calculation uses the following rules:
- Base charge: ₹50 per kilogram.
- Express delivery: Additional ₹100.
- Insurance: Additional ₹50.

## Original Overloading Ambiguity

The original design contained these function declarations:

```cpp
void charge(double weight);
void charge(double weight, bool express);
void charge(double weight, bool express = false, bool insured = false);
```

A call such as `charge(2.0)` becomes ambiguous because both the first and third functions can accept one argument. The compiler cannot select one as the better match.

The redesigned program avoids this ambiguity by using distinct parameter types for the three overloads.

## Function Selection – Prediction and Observation

| Function Call | Selected Overload | Reason |
|---|---|---|
| `charge(2)` | Integer | Exact match |
| `charge(2.0f)` | Double | Float-to-double promotion |
| `charge(2.0)` | Double | Exact match |
| `charge(500, true)` | Integer | Exact match |
| `charge(1.5, false, true)` | Double | Exact match |
| `charge(parcel)` | Parcel | Exact match |

### Overload Resolution

- **Exact Match:** The argument type directly matches the parameter type.
- **Promotion:** A type is converted to a preferred wider type, such as `float` to `double`.
- **Conversion:** A general type conversion, such as `double` to `int`, is considered when a better match is unavailable.

The compiler generally prefers an exact match over a promotion, and a promotion over a standard conversion.

## Default Argument Rules

Default arguments allow functions to be called with fewer arguments.

For example:

```cpp
void display(int a, int b = 10, int c = 20);
```

Default arguments must be specified from right to left. Once a parameter has a default value, all parameters following it must also have default values.

## Alternative Design

An alternative is to use a single structure to represent parcel details and optional services.

```cpp
struct ParcelOptions {
    double weightKg;
    bool express = false;
    bool insured = false;
};
```

A single function could accept a `const ParcelOptions&` parameter and calculate the charge.

This approach makes it easier to add new options in the future. However, callers must create and pass a structure instead of directly supplying different weight types.

A function template is another possible approach, but it would require careful handling of weight units to avoid confusion between grams and kilograms.

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|---|---|---|
| Charge calculation | O(1) | O(1) |
| Overload resolution | Compile-time | No runtime storage |
| Passing integer or double | O(1) | O(1) |
| Passing Parcel by const reference | O(1) | No object copy |

Function overloading is resolved during compilation and does not introduce runtime overload-selection overhead.

Passing a Parcel using a constant reference avoids copying the complete object.

## Compilation and Execution

Compiler: GCC 16.1.0

Compile command:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o task3.exe
```

Run command:

```powershell
.\task3.exe
```

## Output

```text
Courier Charge Calculator
Integer overload (grams): 0.1
Double overload (kg): 100
Double overload (kg): 100
Integer overload (grams): 125
Double overload (kg): 125
Parcel overload: 175
```

## Result

The courier charge calculator was successfully implemented and executed using function overloading and default arguments. The program demonstrates correct overload selection, optional parameters, and efficient object passing using constant references.