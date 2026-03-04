#include<iostream>
using namespace std;
class Teacher{
    double salary;
    public:
    int id;
    string name;
    string dept;

    // setter
    void setSalary(double s){
        salary = s;
    }
    // getter
    double getsalary(){
        return salary;
    }
};
int main(){
    Teacher T1;
    T1.id = 10;
    T1.name = "Rushda" ;
    T1.dept = "Computer Science";
    T1.setSalary(20000);
    
    cout<<T1.getsalary();

    return 0;
}