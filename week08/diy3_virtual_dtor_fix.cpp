#include <iostream>
using namespace std;

class Base {
public:
    // Remove 'virtual' below and run with -fsanitize=address to observe the leak:
    virtual ~Base() { cout << "~Base\n"; }
};

class Derived : public Base {
    int *buf;
public:
    Derived() { buf = new int[100]; }
    ~Derived() override {
        delete[] buf;
        cout << "~Derived (freed buf)\n";
    }
};

int main() {
    Base *ptr = new Derived();
    delete ptr; // With virtual ~Base(), calls ~Derived() then ~Base()
    return 0;
}
