#include<iostream>
using namespace std;
/*
Swap Using References
Task:
Write a function void swap(int &a, int &b) that swaps two integers using references (not
pointers!).
In main(), read two numbers from the user, call swap, and print them.
Sample Input/Output:
Enter two numbers: 5 10
After swap: 10 5
*/

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main(){
	int a,b;
	cout<<"Enter two numbers: ";
	cin>>a>>b;
	swap(a,b);
	cout<<"After swapping: "<<a<<" "<<b <<endl;
}