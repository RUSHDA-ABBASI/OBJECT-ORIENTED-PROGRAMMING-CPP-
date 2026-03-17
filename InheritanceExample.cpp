#include<iostream>
using namespace std;

class Person{
    public:
    string name;
    int age;
    Person(string name, int age){
        this -> name = name;
        this -> age = age;
        cout<< "Parent constructor.\n";
    }

    ~Person(){
        cout << "Parent destructor.\n";
    }
};
class Student : public Person{
    public:
    int roll_no;

    Student(string name, int age, int roll_no) :  Person(name, age){
        this -> roll_no = roll_no;
        cout <<"Child constructor.\n";
    }

    void getInfo(){
        cout<<"Name : " << name << "; Age: "<< age << "; Roll number: "<< roll_no << endl;
    }

    ~Student(){
        cout << "Child Destructor.\n";
    }
};
int main(){
    Student S1("Rushda", 19, 74);
    
    S1.getInfo();

    return 0;
}
