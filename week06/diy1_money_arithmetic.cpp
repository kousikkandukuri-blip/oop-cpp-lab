#include <iostream>
#include <iomanip>
using namespace std;

class Money {
private:
    int rupees;
    int paise;

    void normalize(int totalPaise) {
        rupees = totalPaise / 100;
        paise = totalPaise % 100;
    }
public:
    Money(int r = 0, int p = 0) {
        normalize(r * 100 + p);
    }

    Money operator+(const Money &rhs) const {
        int total = (rupees * 100 + paise) + (rhs.rupees * 100 + rhs.paise);
        return Money(0, total);
    }

    Money operator-(const Money &rhs) const {
        int total = (rupees * 100 + paise) - (rhs.rupees * 100 + rhs.paise);
        return Money(0, total);
    }

    friend ostream& operator<<(ostream &os, const Money &m) {
        os << "Rs." << m.rupees << "." << setw(2) << setfill('0')
           << (m.paise < 0 ? -m.paise : m.paise);
        return os;
    }
};

int main() {
    Money m1(12, 75), m2(5, 60);
    cout << "m1 = " << m1 << ", m2 = " << m2 << endl;
    cout << "m1 + m2 = " << (m1 + m2) << endl;
    cout << "m1 - m2 = " << (m1 - m2) << endl;
    return 0;
}
