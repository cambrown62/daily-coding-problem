#include <string>
#include <iostream>
using namespace std;

/*
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

//slightly simpler case: longest substring that contains exactly k distinct characters

int longest_substring(string s, int k){
	string check_string;
	int length;
	int longest_length = 0;
	for (int i = 0; i < s.size() - k; i++){
		check_string = s.substr(i, i+k-1);
		length = k;
		for (int j = i+k; j < s.size() ; j++){
			if(check_string.find(s[j]) != string::npos){
				length += 1;
			}
			else {
				break;
			}
			if (length > longest_length){
				longest_length = length;
			}
		}
	}
	return longest_length;
}


int main() {
	string s = "abcbbaddf";
	int k = 3;

	cout << longest_substring(s, k) << "\n";

	system("Pause");
	return 0;

}
