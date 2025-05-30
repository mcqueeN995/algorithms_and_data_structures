#include "Stack.h"
#include <iostream>
#include "StackImplementation.h"

Stack::Stack(StackContainer container) : _containerType(container) {
    switch (container) {
        case StackContainer::Vector:
            _pimpl = new VectorStackImplementation();
            break;
        case StackContainer::List:
            _pimpl = new ListStackImplementation();
            break;
        default:
            throw std::invalid_argument("Unknown container type");
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container) : Stack(container) {
	for (size_t i = 0; i < arraySize; ++i) {
		_pimpl->push(valueArray[i]);
	}
}

Stack::Stack(const Stack& copyStack) : _containerType(copyStack._containerType) {
    switch (_containerType) {
        case StackContainer::Vector:
            _pimpl = new VectorStackImplementation(
                *static_cast<VectorStackImplementation*>(copyStack._pimpl)
            );
            break;
        case StackContainer::List:
            _pimpl = new ListStackImplementation(
                *static_cast<ListStackImplementation*>(copyStack._pimpl)
            );
            break;
        default:
            throw std::invalid_argument("Unknown container type");
    }
}

Stack& Stack::operator=(const Stack& copyStack) {
    if (this != &copyStack) {
        delete _pimpl;
        _containerType = copyStack._containerType;
        switch (_containerType) {
            case StackContainer::Vector:
                _pimpl = new VectorStackImplementation(
                    *static_cast<VectorStackImplementation*>(copyStack._pimpl)
                );
                break;
            case StackContainer::List:
                _pimpl = new ListStackImplementation(
                    *static_cast<ListStackImplementation*>(copyStack._pimpl)
                );
                break;
            default:
                throw std::invalid_argument("Unknown container type");
        }
    }
    return *this;
}

Stack& Stack::operator=(Stack&& moveStack) noexcept {
	if (this != &moveStack) {
		delete _pimpl;
		_pimpl = moveStack._pimpl;
		_containerType = moveStack._containerType;
		moveStack._pimpl = nullptr;
	}
	return *this;
}

Stack::~Stack() {
	delete _pimpl;
}

void Stack::push(const ValueType& value) {
	_pimpl->push(value);
}

void Stack::pop() {
	_pimpl->pop();
}

const ValueType& Stack::top() const {
	return _pimpl->top();
}

bool Stack::isEmpty() const {
	return _pimpl->isEmpty();
}

size_t Stack::size() const {
	return _pimpl->size();
}


