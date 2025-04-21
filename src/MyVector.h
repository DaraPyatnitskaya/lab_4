#pragma once
#include <iostream>

class MyVector {
private:
    int* data;
    size_t size;

public:
    MyVector(size_t size);
    ~MyVector();

    // Copy semantics
    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);

    // Move semantics
    MyVector(MyVector&& other) noexcept;
    MyVector& operator=(MyVector&& other) noexcept;

    void fillRandom();
    void print() const;

    size_t getSize() const;
};
