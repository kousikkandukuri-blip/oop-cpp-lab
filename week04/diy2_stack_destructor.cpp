#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int capacity;
    int topIdx;
public:
    Stack(int cap = 10) : capacity(cap), topIdx(-1) {
        arr = new int[capacity];
    }
    ~Stack() {
        delete[] arr;
    }
    bool push(int val) {
        if (topIdx + 1 >= capacity) {
            cout << "Stack overflow\n";
            return false;
        }
        arr[++topIdx] = val;
        return true;
    }
    bool pop(int &out) {
        if (topIdx < 0) {
            cout << "Stack underflow\n";
            return false;
        }
        out = arr[topIdx--];
        return true;
    }
    bool empty() const { return topIdx < 0; }
};

int main() {
    Stack s(3);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40); // overflow

    int x;
    while (s.pop(x)) {
        cout << "Popped: " << x << endl;
    }
    s.pop(x); // underflow
    return 0;
}
