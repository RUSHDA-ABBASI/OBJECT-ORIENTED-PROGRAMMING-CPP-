#include <iostream>
using namespace std;

class Payroll; // Forward declaration

class Employee {
private:
    string name;
    int id;
    string designation;
    double salary;

public:
    // Constructor
    Employee(string n, int i, string d, double s) {
        name = n;
        id = i;
        designation = d;
        salary = s;
    }

    // Display Function
    void display() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }

    // Friend Class Declaration
    friend class Payroll;
};

class Payroll {
public:
    // Function to update salary
    void updateSalary(Employee &e, double increment) {
        e.salary += increment;   // Accessing private member
    }
};

int main() {
    // Create Employee
    Employee emp("Ali", 101, "Manager", 50000);

    cout << "Before Salary Update:\n";
    emp.display();

    // Create Payroll object
    Payroll p;

    // Update salary
    p.updateSalary(emp, 10000);

    cout << "\nAfter Salary Update:\n";
    emp.display();

    return 0;
}