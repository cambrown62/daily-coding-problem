#include <iostream>

/*
Implement division of two positive integers without using the division, multiplication, 
or modulus operators. Return the quotient as an integer, ignoring the remainder.
*/

int longhand_division(int a, int b) {
	int result = 1;
	int remainder = a - b;
	while (remainder >= b) {
		remainder -= b;
		result += 1;
	}
	return result;
}

int main() {
	int a = 5;
	int b = 2;

	std::cout << longhand_division(a, b) << std::endl;

	system("Pause");
	return 0;
}