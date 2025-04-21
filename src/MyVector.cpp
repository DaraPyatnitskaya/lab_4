#include "MyVector.h"
#include <algorithm>
#include <random>

MyVector::MyVector(size_t size) : size(size) {
    data = new int[size];
}

MyVector::~MyVector() {
    delete[] data;
}

MyVector::MyVector(const MyVector& other) : size(other.size) {
    data = new int[size];
    std::copy(other.data, other.data + size, data);
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

// Move constructor
MyVector::MyVector(MyVector&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

// Move assignment
MyVector& MyVector::operator=(MyVector&& other) noexcept {
    if (this != &other) {
        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

void MyVector::fillRandom() {
    for (size_t i = 0; i < size; ++i)
        data[i] = rand() % 100;
}

void MyVector::print() const {
    for (size_t i = 0; i < size; ++i)
        std::cout << data[i] << ' ';
    std::cout << '\n';
}

size_t MyVector::getSize() const {
    return size;
}
