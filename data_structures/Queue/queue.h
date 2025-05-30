#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue {
public:
	struct Node {
		T value;
		Node* next;
		explicit Node(const T& val);
	};

	class Iterator {
		Node* current;
	public:
		explicit Iterator(Node* node);
		Iterator& operator++();
		Iterator operator++(int);
		T& operator*() const;
		bool operator!=(const Iterator& other) const;
	};

private:
	Node* front;
	Node* rear;

public:
	Queue();
	~Queue();
	void Push(const T& value);
	T Pop();
	bool isEmpty() const;
	Iterator begin();
	Iterator end();
};

extern template class Queue<int>;

#endif