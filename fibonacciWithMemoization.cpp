#include<iostream>
using namespace std;
/*
Fibonacci with Memoization (Preview of DP)
Task:
Write a recursive function int fib(int n) that computes the nth Fibonacci number but stores
previously computed values in a global array (size 100, initialized to -1).
This is a top-down DP (memoization) intro!

Rules:
• If fib_cache[n] != -1, return it.
• Else, compute it, store it, then return.
Test:
Cpp:
cout << fib(10); // Should output 55 quickly, even for n=40
*/

int fib_cache[100];
int fib(int n) {
   
    if (n == 0) return 0;
    if (n == 1) return 1;
 
    if (fib_cache[n] != -1) return fib_cache[n];
  
    fib_cache[n] = fib(n - 1) + fib(n - 2);
    return fib_cache[n];
}
int main() {
    
    for (int i = 0; i < 100; i++) {
        fib_cache[i] = -1;
    }
    
    cout << fib(10) << endl; 
    cout << fib(40) << endl; 

    return 0;
}

