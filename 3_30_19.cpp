#include <string>
#include <iostream>
#include <math.h>
using namespace std;

/*
The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. 
For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
*/

int edit_distance(string s1, string s2){
	int output = 0; //abs((int)(s1.size() - s2.size()));
	for (int i = 0; i < (s1.size() > s2.size() ? s2.size() : s1.size()); i++){
		if (s2.find(s1[i]) == string::npos){
			output += 1;
		}
		else if (s2.find(s1[i]) != string::npos){
			s2.erase(s2.find(s1[i]));
		}
	}
	return output;
}

int main() {

	string s1("kittan");
	string s2("ball");

	cout << edit_distance(s1, s2) << "\n";

	system("Pause");
	return 0;
}