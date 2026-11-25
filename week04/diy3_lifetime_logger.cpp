#include <iostream>
using namespace std;

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) { cout << "Construct #" << id << endl; }
    ~Tracer() { cout << "Destruct #" << id << endl; }
};

int main() {
    for (int i = 1; i <= 3; ++i) {
        Tracer *t = new Tracer(i);
        // Commenting out 'delete t;' below causes a memory leak
        // detectable with: g++ -std=c++17 -fsanitize=address diy3_lifetime_logger.cpp
        delete t;
    }
    return 0;
}
