#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <utility>


using ValueType = double;
class Vector
{

private:
    ValueType* _data = NULL;
    size_t _size = 0;
    size_t _capacity = 0;
    float _multiplicativeCoef = 2.0f;

public:
    Vector() = default;
    Vector(const ValueType* rawArray, const size_t size, float coef = 2.0f);
    explicit Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    explicit Vector(Vector&& other) noexcept;
    Vector& operator=(Vector&& other) noexcept;
    ~Vector();
    void Print(){
      std::cout << "[ ";
      for (size_t i = 0; i < _size; i++){
        std::cout << _data[i] << " ";
      }
      std::cout << "]";
      std::cout << std::endl;
    }
    void pushBack(const ValueType& value);
    void pushFront(const ValueType& value);
    void insert(const ValueType& value, size_t pos);
    void insert(const ValueType* values, size_t size, size_t pos);
    void insert(const Vector& vector, size_t pos);
    void popBack();
    void popFront();
    void erase(size_t pos, size_t count = 1);
    void eraseBetween(size_t beginPos, size_t endPos);
    size_t size() const;
    size_t capacity() const;
    double loadFactor() const;
    ValueType& operator[](size_t idx);
    const ValueType& operator[](size_t idx) const;
    long long find(const ValueType& value) const;
    void reserve(size_t capacity);
    void shrinkToFit();
    class Iterator
    {
        ValueType* _ptr;
    public:
        explicit Iterator(ValueType* ptr);
        ValueType& operator*();
        const ValueType& operator*() const;
        ValueType* operator->();
        const ValueType* operator->() const;
        Iterator operator++();
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
    };
    Iterator begin();
    Iterator end();
};

#endif

