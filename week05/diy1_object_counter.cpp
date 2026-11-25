#include <iostream>
using namespace std;

class Counter {
private:
    int count = 0;
    static int totalCreated;
    static int currentlyAlive;
public:
    Counter() {
        ++totalCreated;
        ++currentlyAlive;
    }
    Counter(const Counter &o) : count(o.count) {
        ++totalCreated;
        ++currentlyAlive;
    }
    ~Counter() {
        --currentlyAlive;
    }
    void increment() { ++count; }
    void reset() { count = 0; }
    int get() const { return count; }

    static int created() { return totalCreated; }
    static int alive() { return currentlyAlive; }
};

int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter c1, c2;
    {
        Counter c3;
        cout << "Inside block -> Created: " << Counter::created()
             << ", Alive: " << Counter::alive() << endl;
    }
    cout << "After block  -> Created: " << Counter::created()
         << ", Alive: " << Counter::alive() << endl;
    return 0;
}
