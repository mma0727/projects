#ifndef _QUEUE_ARR_H
#define _QUEUE_ARR_H

#include <iostream>
#include <stdexcept>

template <typename value_t>
class Queue {
public:
	Queue();
	virtual ~Queue();
	void enqueue(const value_t& value);
	void dequeue();
	const value_t& front() const;
	bool empty() const;
	void print();
private: 
	int head, tail;
	int count;
	int capacity;
	value_t* container;
	void expand();
};

static const int INITIAL_CAPACITY = 10;

template<typename value_t>
Queue<value_t>::Queue() {
	capacity = INITIAL_CAPACITY;
	count = 0;
	container = new value_t[INITIAL_CAPACITY];
	head = 0; 
	tail = 0;
}

template <typename value_t>
Queue<value_t>::~Queue() {
	delete[] container;
}

template <typename value_t>

bool Queue<value_t>::empty () const {
	return count == 0;
}

template <typename value_t>
void Queue<value_t>::enqueue(const value_t& value) {
	if (count >= capacity) {
		expand();
	}
	container[tail] = value;
	tail = (tail + 1) %capacity;
	count ++;
}
template <typename value_t>
void Queue<value_t>::dequeue() {
	if (empty()) throw std::length_error("dequeue: empty queue");
	head = (head+1)%capacity;
	count --;
}

template <typename value_t>
const value_t& Queue<value_t>::front () const {
	if (empty()) throw std::length_error("front: empty queue");
	value_t value = container[head];
	head = (head+1)%capacity;
}
template <typename value_t>
void Queue<value_t>::expand() {
	value_t* new_container = new value_t[capacity*2];
	for (int i = 0; i < count; i++) {
		new_container[i] = container[(head+i)%capacity];
	}
	head = 0;
	tail = count;
	delete[] container;
	container = new_container;
	capacity *= 2;
}

template <typename value_t>
void Queue<value_t>::print() {
	if (empty()) throw std:: length_error("print: empty queue");
	for (int i = 0; i < count; i++) {
		std:: cout << container[(head+i)%capacity] << std::endl;
	}

}

#endif





