#include<iostream>
using namespace std;
class calculator{
	float num1;
	float num2;
	
	public:
		calculator(float a,float b){
			num1 = a;
			num2 = b;
			cout<<"Constructor Envoked!"<<endl;
		}
		void add(){
			cout<<"Addition: "<<num1+num2<<endl;
		}
		void subtract(){
			cout<<"Subtraction: "<<num1-num2<<endl;
		}
		void multiply(){
			cout<<"Multiplication: "<<num1*num2<<endl;
		}
		void divide(){
			cout<<"Division: "<<num1/num2<<endl;
		}
		~calculator(){
			cout<<"Destructor Envoked!"<<endl;
		}	
};

int main(){
	float a;
	float b;
	int choice;
	cout<<"Enter 1st number: "<<endl;
	cin>>a;
	cout<<"Enter 2nd number: "<<endl;
	cin>>b;
	
	calculator calc(a,b);
	
	cout<<"Press 1 for addition."<<endl;
	cout<<"Press 2 for subtraction."<<endl;
	cout<<"Press 3 for multiplication."<<endl;
	cout<<"Press 4 for division."<<endl;
	cout<<"Enter your choice:"<<endl;
	cin>>choice;
	
	switch (choice){
		case 1:
			calc.add();
			break;
			
		case 2:
			calc.subtract();
			break;
		
		case 3:
		    calc.multiply();
			break;
			
		case 4:
		    calc.divide();
			break;	
			
		default:
			cout<<"Invalid input."<<endl;
	}
	return 0;
}