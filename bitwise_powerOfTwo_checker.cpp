#include<iostream>
using namespace std;
/*
Problem 2: Bitwise Power-of-Two Checker
Task:
Write a function bool isPowerOfTwo(int n) that returns true if n is a power of two (e.g., 1, 2, 4,
8, 16...), else false.
Hint: Use bitwise AND (&).
Trick: A number n is a power of two iff n > 0 and (n & (n - 1)) == 0.
Sample:
Cpp:
isPowerOfTwo(8); // true
isPowerOfTwo(6); // false
*/

bool isPowerOfTwo(int n){
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(){
	int n = 5;
	cout << boolalpha << isPowerOfTwo(n) << endl;
}
