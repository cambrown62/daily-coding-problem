#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

/*
	   --------------	
      ---
    ------------
   ------
-----
*/

int num_classrooms(vector<vector<int>> intervals){
	int max_classrooms = 0;
	int classrooms;
	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
	for (int i = intervals[0][0]; i <= intervals[intervals.size()-1][1]; i++){
		classrooms = 0;
		for (int j = 0; j < intervals.size(); j++) {
			if (i >= intervals[j][0] && i <= intervals[j][1]){
				classrooms += 1;
			}
		}
		max_classrooms = (classrooms > max_classrooms ? classrooms : max_classrooms); 
	}
	return max_classrooms;
}

/*
int num_classrooms(vector<vector<int>> intervals){
	vector<vector<int>> times;
	vector<int> temp;
	
	for (int i = 0; i < intervals.size(); i++){
		temp.at(0) = intervals[i][0];
		temp.at(1) = 0;
		times.push_back(temp);

		temp.at(0) = intervals[i][1];
		temp.at(1) = 1;
		times.push_back(temp);
	}

	sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
	int classrooms = 0;
	int max_classrooms = 0;
	for (int i = 0; i < times.size(); i++){
		if (times[i][1] == 0){
			classrooms += 1;
		}
		else if(times[i][1] == 1){
			classrooms -= 1;
		}
		max_classrooms = (classrooms > max_classrooms ? classrooms : max_classrooms);
	}
	return max_classrooms;
}
*/

int main() {
	vector<vector<int>> intervals;

	vector<int> inter1;
	inter1.push_back(30);
	inter1.push_back(75);

	vector<int> inter2;
	inter2.push_back(0);
	inter2.push_back(50);

	vector<int> inter3;
	inter3.push_back(40);
	inter3.push_back(150);

	intervals.push_back(inter1);
	intervals.push_back(inter2);
	intervals.push_back(inter3);

	cout << num_classrooms(intervals) << "\n";

	system("Pause");
	return 0;
}