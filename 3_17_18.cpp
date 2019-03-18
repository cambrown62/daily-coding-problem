#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
*/

// naive solution

void substr_max(vector<int> v, int k) {
	int max_el;
	for (int i = 0; i <= v.size()-k; i++) {
		max_el = *max_element(v.begin()+i, v.begin()+i+k);
		cout << max_el << "\n";
	}
}

int main() {
	vector<int> vec;
	int k = 3;

	vec.push_back(10);
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(7);

	substr_max(vec, k);
	
	system("Pause");
	return 0;
}
