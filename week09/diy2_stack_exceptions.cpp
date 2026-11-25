#include <iostream>
#include <exception>
using namespace std;

class Overflow : public exception {
public:
    const char* what() const noexcept override { return "Stack Overflow"; }
};

class Underflow : public exception {
public:
    const char* what() const noexcept override { return "Stack Underflow"; }
};

class Stack {
    int *arr;
    int capacity;
    int topIdx;
public:
    Stack(int cap = 5) : capacity(cap), topIdx(-1) {
        arr = new int[capacity];
    }
    ~Stack() { delete[] arr; }

    void push(int val) {
        if (topIdx + 1 >= capacity) throw Overflow();
        arr[++topIdx] = val;
    }
    int pop() {
        if (topIdx < 0) throw Underflow();
        return arr[topIdx--];
    }
};

int main() {
    Stack s(2);
    try {
        s.push(10);
        s.push(20);
        s.push(30); // throws Overflow
    } catch (const Overflow &e) {
        cerr << "Caught: " << e.what() << endl;
    }

    try {
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl;
        cout << "Popped: " << s.pop() << endl; // throws Underflow
    } catch (const Underflow &e) {
        cerr << "Caught: " << e.what() << endl;
    }
    return 0;
}
