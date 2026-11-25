#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(const string &n, int i) : name(n), id(i) {}
    void display() const {
        cout << "ID: " << id << ", Name: " << name;
    }
};

class Manager : public Employee {
    int teamSize;
public:
    Manager(const string &n, int i, int ts) : Employee(n, i), teamSize(ts) {}
    void display() const {
        Employee::display();
        cout << ", Role: Manager, Team Size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;
public:
    Engineer(const string &n, int i, const string &sk) : Employee(n, i), skill(sk) {}
    void display() const {
        Employee::display();
        cout << ", Role: Engineer, Skill: " << skill << endl;
    }
};

int main() {
    Manager m("Asha", 101, 8);
    Engineer e("Ravi", 102, "SystemVerilog");
    m.display();
    e.display();
    return 0;
}
