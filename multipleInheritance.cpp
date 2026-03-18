#include<iostream>
using namespace std;
class Teacher{
    public:
    string dept;
    double salary;
};

class Student{
    public:
    int rollno;
    string name;
};

class TeacherAssistant : public Student , public Teacher{
    public:
    string subject;

    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Roll no: " << rollno << endl;
        cout << "Department: " << dept << endl;
        cout << "Salary: " << salary << endl;
        cout << "Subject: " << subject<< endl;
    }
};
int main(){
    TeacherAssistant t1;
    t1.name = "Rushda";
    t1.rollno = 74;
    t1.dept = "Computer science";
    t1.salary = 10000;
    t1.subject = "OOP";

    t1.getInfo();
    return 0;
}