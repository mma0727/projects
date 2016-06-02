#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <time.h>

std::vector<int> TwoSum(const std::vector<int>& num1, const std::vector<int>& num2) {
	if (num1.empty() || num1.empty()) return num1.empty() ? num2 : num1;
	int n1_len = num1.size(), n2_len = num2.size();
	int max_len = std::max(n1_len, n2_len);
	std::vector<int> res(max_len + 1, 0);
	int i = n1_len -1 , j = n2_len - 1, k = max_len, carryin = 0;
	while (i >= 0 || j >= 0 || carryin > 0) {
		int val = ((i >= 0) ? num1[i--] : 0) + ((j >= 0) ? num2[j--] : 0) + carryin;
		res[k--] = val%10;
		carryin = val/10;
	}

	// removing the possible leading 0s. 
	int start = 0;
	while (start < res.size() && res[start] == 0) start ++;
	return std::vector<int>(res.begin() + start, res.end());
	

}

void print(const std::vector<int>& nums) {
	for (int i = nums.size()-1; i >= 0; i--) {
		std:: cout << nums[i] << " ";
	}
	std::cout << std::endl;

}

void TwoSumTest() {
	int n1_len = rand()%20;
	int n2_len = rand()%20;
	std::vector<int> num1(n1_len, 0);
	std::vector<int> num2(n2_len, 0);
	for (int i = 0; i < n1_len; i++) num1[i] = rand()%10;
	for (int i = 0; i < n2_len; i++) num2[i] = rand()%10;
	std::cout << "num1:" << std::endl;
	print(num1);
	std::cout << "num2:" << std::endl;
	print(num2);
	std::vector<int> res = TwoSum(num1, num2);
	std::cout << "num1 + num2 :" << std::endl;
	print(res);
}


int main() {
	srand(time(NULL));
	TwoSumTest();
	return 0;
}