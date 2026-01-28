#include <iostream>
#include <cstring>
#include <string>
using namespace std;
/*
Create a class called Employee that includes three pieces of information as data members—a
first name (type char* (DMA)), a last name (type string) and a monthly salary (type int). Your
class should have a setter function that initializes the three data members. Provide a getter
function for each data member. If the monthly salary is not positive, set it to 0. Write a test
program that demonstrates class Employee’s capabilities. Create two Employee objects and
display each object’s yearly salary. Then give each Employee a 10 percent raise and display
each Employee’s yearly salary again. Identify and add any other related functions to achieve the
said goal.
*/
class Employee {
private:
    char* firstName; 
    string lastName;
    int monthlySalary;
public:
    Employee() {
        firstName = nullptr;
        monthlySalary = 0;
    }
    void setEmployee(const char* fName, string lName, int salary) {
        if (firstName != nullptr) {
            delete[] firstName;
        }
        firstName = new char[strlen(fName) + 1];
        strcpy(firstName, fName);

        lastName = lName;

        if (salary > 0)
            monthlySalary = salary;
        else
            monthlySalary = 0;
    }
    char* getFirstName() const {
        return firstName;
    }
    string getLastName() const {
        return lastName;
    }
    int getMonthlySalary() const {
        return monthlySalary;
    }
    int getYearlySalary() const {
        return monthlySalary * 12;
    }
    void giveRaise(double percent) {
        monthlySalary += monthlySalary * (percent / 100);
    }
    ~Employee() {
        delete[] firstName;
    }
};
int main() {
    Employee e1, e2;

    e1.setEmployee("Ali", "Khan", 50000);
    e2.setEmployee("Sara", "Ahmed", 60000);
    cout << "Yearly Salary of " << e1.getFirstName() << " "
         << e1.getLastName() << ": "
         << e1.getYearlySalary() << endl;
    cout << "Yearly Salary of " << e2.getFirstName() << " "
         << e2.getLastName() << ": "
         << e2.getYearlySalary() << endl;

    e1.giveRaise(10);
    e2.giveRaise(10);

    cout << "\nAfter 10% Raise:\n";
    cout << "Yearly Salary of " << e1.getFirstName() << " "
         << e1.getLastName() << ": "
         << e1.getYearlySalary() << endl;
    cout << "Yearly Salary of " << e2.getFirstName() << " "
         << e2.getLastName() << ": "
         << e2.getYearlySalary() << endl;
    return 0;
}
