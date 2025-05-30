#include <iostream>
#include "List.h"

List::List(const List& other) {
	Node* current = other._head;
	while (current) {
		pushBack(current->value);
		current = current->next;
	}
}


List& List::operator=(const List& other){
	if (this != &other) {
		clear();
		Node* current = other._head;
		while (current) {
			pushBack(current->value);
			current = current->next;
		}
	}
	return *this;
}

void List::pushBack(const ValueType& value) {
	Node* newNode = new Node(value, nullptr, _tail);
	if (_tail) {
		_tail->next = newNode;
	} else {
		_head = newNode;
	}
	_tail = newNode;
	_size++;
}

void List::popBack() {
	if (_size == 0) {
		throw std::out_of_range("List is empty");
	}

	Node* toDelete = _tail;
	_tail = _tail->prev;
	if (_tail) {
		_tail->next = nullptr;
	} else {
		_head = nullptr;
	}
	delete toDelete;
	_size--;
}

const ValueType& List::back() const {
	if (_size == 0) {
		throw std::out_of_range("List is empty");
	}
	return _tail->value;
}

size_t List::size() const {
	return _size;
}

bool List::isEmpty() const {
	return _size == 0;
}

void List::clear() {
	while (_head) {
		Node* temp = _head;
		_head = _head->next;
		delete temp;
	}
	_tail = nullptr;
	_size = 0;
}

List::~List() {
	clear();
}

