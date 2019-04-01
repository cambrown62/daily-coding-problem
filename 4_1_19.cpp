#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list
so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/

void running_median(vector<float> v) {
	vector<float> temp;
	for (int i = 0; i < v.size(); i++) {
		temp.push_back(v[i]);
		sort(begin(temp), end(temp));
		
		if (i == 0) {
			cout << temp[i] << "\n";
		}
		else if ((i+1) % 2 == 0) {
			cout << (temp[floor((float)i / 2.0)] + temp[ceil((float)i / 2.0)]) / 2.0 << "\n";
		}
		else {
			cout << temp[i / 2] << "\n";
		}
		
	}
}

int main() {

	vector<float> vec;
	vec.push_back(2.0);
	vec.push_back(1.0);
	vec.push_back(5.0);
	vec.push_back(7.0);
	vec.push_back(2.0);
	vec.push_back(0.0);
	vec.push_back(5.0);

	running_median(vec);

	system("Pause");
	return 0;
}