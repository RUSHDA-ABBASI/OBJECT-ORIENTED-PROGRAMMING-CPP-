#include<iostream>
#include<string>
using namespace std;

 class Shape{
    virtual void draw() = 0; //pure virtual function.
    // a class with pure virtual function automatically becomes an abstract class
};

class Circle : public Shape{
    public:
    void draw(){
        cout<<"Drawing a circle.\n";
    }
};
int main(){
    Circle c;
    c.draw();

    return 0;
}