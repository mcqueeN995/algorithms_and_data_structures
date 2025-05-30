#include <iostream>
#include "Vector.h"
#include <cassert>
#include <random>


int randomInt(int min, int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}


double* generateRandomArray(size_t size, int minVal = 10, int maxVal = 100) {
    double* arr = new double[size];
    for (size_t i = 0; i < size; ++i) {
        arr[i] = randomInt(minVal, maxVal);
    }
    return arr;
}

void testConstructors() {
    std::cout << "\n=== Testing Constructors ===" << std::endl;

    size_t size1 = randomInt(5, 10);
    double* arr1 = generateRandomArray(size1);
    Vector v1(arr1, size1);
    assert(v1.size() == size1);
    std::cout << "Parametrized constructor: OK" << std::endl;


    Vector v2(v1);
    assert(v2.size() == v1.size() && v2[0] == v1[0]);
    std::cout << "Copy constructor: OK" << std::endl;

    Vector v3(std::move(v2));
    assert(v3.size() == size1 && v2.size() == 0);
    std::cout << "Move constructor: OK" << std::endl;

    delete[] arr1;
}

void testPushMethods() {
    std::cout << "\n=== Testing Push Methods ===" << std::endl;


    Vector v1;
    size_t iterations = randomInt(3, 7);
    for (size_t i = 0; i < iterations; ++i) {
        double val = randomInt(100, 200);
        v1.pushBack(val);
        assert(v1[v1.size()-1] == val);
    }
    std::cout << "pushBack (" << iterations << " elements): OK" << std::endl;

    Vector v2;
    size_t capacityBefore = v2.capacity();
    for (size_t i = 0; i < 10; ++i) {
        v2.pushFront(i);
    }
    assert(v2.size() == 10 && v2.capacity() > capacityBefore);
    std::cout << "pushFront with reallocation: OK" << std::endl;
}

void testInsertMethods() {
    std::cout << "\n=== Testing Insert Methods ===" << std::endl;


    Vector v1;
    for (int i = 0; i < 5; ++i) v1.pushBack(i);
    v1.insert(99, 2);
    assert(v1.size() == 6 && v1[2] == 99);
    std::cout << "Insert middle: OK" << std::endl;


    double arr[] = {10, 20, 30};
    v1.insert(arr, 3, 0);
    assert(v1.size() == 9 && v1[0] == 10);
    std::cout << "Insert array at start: OK" << std::endl;

    Vector v2(arr, 3);
    v1.insert(v2, 5);
    assert(v1.size() == 12 && v1[5] == 10);
    std::cout << "Insert vector: OK" << std::endl;
}

void testEraseMethods() {
    std::cout << "\n=== Testing Erase Methods ===" << std::endl;


    Vector v1;
    for (int i = 0; i < 10; ++i) v1.pushBack(i);
    v1.eraseBetween(3, 7);
    assert(v1.size() == 6 && v1[3] == 7);
    std::cout << "eraseBetween middle: OK" << std::endl;


    v1.erase(4, 10);
    assert(v1.size() == 4);
    std::cout << "erase till end: OK" << std::endl;


    v1.erase(0, v1.size());
    assert(v1.size() == 0);
    std::cout << "erase all elements: OK" << std::endl;
}

void testEdgeCases() {
    std::cout << "\n=== Testing Edge Cases ===" << std::endl;


    Vector v1;
    try {
        v1.popBack();
        assert(false);
    } catch(...) {
        std::cout << "Empty vector popBack: OK" << std::endl;
    }


    try {
        v1.insert(5, 100);
        assert(false);
    } catch(...) {
        std::cout << "Invalid insert position: OK" << std::endl;
    }


    Vector v2(generateRandomArray(5), 5);
    v2.erase(2, 0);
    assert(v2.size() == 5);
    std::cout << "Zero-count erase: OK" << std::endl;
}

void testMemoryManagement() {
    std::cout << "\n=== Testing Memory Management ===" << std::endl;

    Vector v1(generateRandomArray(10), 10);
    v1.reserve(20);
    v1.shrinkToFit();
    assert(v1.capacity() == v1.size());
    std::cout << "shrinkToFit: OK" << std::endl;


    size_t newCapacity = randomInt(15, 25);
    v1.reserve(newCapacity);
    assert(v1.capacity() >= newCapacity);
    std::cout << "reserve: OK" << std::endl;
}

int main() {
    testConstructors();
    testPushMethods();
    testInsertMethods();
    testEraseMethods();
    testEdgeCases();
    testMemoryManagement();

    std::cout << "\n=== All tests passed successfully! ===" << std::endl;
    return 0;
}