#include <iostream>
#include <vector>

std::vector<float> moving_average_filter(std::vector<int> v, int w) {
	std::vector<float> result_vec;
	for (int i = 0; i < v.size(); ++i) {
		float sum = 0;
		for (int j = i - w / 2; j <= i + w / 2; ++j) {
			if (j < 0 || j > v.size() - 1) {
				continue;
			}
			sum += v[j];
		}
		result_vec.push_back(sum / (float)w);
	}
	return result_vec;
}

int main() {

	std::vector<int> v;
	int window = 4;
	v.push_back(6);
	v.push_back(9);
	v.push_back(11);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);

	std::vector<float> new_vec = moving_average_filter(v, window);

	for (int i = 0; i < new_vec.size(); ++i) {
		std::cout << new_vec[i] << std::endl;
	}
	
	system("Pause");
	return 0;
}