#include<iostream>
using namespace std;
/*
Dynamic Array Sum
Task:
Ask the user for n, then dynamically allocate an array of n integers using new.
Read n numbers into the array, compute their sum, and print it.
Don’t forget to delete[] the array!
Sample:
How many numbers? 3
Enter numbers: 4 7 2
Sum = 13
*/
int main(){
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	int* arr = new int[n];
	
	for(int i = 0; i<n; i++){
		cout<<"Enter elements of array: ";
		cin>>arr[i];
	}
	int sum=0;
	for(int i = 0; i<n; i++){
		sum += arr[i];
	}
	cout<<"sum is: "<<sum<<endl;
	
