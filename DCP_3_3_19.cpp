#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. 
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

int first_missing(vector<int> v) {
	int size  = v.size();
	sort(v.begin(), v.end());
	for (int i = 0; i < size; i++){
		if (v[i] > -1) {
			for (int j = i; j < size-1; j++) {
				if((v[j+1] - v[j]) > 1){
					return v[j] + 1;
				}
			}

		}
	}
	return 0;
}

int main() {

	vector<int> vec;
	vec.push_back(4);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(6);

	int x = first_missing(vec);

	cout << x << "\n";

	system("Pause");
	return 0;
}