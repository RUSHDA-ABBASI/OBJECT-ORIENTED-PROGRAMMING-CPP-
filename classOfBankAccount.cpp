#include <iostream>
#include <string>
using namespace std;
class BankAccount{
private:
string owner;
double balance; // Hidden from outside!

public:
// Constructor
BankAccount(string name, double initial) {
owner = name;
balance = initial;
}
// Public interface (safe access
void deposit(double amount) {
if (amount > 0) balance += amount;
}

bool withdraw(double amount) {
if (amount <= balance && amount > 0) {
balance -= amount;
return true;
}
return false;
}
void display() {
cout << "Owner: " << owner << ", Balance: $" << balance << "\n";
}
};

int main() {

// Create two OBJECTS

BankAccount acc1("Ali", 100.0);

BankAccount acc2("Sara", 50.0);

acc1.deposit(25);

acc2.withdraw(10);

acc1.display(); // Owner: Ali, Balance: $125

acc2.display(); // Owner: Sara, Balance: $40

// ? This would cause ERROR:

// cout << acc1.balance; // 'balance' is private!

}