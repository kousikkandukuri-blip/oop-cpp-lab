#include <iostream>
#include <stdexcept>
using namespace std;

class SafeArray {
private:
    int *data;
    int size;
public:
    SafeArray(int n) : size(n) {
        data = new int[size]{};
    }
    SafeArray(const SafeArray &o) : size(o.size) {
        data = new int[size];
        for (int i = 0; i < size; ++i) data[i] = o.data[i];
    }
    SafeArray& operator=(const SafeArray &o) {
        if (this != &o) {
            delete[] data;
            size = o.size;
            data = new int[size];
            for (int i = 0; i < size; ++i) data[i] = o.data[i];
        }
        return *this;
    }
    ~SafeArray() { delete[] data; }

    int& operator[](int idx) {
        if (idx < 0 || idx >= size) {
            throw out_of_range("Index out of bounds: " + to_string(idx));
        }
        return data[idx];
    }
};

int main() {
    SafeArray arr(5);
    try {
        arr[0] = 10;
        arr[4] = 50;
        cout << "arr[0] = " << arr[0] << ", arr[4] = " << arr[4] << endl;
        cout << "Accessing arr[10]...\n";
        arr[10] = 99;
    } catch (const out_of_range &e) {
        cerr << "Error caught: " << e.what() << endl;
    }
    return 0;
}
