#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int **data;
public:
    Matrix(int m, int n) : rows(m), cols(n) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]{};
        }
    }

    // Deep copy constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    void set(int r, int c, int val) { data[r][c] = val; }
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1(2, 3);
    m1.set(0, 1, 5);
    m1.set(1, 2, 9);

    Matrix m2 = m1; // deep copy
    m2.set(0, 1, 99);

    cout << "Original m1:\n";
    m1.print();
    cout << "Modified copy m2:\n";
    m2.print();
    return 0;
}
