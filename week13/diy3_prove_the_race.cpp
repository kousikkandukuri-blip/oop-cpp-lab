#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

long counter = 0;
mutex m;

void addUnsafe(int times) {
    for (int i = 0; i < times; ++i) {
        ++counter; // data race: not atomic!
    }
}

void addSafe(int times) {
    for (int i = 0; i < times; ++i) {
        lock_guard<mutex> lk(m);
        ++counter; // protected critical section
    }
}

int main() {
    cout << "--- Without lock_guard (race condition) ---\n";
    for (int run = 1; run <= 3; ++run) {
        counter = 0;
        thread t1(addUnsafe, 100000);
        thread t2(addUnsafe, 100000);
        t1.join();
        t2.join();
        cout << "Run " << run << ": counter = " << counter
             << " (expected 200000)\n";
    }

    cout << "--- With lock_guard (thread-safe) ---\n";
    counter = 0;
    thread t1(addSafe, 100000);
    thread t2(addSafe, 100000);
    t1.join();
    t2.join();
    cout << "Safe run: counter = " << counter << " (expected 200000)\n";
    return 0;
}
