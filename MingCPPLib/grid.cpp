#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

/*Two functions both caculate the probability of traversing (a, b) from (0,0) to (x-1, y-1)*/
std::vector<std::vector<double> > grid_prob(const int&x, const int& y);
void grid_prob_vec(const int& x, const int& y);

std::vector<std::vector<double> > grid_prob(const int& x, const int& y) {
	std::vector<std::vector<double> > res;
	if (x == 0 && y == 0) return res;
	res = std::vector<std::vector<double > > (x+1, std::vector<double> (y+1, 0));
	res[1][0] = 1;
	res[0][1] = 1;
	for (int i = 1; i <= x; i ++) {
		for (int j = 1; j <= y; j++) {
			res[i][j] = res[i-1][j]/2 + res[i][j-1]/2;
			if (j == y) res[i][j] += res[i-1][j]/2;
			if (i == x) res[i][j] += res[i][j-1]/2;
		}
	}
	return res;
}

void print(const std::vector<std::vector<double> >& res) {
	for (int i = 1; i < res.size(); i++) {
		for (int j = 1; j < res[0].size(); j++) 
			std::cout <<res[i][j] << "	";
		std::cout << std::endl;
	}
}

void grid_prob_vec(const int &x, const int &y) {
	if (x == 0 && y == 0) return;
	int size = y, inner = y, outer = x;
	if (x < y) {
		size = x, inner = x, outer = y;
	}
	std::vector<double> res(size, 0);
	res[0] = 1;
	std::cout << std::endl;

	for (int i = 0; i < outer; i++) {
		for (int j = 0; j < inner; j++) {
			if (i == 0) {
				if (j > 0) res[j] = res[j-1]/2;
			}
			else if (j == 0) res[j] /= 2;		// i != 0 && j == 0.


			else if (j == inner-1) {
				if (i == outer - 1) res[j] += res[j-1];
				else res[j] += res[j-1]/2;
			}
			else {
				res[j] /= 2;
				if (i == outer - 1) res[j] += res[j-1];
				else res[j] += res[j-1]/2;
			}
			std::cout << res[j] << "	";
		}
		std::cout << std::endl; 

	}

}
int main() {
	int x, y;
	std::cout <<" x, y : ";
	std::cin >> x >> y;
	std::vector<std::vector<double> > res = grid_prob(x, y);
	print(res);
	std::cout << "using vector ..." << std::endl;
	grid_prob_vec(x,y);
	return 0;
}