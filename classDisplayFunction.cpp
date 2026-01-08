#include<iostream>
using namespace std;
class students{
	public:
		string name;
		int id;
		
	void displayData(){
	cout<<"Your name: "<<name<<endl;
	cout<<"Your id: "<<id<<endl;
	}
};

int main(){
	students S1;
	S1.name = "Rushda";
	S1.id = 74;
	S1.displayData();
	
	return 0;
}