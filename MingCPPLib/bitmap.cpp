#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits.h>
#include <time.h>


#define MAX_NUM 1000000
#define bit_len sizeof(int)*8

class bit_map{
public:
	bit_map();
	~bit_map();
	void insert(const unsigned int& x);
	bool find(const unsigned int& x) const;	
private:
	std::vector<unsigned int> bmap;
	int size;
};

bit_map::bit_map() {
	int size = MAX_NUM/bit_len + 1;
	bmap = std::vector<unsigned int>(size, 0);
}
bit_map::~bit_map() {}
void bit_map::insert(const unsigned int& x) {
	if (find(x)) {
		std:: cout << x << " already exist" << std::endl;
		return;
	}
	unsigned int index = x/bit_len;
	unsigned int offset = x%bit_len;
	unsigned int value = 1 << offset;
	bmap[index] ^= value;
}
bool bit_map::find(const unsigned int& x ) const {
	unsigned int index = x/bit_len;
	unsigned int offset = x%bit_len;
	unsigned int value = 1 << offset;
	value ^= bmap[index];
	value >>= offset;
	return value == 0;
}
int main() {
	bit_map bmap;
	srand(time(NULL));
	int num_insert, num_check;
	num_insert = rand()%50;
	num_check = rand()%50;
	std::vector<unsigned int> input;
	for (int i = 0; i < num_insert; i++) {
		unsigned int value = rand()%(MAX_NUM+1);
		input.push_back(value);
		bmap.insert(value);
		std:: cout << value << std::endl;
	}

	for (int i = 0; i < rand()%(input.size()+1); i++) {
		unsigned int target = input[rand()%(input.size()+1)];
		if (bmap.find(target)) {
			std::cout << "find " << target << std::endl;
		}
		else std::cout << target << " not exist" << std::endl;
	}

	return 0;
}