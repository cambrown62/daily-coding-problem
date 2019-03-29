#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/*
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive 
characters as a single count and character.

For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists 
solely of alphabetic characters. You can assume the string to be decoded is valid.
*/


string run_length_encoder(string s) {
	string output;
	int letter_counter = 1;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) {
			letter_counter += 1;
			if (i + 1 == s.size() - 1) {
				output.append(to_string(letter_counter));
				output.push_back(s[i]);
			}
		}
		else {
			output.append(to_string(letter_counter));
			output.push_back(s[i]);
			letter_counter = 1;
		}

	}
	return output;
}

int main() {

	string s1("AAAABBBCCDAA");

	string s2 = run_length_encoder(s1);

	cout << s2 << "\n";

	system("Pause");
	return 0;
}