#include "queue_arr.h"
#include "stack_vec.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void queue_test() {
	Queue<int> que;
	int size = rand()%50;
	for (int i = 0; i < size; i++) {
		que.enqueue(rand()%100);
	}
	que.print();
	int deque_num = rand()%size + 1;
	for (int i = 0; i < deque_num; i++) {
		que.dequeue();
	}
}
void stack_test() {
	Stack<int> my_stack;
	int size = rand()%50;
	std::cout <<"push: " << std::endl;
	for (int i = 0; i < size; i++) {
		my_stack.push(rand()%100);
	}
	my_stack.print();
	int pop_num = rand()%size + 1;
	for (int i = 0; i < pop_num; i++) {
		my_stack.pop();
	}
	std::cout << "after popping: " << std::endl;
	my_stack.print();
	std::cout << "minimum: " << my_stack.get_min() << std::endl;
 
}


int main() {
	srand(time(NULL));
	//queue_test();
	stack_test();
	return 0;
}
