#include<iostream>
using namespace std;
/*
You are a programmer for the ABC Bank assigned to develop a class that models the basic
workings of a bank account. The class should perform the following tasks:
o Save the account balance.
o Save the number of transactions performed on the account.
o Allow deposits to be made to the account.
o Allow with drawls to be taken from the account.
o Report the current account balance at any time.
o Report the current number of transactions at any time.
Menu
1. Display the account balance
2. Display the number of transactions
3. Display interest earned for this period
4. Make a deposit
5. Make a withdrawal
6. Exit the program
*/
class BankAccount{
	double balance;
	int transactions;
	const double interestRate = 0.05;
	public:
		BankAccount(){
			balance = 0.0;
			transactions = 0;
	}
		void deposit(double amount){
			if(amount > 0){
				balance += amount;
				transactions++;
				cout << "Deposit successful.\n";
			}
			else{
				cout << "Invalid deposit amount.\n";
			}
	}
		void withdraw(double amount){
			if(amount > 0 && amount <= balance){
				balance -= amount;
				transactions++;
		        cout<<"Withdrawal successful.\n";
			}
			else{
				cout << "Invalid or insufficient balance.\n";
			}
	}
		void showBalance() const {
        cout << "Current Balance: Rs. " << balance << endl;
    }
     void showTransactions() const {
        cout << "Number of Transactions: " << transactions << endl;
	}
    void showInterest() const {
        double interest = balance * interestRate;
        cout << "Interest Earned This Period: Rs. " << interest << endl;
    }
};
int main(){
	 BankAccount account;
    int choice;
    double amount;
    do {
        cout << "1. Display account balance\n";
        cout << "2. Display number of transactions\n";
        cout << "3. Display interest earned for this period\n";
        cout << "4. Make a deposit\n";
        cout << "5. Make a withdrawal\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.showBalance();
                break;

            case 2:
                account.showTransactions();
                break;

            case 3:
                account.showInterest();
                break;

            case 4:
                cout << "Enter deposit amount: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 5:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 6:
                cout << "Thank you for using ABC Bank.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
	return 0;}