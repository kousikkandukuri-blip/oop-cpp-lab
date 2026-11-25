#include <iostream>
using namespace std;

class Complex {
private:
    double real = 0;
    double imag = 0;
public:
    void setData(double r, double i) {
        real = r;
        imag = i;
    }
    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ")
             << (imag >= 0 ? imag : -imag) << "i" << endl;
    }
};

int main() {
    Complex arr[3];
    arr[0].setData(2.5, 3.0);
    arr[1].setData(1.0, -4.5);
    arr[2].setData(-3.0, 0.5);

    for (int i = 0; i < 3; ++i) {
        cout << "z" << i + 1 << " = ";
        arr[i].display();
    }
    return 0;
}
