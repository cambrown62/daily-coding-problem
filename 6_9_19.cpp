#include <vector>
#include <iostream>

/*
Given a list of integers and a number K, return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4], since 2 + 3 + 4 = 9.
*/

std::vector<int> contiguous_sum(std::vector<int> v, int K) {
	std::vector<int> result;
	int j;
	
	for (int i = 0; i < v.size(); ++i) {
		int sum = 0;
		j = i;
		while (sum < K && j < v.size()) {
			sum += v[j];
			result.push_back(v[j]);
			++j;
		}
		if (sum == K) {
			return result;
		}
		else {
			result.clear();
		}
	}
	std::cout << "Could not find contiguous elements summing to " << K << std::endl;
	return result;
}

int main() {

	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	int K = 9;

	std::vector<int> res = contiguous_sum(v, K);

	for (int i = 0; i < res.size(); ++i) {
		std::cout << res[i] << " " ;
	}
	std::cout << std::endl;

	system("Pause");
	return 0;
}
