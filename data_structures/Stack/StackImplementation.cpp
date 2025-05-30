#include <iostream>
#include "StackImplementation.h"


void VectorStackImplementation::push(const ValueType& value){
	vector.pushBack(value);
}

void VectorStackImplementation::pop(){
	if (vector.size() == 0) {
		throw std::out_of_range("Stack is empty");
	}
	vector.popBack();
}

const ValueType& VectorStackImplementation::top() const{
	if (vector.size() == 0) {
		throw std::out_of_range("Stack is empty");
	}
	return vector[vector.size() - 1];
}

bool VectorStackImplementation::isEmpty() const{
	return vector.size() == 0;
}

size_t VectorStackImplementation::size() const{
	return vector.size();
}


//______________________________________________________________________________________________
//тут уже лист начинает дальше снизу
//______________________________________________________________________________________________

void ListStackImplementation::push(const ValueType& value){
        _list.pushBack(value);
}

void ListStackImplementation::pop(){
        if (_list.isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        _list.popBack();
}

const ValueType& ListStackImplementation::top() const{
        return _list.back();
}

bool ListStackImplementation::isEmpty() const{
        return _list.isEmpty();
}

size_t ListStackImplementation::size() const{
        return _list.size();
}

