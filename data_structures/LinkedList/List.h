//
// Created by kiril on 13.04.2025.
//

#ifndef LIST_H
#define LIST_H
#include <iostream>

using ValueType = double;

class List {
	private:
		struct Node {
			ValueType value;
			Node* next;
			Node* prev;
			Node(const ValueType& val, Node* nxt = nullptr, Node* prv = nullptr) : value(val), next(nxt), prev(prv) {}
		};

		Node* _head = nullptr;
		Node* _tail = nullptr;
		size_t _size = 0;

    public:
    	List() = default;
		List(const List& other);
        ~List();
		List& operator=(const List& other);
		void pushBack(const ValueType& value);
		void popBack();
		const ValueType& back() const;
		size_t size() const;
		bool isEmpty() const;
		void clear();
};

#endif //LIST_H
