#include<iostream>
using namespace std;

class Animal {
public:
    // Pure virtual function ? makes class abstract
    virtual void speak() = 0; 

    // Can have non-virtual helpers too
    void sleep() { cout << "Zzz...\n"; }
};

class Dog : public Animal { 
	void speak() override {
		cout<<"Dog says woof!\n";
	}
//	void sleep() override{
//		cout<<"Dog is sleeping.\n";
//	}
 }; // must implement speak()

int main(){
Animal* a = new Dog();
    a->speak(); // Output: "Woof!" ?
    a->sleep();
    delete a;
}