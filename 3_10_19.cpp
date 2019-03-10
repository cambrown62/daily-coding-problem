#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings 
in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/

vector<string> autocomplete(string s, vector<string> v) {
	int query_size = s.size();
	vector<int> index_vector;
	vector<string> return_vec;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].substr(0, query_size) == s) {
			return_vec.push_back(v[i]);
		}
	}
	return return_vec;
}

int main() {
	
	vector<string> vec;
	/*
	string w1 = "dog";
	string w2 = "deer";
	string w3 = "deal";
	vec.push_back(w1);
	vec.push_back(w2);
	vec.push_back(w3);

	string q = "de";
	*/

	string w1 = "built";
	string w2 = "bond";
	string w3 = "billion";
	string w4 = "bunt";
	string w5 = "bust";
	string w6 = "cat";
	vec.push_back(w1);
	vec.push_back(w2);
	vec.push_back(w3);
	vec.push_back(w4);
	vec.push_back(w5);
	vec.push_back(w6);

	string q = "bu";


	vector<string> vec2 = autocomplete(q, vec);

	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << "\n";
	}

	system("Pause");
	return 0;

}