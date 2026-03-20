#include<iostream>
#include<string>
using namespace std;
class A{
    public:
    int x;

};
int main(){
    A obj1;
    obj1.x = 10;
    cout<<obj1.x<<endl;

    A obj2;
    obj2.x = 20;
    cout<<obj2.x;

    return 0;
}