#include<iostream>
using namespace std;

class book{
	string title;
	string author;
    string isbn;
    bool isAvailable;
    
    public:
    	book(string t, string a, string i){
    		title = t;
    		author = a;
    		isbn = i;
    		
    		isAvailable = true;
		}
		void borrow(){
			if(isAvailable){
				isAvailable = false;
				cout << "\"" << title << "\" has been borrowed.\n";
			}
			else{
				cout << "\"" << title << "\" is already borrowed!\n";
			}
		}
		void returnBook() {
			if (!isAvailable) {
			    isAvailable = true;
				cout << "\"" << title << "\" has been returned.\n";
			} 
			else {
				cout << "\"" << title << "\" was not borrowed!\n";
			}
		}
		void displayStatus() {

			cout << "\"" << title << "\" by " << author <<" is "<< (isAvailable ? "Available" : "Borrowed") << "\n";
		}
};

int main(){
	book b("Clean Code", "Robert Martin", "978-0132350884");

 	b.displayStatus(); // Available
	b.borrow(); // Borrow it
	b.displayStatus(); // Borrowed
	b.borrow(); // Try again – should fail
	b.returnBook(); // Return
	b.returnBook(); // Try returning again – should warn
	b.displayStatus(); // Available
	
	return 0;
}