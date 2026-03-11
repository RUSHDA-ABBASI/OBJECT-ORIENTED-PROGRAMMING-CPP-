#include<iostream>
using namespace std;
class Teacher{
    private:
    double salary;
    public:
    int id;
    string name;
    string dept;
    //parameterized constructor
    Teacher(int id, string name, string dept, double salary){
        this -> id = id;      
        this -> name = name;  
        this -> dept = dept;
        this -> salary = salary;
    }

    //copy constructor
     Teacher(Teacher &orgObj){
        cout<<"Copy constructor invoked.\n";
        this -> id = orgObj.id;      
        this -> name = orgObj.name;  
        this -> dept = orgObj.dept;
        this -> salary = orgObj.salary;
     }
    void changeDept(string newDept){
        dept = newDept;
    }
    void getInfo(){
        cout << id << endl;
        cout << name << endl;
        cout << dept << endl;
        cout << salary << endl;
    }
};
int main(){
    Teacher T1(74, "Rushda", "Computer Science", 20000);
    Teacher T2(T1);
    T2.getInfo();

    return 0;
}