#include <iostream>
using namespace std;
/*
Task:
Build a IntVector class that mimics a simple dynamic array:
Private: int* arr, int size
Constructor: IntVector(int s) ? allocates array of s ints (init to 0)
Copy constructor: deep copy
Method: void set(int index, int value), int get(int index)
Destructor
Test:
IntVector v1(5);
v1.set(0, 100);
IntVector v2 = v1;
v2.set(0, 200);
cout << v1.get(0) << " " << v2.get(0); // Should print: 100 200
? If it prints 200 200 ? you did shallow copy! Fix it.
*/
class IntVector {
private:
    int* arr;
    int size;

public:
    // Constructor
    IntVector(int s) {
        size = (s > 0) ? s : 1;
        arr = new int[size](); // () initializes to 0
    }

    // Copy constructor ? DEEP COPY
    IntVector(IntVector &other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        cout << "Deep copy of IntVector made!\n";
    }

    // Destructor
    ~IntVector() {
        delete[] arr;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size)
            arr[index] = value;
    }

    int get(int index) {
        if (index >= 0 && index < size)
            return arr[index];
        cout << "Error: iNvalid index";
	return -1; // error indicator
    }
};

// Test
int main() {
    IntVector v1(5);
    v1.set(0, 100);

    IntVector v2 = v1; // Deep copy
    v2.set(0, 200);

    cout << v1.get(0) << " " << v2.get(0) << "\n"; // Output: 100 200

    return 0;
}
