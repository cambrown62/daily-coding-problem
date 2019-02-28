#include <cmath>
#include <vector>
#include <iostream>
using namespace std;


/*
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

*/

bool addUp(const vector<int> v, const int k) {
	int size = v.size();
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++){
			//bool temp = (v[i] + v[j] == k) ? true : false;
			if (v[i] + v[j] == k){
				return true;
			}
		}
	}
	return false;
}

bool addUp_bonus(vector<int> v, const int k) {
	int size = v.size();


}


int main() {

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	int k = 17;

	bool x = addUp(vec, k);
	
	cout << x << "\n";

	system("pause");
	return 0;

}