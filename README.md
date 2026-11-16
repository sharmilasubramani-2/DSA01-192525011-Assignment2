# DSA0111 – OOPS | Assignment 2

## 1. Assignment Overview

This repository contains the implementation, testing, analysis and documentation for Assignment 2 of the DSA0111 OOPS course.

The assignment covers function mechanisms, references, function overloading, classes, arrays, static members, friend functions, inline functions and object-oriented program design.

The assignment is organized into seven independent tasks. Each task directory contains its implementation files, individual documentation and relevant execution evidence.

## 2. Student Information

| Field | Details |
|---|---|
| Name | Sharmila S |
| Register Number | 192525011 |
| Programme | B.Tech – Artificial Intelligence and Machine Learning |
| Department | Intelligence Systems |
| Course Code | DSA0111 |
| Course | OOPS |
| Assignment | Assignment 2 |

## 3. Learning Objectives

The objectives of this assignment are to:

- Understand call by value, call by reference and call by pointer.
- Implement functions that return references and understand their associated risks.
- Apply default arguments and function overloading.
- Design classes using appropriate access specifiers.
- Implement arrays within classes and arrays of objects.
- Understand static data members and static member functions.
- Apply friend functions and inline functions.
- Evaluate alternative implementations using time and space complexity.
- Develop appropriate solutions using object-oriented programming principles.

## 4. Repository Structure

```text
DSA01-192525011-Assignment2/
|
|-- .gitignore
|-- README.md
|
|-- Task 1/
|   |-- main.cpp
|   |-- README.md
|   |-- screenshots/
|       |-- task1_execution.png
|
|-- Task 2/
|   |-- main.cpp
|   |-- dangling_reference.cpp
|   |-- README.md
|   |-- screenshots/
|       |-- task2_compiler_warning.png
|       |-- task2_execution.png
|
|-- Task 3/
|   |-- main.cpp
|   |-- README.md
|   |-- screenshots/
|       |-- task3_execution.png
|
|-- Task 4/
|   |-- main.cpp
|   |-- README.md
|   |-- screenshots/
|       |-- task4_execution.png
|
|-- Task 5/
|   |-- main.cpp
|   |-- README.md
|   |-- screenshots/
|       |-- task5_execution.png
|
|-- Task 6/
|   |-- main.cpp
|   |-- benchmark.cpp
|   |-- README.md
|   |-- screenshots/
|       |-- task6_benchmark.png
|       |-- task6_execution.png
|
|-- Task 7/
    |-- main.cpp
    |-- README.md
    |-- screenshots/
        |-- task7_comparison.png
```

**Note:** Compiled executable files (`.exe`) are excluded from version control using `.gitignore`. Source code, documentation and screenshots are maintained in the repository.

## 5. Task Overview

| Task | Topic | Marks |
|---|---|---:|
| 1 | Call by Value, Reference and Pointer | 6 |
| 2 | Return by Reference and Its Dangers | 4 |
| 3 | Default Arguments and Function Overloading | 6 |
| 4 | Specifying a Class with an Array Inside It | 6 |
| 5 | Static Members and Arrays of Objects | 7 |
| 6 | Friend Functions and Inline Functions | 8 |
| 7 | Diagnose, Redesign and Validate | 13 |
| | **Total** | **50** |

## 6. Development Environment

| Component | Details |
|---|---|
| Operating System | Windows |
| IDE | Visual Studio Code |
| Compiler | GNU C++ (G++) |
| Compiler Version | 16.1.0 |
| Compiler Distribution | MSYS2 |
| Language Standard | C++17 |
| Version Control | Git 2.54.0.windows.1 |
| Repository Hosting | GitHub |

## 7. Compilation and Execution

The programs are compiled using the GNU C++ compiler with the C++17 language standard and additional warning flags.

### Compilation

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
```

For example, to compile a program inside Task 1:

```powershell
cd "Task 1"
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main.exe
```

### Execution

```powershell
.\main.exe
```

For Task 6, the benchmark program can be compiled separately:

```powershell
g++ -std=c++17 -O0 benchmark.cpp -o benchmark_O0.exe
g++ -std=c++17 -O2 benchmark.cpp -o benchmark_O2.exe
```

### Compiler Verification

```powershell
g++ --version
```

## 8. Documentation and Validation

Each task includes an individual README file documenting the relevant implementation and analysis.

Documentation covers the following aspects, as applicable:

- Aim and problem statement
- Concepts and techniques used
- Implementation approach
- Output prediction and reasoning
- Actual execution results
- Test cases and validation
- Time and space complexity analysis
- Alternative approaches
- Design decisions and justification
- Conclusion

Execution screenshots are maintained in the corresponding task directories as supporting evidence.

## 9. Version Control

Git is used to maintain the development history of this assignment.

Changes are tracked through task-wise commits with meaningful commit messages. The repository maintains source files, documentation and execution evidence while excluding compiled executable files.

## 10. Repository Information

**Repository Name:** DSA01-192525011-Assignment2

**Course:** DSA0111 – OOPS

**Platform:** GitHub

---

*DSA0111 – OOPS | Assignment 2*
*B.Tech – Artificial Intelligence and Machine Learning*