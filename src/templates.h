#pragma once
#include <sstream>
#include <string>
#include <iterator>

template<typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template<typename Container>
std::string cont_to_str(const Container& container) {
    std::ostringstream oss;
    for (const auto& elem : container) {
        oss << elem << " ";
    }
    return oss.str();
}
