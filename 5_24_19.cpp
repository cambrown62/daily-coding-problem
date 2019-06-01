#include <string>
#include <iostream>
#include <math.h>

/*
Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed 
to make the string valid (i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must 
remove all of them.

"(()()(((()((("
"())(()"
*/

int num_to_validation(std::string s) {

	int result = 0;
	int i = 0;
	int open_ct = 0;
	int closed_ct = 0;

	while (s[i] == ')') {
		result += 1;
		i++;
	}

	for (int j = i; j < s.size(); ++j) {
		if (s[j] == '(') {
			open_ct += 1;
		}
		else if (s[j] == ')') {
			closed_ct += 1;
		}
	}

	return result + fabs(open_ct - closed_ct);
}

int main() {
	std::string s("())()(())(");
	std::cout << num_to_validation(s) << std::endl;

	system("Pause");
	return 0;
}