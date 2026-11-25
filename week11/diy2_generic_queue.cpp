#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <typename T>
class Queue {
private:
    static const int CAP = 100;
    T data[CAP];
    int head = 0;
    int tail = 0;
    int count = 0;
public:
    void enqueue(const T &val) {
        if (count == CAP) throw overflow_error("Queue is full");
        data[tail] = val;
        tail = (tail + 1) % CAP;
        ++count;
    }
    void dequeue() {
        if (empty()) throw underflow_error("Queue is empty");
        head = (head + 1) % CAP;
        --count;
    }
    const T& front() const {
        if (empty()) throw underflow_error("Queue is empty");
        return data[head];
    }
    bool empty() const { return count == 0; }
};

int main() {
    Queue<string> q;
    q.enqueue("TX_PKT_1");
    q.enqueue("TX_PKT_2");
    q.enqueue("TX_PKT_3");

    while (!q.empty()) {
        cout << "Front: " << q.front() << endl;
        q.dequeue();
    }
    return 0;
}
