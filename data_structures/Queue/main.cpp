#include "queue.h"
#include <iostream>

int main() {
	Queue<int> q;

	q.Push(10);
	q.Push(20);
	q.Push(30);

	std::cout << "Queue elements: ";
	for (auto it = q.begin(); it != q.end(); ++it) {
		std::cout << *it << " ";
	}

	while (!q.isEmpty()) {
		std::cout << "\nPopped: " << q.Pop();
	}

	return 0;
}