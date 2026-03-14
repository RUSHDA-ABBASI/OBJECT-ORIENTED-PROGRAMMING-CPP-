#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;

};

class Student : public Person{
    public:
    int rollno;

};

class Teacher : public Person{
    public:
    double salary;
};
int main(){
    Student s1;
    s1.name = "Rushda";
    s1.age = 19;
    s1.rollno = 74;

    cout<<s1.name;

    Teacher t1;
    t1.name = "Abbasi";
    t1.age = 40;
    t1.salary = 10000;

    cout<<t1.salary;

    return 0;
}