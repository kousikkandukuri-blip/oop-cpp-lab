#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hh, mm;
public:
    Time(int h = 0, int m = 0) : hh(h), mm(m) {}
    friend Time laterOf(Time a, Time b);
    void show() const {
        cout << setw(2) << setfill('0') << hh << ":"
             << setw(2) << setfill('0') << mm << endl;
    }
};

Time laterOf(Time a, Time b) {
    int minsA = a.hh * 60 + a.mm;
    int minsB = b.hh * 60 + b.mm;
    return (minsA >= minsB) ? a : b;
}

int main() {
    Time t1(9, 45), t2(14, 15);
    cout << "Later time: ";
    laterOf(t1, t2).show();
    return 0;
}
