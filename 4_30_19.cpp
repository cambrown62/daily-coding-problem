#include <iostream>
using namespace std;

/*
Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/

int power(int x, int y) {
	if (y == 0) {
		return 1;
	}
	else if (y % 2 != 0) {
		return x * power(x*x, (y - 1) / 2);
	}
	else {
		return power(x*x, y / 2);
	}
}

int main() {

	cout << power(4, 1) << "\n";
	system("Pause");
	return 0;
}