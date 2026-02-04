#include <iostream>
using namespace std;

class Student {
    int rollNo;

public:
    Student(int r) {
        rollNo = r;
    }
    Student(const Student &obj) {
        rollNo = obj.rollNo;
    }
    void display() {
        cout << "Roll Number: " << rollNo << endl;
    }
};

int main() {
    Student s1(101);   
    Student s2 = s1; 

    cout << "Object s1: ";
    s1.display();

    cout << "Object s2 (copied from s1): ";
    s2.display();

    return 0;
}
