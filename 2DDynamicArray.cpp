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
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
        }
    }

    // Copy Constructor
    Array2D(const Array2D &obj) {
        rows = obj.rows;
        cols = obj.cols;

        arr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                arr[i][j] = obj.arr[i][j];
            }
        }
    }

    // Assignment Operator
    Array2D& operator=(const Array2D &obj) {
        if (this != &obj) {
            // delete old memory
            for (int i = 0; i < rows; i++) {
                delete[] arr[i];
            }
            delete[] arr;

            // copy new
            rows = obj.rows;
            cols = obj.cols;

            arr = new int*[rows];
            for (int i = 0; i < rows; i++) {
                arr[i] = new int[cols];
                for (int j = 0; j < cols; j++) {
                    arr[i][j] = obj.arr[i][j];
                }
            }
        }
        return *this;
    }

    // Indexing Operator
    int* operator[](int i) {
        return arr[i];
    }

    // Addition Operator
    Array2D operator+(const Array2D &obj) {
        Array2D temp(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.arr[i][j] = arr[i][j] + obj.arr[i][j];
        return temp;
    }

    // Subtraction Operator
    Array2D operator-(const Array2D &obj) {
        Array2D temp(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.arr[i][j] = arr[i][j] - obj.arr[i][j];
        return temp;
    }

    // Multiplication Operator (element-wise)
    Array2D operator*(const Array2D &obj) {
        Array2D temp(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                temp.arr[i][j] = arr[i][j] * obj.arr[i][j];
        return temp;
    }

    // Input Function
    void input() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> arr[i][j];
    }

    // Display Function
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }

    // Destructor
    ~Array2D() {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
int main() {
    Array2D A(2,2), B(2,2);

    cout << "Enter elements of A:\n";
    A.input();

    cout << "Enter elements of B:\n";
    B.input();

    cout << "\nMatrix A:\n";
    A.display();

    cout << "\nMatrix B:\n";
    B.display();

    // Testing +
    Array2D C = A + B;
    cout << "\nA + B:\n";
    C.display();

    // Testing -
    Array2D D = A - B;
    cout << "\nA - B:\n";
    D.display();

    // Testing *
    Array2D E = A * B;
    cout << "\nA * B (element-wise):\n";
    E.display();

    // Testing Copy Constructor
    Array2D F = A;
    cout << "\nCopy of A:\n";
    F.display();

    // Testing Assignment Operator
    Array2D G;
    G = B;
    cout << "\nAssigned B to G:\n";
    G.display();

    // Testing Indexing Operator
    cout << "\nAccess using indexing A[0][1]: " << A[0][1] << endl;

    return 0;
}