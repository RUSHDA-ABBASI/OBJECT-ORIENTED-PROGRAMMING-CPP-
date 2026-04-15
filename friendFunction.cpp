#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    string designation;
    double salary;

public:
    Employee(string n, int i, string d, double s) {
        name = n;
        id = i;
        designation = d;
        salary = s;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }

    // Friend function declaration
    friend void updateSalary(Employee &emp, double percentIncrease);
};

// Friend function definition
void updateSalary(Employee &emp, double percentIncrease) {
    emp.salary = emp.salary + (emp.salary * percentIncrease / 100);
}

int main() {
    Employee e1("Sara", 102, "Manager", 80000);

    cout << "Before Salary Update:\n";
    e1.display();

    updateSalary(e1, 15); // 15% increase

    cout << "\nAfter Salary Update:\n";
    e1.display();

    return 0;
}