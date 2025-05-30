#include <iostream>
#include "vector.h"
#include <utility>
#include <vector>



Vector::Vector(const ValueType* rawArray, const size_t size, float coef){
  _size = size;
  _multiplicativeCoef= coef;
  _capacity = size;
  _data = new double[this->_capacity];
  for (size_t i = 0; i < size; i++) {
    _data[i] = rawArray[i];
  }
 }

Vector::Vector(const Vector& other){
    _size = other._size;
    _multiplicativeCoef = other._multiplicativeCoef;
    _capacity = other._capacity;
    _data = new double[_capacity];

    for (size_t i = 0; i < _size; i++) {
        _data[i] = other._data[i];
    }
}

Vector & Vector::operator=(const Vector& other){
  if (this == &other){
    return *this;
  }
  delete[] _data;
  _size = other._size;
  _multiplicativeCoef = other._multiplicativeCoef;
  _capacity = other._capacity;
  _data = new double[_capacity];
  for (size_t i = 0; i < _size; i++) {
    _data[i] = other._data[i];
  }
  return *this;
}

Vector::Vector(Vector&& other) noexcept{
  _size = other._size;
  _multiplicativeCoef = other._multiplicativeCoef;
  _capacity = other._capacity;
  _data = other._data;

  other._size = 0;
  other._multiplicativeCoef = 0;
  other._capacity = 0;
  other._data = nullptr;
}

Vector& Vector::operator=(Vector&& other) noexcept{
  if (this == &other){
    return *this;
  }
  _size = other._size;
  _multiplicativeCoef = other._multiplicativeCoef;
  _capacity = other._capacity;
  _data = other._data;

  other._size = 0;
  other._multiplicativeCoef = 0.0f;
  other._capacity = 0;
  other._data = nullptr;
  return *this;
}

Vector::~Vector(){
    delete[] _data;
}

void Vector::pushBack(const ValueType& value) {
  if (_size == _capacity) {
    size_t newCapacity;
    if (_capacity == 0) {
      newCapacity = 1;
    } else {
      newCapacity = _capacity * _multiplicativeCoef;
    }
    reserve(newCapacity);
  }
  _data[_size] = value;
  _size++;
}
void Vector::pushFront(const ValueType& value) {
  if (_size == _capacity) {
    size_t newCapacity;
    if (_capacity == 0) {
      newCapacity = 1;
    } else {
      newCapacity = _capacity * _multiplicativeCoef;
    }
    reserve(newCapacity);
  }
  for (size_t i = _size; i > 0; i--) {
    _data[i] = _data[i - 1];
  }
  _data[0] = value;
  _size++;
}

void Vector::insert(const ValueType& value, size_t pos) {
  if (pos > _size) {
    throw std::out_of_range("Vector::insert");
  }
  if (_size == _capacity) {
    size_t newCapacity = (_capacity == 0) ? 1 : _capacity * _multiplicativeCoef;
    reserve(newCapacity);
  }
  _size++;
  for (size_t i = _size - 1; i > pos; i--) {
    _data[i] = _data[i - 1];
  }
  _data[pos] = value;
}

void Vector::insert(const ValueType* values, size_t size, size_t pos){
  if(pos > _size) {
    throw std::out_of_range("Vector::insert");
  }
  while (_size + size > _capacity) {
        _capacity *= _multiplicativeCoef;
    }

  if (_size + size > _capacity) {
     ValueType* buffer = new ValueType[_capacity];
     for (size_t i = 0; i < _size; i++) {
        buffer[i] = _data[i];
     }
     delete[] _data;
     _data = buffer;
  }

   for (size_t i = _size; i > pos; i--) {
        _data[i + size - 1] = _data[i - 1];
    }

    for (size_t i = 0; i < size; i++) {
        _data[pos + i] = values[i];
    }

    _size += size;
}

