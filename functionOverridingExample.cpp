#include<iostream>
#include<string>
using namespace std;

class Parent{
    public:
    void getInfo(){
        cout<<"Parent.\n";
    }
};

class Child : public Parent{
    public:
    void getInfo(){
        cout<<"Child.\n";
    }
};
int main(){
    Child c;
    c.getInfo();  //child class function has overridden parent class function. 

    return 0;
}