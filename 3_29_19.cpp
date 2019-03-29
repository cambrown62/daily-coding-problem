#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
You are given an array of non-negative integers that represents a two-dimensional elevation map where each element 
is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, 
and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
*/

int water_trap(vector<int> v) {

	int left_wall_height = v[0];
	int left_wall_position = 1;
	int right_wall_height;
	int right_wall_position;
	int water_units = 0;
	int units_already_taken = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != 0) {
			right_wall_height = v[i];
			right_wall_position = i+1;
			if (right_wall_height < left_wall_height) {
				water_units += (right_wall_position - left_wall_position - 1)*right_wall_height - units_already_taken;
				units_already_taken += water_units + right_wall_height;
			}
			else {
				water_units += (right_wall_position - left_wall_position - 1)*left_wall_height - units_already_taken;
				left_wall_position = right_wall_position;
				units_already_taken = 0;
			}
			
		}
	}
	return water_units;
}

int main() {

	vector<int> v;
	
	v.push_back(3);
	v.push_back(0);
	v.push_back(1);
	v.push_back(3);
	v.push_back(0);
	v.push_back(5);
	

	/*
	v.push_back(3);
	v.push_back(1);
	v.push_back(3);
	v.push_back(0);
	*/

	cout << water_trap(v) << "\n";

	system("Pause");
	return 0;
}