#include <iostream>
#include <numeric>
using namespace std;

class Fraction {
private:
    int num, den;

    void simplify() {
        if (den == 0) {
            cout << "Denominator cannot be zero; setting to 1.\n";
            den = 1;
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
        int g = gcd(num < 0 ? -num : num, den);
        if (g > 1) {
            num /= g;
            den /= g;
        }
    }
public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    friend istream& operator>>(istream &is, Fraction &f) {
        is >> f.num >> f.den;
        f.simplify();
        return is;
    }

    friend ostream& operator<<(ostream &os, const Fraction &f) {
        os << f.num << "/" << f.den;
        return os;
    }
};

int main() {
    Fraction a(12, 18), b;
    cout << "Simplified 12/18 = " << a << endl;

    cout << "Enter numerator and denominator: ";
    if (cin >> b) {
        cout << "Simplified input = " << b << endl;
    }
    return 0;
}
