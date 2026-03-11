#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    float* cgpaPtr;

    //parametetrized constructor.
    Student(string name, float cgpa){
        cout<< "Parameterized constructor invoked.\n";
        this-> name = name;
        cgpaPtr = new float;
        *cgpaPtr = cgpa;
    }

    //copy constructor for deep copy.
    Student (Student &obj){
        cout << "Copy constructor invoked.\n";
        this -> name = obj.name;
        cgpaPtr = new float;
        *cgpaPtr = *obj.cgpaPtr;
    }
    void getInfo(){
        cout<< "Name : " << name << endl;
        cout << "CGPA : "<< *cgpaPtr <<endl;
    }
    ~Student(){
        cout << "Destrucctor invoked.\n";
        delete cgpaPtr;  // releasing dynamically allocated memory.
    }
};
int main(){
    Student s1("Rushda", 3.75);
    s1.getInfo();
    Student s2(s1);
    s2.name = "Abbasi";
    *(s2.cgpaPtr) = 4;
    s1.getInfo();
    s2.getInfo();

    return 0;
}