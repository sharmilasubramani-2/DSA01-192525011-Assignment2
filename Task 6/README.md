# Task 6 – Friend Functions and Inline Functions

## Aim

To implement friend functions for comparing two Time objects and study the performance of inline and non-inline functions.

## Concepts Used

- Classes and objects
- Data encapsulation
- Friend functions
- Inline functions
- Function execution time
- Compiler optimization

## Implementation

The `Time` class contains private data members `h` and `m`, representing hours and minutes.

Two friend functions are implemented:

1. `minutesBetween()` calculates the absolute difference between two time objects in minutes.
2. `earlier()` checks whether the first time occurs before the second time.

Both functions access private data members directly through friendship.

## Sample Output

```text
TRAIN JOURNEY TIME PLANNER
Minutes Between Departure and Arrival: 205
Is Arrival Earlier Than Departure: false
Minutes Between Morning and Afternoon: 345
Is Morning Earlier Than Afternoon: true
Minutes Between Same Times: 0
Is First Same Time Earlier: false
```

## Test Case Analysis

| Test Case | Expected Result | Actual Result |
|---|---|---|
| 09:45 to 13:10 | 205 minutes | 205 minutes |
| 08:30 to 14:15 | 345 minutes | 345 minutes |
| 11:30 to 11:30 | 0 minutes | 0 minutes |
| Arrival earlier than departure | false | false |
| Morning earlier than afternoon | true | true |

All test cases passed successfully.

## Friend Functions vs Member Functions

A friend function is not a member of the class, but it is permitted to access private and protected members.

Friend functions are useful when an operation works equally with multiple objects.

A member function can directly access the members of its own object through the `this` pointer. A non-member friend function has no `this` pointer and accesses objects through the parameters supplied to it.

An alternative design could use public getter functions, avoiding friendship while preserving private data.

## Inline and Non-Inline Performance Comparison

A separate benchmark program performs 10,000,000 function calls and compares inline and non-inline execution.

The benchmark was compiled using GCC with `-O0` and `-O2` optimization levels.

### Measured Results

| Optimization Level | Inline Time (µs) | Non-Inline Time (µs) |
|---|---:|---:|
| -O0 | 23573 | 24547 |
| -O2 | 7245 | 23803 |

Both implementations produced the same result:

```text
160000000
```

### Analysis

At `-O0`, the inline function completed slightly faster than the non-inline function.

At `-O2`, the inline function showed a significant reduction in execution time because the compiler could optimize the function call and its surrounding code.

The `inline` keyword suggests that the compiler may substitute the function body at the call site. However, it does not guarantee that the compiler will perform inline expansion.

The non-inline benchmark uses a GCC-specific `noinline` attribute to prevent function inlining during comparison.

Execution times may vary depending on hardware, compiler version, optimization settings and system load.

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| minutesBetween() | O(1) |
|| earlier() | O(1) |
| Benchmark execution | O(n) |
| Auxiliary space | O(1) |

Here, `n` represents the number of function calls performed by the benchmark.

## Result

The `Time` class successfully uses friend functions to access private data members and perform time comparisons. The benchmark demonstrates how compiler optimization can influence inline and non-inline function performance. Both implementations produce the same result, while their execution times vary with optimization settings.