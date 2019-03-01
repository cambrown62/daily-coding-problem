#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

/*
Given an array of integers, return a new array such that each element at index i of the new array is the product of all 
the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. 
If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/


vector<int> prod_array(vector<int> v) {
	int size = v.size();
	int prod = 1;
	for (int i = 0; i < size; i++) {
		prod = prod * v[i];
	}
	vector<int> v_new;
	for (int i = 0; i < size; i++) {
		v_new.push_back(prod / v[i]);
	}
	return v_new;
}

vector<int> prod_array_bonus(vector<int> v) {
	int size = v.size();
	int prod = 1;
	vector<int> v_new;
	for (int i = 0; i < size; i++) {
		int prod = 1;
		if (i + 1 != size) {
			for (int j = i + 1; j < size; j++) {
				prod = prod * v[j];
			}
		}
		if (i-1 != -1) {
			for (int k = i - 1; k > -1; k--) {
				prod = prod * v[k];
			}
		}
		v_new.push_back(prod);
	}
	return v_new;
}


int main() {

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);

	
	vector<int> v2 = prod_array(v1);
	int size = v2.size();
	for (int i = 0; i < size; i++){
		cout << v2[i] << "\n";
	}
	 
	

	system("Pause");
	return 0;
}
