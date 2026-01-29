#include<iostream>
using namespace std;

class student{
	string name;
	int rollno;
	float gpa;
    public: 
	student(string n, int r, float g){
		name = n;
		rollno = r;
		if(g <= 4.0f && g >= 0.0f)
		gpa = g;
		else 
		  gpa = 0.0f; //default if invalid
	}
	void updategpa(float newgpa){
		if(newgpa >= 0.0 && newgpa <= 4.0)
		gpa = newgpa;
		else
		cout << "Invalid GPA! Must be between 0.0 and 4.0.\n";
	}
	void printinfo(){
		cout<<"Name: "<<name<<", Roll No: "<<rollno<<", GPA: "<<gpa<<endl;
	}
};
int main(){
	student s1("Ali", 101, 3.5);
	student s2("Ahmed", 102, 3.7);
	
	s1.updategpa(3.9);
	s2.updategpa(3.5); 
	
	s1.printinfo();
	s2.printinfo();
	
	return 0;
}