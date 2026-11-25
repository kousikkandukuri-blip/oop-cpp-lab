#include <iostream>
#include <memory>
using namespace std;

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) { cout << "Construct #" << id << endl; }
    ~Tracer() { cout << "Destruct #" << id << endl; }
};

int main() {
    for (int i = 1; i <= 3; ++i) {
        unique_ptr<Tracer> t = make_unique<Tracer>(i);
        cout << "  Using Tracer #" << i << endl;
        // Automatically freed at end of each iteration; no delete needed
    }
    return 0;
}
