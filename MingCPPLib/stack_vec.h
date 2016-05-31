#ifndef _stack_vec_h
#define _stack_vec_h
#include <iostream>
#include <stdexcept>
#include <vector>
#include <utility>

template <typename value_t>
class Stack {
public:
	Stack();
	~Stack();
	void pop();
	void push(const value_t& val);
	const value_t& peek() const;
	const value_t& get_min() const;
	const void print() const;
private:
	std::vector<value_t> input;
	std::vector<std::pair<value_t, value_t> > minimum;
};

template <typename value_t>
Stack<value_t>::Stack() {}
template <typename value_t>
Stack<value_t>::~Stack() {}

template <typename value_t>
void Stack<value_t>::push(const value_t& val) {
	input.push_back(val);
	if (minimum.empty() || minimum.back().first > val) {
		std::pair<value_t, int> new_min(val, 1);
		minimum.push_back(new_min);
	}
	else if (minimum.back().first == val) minimum.back().second++;
}

template <typename value_t>
void Stack<value_t>::pop() {
	if (input.empty()) {
		throw std::logic_error("empty stack");
	//	return;
	}
	if (input.back() == minimum.back().first) {
		if (--minimum.back().second < 1) {
			minimum.pop_back();
		}
	}
	input.pop_back();
}
template <typename value_t>
const value_t& Stack<value_t>::peek() const {
	if (input.empty()) {
		throw std::logic_error("empty stack");
	//	return 0;
	}
	return input.back();
}

template <typename value_t>
const value_t& Stack<value_t>::get_min() const{
	if (minimum.empty()) {
		throw std::logic_error("empty stack");
	//	return 0;
	}
	return minimum.back().first;
}

template<typename value_t>
const void Stack<value_t>::print() const {
	if (input.empty()) {
		throw std::logic_error("empty stack");
	//	return;
	}
	for (int i = input.size()-1; i >= 0; i--) {
		std::cout << input[i] << std::endl;
	}
}

#endif