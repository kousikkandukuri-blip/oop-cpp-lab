#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    static int nextId;
    int orderId;
    string item;
public:
    Order(const string &itemName) : orderId(nextId++), item(itemName) {}
    void show() const {
        cout << "Order #" << orderId << ": " << item << endl;
    }
};

int Order::nextId = 1001;

int main() {
    Order o1("Sensor Module");
    Order o2("FPGA Board");
    Order o3("Logic Analyzer");

    o1.show();
    o2.show();
    o3.show();
    return 0;
}
