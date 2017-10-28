// compute square root of a number
// CCI (56)
#include <iostream>

using namespace std;

int sqrt_helper(int n, int min, int max) {
    if (max < min) return -1;

    int guess = (min+max)/2;
    if (guess * guess == n) {
        return guess;
    } else if (guess * guess < n) {
        return sqrt_helper(n, guess+1, max);
    } else {
        return sqrt_helper(n, min, guess - 1);
    }
}

int sqrt(int n) {
    return sqrt_helper(n, 1, n);
}

int sqrt2(int n) {
    for (int guess = 1; guess * guess <= n; guess++) {
        if (guess * guess == n) {
            return guess;       
        }
    } 
    return -1;
}

int main()
{
    int n = 100;
    int x = sqrt(100);

    cout << "sqrt(" << n << ")=" << x << endl;
    return 0;
}
