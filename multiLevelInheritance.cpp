#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
    Person(){
       cout <<"Parent class Constructor.\n";
    }
};

class Student : public Person{
    public:
    int rollno;

    Student(){
    cout << "1st derived class constructor.\n";
    }
};
class GradStudent : public Student{
    public:
    string researchArea;

    GradStudent (){
        cout<< "2nd derived class constructor.\n";
    }

    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll no: " << rollno<< endl;
        cout << "Research area: " << researchArea << endl;
    }
};
int main(){
    GradStudent g1;
    g1.name = "Rushda";
    g1.age = 19;
    g1.rollno = 74;
    g1.researchArea = "OOP";
    g1.getInfo();
    return 0;
}