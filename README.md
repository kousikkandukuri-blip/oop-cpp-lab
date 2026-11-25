# ECE121 — Object-Oriented Programming in C++ Lab (DIY Programs)

C++17 solutions for all 39 **DIY – Test Your Understanding** exercises from the ECE121 Lab Manual (Weeks 1–13).

## Structure

- `week01/` – From C to C++: The Transition
- `week02/` – Functions: Overloading, Default & Inline
- `week03/` – Classes, Objects & Encapsulation
- `week04/` – Constructors, Destructors & Dynamic Memory
- `week05/` – Static Members & Friend Functions
- `week06/` – Operator Overloading
- `week07/` – Inheritance
- `week08/` – Polymorphism & Virtual Functions
- `week09/` – Exception Handling
- `week10/` – File Input / Output
- `week11/` – Templates & STL Containers
- `week12/` – STL Algorithms, Lambdas & Problem-Solving Patterns
- `week13/` – Smart Pointers, Design Patterns & Basic Multithreading

## Compile & Run

```bash
g++ -std=c++17 -Wall week01/diy1_vowel_consonant.cpp -o program
./program
```

For Week 13 (multithreading), add `-pthread`:

```bash
g++ -std=c++17 -Wall -pthread week13/diy3_prove_the_race.cpp -o program
./program
```
