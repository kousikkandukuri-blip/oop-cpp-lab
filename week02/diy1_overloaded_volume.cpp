#include <iostream>
using namespace std;

double volume(double side) {
    return side * side * side;
}

double volume(double l, double b, double h) {
    return l * b * h;
}

double volume(double r, double h) {
    return 3.14159 * r * r * h;
}

int main() {
    cout << "Cube (side=3): " << volume(3.0) << endl;
    cout << "Cuboid (2x3x4): " << volume(2.0, 3.0, 4.0) << endl;
    cout << "Cylinder (r=2, h=5): " << volume(2.0, 5.0) << endl;
    return 0;
}
