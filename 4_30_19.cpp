#include <iostream>
using namespace std;

/*
There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the
top-left corner and getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:
Right, then down
Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*/

int num_ways = 0;

void top_lft_to_btm_rgt(int N, int M, int i, int j) {

	if (i < N-1 && j < M-1){
		top_lft_to_btm_rgt(N, M, i, j+1);
		top_lft_to_btm_rgt(N, M, i+1, j);
	}
	else if(i == N-1 && j < M-1){
		top_lft_to_btm_rgt(N, M, i, j+1);
	}
	else if(i < N-1 && j == M-1){
		top_lft_to_btm_rgt(N, M, i+1, j);
	}
	else if(i == N-1 && j == M-1){
		num_ways += 1;
	}

}	

int main() {
	int N = 5;
	int M = 5;

	top_lft_to_btm_rgt(N, M, 0, 0);

	cout << num_ways << "\n";

	system("Pause");
	return 0;
}