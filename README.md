# Modern Buffer Kit

A small C++ project exploring std::vector, value semantics,
safe element access, and the Rule of Zero.

## Concepts

- std::vector
- size vs capacity
- reserve vs resize
- operator[] vs at()
- copy semantics
- move semantics
- moved-from object state
- Rule of Zero

## Buffer

Buffer uses std::vector<int> as its underlying storage.

Because std::vector already manages its own memory, Buffer does not
need custom copy, move, or destructor implementations.

## What I Tested

- Element read/write
- Bounds-checked access
- Copy construction
- Copy independence
- Move construction
- Move assignment
- Reusing a moved-from object

## Build

- Visual Studio 2022
- C++17 or later