void Vector::insert(const Vector& vector, size_t pos){
    if(pos > _size) {
    throw std::out_of_range("Vector::insert");
  }
  while (_size + vector._size > _capacity) {
        _capacity *= _multiplicativeCoef;
    }

  if (_size + vector._size > _capacity) {
     ValueType* buffer = new ValueType[_capacity];
     for (size_t i = 0; i < _size; i++) {
        buffer[i] = _data[i];
     }
     delete[] _data;
     _data = buffer;
  }
  for (size_t i = _size; i > pos; i--) {
    _data[i + vector._size - 1] = _data[i - 1];
  }
  for (size_t i = 0; i < vector._size; i++) {
    _data[pos + i] = vector._data[i];
  }
  _size += vector._size;
}

void Vector::popBack(){
  if (_size == 0) {
    throw std::out_of_range("Vector::popBack");
  }
  _size--;
}

void Vector::popFront(){
  if (_size == 0) {
    throw std::out_of_range("Vector::popFront");
  }
  for (size_t i = 0; i < _size; i++) {
    _data[i] = _data[i + 1];
  }
  _size--;
}

void Vector::erase(size_t pos, size_t count) {
  if (pos >= _size) {
    throw std::out_of_range("Vector::erase");
  }
  if (count == 0) {
    return;
  }
  size_t real_count = std::min(count, _size - pos);
  size_t new_size = _size - real_count;
  for (size_t i = pos; i < new_size; ++i) {
    _data[pos + i] = std::move(_data[pos + real_count + i]);
  }
  _size = new_size;
}

void Vector::eraseBetween(size_t begin, size_t end){
   if (begin >= _size || end <= begin) {
     throw std::out_of_range("Vector::erase");
   }
   end = std::min(end, _size);
   const size_t count = end - begin;
   const size_t elementsToMove = _size - end;
   for (size_t i = 0; i < elementsToMove; ++i) {
     _data[begin + i] = std::move(_data[end + i]);
   }
   _size = _size - count;
}

size_t Vector::size() const{
  return _size;
}

size_t Vector::capacity() const{
  return _capacity;
}

double Vector::loadFactor() const{
  return _size / _capacity;
}

const ValueType& Vector::operator[](size_t idx) const{
  if (idx >= _size) {
    throw std::out_of_range("Vector::operator[]");
  }
  return _data[idx];
}

ValueType& Vector::operator[](size_t idx){
  if (idx >= _size) {
    throw std::out_of_range("Vector::operator[]");
  }
  return _data[idx];
}

long long Vector::find(const ValueType& value) const{
  for (size_t i = 0; i < _size; i++) {
    if (_data[i] == value) {
      return i;
    }
  }
  return -1;
}

void Vector::shrinkToFit(){
  _capacity = _size;
  double *buffer = new double[_capacity];
  for (size_t i = 0; i < _size; i++) {
    buffer[i] = _data[i];
  }
  delete[] _data;
  _data = buffer;
}

void Vector::reserve(size_t capacity){
  if (capacity <= _capacity) {
    return;
  }
  ValueType* buffer = new ValueType[capacity];
  for (size_t i = 0; i < _size; ++i) {
    buffer[i] = _data[i];
  }
  delete[] _data;
  _data = buffer;
  _capacity = capacity;
}

Vector::Iterator::Iterator(ValueType* ptr){
  _ptr = ptr;
}

ValueType& Vector::Iterator::operator*(){
  return *_ptr;
}

const ValueType& Vector::Iterator::operator*() const{
  return *_ptr;
}
ValueType* Vector::Iterator::operator->(){
  return _ptr;
}

const ValueType* Vector::Iterator::operator->() const{
  return _ptr;
}

Vector::Iterator Vector::Iterator::operator++(){
  ++_ptr;
  return *this;
}

Vector::Iterator Vector::Iterator::operator++(int){
  Iterator tmp = *this;
  _ptr++;
  return tmp;
}

bool Vector::Iterator::operator==(const Iterator& other) const{
  return _ptr == other._ptr;
}

bool Vector::Iterator::operator!=(const Iterator& other) const{
  return _ptr != other._ptr;
}

Vector::Iterator Vector::begin(){
  return Iterator(_data);
}

Vector::Iterator Vector::end(){
  return Iterator(_data + _size);
}
