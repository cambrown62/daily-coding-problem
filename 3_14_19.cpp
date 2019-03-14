#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
using namespace std;


/*
The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x^2 + y^2 = r^2.
*/

float calculate_pi(int N) {
    int pts_inside = 0;
    float x;
    float y;
    for (int i = 1; i < N+1; i++){
        x = rand();
        y = rand();
        x = x / RAND_MAX;
        y = y / RAND_MAX;
        if (x*x + y*y <= 1){
            pts_inside++;    
        } 
    }
    cout << pts_inside << "\n";
    return 4.0 * (float)pts_inside/(float)N;
}

int main() {
    srand(time(NULL));

    cout << calculate_pi(10000) << "\n";

    system("Pause");
    return 0;
}
