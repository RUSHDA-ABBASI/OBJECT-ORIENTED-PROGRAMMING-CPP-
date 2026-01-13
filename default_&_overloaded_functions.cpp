#include <iostream>
#include <string>
/*
Problem 1: Greeting with Default & Overloaded Functions
Task:
Write two overloaded functions named greet:
1. greet(string name) ? prints "Hello, [name]!"
2. greet(string name, string greeting) ? prints "[greeting],
[name]!"
Also, write a third version:
3. greet(string name = "Guest") ? uses a default argument
Test in main():
Cpp:
greet("Ali"); // Hello, Ali!
greet("Sara", "Hi"); // Hi, Sara!
greet(); // Hello, Guest!
*/
using namespace std;

void greet(string name = "Guest") {
    cout << "Hello, " << name << "!" << endl;
}

void greet(string name, string greeting) {
    cout << greeting << ", " << name << "!" << endl;
}

int main() {
    greet("Ali");     
    greet("Sara", "Hi");
    greet();                 

    return 0;
}
