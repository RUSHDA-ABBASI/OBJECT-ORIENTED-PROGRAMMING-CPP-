#include<iostream>
using namespace std;

int main(){
	int *a = new int[5];
	
	for(int i = 0; i < 5; i++){
		cout<<"Enter a number: ";
		cin>>*(a+i);
	}
	for(int i = 0; i < 5; i++){
		cout<<"You entered: "<<*(a++)<<endl;
	}
	delete[] a;
	
	return 0;
}