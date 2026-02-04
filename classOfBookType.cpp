#include<iostream>
using namespace std;
/*
Some of the characteristics of a book are the title, author(s), publisher, ISBN, price,
and year of publication. Design a class bookType that defines the book as an ADT.
? Each object of the class bookType can hold the following information about a
book: title, up to four authors, publisher, ISBN, price, and number of copies in
stock. To keep track of the number of authors, add another member variable.
? Include the member functions to perform the various operations on objects of
type bookType.
For example, the usual operations that can be performed on the title are to
show the title, set the title, and check whether a title is the same as the actual
title of the book. Similarly, the typical operations that can be performed on the
number of copies in stock are to show the number of copies in stock, set the
number of copies in stock, update the number of copies in stock, and return the
number of copies in stock. Add similar operations for the publisher, ISBN, book
price, and authors. Add the appropriate constructors and a destructor (if one is
needed).
? Write the definitions of the member functions of the class bookType.
? Write a program that uses the class bookType and tests various operations on
the objects of the class bookType. Declare an array of 100 components of type
bookType. Some of the operations that you should perform are to search for a
book by its title, search by ISBN, and update the number of copies of a book.
*/
class BookType{
	string title;
	string authors[4];
	int authorCount;
	string publisher;
	string isbn;
	float price;
	int copies;
	public:
		BookType(){
			authorCount = 0;
			price = 0;
			copies = 0;
		}
		void setTitle(string t){
			title = t;	
		}
		string getTitle(){
			return title;
		}
		bool checkTitle(string t) {
        return title == t;
    }
   		 void addAuthor(string a) {
        	if (authorCount < 4) {
            authors[authorCount] = a;
            authorCount++;
        }
    }
    	void showAuthors() {
        	for (int i = 0; i < authorCount; i++) {
            	cout << authors[i] << endl;
        }
    }
    void setPublisher(string p) {
        publisher = p;
    }
    void setISBN(string i) {
        isbn = i;
    }
    bool checkISBN(string i) {
        return isbn == i;
    }
    void setPrice(double p) {
        price = p;
    }
    void setCopies(int c) {
        copies = c;
    }
    void updateCopies(int c) {
        copies += c;
    }
    int getCopies() {
        return copies;
    }
    void showBook() {
        cout << "Title: " << title << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Price: " << price << endl;
        cout << "Copies in stock: " << copies << endl;
        cout << "Authors:" << endl;
        showAuthors();
    }
};

int main() {
    BookType library[100];
    int totalBooks = 0;
    
    library[0].setTitle("C++ Programming");
    library[0].addAuthor("Bjarne Stroustrup");
    library[0].setPublisher("Pearson");
    library[0].setISBN("1111");
    library[0].setPrice(500);
    library[0].setCopies(10);

    totalBooks++;

    string searchTitle = "C++ Programming";
    for (int i = 0; i < totalBooks; i++) {
        if (library[i].checkTitle(searchTitle)) {
            cout << "\nBook found by title:\n";
            library[i].showBook();
        }
    }
    string searchISBN = "1111";
    for (int i = 0; i < totalBooks; i++) {
        if (library[i].checkISBN(searchISBN)) {
            library[i].updateCopies(5);
            cout << "\nUpdated copies after adding 5:\n";
            cout << library[i].getCopies() << endl;
        }
    }
    return 0;
}