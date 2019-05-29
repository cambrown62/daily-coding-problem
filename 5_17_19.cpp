#include <vector>
#include <iostream>

/*
Given an array of integers, write a function to determine whether the array could become non-decreasing by modifying 
at most 1 element.

For example, given the array [10, 5, 7], you should return true, since we can modify the 10 into a 1 to make the 
array non-decreasing.

Given the array [10, 5, 1], you should return false, since we can't modify any one element to get a non-decreasing array.
*/

bool one_element_swap_non_decreasing(std::vector<int> v) {
	int non_decreasing_sets = 0;
	for (int i = 0; i < v.size()-1; ++i) {
		if (v[i] <= v[i + 1]) {
			continue;
		}
		else {
			non_decreasing_sets += 1;
		}

		if (non_decreasing_sets > 1) {
			return false;
		}
	}

	return true;

	/*
	int i = 0;
	int non_decreasing_set = 0;
	while()
	*/
}

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(1);
	vec.push_back(7);

	std::cout << one_element_swap_non_decreasing(vec) << std::endl;

	system("Pause");
	return 0;
}