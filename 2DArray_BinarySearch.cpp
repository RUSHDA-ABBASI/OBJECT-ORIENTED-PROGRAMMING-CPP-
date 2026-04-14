#include <iostream>
using namespace std;

class Array2D {
private:
    int **arr;
    int rows, cols;

public:
    // Default Constructor
    Array2D() {
        rows = cols = 0;
        arr = nullptr;
    }

    // Parameterized Constructor
    Array2D(int r, int c) {
        rows = r;
        cols = c;

        arr = new int*[rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new int[cols];
    }

    // Copy Constructor
    Array2D(const Array2D &obj) {
        rows = obj.rows;
        cols = obj.cols;

        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                arr[i][j] = obj.arr[i][j];
        }
    }

    // Assignment Operator
    Array2D& operator=(const Array2D &obj) {
        if (this != &obj) {
            for (int i = 0; i < rows; i++)
                delete[] arr[i];
            delete[] arr;

            rows = obj.rows;
            cols = obj.cols;

            arr = new int*[rows];
            for (int i = 0; i < rows; i++) {
                arr[i] = new int[cols];
                for (int j = 0; j < cols; j++)
                    arr[i][j] = obj.arr[i][j];
            }
        }
        return *this;
    }

    // Indexing Operator
    int* operator[](int i) {
        return arr[i];
    }

    // Input
    void input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> arr[i][j];
    }

    // Display
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    // Binary Search Function
    bool search(int target) {
        int left = 0;
        int right = rows * cols - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            int i = mid / cols;
            int j = mid % cols;

            if (arr[i][j] == target)
                return true;
            else if (arr[i][j] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }

    // Destructor
    ~Array2D() {
        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
    }
};

int main() {
    Array2D A(3,4);

    cout << "Enter matrix elements:\n";
    A.input();

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (A.search(target))
        cout << "Output: true\n";
    else
        cout << "Output: false\n";

    return 0;
}