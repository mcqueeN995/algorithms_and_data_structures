#include "queue.h"
#include <iostream>

/*
Implementation of the Queue data structure based on Linked List
 */
template <typename T>
Queue<T>::Node::Node(const T& val) : value(val), next(nullptr) {}

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::~Queue() {
	while (!isEmpty()) Pop();
}

template <typename T>
void Queue<T>::Push(const T& value) {
	Node* newNode = new Node(value);
	if (isEmpty()) {
		front = rear = newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
	}
}

template <typename T>
T Queue<T>::Pop() {
	if (isEmpty()) {
		throw std::runtime_error("Queue is empty");
	}
	Node* temp = front;
	T value = front->value;
	front = front->next;
	if (!front) rear = nullptr;
	delete temp;
	return value;
}

template <typename T>
bool Queue<T>::isEmpty() const {
	return front == nullptr;
}

template <typename T>
Queue<T>::Iterator::Iterator(Node* node) : current(node) {}

template <typename T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
	if (current) current = current->next;
	return *this;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int) {
	typename Queue<T>::Iterator temp = *this;
	++(*this);
	return temp;
}

template <typename T>
T& Queue<T>::Iterator::operator*() const {
	return current->value;
}

template <typename T>
bool Queue<T>::Iterator::operator!=(const Iterator& other) const {
	return current != other.current;
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::begin() {
	return Iterator(front);
}

template <typename T>
typename Queue<T>::Iterator Queue<T>::end() {
	return Iterator(nullptr);
}

template class Queue<int>;