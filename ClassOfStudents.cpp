#include<iostream>
using namespace std;
/*
Write a program in which a class named student has member variables name, roll_no, semester
and section. Create 4 objects of this class to store data of 4 different students, now display data
of only those students who belong to section A.
*/
class Student{
	string name;
	int roll_no;
	int semester;
	char section;
	public:
		Student(string n, int r, int sem, char s){
			name = n;
			roll_no = r;
			semester = sem;
			section = s;
		}
		void display(){
			cout << "Name: " << name
            << ", Roll No: " << roll_no
            << ", Semester: " << semester
            << ", Section: " << section << endl;
		}
		char getSection(){
			return section;
		}
};
int main(){
	Student s1("Ali",1,2,'B');
	Student s2("Ahmed", 2, 2, 'B');
	Student s3("Umar", 3, 2, 'A');
	Student s4("Rushda", 4, 2, 'A');
	
	if(s1.getSection() == 'A') s1.display();
	if(s2.getSection() == 'A') s2.display();
	if(s3.getSection() == 'A') s3.display();
	if(s4.getSection() == 'A') s4.display();
	
	return 0;
}