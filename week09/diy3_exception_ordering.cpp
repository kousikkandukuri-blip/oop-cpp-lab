#include <iostream>
#include <exception>
using namespace std;

struct MathError : exception {
    const char* what() const noexcept override { return "General MathError"; }
};

struct DivideByZero : MathError {
    const char* what() const noexcept override { return "DivideByZero error"; }
};

double divide(double a, double b) {
    if (b == 0.0) throw DivideByZero();
    return a / b;
}

int main() {
    cout << "1. Wrong order (base caught first):\n";
    try {
        divide(10, 0);
    } catch (const MathError &e) {
        cout << "  Caught by MathError handler: " << e.what() << endl;
    } catch (const DivideByZero &e) {
        cout << "  Caught by DivideByZero handler: " << e.what() << endl;
    }

    cout << "2. Fixed order (derived caught first):\n";
    try {
        divide(10, 0);
    } catch (const DivideByZero &e) {
        cout << "  Caught by DivideByZero handler: " << e.what() << endl;
    } catch (const MathError &e) {
        cout << "  Caught by MathError handler: " << e.what() << endl;
    }
    return 0;
}
