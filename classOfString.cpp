#include <iostream>
#include <cstring>
using namespace std;
/*
Task:
Create a MyString class that:
Holds a char* (dynamically allocated)
Constructor: MyString(const char* s)
Copy constructor: deep copy
Method: void append(const char* suffix) → reallocate + copy
Destructor
Challenge: (Make this work without crashing)
"MyString s1("Hello");
MyString s2 = s1;
s1.append(" World");
s2.print(); // Should still print "Hello“ "
This reveals why shallow copy fails when one object modifies shared data.
*/

class MyString {
private:
    char* data;

    // Helper: reallocate and copy
    void resizeAndCopy(char* newStr) {
        delete[] data;
        data = new char[strlen(newStr) + 1];
        strcpy(data, newStr);
    }

public:
    // Constructor
    MyString(const char* s) {
        if (s != nullptr) {
            data = new char[strlen(s) + 1];
            strcpy(data, s);
        } else {
            data = new char[1];
            data[0] = '\0';
        }
    }

    // Copy constructor → DEEP COPY
    MyString(const MyString &other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "MyString deep copied.\n";
    }

    // Destructor
    ~MyString() {
        delete[] data;
    }

    // Append method (reallocate + copy)
    void append(const char* suffix) {
        if (suffix == nullptr) return;

        int len1 = strlen(data);
        int len2 = strlen(suffix);
        char* temp = new char[len1 + len2 + 1];
        strcpy(temp, data);  // temp = "Hello"
        strcat(temp, suffix); // temp = "Hello World"
        resizeAndCopy(temp);
        delete[] temp;
    }

    void print() {
        cout << "\"" << data << "\"\n";
    }
};

// Test
int main() {
    MyString s1("Hello");
    MyString s2 = s1;  // Deep copy

    s1.append(" World");

    s1.print(); // "Hello World"
    s2.print(); // "Hello" → still original!

    return 0;
}