#include <vector>
#include <iostream>
using namespace std;

/*
We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. 
That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
*/

int count_inversions(vector<int> v){
	int inversions = 0;
	for (int i = 0; i < v.size(); i++){
		for (int j = i+1; j < v.size(); j++){
			if (v[i] > v[j]){
				inversions += 1;
			}
		}
	}
	return inversions;
}

int main(){

	vector<int> vec;
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);

	cout << count_inversions(vec) << "\n";

	system("Pause");
	return 0;
}