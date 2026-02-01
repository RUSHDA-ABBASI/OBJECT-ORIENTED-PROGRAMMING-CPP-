#include<iostream>
#include<string>
#include<vector>
using namespace std;

// class of books.
class Book{
	const int bookId;
	string title;
	string author;
	float price;
	bool isIssued;
	
	public:
		static int totalBooks;
	Book(int i, string t, string a, float p) //constructor
	:bookId(i)
	{
		title = t;
		author = a;
		if(p >= 0)
		price = p;
		else
		price = 0;
		isIssued = false;
		totalBooks++;
	}
	//getter functions
	int getbookId() const {
        return bookId;
    }
    
    string getTitle() const {
    	return title;
	}
	
	string getAuthor() const {
		return author;
	}
	
	float getPrice() const {
		return price;
	}
	
	void setPrice(float p){  //setter function
    if (p >= 0)
        price = p;
    else
        cout << "Price cannot be negative!\n";
	}
	static int getTotalBooks() {
        return totalBooks;
    }
    bool getIsIssued() const{
    	return isIssued;
	}
	void issue(){
		isIssued = true;
	}
};
int Book::totalBooks = 0; //static member should be initialized outside the class.

//class of members.
class Member{
	int memberId;
	string name;
	const int maxBooksAllowed = 4;
	int booksIssued;
	
	public:
		static int totalMembers;
	Member(int id, string n) //constructor
	{
		memberId = id;
		name = n;
		booksIssued = 0;
		totalMembers++;
	}
	
	int getMemberId() const {
		return memberId;
	}
	
	string getName() const {
		return name;
	}
	
	int getMaxBooksAllowed() const{
		return maxBooksAllowed;
	}
	
	static int getTotalMembers(){
		return totalMembers;
	}
	bool canIssueBook() const {
    return booksIssued < maxBooksAllowed;
	}
	void issueBook() {
      if( canIssueBook() ){
       booksIssued++;
    }  else {
        cout << "Book limit reached!\n";
    }
	}	
};
int Member::totalMembers = 0;

//class of library.
class Library{
	vector<Book> books;
	vector<Member> members;
	
	public:
    void addBook(const Book& b) {
        books.push_back(b);
    }
    void registerMember(const Member& m) {
        members.push_back(m);
    }
    void issueBook(int bookId, int memberId) {
    for (Book &b : books) {
        if (b.getbookId() == bookId && !b.getIsIssued()) {  //checks if book is available.

            for (Member &m : members) {
                if (m.getMemberId() == memberId) {  //checks if member is registered.

                    if (m.canIssueBook()) {
                        b.issue();
                        m.issueBook();
                        cout << "Book issued successfully\n";
                        return;
                    } else {
                        cout << "Member reached limit\n";
                        return;
                    }
                }
            }
            cout << "Member not found\n";
            return;
        }
    }
    cout << "Book not available\n";
	}
	void displayAllBooks() const {
    	for (const Book &b : books) {
        	cout << b.getbookId() << " " << b.getTitle() << " "<< b.getAuthor() << endl;
    	}
	}
	void displayAllMembers() const {
    	for (const Member &m : members) {
        	cout << m.getMemberId() << " "<< m.getName() << endl;            
    	}
	} 
};

 
int main(){
	Library lib;

    Book b1(101, "Programming", "Jackson White", 50);
    Book b2(102, "C++ Programming Language", "Brian Klem", 70);
    Book b3(103, "Programming Fundamentals", "John Lee", 90);

    Member m1(1, "Rushda");
    Member m2(2, "Abbasi");
    Member m3(3, "Abcd");

    lib.addBook(b1);
    lib.addBook(b2);

    lib.registerMember(m1);
    lib.registerMember(m2);

    lib.issueBook(101, 1);
    lib.issueBook(102, 3); // will show warning because m3 is not registered in the library.
    lib.issueBook(103, 2); //will show warning because b3 is not added to the library.
    
    cout<<"\nAll Books registered in the library are: \n";
    lib.displayAllBooks();
    
    cout<<"\nAll members registered in the library are: \n";
    lib.displayAllMembers();
	return 0;
}