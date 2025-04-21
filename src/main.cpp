#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include "MyVector.h"
#include "MyArray.h"
#include "templates.h"

int main() {
    using namespace std::chrono;

    MyVector vec1(1000000000);
    vec1.fillRandom();

    // Копирование
    auto startCopy = high_resolution_clock::now();
    MyVector vec2 = vec1;
    auto endCopy = high_resolution_clock::now();

    // Перемещение
    auto startMove = high_resolution_clock::now();
    MyVector vec3 = std::move(vec1);
    auto endMove = high_resolution_clock::now();

    std::cout << "Copy time: " << duration_cast<milliseconds>(endCopy - startCopy).count() << " ms\n";
    std::cout << "Move time: " << duration_cast<milliseconds>(endMove - startMove).count() << " ms\n";

    // mySwap
    std::string a = "Hello", b = "World";
    mySwap(a, b);
    std::cout << "After swap: " << a << " " << b << '\n';
    int c = 1, d = 2;
    mySwap(c, d);
    std::cout << "After swap: " << c << " " << d << '\n';

    // контейнер_в_строку
    std::vector<int> v = {1, 2, 3};
    std::set<std::string> s = {"one", "two", "three"};
    std::cout << cont_to_str(v) << '\n';
    std::cout << cont_to_str(s) << '\n';

    // MyArray
    MyArray<std::string, 5> arr;
    arr[0] = "A";
    arr[1] = "B";
    arr[2] = "C";
    std::cout << "MyArray size: " << arr.size() << '\n';
    std::cout << arr[0] << " " << arr[1] << " " << arr[2] << '\n';

    return 0;
}
