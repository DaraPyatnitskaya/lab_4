#pragma once
#include <stdexcept>

template<typename T, size_t N>
class MyArray {
private:
    T data[N];

public:
    T& operator[](size_t index) {
        if (index >= N) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= N) throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t size() const {
        return N;
    }
};
