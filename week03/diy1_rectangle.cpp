#include <iostream>
using namespace std;

class Rectangle {
private:
    double length = 0;
    double width = 0;
public:
    bool setLength(double l) {
        if (l < 0) {
            cout << "Invalid length (negative rejected)\n";
            return false;
        }
        length = l;
        return true;
    }
    bool setWidth(double w) {
        if (w < 0) {
            cout << "Invalid width (negative rejected)\n";
            return false;
        }
        width = w;
        return true;
    }
    double area() const { return length * width; }
    double perimeter() const { return 2 * (length + width); }
};

int main() {
    Rectangle r;
    r.setLength(-5); // rejected
    r.setLength(10);
    r.setWidth(4);
    cout << "Area = " << r.area() << ", Perimeter = " << r.perimeter() << endl;
    return 0;
}
