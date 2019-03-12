#include <vector>
#include <iostream>
using namespace std;


/*
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, write a function 
that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1

2, 1, 1
1, 2, 1
1, 1, 2

2, 2

What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X?
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

//Always going to be at least 1 way to climb with all 1-steps

/* N = 5
	1,1,1,1,1

	2,1,1,1
	1,2,1,1
	1,1,2,1
	1,1,1,2

	2,2,1
	2,1,2
	1,2,2
	
*/

/* N = 6
	1,1,1,1,1,1

	2,1,1,1,1
	1,2,1,1,1
	1,1,2,1,1
	1,1,1,2,1
	1,1,1,1,2

	^^ all 1's and one 2 section will always be N-1 ways

	2,2,1,1
	2,1,2,1
	2,1,1,2
	1,2,2,1
	1,2,1,2
	1,1,2,2

	2,2,2

	^^ if even, will always have an all 2's way


*/


/*
	Actually, as far as i can tell from googling, this is a permutation of a multiset

	so, the number of ways will be
	
	1 
	+
	(N-1)! / 1!(N-2)!
	+
	(N-2)! / 2!(N-4)!
	+
	(N-3)! / 3!(N-6)!
	+
	...

	and the size of the smallest multiset will be ceil(N/2)

	N-i = ceil(N/2)
	i = N - ceil(N/2)
*/

int factorial(int x) {
	if (x <= 0) {
		return 1;
	}
	return x * factorial(x - 1);
}

int stair_stepper(int N) {
	float num_ways = 1;
	int i = 1;
	while (N - i >= ceil(N / 2)) {
		num_ways += factorial(N - i) / (factorial(i) * factorial(N - i * 2));
		i += 1;
	}
	return num_ways;
}

int main() {

	cout << stair_stepper(7) << "\n";

	system("Pause");
	return 0;
}