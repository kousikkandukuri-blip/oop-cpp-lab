#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct Shape {
    virtual double area() const = 0;
    virtual string kind() const = 0;
    virtual ~Shape() {}
};

struct Circle : Shape {
    double r;
    Circle(double r) : r(r) {}
    double area() const override { return 3.14159 * r * r; }
    string kind() const override { return "Circle"; }
};

struct Square : Shape {
    double s;
    Square(double s) : s(s) {}
    double area() const override { return s * s; }
    string kind() const override { return "Square"; }
};

struct Triangle : Shape {
    double b, h;
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    string kind() const override { return "Triangle"; }
};

unique_ptr<Shape> makeShape(const string &kind) {
    if (kind == "circle") return make_unique<Circle>(2.0);
    if (kind == "triangle") return make_unique<Triangle>(4.0, 5.0);
    if (kind == "square") return make_unique<Square>(3.0);
    return nullptr;
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    string input;
    cout << "Enter shape names (circle, square, triangle) or 'done':\n";
    while (cin >> input && input != "done") {
        auto s = makeShape(input);
        if (s) {
            shapes.push_back(std::move(s));
        } else {
            cout << "Unknown shape: " << input << endl;
        }
    }

    cout << "\nCreated shapes:\n";
    for (const auto &s : shapes) {
        cout << s->kind() << " -> area = " << s->area() << endl;
    }
    return 0;
}
